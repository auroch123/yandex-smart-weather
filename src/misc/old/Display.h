// #include <Arduino.h>
// #include <SPI.h>

// #include <Adafruit_ILI9341.h>
// #include <Adafruit_GFX.h>
// #include <XPT2046.h>

// #define TFT_DC 2
// #define TFT_CS 15

// /******************* UI details */
// #define BUTTON_X 40
// #define BUTTON_Y 100
// #define BUTTON_W 60
// #define BUTTON_H 30
// #define BUTTON_SPACING_X 20
// #define BUTTON_SPACING_Y 20
// #define BUTTON_TEXTSIZE 2

//  //text box where numbers go
// #define TEXT_X 10
// #define TEXT_Y 10
// #define TEXT_W 220
// #define TEXT_H 50
// #define TEXT_TSIZE 3
// #define TEXT_TCOLOR ILI9341_MAGENTA

// XPT2046 Touch(/*cs=*/ 16, /*irq=*/ 3);

// class Display{
  
  

// /// the data (phone #) we store in the textfield
// #define TEXT_LEN 12
// char textfield[TEXT_LEN+1] = "";
// uint8_t textfield_i=0;

// Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);


// //* create 15 buttons, in classic candybar phone style */
// char buttonlabels[15][5] = {"Send", "Clr", "End", "1", "2", "3", "4", "5", "6", "7", "8", "9", "*", "0", "#" };
// uint16_t buttoncolors[15] = {ILI9341_DARKGREEN, ILI9341_DARKGREY, ILI9341_RED, 
//                            ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, 
//                            ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, 
//                            ILI9341_BLUE, ILI9341_BLUE, ILI9341_BLUE, 
//                            ILI9341_ORANGE, ILI9341_BLUE, ILI9341_ORANGE};
// Adafruit_GFX_Button buttons[15];
// public:
//    void setupDisplay() {
//     // put your setup code here, to run once:
//     delay(1000);
      
    
    
    
//     tft.begin();
//     Touch.begin(tft.width(), tft.height());  // Must be done before setting rotation
//     //Serial.print("tftx ="); Serial.print(tft.width()); Serial.print(" tfty ="); Serial.println(tft.height());
//     tft.fillScreen(ILI9341_BLACK);
     
//     // Replace these for your screen module
//     Touch.setCalibration(1832, 262, 264, 1782);
    
//     // create buttons
//     for (uint8_t row=0; row<5; row++) {
//       for (uint8_t col=0; col<3; col++) {
//         buttons[col + row*3].initButton(&tft, BUTTON_X + col * (BUTTON_W+BUTTON_SPACING_X), 
//                                               BUTTON_Y + row * (BUTTON_H+BUTTON_SPACING_Y),    // x, y, w, h, outline, fill, text
//                                               BUTTON_W, BUTTON_H, ILI9341_WHITE, buttoncolors[col+row*3], ILI9341_WHITE,
//                                               buttonlabels[col + row*3], BUTTON_TEXTSIZE); 
//                                               buttons[col + row*3].drawButton();
//       }
//     }
   
//     // create 'text field'
//     tft.drawRect(TEXT_X, TEXT_Y, TEXT_W, TEXT_H, ILI9341_WHITE);
    
//   }
    
//   void loopDisplay() {
//     // put your main code here, to run repeatedly:
//     uint16_t x, y;
//     if (Touch.isTouching()){ 
//       Touch.getPosition(x, y);}
    
//     // go thru all the buttons, checking if they were pressed
//     for (uint8_t b=0; b<15; b++) {
//       if (buttons[b].contains(x, y)) {
//         //Serial.print("Pressing: "); Serial.println(b);
//         buttons[b].press(true);  // tell the button it is pressed
//       } else {
//         buttons[b].press(false);  // tell the button it is NOT pressed
//       }
//     }
   
//       //// now we can ask the buttons if their state has changed
//     for (uint8_t b=0; b<15; b++) {
//       if (buttons[b].justReleased()) {
//         // Serial.print("Released: "); Serial.println(b);
//         buttons[b].drawButton();  // draw normal
//       }
        
//       if (buttons[b].justPressed()) {
//           buttons[b].drawButton(true);  // draw invert!
            
//           // if a numberpad button, append the relevant # to the textfield
//           if (b >= 3) 
//           {
//             if (textfield_i < TEXT_LEN) 
//             {
//               textfield[textfield_i] = buttonlabels[b][0];
//               textfield_i++;
//               textfield[textfield_i] = 0; // zero terminate
                
//               //fona.playDTMF(buttonlabels[b][0]);
//             }
//           }
    
//           // clr button! delete char
//           if (b == 1)
//           {
              
//             textfield[textfield_i] = 0;
//             if (textfield > 0) 
//             {
//               textfield_i--;
//               textfield[textfield_i] = ' ';
//             }
//           }
   
//           // update the current text field
//           Serial.println(textfield);
//           tft.setCursor(TEXT_X + 2, TEXT_Y+10);
//           tft.setTextColor(TEXT_TCOLOR, ILI9341_BLACK);
//           tft.setTextSize(TEXT_TSIZE);
//           tft.print(textfield);

//           // its always OK to just hang up
//           //if (b == 2) {
//             //status(F("Hanging up"));
//             //fona.hangUp();
//          // }
//           // we dont really check that the text field makes sense
//           // just try to call
//           //if (b == 0) {
//             //status(F("Calling"));
//             //Serial.print("Calling "); Serial.print(textfield);
              
//             //fona.callPhone(textfield);
//           //}
            
//         delay(100); // UI debouncing
//       }
//     }
//   }
// };

#include <Arduino.h>
#include <SPI.h>

// #include <Ucglib.h>
// #include <XPT2046.h>

// // Modify the following two lines to match your hardware
// Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/ 2 , /*cs=*/ 15, /*reset=*/ 4);
// XPT2046 touch(/*cs=*/ 16, /*irq=*/ 5);

// static void calibratePoint(uint16_t x, uint16_t y, uint16_t &vi, uint16_t &vj) {
//   // Draw cross
//   ucg.setColor(0xff, 0xff, 0xff);
//   ucg.drawHLine(x - 8, y, 16);
//   ucg.drawVLine(x, y - 8, 16);
//   while (!touch.isTouching()) {
//     delay(10);
//   }
//   touch.getRaw(vi, vj);
//   // Erase by overwriting with black
//   ucg.setColor(0, 0, 0);
//   ucg.drawHLine(x - 8, y, 16);
//   ucg.drawVLine(x, y - 8, 16);
// }

// void calibrate() {
//   uint16_t x1, y1, x2, y2;
//   uint16_t vi1, vj1, vi2, vj2;
//   touch.getCalibrationPoints(x1, y1, x2, y2);
//   calibratePoint(x1, y1, vi1, vj1);
//   delay(1000);
//   calibratePoint(x2, y2, vi2, vj2);
//   touch.setCalibration(vi1, vj1, vi2, vj2);

//   char buf[80];
//   snprintf(buf, sizeof(buf), "%d,%d,%d,%d", (int)vi1, (int)vj1, (int)vi2, (int)vj2);
//   ucg.setFont(ucg_font_helvR14_tr);
//   ucg.setColor(0xff, 0xff, 0xff);
//   ucg.setPrintPos(0, 25);
//   ucg.print("setCalibration params:");
//   ucg.setPrintPos(0, 50);
//   ucg.print(buf);
// }

// void displaySetup() {
//   delay(1000);
//   ucg.begin(UCG_FONT_MODE_TRANSPARENT);
//   //ucg.begin(UCG_FONT_MODE_SOLID);
//   touch.begin(ucg.getWidth(), ucg.getHeight());
//   ucg.clearScreen();

//   calibrate();  // No rotation!!
// }

