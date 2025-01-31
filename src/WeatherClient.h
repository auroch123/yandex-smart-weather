// WeatherClient.h
#ifndef WEATHERCLIENT_H
#define WEATHERCLIENT_H

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

class WeatherClient {
public:
    WeatherClient(const char* ssid, const char* password, const long utcOffsetInSeconds, const char* graphqlEndpoint);
    void begin();
    bool update();
    String getFormattedTime();
    int getHours();
    int getMinutes();
    int getSeconds();
    int getDay();
    String convertEpoch(int epochTime);
    struct WeatherNow{
        //Tommorow sunrise and sunset as today
        const char* sunriseBeginTimestampNow; 
        const char* sunsetEndTimestampNow;
        //Weather right now
        int         temperatureNow; // -6
        int         feelsLikeNow; // -12
        float       windSpeedNow; // 4
        const char* windDirectionNow;
        float       windGustNow; // 11
        const char* conditionNow; // "OVERCAST"
        const char* iconNow; //voc
    };
    struct WeatherForecastHours{
        int         temperatureHour; // -6
        int         feelsLikeHour; // -12
        float       windSpeedHour; // 4
        const char* windDirectionHour;
        float       windGustHour; // 11
        const char* conditionHour; // "OVERCAST"
        const char* iconHour; //voc
    };
    struct WeatherForecastDays{
        int         temperatureDay;
        int         feelsLikeDay;
        float       windSpeedDay;
        const char* windDirectionDay;
        float       windGustDay;
        const char* conditionDay;
        const char* iconDay;
    };
    
    WeatherNow weatherRightNow;
    WeatherForecastHours weatherHours[26];
    WeatherForecastDays weatherDays[3];
    

private:
    const char* ssid;
    const char* password;
    const long utcOffsetInSeconds;
    const char* graphqlEndpoint;
    
    WiFiUDP udp;
    WiFiClient wifiClient;
    NTPClient timeClient;
    HTTPClient http;
    
    const int startHour = 8;  // Начало работы (8:00)
    const int endHour = 18;    // Конец работы (18:00)
    
    unsigned long lastRequestTime = 0; // Время последнего запроса
    const unsigned long requestInterval = 3 * 60 * 60 * 1000; // Интервал запросов (3 часа в миллисекундах)

    void connectToWiFi();
    void fetchWeatherData();
};

#endif // WEATHERCLIENT_H