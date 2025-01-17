#include <Arduino.h>
#include <Adafruit_ILI9341.h>

#ifndef SCREENPOINT_H
#define SCREENPOINT_H
class ScreenPoint {
    
 public:
  int16_t x;
  int16_t y;
  // default constructor
  ScreenPoint();
  ScreenPoint(int16_t xIn, int16_t yIn);
  ScreenPoint getScreenCoords(int16_t x, int16_t y, Adafruit_ILI9341 tft);
};
#endif