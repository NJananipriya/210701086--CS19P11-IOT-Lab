//#include <LCD03.h>

//#include <Adafruit_LiquidCrystal.h>

//#include <LiquidCrystal.h>

#include<SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
//..
#include "MAX30100_PulseOximeter.h"
#define REPORTING_PERIOD_MS 1000
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 columns, 2 rows
PulseOximeter pox;

unsigned long lastReportTime = 0;
//.

SoftwareSerial hc05(2,3);

const int flexPin0= A0;
const int flexPin1= A1;
const int flexPin2= A2;

const int threshold = 700;

void setup() {
  //...PR
  Serial.begin(9600);
  lcd.begin();                        // Initialize the LCD
  lcd.backlight();                 // Turn on the backlight
  lcd.setCursor(0,0);
  lcd.print("Pulse Oximeter");
  lcd.setCursor(0,1);
  lcd.print("Initializing...");
  delay(2000);
  
  // Initialize the pulse oximeter
  if (!pox.begin()) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Error: Sensor");
    lcd.setCursor(0,1);
    lcd.print("not found");
    while(1);
  }

  pox.setOnBeatDetectedCallback(onBeatDetected);
  Serial.println("Pulse Oximeter Ready");
  //...PR
  // put your setup code here, to run once:
hc05.begin(9600);
 Serial.begin(9600);
 delay(1);

}

void loop() {
  //...PR
  pox.update();

  if (millis() - lastReportTime > REPORTING_PERIOD_MS) {
    lastReportTime = millis();
    float hr = pox.getHeartRate();
    float spo2 = pox.getSpO2();
    if (hr > 0 && spo2 > 0) {
      displayData(hr, spo2);
    }
}
  //..PR
  // put your main code here, to run repeatedly:
  int flexValue0 = analogRead(flexPin0);
  int flexValue1 = analogRead(flexPin1);
  int flexValue2 = analogRead(flexPin2);

  int c=0;
  Serial.println(flexValue0);

  //check if the flex sensor reading exceeds the threshold 
  if(flexValue0 > 950){
    hc05.print("I need Food now");
    Serial.println(flexValue0); // send msg to phone
  }
  Serial.println(flexValue0);
  if(flexValue0 < 400 && flexValue1 < 400 && flexValue2< 400 ){
    Serial.println("It is an emergency");
    hc05.println("It is an emergency");
  }
  else if(flexValue1 < 400 && flexValue2 < 400){
    Serial.println("Want to use restroom");
    hc05.println("Want to use restroom");
  }
  else if(flexValue0 < 400 && flexValue2 < 400){
    Serial.println("Not feeling well");
    hc05.println("Not feeling well");
  }
  else if(flexValue0 < 400 && flexValue1 < 400){
    Serial.println("I'm happy");
    hc05.println("I'm happy");
  }
  else if(flexValue0 < 400 ){
    Serial.println("I want food");
    hc05.flush();
    hc05.println("I want food");
  }
  else if(flexValue1 < 400 ){
    Serial.println("I want to play");
    hc05.flush();
    hc05.println("I want to play");
  }
  else if(flexValue2 < 400 ){
    Serial.println("I need help");
    hc05.flush();
    hc05.println("I need help");
  }

  delay(1000); //Delay for stability

}

void onBeatDetected() {
  Serial.println("Beat!");
}

void displayData(float hr, float spo2) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HR: ");
  lcd.print(hr);
  lcd.print(" bpm");

  lcd.setCursor(0,1);
  lcd.print("SpO2: ");
  lcd.print(spo2);
  lcd.print("%");
}