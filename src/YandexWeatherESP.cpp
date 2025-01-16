



#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <FontsRus/FreeSerifBold10.h>
#include <XPT2046_Touchscreen.h>
#include <ScreenPoint.h>
#include <Button.h>

// MOSI=11, MISO=12, SCK=13
#define TFT_CS  15
#define TFT_DC  2
#define T_IRQ 5
#define T_CS 4

// Modify the following two lines to match your hardware
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, -1);
XPT2046_Touchscreen ts(T_CS, T_IRQ);


//Button tempButton1;
Button playButton2;
Button settingsButton3;
Button relayButton4;
Button relayButton5;
Button relayButton6;


void setup() {
  Serial.begin(230400);
  
  //GPIO 3 (RX) swap the pin to a GPIO.
  //pinMode(3, FUNCTION_3);
  tft.begin();
  tft.setFont(&FreeSerifBold10pt8b);
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  ts.begin();
  //ts.setRotation(1);
  //MainMenu1();
  //Menu1();
  //while (!Serial && (millis() <= 1000));
}
ScreenPoint sp = ScreenPoint();
boolean wastouched = false;
TS_Point p;

void loop(){ 
  
  
  
  

  
  
  delay(0);}


