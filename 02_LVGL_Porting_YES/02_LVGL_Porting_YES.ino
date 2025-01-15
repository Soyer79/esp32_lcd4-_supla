#include <Arduino.h>
#include <ESP32Time.h>
#include <esp_sntp.h> 
#include <WiFiMulti.h>
#include <WiFiClientSecure.h>
#include <ESP_Panel_Library.h>
#include <PubSubClient.h>
#include <lvgl.h>
#include "lvgl_port_v8.h"
#include "ui.h"
#include "actions.h"
#include "screens.h"
#include <ESP_IOExpander_Library.h>
#include "HWCDC.h"
#include <NetworkClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include <HTTPUpdateServer.h>
//#include <string.h>

const char *host = "esp32";
WebServer httpServer(80);
HTTPUpdateServer httpUpdater;

HWCDC USBSerial;

#define EXAMPLE_CHIP_NAME TCA95xx_8bit
#define EXAMPLE_I2C_NUM (1)
#define EXAMPLE_I2C_SDA_PIN (8)
#define EXAMPLE_I2C_SCL_PIN (9)

#define _EXAMPLE_CHIP_CLASS(name, ...) ESP_IOExpander_##name(__VA_ARGS__)
#define EXAMPLE_CHIP_CLASS(name, ...) _EXAMPLE_CHIP_CLASS(name, ##__VA_ARGS__)

ESP_IOExpander *expander = NULL;

WiFiMulti wifiMulti;
WiFiClientSecure client1;
PubSubClient client(client1);

#define uS_TO_S_FACTOR 1000000ULL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  25200          /* Time ESP32 will go to sleep (in seconds) */
String jsonBuffer;
ESP32Time rtc;
String tim;
//String dat;
unsigned long pmillisTime = 0;
unsigned long pmillisEvent = 0;
unsigned long pmillisAlert = 0;
int alert=0;
int setAlert=0;
boolean lPlacState = 0;
boolean lWjazdState = 0;
boolean setMain = false;
boolean updateButton=0;
boolean updating = 0;
boolean switchOn=1;
int pinPozycja=1;
int PINkey =0;
int pinCyfra1 = 2;
int pinCyfra2 = 9;
int pinCyfra3 = 0;
int pinCyfra4 = 5;
int cfr=0;
int alertRestart=0;
const char* mqtt_server = "mqttxx.supla.org";
const char* mqtt_user = "xx";
const char* mqtt_pass = "xx";
float tempGrunt;
String top1="supla/xx/devices/xx/channels/x/state/temperature";//TemGrunt
String top2="supla/xx/devices/xx/channels/x/state/value";//wiatr
String top3="supla/xx/devices/xx/channels/x/state/hi";//krancowka wjazd true->zamk
String top4="supla/xx/devices/xx/channels/x/state/hi";//krancowka garaz true->zamk
String top5="supla/xx/devices/xx/channels/x/state/on";//LAMPY PODJAZD
String top6="supla/xx/devices/xx/channels/x/state/on";//lampy plac
String top7="supla/xx/devices/xx/channels/x/state/value";//PM2.5
String week[7] = {"Niedziela", "Poniedziałek", "Wtorek", "Środa", "Czwartek", "Piątek", "Sobota"};
String month[12] ={
  "Styczeń", "Luty", "Marzec", "Kwiecień", "Maj", "Czerwiec", "Lipiec", "Sierpień", "Wrzesień", "Październik", "Listopad", "Grudzień"};

void my_time(lv_timer_t * timer){  
  LV_UNUSED(timer);
  if (lv_scr_act()==objects.main){
   tim = rtc.getTime();
   lv_label_set_text(objects.lbl_0_time, tim.c_str());
  }
}
void screenSaver(lv_timer_t * timer1){
  LV_UNUSED(timer1);
  if (lv_scr_act()==objects.main){
   lv_scr_load_anim(objects.scr6, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);
  }
  else if (lv_scr_act()==objects.scr6){
   lv_scr_load_anim(objects.scr7, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);
  }
  else if (lv_scr_act()==objects.scr7){
   lv_scr_load_anim(objects.scr6, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);
  }
}



void setup() {
  USBSerial.begin(9600);
  expander = new EXAMPLE_CHIP_CLASS(EXAMPLE_CHIP_NAME,
                                    (i2c_port_t)EXAMPLE_I2C_NUM, ESP_IO_EXPANDER_I2C_TCA9554_ADDRESS_000,
                                    EXAMPLE_I2C_SCL_PIN, EXAMPLE_I2C_SDA_PIN);

  expander->init();
  esp_err_t initStatus = expander->begin();
delay(100);
  if (initStatus == ESP_OK) {
    USBSerial.println("Expander initialized successfully.");
  } else {
    expander = new EXAMPLE_CHIP_CLASS(EXAMPLE_CHIP_NAME,
                                      (i2c_port_t)1, ESP_IO_EXPANDER_I2C_TCA9554_ADDRESS_000,
                                      7, 15);
    expander->init();
    expander->begin();
  }
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);

  USBSerial.println("Original status:");
  expander->printStatus();
  //expander->pinMode(5, OUTPUT);
  //expander->digitalWrite(5, HIGH);
  expander->pinMode(0, OUTPUT);
  expander->digitalWrite(0, LOW);
  expander->pinMode(2, OUTPUT);
  expander->digitalWrite(2, LOW);
  //expander->printStatus();
  delay(200);
  //expander->digitalWrite(5, LOW);
  expander->digitalWrite(2, HIGH);
  expander->digitalWrite(0, HIGH);
  //expander->printStatus();

  
  USBSerial.println("Initialize panel device");
  ESP_Panel *panel = new ESP_Panel();
  
  panel->init();

 #if LVGL_PORT_AVOID_TEAR
  // When avoid tearing function is enabled, configure the RGB bus according to the LVGL configuration
  ESP_PanelBus_RGB *rgb_bus = static_cast<ESP_PanelBus_RGB *>(panel->getLcd()->getBus());
  rgb_bus->configRgbFrameBufferNumber(LVGL_PORT_DISP_BUFFER_NUM);
  rgb_bus->configRgbBounceBufferSize(LVGL_PORT_RGB_BOUNCE_BUFFER_SIZE);
 #endif

  panel->begin();
   
  USBSerial.println("Initialize LVGL");
  lvgl_port_init(panel->getLcd(), panel->getTouch());

  USBSerial.println("Create UI");
  /* Lock the mutex due to the LVGL APIs are not thread-safe */
  lvgl_port_lock(-1);
  lvgl_port_unlock();

  wifiConfig();
  timeConfig();
  mqttConfig();
  uiConfig();
 
  lv_timer_t * timer = lv_timer_create(my_time, 1000,  NULL);
 lv_timer_t * timer1 = lv_timer_create(screenSaver, 600000,  NULL);

  updating=0;
 pmillisTime = millis();
 esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
 USBSerial.println("LET'S START...");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  if(updating){
    httpServer.handleClient();
  }
  dateTime();
  mainScr();
}

void uiConfig(){
  USBSerial.println("UI config...");
  ui_init();
  lv_label_set_text(objects.lbl_0_time, tim.c_str());
  date();
}
void mqttConfig(){
 USBSerial.println("MQTT config...");
 client1.setInsecure();
 client.setServer(mqtt_server, 8883);
 client.setCallback(callback);
}
void timeConfig(){
  USBSerial.println("TIME config...");
  USBSerial.println("..............");
  configTime(3600, 3600, "tempus2.gum.gov.pl");
  delay(100);
  sntp_sync_status_t syncStatus;
  syncStatus = sntp_get_sync_status();
    while (syncStatus != SNTP_SYNC_STATUS_COMPLETED) {
        syncStatus = sntp_get_sync_status();
        delay(100); // Adjust the delay time as per your requirements
    }
  tim = rtc.getTime();
  USBSerial.println(tim);
  USBSerial.println("..............");
}
void wifiConfig(){
  USBSerial.println("WIFI config...");
  wifiMulti.addAP("xx", "x");
  wifiMulti.addAP("xx", "x");
  wifiMulti.addAP("xx", "x");
  wifiMulti.addAP("xx", "x");
  wifiMulti.addAP("xx", "x");
  while(wifiMulti.run() != WL_CONNECTED) {
    USBSerial.println(".");
    delay(500);
  }
}
void mainScr(){
  if(((millis()-pmillisEvent)>60000) && (setMain)){
    setMain=false;
    lv_scr_load(objects.main); 
   // lv_timer_reset(timer1);
  }
}

void showAlert(){
  if((setAlert==0)&&((millis()-pmillisAlert)>60000)){
    lv_label_set_text(objects.lbl_0_alert, "");
    setAlert=1;
  }
}
void dateTime(){
  if((millis()-pmillisTime)>2000){
   pmillisTime=millis();
    if((rtc.getHour(true)<1) && (rtc.getMinute()<1)){
     String dat = "          Witam, dzisiaj mamy:  "+ week[rtc.getDayofWeek()] +"   "+ rtc.getDay() +" "+ month[rtc.getMonth()] +"   "+ rtc.getYear() +" roku                    ";
     lv_label_set_text(objects.lbl_0_date, dat.c_str());
    }
    else{
      showAlert();
    }
  }
 }
void date(){
  String dat = "          Witam, dzisiaj mamy:  "+ week[rtc.getDayofWeek()] +"   "+ rtc.getDay() +" "+ month[rtc.getMonth()] +"   "+ rtc.getYear() +" roku                    ";
     lv_label_set_text(objects.lbl_0_date, dat.c_str());
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    USBSerial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_pass)) {
      USBSerial.println("connected");
      client.subscribe(top1.c_str());
      client.subscribe(top2.c_str());
      client.subscribe(top3.c_str());
      client.subscribe(top4.c_str());
      client.subscribe(top5.c_str());
      client.subscribe(top6.c_str());
      client.subscribe(top7.c_str());
    } else {
      USBSerial.print("failed, rc=");
      USBSerial.print(client.state());
      USBSerial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void callback(char* topic, byte* payload, unsigned int length) {
  USBSerial.print("Message arrived [");
  USBSerial.print(topic);
  USBSerial.print("] ");
  for (int i = 0; i < length; i++) {
    USBSerial.print((char)payload[i]);
  }
  USBSerial.println();
 if (strcmp(topic,top1.c_str())==0){
    payload[length] = '\0';
    float temporaryGrunt=atof((char*)payload);
    if(temporaryGrunt > -270){
      tempGrunt=temporaryGrunt;
    }
    lv_label_set_text_fmt(objects.lbl_0_temp, "%.1f °C", tempGrunt);
    if(tempGrunt<-9){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xff1453ff), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if((tempGrunt>-10)&&(tempGrunt<0.1)){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xff2196f3), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if((tempGrunt>0)&&(tempGrunt<16)){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xff04e1b8), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if((tempGrunt>15)&&(tempGrunt<26)){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if((tempGrunt>25)&&(tempGrunt<34)){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xffffaf2e), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if(tempGrunt>33){
      lv_obj_set_style_bg_color(objects.cont_0_temp, lv_color_hex(0xffff4a2e), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }//      °
  if (strcmp(topic,top2.c_str())==0){//wind
    payload[length] = '\0';
    float W=atof((char*)payload);
    lv_label_set_text_fmt(objects.lbl_0_wind, "%.0f km/h", W);
    if(W<46){
      lv_obj_set_style_bg_color(objects.cont_0_wind, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if((W>45)&&(W<61)){
      lv_obj_set_style_bg_color(objects.cont_0_wind, lv_color_hex(0xffF3AA21), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if(W>60){
      lv_obj_set_style_bg_color(objects.cont_0_wind, lv_color_hex(0xfff32124), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
  }
  if (strcmp(topic,top3.c_str())==0){//kranc wjazd
    alertRestart++;
    payload[length] = '\0';
    if(strcmp((char *)payload, "true") == 0){    
     lv_obj_set_style_bg_color(objects.rly_1_brama1, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_label_set_text(objects.lbl_1_brama1, "ZAMKNIĘTA");
     if(alertRestart>1){
     lv_label_set_text(objects.lbl_0_alert, "! Zamknięto bramę wjazdową !          ");
     }
     setAlert=0;
     pmillisAlert=millis();
    }
    else{
      lv_obj_set_style_bg_color(objects.rly_1_brama1, lv_color_hex(0xfff73906), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_1_brama1, "OTWARTA");
      if(alertRestart>1){
       lv_label_set_text(objects.lbl_0_alert, "! Otwarto bramę wjazdową !          ");
      }
      setAlert=0;
      pmillisAlert=millis();
    }
    showAlert();
  }
  if (strcmp(topic,top4.c_str())==0){//kranc garaz
    if(alertRestart==1){
      lv_label_set_text(objects.lbl_0_alert, "");
    }
    payload[length] = '\0';
    if(strcmp((char *)payload, "true") == 0){  
      lv_obj_set_style_bg_color(objects.rly_1_brama2, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_1_brama2, "ZAMKNIĘTA");
      if(alertRestart>1){
       lv_label_set_text(objects.lbl_0_alert, "! Zamknięto bramę garażową !          ");
      }
      setAlert=0;
      pmillisAlert=millis();
    }
    else{
      lv_obj_set_style_bg_color(objects.rly_1_brama2, lv_color_hex(0xfff73906), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_1_brama2, "OTWARTA");
      if(alertRestart>1){
      lv_label_set_text(objects.lbl_0_alert, "! Otwarto bramę garażową !          ");
      }
      setAlert=0;
      pmillisAlert=millis();
    }
    showAlert();
  }
  if (strcmp(topic,top5.c_str())==0){//lampy podjazd
    payload[length] = '\0';
    if(strcmp((char *)payload, "false") == 0){
      lWjazdState = 0;
      lv_obj_set_style_bg_color(objects.rly_2_lampa1, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_2_lampa1, "WYŁĄCZONE");
    }
    else{
      lWjazdState = 1;
      lv_obj_set_style_bg_color(objects.rly_2_lampa1, lv_color_hex(0xfff73906), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_2_lampa1, "WŁĄCZONE");
    }
  }
  if (strcmp(topic,top6.c_str())==0){//lampy plac
    payload[length] = '\0';
    if(strcmp((char *)payload, "false") == 0){
      lPlacState = 0;
      lv_obj_set_style_bg_color(objects.rly_2_lampa2, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_2_lampa2, "WYŁĄCZONE");
    }
    else{
      lPlacState = 1;
      lv_obj_set_style_bg_color(objects.rly_2_lampa2, lv_color_hex(0xfff73906), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_2_lampa2, "WŁĄCZONE");
    }
  }
  if (strcmp(topic,top7.c_str())==0){//PM2.5
    payload[length] = '\0';
    String ai=String((char*)payload);
    int air = ai.toInt();
    if(air<14) {
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xff12b43b), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "SUPER");
    }
    else if((air>13) && (air<36)){
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xff14ff78), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "OK");
    }
    else if((air>35) && (air<56)){
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xffd2e110), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "TAKA SOBIE");
    }
    else if((air>55) && (air<151)){
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xfff68e02), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "ZŁA");
    }
    else if((air>150) && (air<256)){
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xffe1102f), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "BARDZO ZŁA");
    }
    else if(air>255){
      lv_obj_set_style_bg_color(objects.cont_0_air, lv_color_hex(0xff782222), LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(objects.lbl_0_air, "TRAGICZNA");
    }
  }
}
void action_akcja(lv_event_t * e){
  pmillisEvent = millis();
  //lv_timer_reset(timer1);
  setMain = true;
  lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);
 
    if (obj == objects.btn_0_next)
    {
      lv_scr_load_anim(objects.scr1, LV_SCR_LOAD_ANIM_OUT_LEFT, 1000, 100, false);
    }
    else if (obj == objects.btn_1_back)
    {
      lv_scr_load_anim(objects.main, LV_SCR_LOAD_ANIM_OVER_RIGHT, 1000, 100, false);     
    }
    else if (obj == objects.btn_1_next)
    {
      lv_scr_load_anim(objects.scr2, LV_SCR_LOAD_ANIM_OUT_LEFT, 1000, 100, false);     
    }
    else if (obj == objects.btn_2_back)
    {
      lv_scr_load_anim(objects.scr1, LV_SCR_LOAD_ANIM_OVER_RIGHT, 1000, 100, false);     
    }
    else if (obj == objects.btn_2_next)
    {
      lv_scr_load_anim(objects.scr4, LV_SCR_LOAD_ANIM_OUT_LEFT, 1000, 100, false);     
    }
    else if (obj == objects.btn_3_back)
    {
      lv_scr_load_anim(objects.main, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);    
    }
    else if (obj == objects.btn_4_back)
    {
      lv_scr_load_anim(objects.scr2, LV_SCR_LOAD_ANIM_OVER_RIGHT, 1000, 100, false);    
    }
    else if (obj == objects.btn_0_sleep)
    {
      lv_scr_load_anim(objects.scr5, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);    
    }
    else if (obj == objects.btn_5_sleep)
    {
      esp_deep_sleep_start();   
    }
    else if (obj == objects.btn_6_main)
    {
      lv_scr_load_anim(objects.main, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);  
    }
    else if (obj == objects.btn_7_main)
    {
      lv_scr_load_anim(objects.main, LV_SCR_LOAD_ANIM_OVER_TOP, 1000, 100, false);  
    }
    else if (obj == objects.rly_1_brama1)
    {
       client.publish("supla/xxx/devices/xx/channels/xx/execute_action", "OPEN_CLOSE");
    } 
    else if (obj == objects.rly_1_brama2)
    {
       client.publish("supla/xxx/devices/xxx/channels/xx/execute_action", "OPEN_CLOSE");
    } 
    else if (obj == objects.rly_2_lampa1)
    {
      if(!lWjazdState){
       client.publish("supla/xx/devices/xx/channels/xx/set/on", "true");
       lWjazdState = 1;
      } 
      else if(lWjazdState){
       client.publish("supla/xx/devices/xx/channels/xx/set/on", "false");
       lWjazdState = 0;
      } 
    }
    else if (obj == objects.rly_2_lampa2)
    {
      if(!lPlacState){
       client.publish("supla/xx/devices/xx/channels/xx/set/on","true");
       lPlacState = 1;
      } 
      else if(lPlacState){
       client.publish("supla/xx/devices/xx/channels/xx/set/on","false");
       lPlacState = 0;
      } 
    }
    else if (obj == objects.btn_3_update)
    {
     qrcodeLink();
     lv_label_set_recolor(objects.lbl_3_alert, true);
     lv_label_set_text(objects.lbl_3_alert, "HTTPUpdateServer gotowy! Otwórz w przeglądarce #fa0404 http://esp32.local/update# lub #2196f3 zeskanuj kod QR#, następnie, pod 'firmare', w okienku 'wybierz plik' podaj ścieżkę do pliku .bin, kliknij 'update firmware' i poczekaj na załadowanie nowego oprogramowania...");
     lv_label_set_text(objects.lbl_3_update, "UPDATE ready");
     lv_obj_set_style_bg_color(objects.btn_3_update, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
     
     if (MDNS.begin(host)) {
      Serial.println("mDNS responder started");
     }
    httpUpdater.setup(&httpServer);
    httpServer.begin();
    MDNS.addService("http", "tcp", 80);
    updating=1;
     } 
     else if (obj == objects.btn_3_reset)
     {
       ESP.restart();
       updating=0;
     }
    else if (obj == objects.btn_4_1)
    {
      cfr=1;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_2)
    {
      cfr=2;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_3)
    {
      cfr=3;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_4)
    {
      cfr=4;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_5)
    {
      cfr=5;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_6)
    {
      cfr=6;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_7)
    {
      cfr=7;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_8)
    {
      cfr=8;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_9)
    {
      cfr=9;
      getPin(cfr);
    }
    else if (obj == objects.btn_4_0)
    {
      cfr=0;
      getPin(cfr);
    }
} 
void getPin(int cyfra){
if (pinPozycja == 1) { //Jesli sprawdzamy 1 pozycje PINu
  if (cyfra == pinCyfra1) {
   PINkey++;
  }
 pinPozycja++;
 lv_label_set_text(objects.lbl_4_pin, "* ");
}
else if (pinPozycja == 2) { //Jesli sprawdzamy 2 pozycje PINu
  if (cyfra == pinCyfra2) {
   PINkey++;
  }
 pinPozycja++;
 lv_label_set_text(objects.lbl_4_pin, "* * ");
}
else if (pinPozycja == 3) { //Jesli sprawdzamy 3 pozycje PINu
  if (cyfra == pinCyfra3) {
   PINkey++;
  }
 pinPozycja++;
 lv_label_set_text(objects.lbl_4_pin, "* * * ");
}
else if (pinPozycja == 4) { //Jesli sprawdzamy 4 pozycje PINu
  if (cyfra == pinCyfra4) {
   PINkey++;
  }
  pinPozycja = 1;
  lv_label_set_text(objects.lbl_4_pin, "* * * *");
   if(PINkey==4) {
    lv_scr_load_anim(objects.scr3, LV_SCR_LOAD_ANIM_FADE_ON, 1500, 100, false);
    PINkey=0;
   }  
   else{
    lv_label_set_text(objects.lbl_4_pin, "");
    PINkey=0;
   }
 }      
}
void qrcodeLink(void)
{
  lv_obj_set_pos(objects.btn_3_update, 60, 63);
  lv_obj_t * obj = lv_qrcode_create(objects.scr3, 125, lv_color_hex(0xff3f3a3a), lv_color_hex(0xffcdc8c8));
  objects.qr1 = obj;
  lv_obj_set_pos(obj, 290, 60);
  const char * data = "http://esp32.local/update";
  lv_qrcode_update(obj, data, strlen(data));
  lv_obj_set_style_border_color(obj, lv_color_hex(0xffcdc8c8), 0);
  lv_obj_set_style_border_width(obj, 5, 0);
}
