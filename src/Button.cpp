#include <Button.h>
    

    
    // Здесь можно добавить дополнительные методы, если необходимо






// class Button {
 
// u_int8_t x;
// u_int8_t y;
// u_int8_t width;
// u_int8_t height;
// u_int8_t color = 565;
// char *text;
 
// Button(){ 
// }
 
// void initButton(u_int16_t xPos, u_int16_t yPos, u_int16_t butWidth, u_int16_t butHeight, char *butText, u_int16_t bColor, Adafruit_ILI9341 tft){
// x = xPos;
// y = yPos;
// width = butWidth;
// height = butHeight;
// text = butText;
// color = bColor;

// render(tft);
// }
 
// void render(Adafruit_ILI9341 tft){
// tft.setCursor(x+0X000A,y+0X000A);
// tft.fillRect(x,y,width,height, color); // draw rectangle
// tft.setTextSize(0x001);
// tft.setTextColor(0xFFFF);
// tft.println(text);
// }
 
// bool isClicked(ScreenPoint sp){
// if ((sp.x >= x) & (sp.x <= (x+width)) & (sp.y >= y) & (sp.y <= (y+height))){
// return true;
// }
// else {
// return false;
// }
// }
// };