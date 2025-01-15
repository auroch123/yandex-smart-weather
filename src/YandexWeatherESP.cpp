



#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <OneWire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
// #include <UTouch.h>
#include <XPT2046_Touchscreen.h>
#include <DallasTemperature.h>



// MOSI=11, MISO=12, SCK=13
#define TFT_CS  15
#define TFT_DC  2
#define T_IRQ 3
#define T_CS 4
// // Data wire is plugged into pin 2 on the Arduino
 #define ONE_WIRE_BUS 0

// // Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
 OneWire oneWire(ONE_WIRE_BUS);

// // Pass our oneWire reference to Dallas Temperature. 
 DallasTemperature sensors(&oneWire);


// calibration values
float xCalM = -0.09, yCalM = -0.07; // gradients
float xCalC = 349.97, yCalC = 257.24; // y axis crossing points
// Sensor Green Black Grey
DeviceAddress sensor0 {0x28, 0x0, 0xCA, 0x1C, 0x7, 0x0, 0x0, 0xD1};
boolean relay1Pressed = false;
boolean relay2Pressed = false;
boolean relay3Pressed = false;
boolean relay1WasPressed = false;
boolean relay2WasPressed = false;
boolean relay3WasPressed = false;

// Modify the following two lines to match your hardware
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
XPT2046_Touchscreen ts(T_CS, T_IRQ);
// UTouch myTouch(T_CLK, T_CS, T_DIN, T_DO, T_IRQ);
// Modify the following two lines to match your hardware
uint16_t color = 565;
uint32_t pixels = 200;
class ScreenPoint {
public:
int16_t x;
int16_t y;
 
// default constructor
ScreenPoint(){
}
 
ScreenPoint(int16_t xIn, int16_t yIn){
x = xIn;
y = yIn;
}
};
 
ScreenPoint getScreenCoords(int16_t x, int16_t y){
int16_t xCoord = round((x * xCalM) + xCalC);
int16_t yCoord = round((y * yCalM) + yCalC);
if(xCoord < 0) xCoord = 0;
if(xCoord > tft.width()) xCoord = tft.width() - 1;
if(yCoord < 0) yCoord = 0;
if(yCoord > tft.height()) yCoord = tft.height() - 1;
return(ScreenPoint(xCoord, yCoord));
}
 
//void calibrateTouchScreen(){
//TS_Point p;
//int16_t x1,y1,x2,y2;
 
//tft.fillScreen(ILI9341_BLACK);
// wait for no touch
//while(ts.touched());
//tft.drawFastHLine(10,20,20,ILI9341_RED);
//tft.drawFastVLine(20,10,20,ILI9341_RED);
//while(!ts.touched());
//delay(50);
//p = ts.getPoint();
//x1 = p.x;
//y1 = p.y;
//tft.drawFastHLine(10,20,20,ILI9341_BLACK);
//tft.drawFastVLine(20,10,20,ILI9341_BLACK);
//delay(500);
//while(ts.touched());
//tft.drawFastHLine(tft.width() - 30,tft.height() - 20,20,ILI9341_RED);
//tft.drawFastVLine(tft.width() - 20,tft.height() - 30,20,ILI9341_RED);
//while(!ts.touched());
//delay(50);
//p = ts.getPoint();
//x2 = p.x;
//y2 = p.y;
//tft.drawFastHLine(tft.width() - 30,tft.height() - 20,20,ILI9341_BLACK);
//tft.drawFastVLine(tft.width() - 20,tft.height() - 30,20,ILI9341_BLACK);
 
//int16_t xDist = tft.width() - 40;
//int16_t yDist = tft.height() - 40;
 
// translate in form pos = m x val + c
// x
//xCalM = -0.09;   //(float)xDist / (float)(x2 - x1); 
//xCalC = 349.97; //20.0 - ((float)x1 * xCalM);      
// y
//yCalM = -0.07;  //(float)yDist / (float)(y2 - y1); 
//yCalC = 257.24; //20.0 - ((float)y1 * yCalM);     
 

 
//}

class Button {
public:
 
u_int8_t x;
u_int8_t y;
u_int8_t width;
u_int8_t height;
char *text;
 
Button(){ 
}
 
void initButton(u_int16_t xPos, u_int16_t yPos, u_int16_t butWidth, u_int16_t butHeight, char *butText, u_int16_t bColor){
x = xPos;
y = yPos;
width = butWidth;
height = butHeight;
text = butText;
color = bColor;

render();
}
 
void render(){
tft.fillRect(x,y,width,height, color); // draw rectangle
tft.setCursor(x+10,y+10);
tft.setTextSize(2);
tft.setTextColor(0xFFFF,0x0000);
tft.print(text);
}
 
bool isClicked(ScreenPoint sp){
if ((sp.x >= x) & (sp.x <= (x+width)) & (sp.y >= y) & (sp.y <= (y+height))){
return true;
}
else {
return false;
}
}
};
//Button tempButton1;
Button playButton2;
Button settingsButton3;
Button relayButton4;
Button relayButton5;
Button relayButton6;
float temperatureC;
void MainMenu1(){
  //tempButton1.initButton(0,0,75,75,"", ILI9341_BLUE);
  
  playButton2.initButton(0,80,75,75, "play", ILI9341_DARKGREEN);
  settingsButton3.initButton(0,160,75,75,"setngs", ILI9341_DARKGREEN);
  if(relay1Pressed & relay1WasPressed){
    relayButton4.initButton(80,160,75,75,"rel1", ILI9341_GREEN);}
  else{
    relayButton4.initButton(80,160,75,75,"rel1", ILI9341_RED);}
  if(relay2Pressed & relay2WasPressed){
    relayButton5.initButton(165,160,75,75,"rel2", ILI9341_GREEN);}
  else{
    relayButton5.initButton(165,160,75,75,"rel2", ILI9341_RED);}
  if(relay3Pressed & relay3WasPressed){
    relayButton6.initButton(250,160,75,75,"rel3", ILI9341_GREEN);}
  else{
    relayButton6.initButton(250,160,75,75,"rel3", ILI9341_RED);}
  

}
void Menu1(){
  
  settingsButton3.initButton(0,160,75,75,"setngs", ILI9341_DARKGREEN);
  if(relay1Pressed & relay1WasPressed){
    relayButton4.initButton(80,160,75,75,"rel1", ILI9341_GREEN);}
  else{
    relayButton4.initButton(80,160,75,75,"rel1", ILI9341_RED);}
  if(relay2Pressed & relay2WasPressed){
    relayButton5.initButton(165,160,75,75,"rel2", ILI9341_GREEN);}
  else{
    relayButton5.initButton(165,160,75,75,"rel2", ILI9341_RED);}
  if(relay3Pressed & relay3WasPressed){
    relayButton6.initButton(250,160,75,75,"rel3", ILI9341_GREEN);}
  else{
    relayButton6.initButton(250,160,75,75,"rel3", ILI9341_RED);}
}

void setup() {
  Serial.begin(115200);
  sensors.begin();
  //GPIO 3 (RX) swap the pin to a GPIO.
  pinMode(3, FUNCTION_3);
  tft.begin(40000000U);
  tft.setRotation(1);
  tft.fillScreen(ILI9341_DARKGREY);
  ts.begin();
  ts.setRotation(1);
  MainMenu1();
  //while (!Serial && (millis() <= 1000));
}
ScreenPoint sp = ScreenPoint();
boolean wastouched = true;

void loop(){ 
  
  
  
  sensors.requestTemperatures();
  Menu1();
  
  
  boolean istouched = ts.touched();
  TS_Point p;
  
  if (istouched) {
    
    TS_Point p = ts.getPoint();
    sp = getScreenCoords(p.x, p.y);

    if(playButton2.isClicked(sp)){

    }
    if(settingsButton3.isClicked(sp)){
      
    }
    if(relayButton4.isClicked(sp)){
      
      if(relay1WasPressed){
        relay1WasPressed = false;
        relay1Pressed = false;
      }
      else{
        relay1WasPressed = true;
        relay1Pressed = true;
      }
    }
    if(relayButton5.isClicked(sp)){
      if(relay2WasPressed){
        relay2WasPressed = false;
        relay2Pressed = false;
      }
      else{
        relay2WasPressed = true;
        relay2Pressed = true;
      }
    }
    if(relayButton6.isClicked(sp)){
      if(relay3WasPressed){
        relay3WasPressed = false;
        relay3Pressed = false;
      }
      else{
        relay3WasPressed = true;
        relay3Pressed = true;
      }
    }
    
    if (!wastouched) {
      
    }
    
    
  } else {
    if (wastouched) {
      
      
      
    }
    
  }
  wastouched = istouched;
  delay(0);}


