#include <ScreenPoint.h>



  // calibration values
  float xCalM = -0.09, yCalM = -0.07; // gradients
  float xCalC = 349.97, yCalC = 257.24; // y axis crossing points
  int16_t x;
  int16_t y;
   
  // default constructor
  ScreenPoint::ScreenPoint(){
  }
 
  ScreenPoint::ScreenPoint(int16_t xIn, int16_t yIn){
      x = xIn;
      y = yIn;
  }

  ScreenPoint ScreenPoint::getScreenCoords(int16_t x, int16_t y, Adafruit_ILI9341 tft){
    int16_t xCoord = round((x * xCalM) + xCalC);
    int16_t yCoord = round((y * yCalM) + yCalC);
    //tft.print("xm = "); tft.print(xCalM); tft.print("xc = "); tft.print(xCalC);
    if(xCoord < 0) xCoord = 0;
    if(xCoord > tft.width()) xCoord = tft.width() - 1;
    if(yCoord < 0) yCoord = 0;
    if(yCoord > tft.height()) yCoord = tft.height() - 1;
    
    return(ScreenPoint(xCoord, yCoord));
}

