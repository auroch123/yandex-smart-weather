#include <Arduino.h>
#include <Adafruit_ILI9341.h>

class ScreenPoint {

 private:
  // calibration values
  float xCalM, yCalM; // gradients
  float xCalC, yCalC; // y axis crossing points
    
 public:
  int16_t x;
  int16_t y;
  // default constructor
  ScreenPoint();
  ScreenPoint(int16_t xIn, int16_t yIn);
  void getScreenCoords(int16_t x, int16_t y, Adafruit_ILI9341 tft);
};

