#include <Arduino.h>
#include <Adafruit_ILI9341.h>
#include <ScreenPoint.h>
class Button {

 public:  
  u_int8_t x;
  u_int8_t y;
  u_int8_t width;
  u_int8_t height;
  u_int8_t color = 565;
  char *text;
 
  Button(){}
  void initButton(u_int16_t xPos, u_int16_t yPos, u_int16_t butWidth, u_int16_t butHeight, char *butText, u_int16_t bColor, Adafruit_ILI9341 tft);
  void render(Adafruit_ILI9341 tft);
  bool isClicked(ScreenPoint sp);
  
};