
#include <Arduino.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <ScreenPoint.h>
#include <Button.h>
#include <WeatherClient.h>
#include <MenuSystem.h>
// MOSI=11, MISO=12, SCK=13
#define TFT_CS  15
#define TFT_DC  2
#define T_IRQ 5
#define T_CS 4

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, -1);
XPT2046_Touchscreen ts(T_CS, T_IRQ);
Button exampleButton = Button();

// Настройки WiFi и NTP
const char* ssid = "SSID";
const char* password = "PASSWORD";
const unsigned long utcOffsetInSeconds = 3 * 3600; // Смещение по времени (UTC+3)
const char* graphqlEndpoint = "http://api.weather.yandex.ru/graphql/query"; //Обязательно использовать HTTP вместо HTTPS. Если же захочется использовать HTTPS необходимо добавить SSL сертификаты и их проверку
char daysOfTheWeek[7][12] = {"ВС", "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ"};



WeatherClient weatherClient(ssid, password, utcOffsetInSeconds, graphqlEndpoint);
MenuSystem menuSystem(&tft, utcOffsetInSeconds);

void setup() {
    Serial.begin(9600);
    tft.begin();
    tft.setFont(&RobotoBold6);
    tft.setTextColor(ILI9341_BLACK);
    tft.setRotation(0x001);
    delay(100);
    tft.setCursor(124,120);
    tft.print(PSTR("Загрузка..."));
    ts.begin();
    ts.setRotation(1);
     
    weatherClient.begin(); // Инициализация WeatherClient
    menuSystem.MainMenu();

}

TS_Point p;
ScreenPoint sp = ScreenPoint();
boolean waspressed = false;
int i = 0;

int oldMinute = 0;

void loop() {

  tft.fillRect(0,0,60,15,ILI9341_WHITE);
  tft.setCursor(5,13);
  tft.printf("%s, %s",weatherClient.getFormattedTime(), daysOfTheWeek[weatherClient.getDay()]);

  delay(1000);

// Обновление состояния WeatherClient и рисование структур из WeatherCkient.h c помощью MenuSystem.
    if(weatherClient.update()){
        menuSystem.weatherNow(weatherClient);
        menuSystem.weatherForecast(weatherClient);
        menuSystem.weatherNowHours(weatherClient, weatherClient.getHours());
    }; 
    
   

    // // Обработка нажатий на экран
    // p = ts.getPoint();
    // sp = sp.getScreenCoords(p.x, p.y, tft);
    // if (ts.touched()) {
    //     // Если экран нажат
    //     if (exampleButton.contains(sp.x, sp.y)) {
    //         if (!waspressed) { // Если кнопка не была нажата ранее
    //             exampleButton.press(true);
    //             exampleButton.drawButton(true); // Отображаем нажатую кнопку
    //             waspressed = true; // Устанавливаем флаг
    //         }
    //     } else {
    //         if (waspressed) { // Если кнопка была нажата, но теперь не на ней
    //             exampleButton.press(false);   
    //             exampleButton.drawButton(false); // Отображаем неактивную кнопку
    //             waspressed = false; // Сбрасываем флаг  
    //         }
    //     }
    // } else if (waspressed) {
    //     // Если экран не нажат (стилус отпущен)
    //     if (waspressed) { // Если кнопка была нажата
    //         exampleButton.press(false);
    //         waspressed = false; // Сбрасываем флаг
    //     }
    //     // Обработка отпускания кнопки
    //     if (exampleButton.justReleased()) {
    //         exampleButton.drawButton(false);
    //     }
    // }

}




