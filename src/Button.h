#include <Arduino.h>

#include <Adafruit_GFX.h>
#ifndef BUTTON_H
#define BUTTON_H
class Button : public Adafruit_GFX_Button {
public:
    Button() : Adafruit_GFX_Button() { 
    }
    // void initButton(Adafruit_GFX *gfx, int16_t x, int16_t y,
    //                                  uint16_t w, uint16_t h, uint16_t outline,
    //                                  uint16_t fill, uint16_t textcolor,
    //                                  char *label, uint8_t textsize);
    
};
#endif