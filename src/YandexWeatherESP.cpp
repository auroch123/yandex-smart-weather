
#include <Arduino.h>

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

Button exampleButton = Button();



void MainMenu(){
  tft.fillScreen(ILI9341_BLACK);
  exampleButton.initButton(&tft,0x0023,0x0023,0x0046,0x0046,0, ILI9341_RED, ILI9341_WHITE, "", 1);
  exampleButton.drawButton();
};

void setup() {
  Serial.begin(9600);

  
  tft.begin();
  tft.setFont(&FreeSerifBold10pt8b);
  tft.setRotation(0x001);
  delay(100);
  
  ts.begin();
  ts.setRotation(1);
   
  
  MainMenu();
  //Menu1();
  //while (!Serial && (millis() <= 1000));
}


TS_Point p;
ScreenPoint sp = ScreenPoint();
boolean waspressed = false;
void loop(){
  
  
  
  
  p = ts.getPoint();
  sp = sp.getScreenCoords(p.x,p.y, tft);
  if (ts.touched()) {
        // Если экран нажат
        if (exampleButton.contains(sp.x, sp.y)) {
            if (!waspressed) { // Если кнопка не была нажата ранее
                exampleButton.press(true);
                exampleButton.drawButton(true); // Отображаем нажатую кнопку
                waspressed = true; // Устанавливаем флаг
            }
        } else {
            if (waspressed) { // Если кнопка была нажата, но теперь не на ней
                exampleButton.press(false);
                exampleButton.drawButton(false); // Отображаем неактивную кнопку
                waspressed = false; // Сбрасываем флаг
                tft.print("Ok");
            }
        }
    } else if (waspressed){
        // Если экран не нажат (стилус отпущен)
        if (waspressed) { // Если кнопка была нажата
            exampleButton.press(false);
            waspressed = false; // Сбрасываем флаг
        }
        // Обработка отпускания кнопки
        if (exampleButton.justReleased()) {
           exampleButton.drawButton(false);
        }
    }

    
  
  delay(100);
}


