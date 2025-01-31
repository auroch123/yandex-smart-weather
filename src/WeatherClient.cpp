#include <WeatherClient.h>


WeatherClient::WeatherClient(const char* ssid, const char* password, const long utcOffsetInSeconds, const char* graphqlEndpoint)
    : ssid(ssid), password(password), utcOffsetInSeconds(utcOffsetInSeconds), graphqlEndpoint(graphqlEndpoint), timeClient(udp, "pool.ntp.org", utcOffsetInSeconds) {};

void WeatherClient::begin() {
    connectToWiFi();
    timeClient.begin();
    timeClient.setTimeOffset(utcOffsetInSeconds);
    timeClient.update();
    
}

void WeatherClient::connectToWiFi() {
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");
}

bool WeatherClient::update() {
    timeClient.update();
    unsigned long currentMillis = timeClient.getEpochTime();


        if (currentMillis - lastRequestTime >= requestInterval) {

            lastRequestTime = currentMillis;
            fetchWeatherData();
            return true;

        }else{
          return false;
        }    
}

String WeatherClient::getFormattedTime(){
    return timeClient.getFormattedTime();
}

 String WeatherClient::convertEpoch(int epochTime){
    unsigned long rawTime = timeClient.getEpochTime();
    unsigned long hours = (rawTime % 86400L) / 3600;
     String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

    unsigned long minutes = (rawTime % 3600) / 60;
    String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);
    return "0";

 };

int WeatherClient::getDay(){
    return timeClient.getDay();
}

int WeatherClient::getHours(){
    return timeClient.getHours();
}

int WeatherClient::getMinutes(){
    return timeClient.getMinutes();
}
int WeatherClient::getSeconds(){
    return timeClient.getSeconds();
}

void WeatherClient::fetchWeatherData() {
    if (WiFi.status() == WL_CONNECTED) {
        
        http.begin(wifiClient, graphqlEndpoint);
        
        http.addHeader(PSTR("X-Yandex-Weather-Key"), PSTR("Ваш ключ API"));
        http.addHeader(PSTR("Content-Type"), PSTR("application/json"));
      
        // https://yandex.ru/dev/weather/doc/ru/concepts/auth
        // String jsonRequest = PSTR(R"({
        // "query": "{\n  weatherByPoint(request: { lat: 52.37125, lon: 4.89388 })  {    now {      temperature    }  }}" })");
        
        
        String jsonRequest = PSTR(R"({
        "query": "{  weatherByPoint(request: { lat: 49.376475, lon: 44.015482 }){
           now {
      temperature(unit:CELSIUS)
      feelsLike(unit:CELSIUS)
      windSpeed(unit: METERS_PER_SECOND)
      windDirection
      windGust(unit:METERS_PER_SECOND)
      condition
      icon(format: CODE)

     }
     forecast{
      days(offset:0 limit:2){
        sunriseBeginTimestamp
        sunsetEndTimestamp
        summary{
          day{
            temperature(unit:CELSIUS)
            feelsLike(unit:CELSIUS)
            windSpeed(unit: METERS_PER_SECOND)
            windDirection
            windGust(unit:METERS_PER_SECOND)
            condition
            icon(format:CODE)  
            
          }
        }
      }
      hours(first: 24) {
        edges {
          node {
            temperature(unit: CELSIUS)
            feelsLike(unit: CELSIUS)
            windSpeed(unit: METERS_PER_SECOND)
            windDirection
            windGust(unit:METERS_PER_SECOND)
            condition
            icon(format: CODE)

            
          }
        }
      }
    }
  }}" })");

        int httpResponseCode = http.POST(jsonRequest);
        
        if (httpResponseCode > 0) { 

            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
            JsonDocument doc;
            DeserializationError error = deserializeJson(doc, response);
           
            if (error) {
              Serial.print(F("deserializeJson() failed: "));
              Serial.println(error.f_str());
              return;
            }
            
            // Получение значений
            JsonArray daysArray = doc["data"]["weatherByPoint"]["forecast"]["days"].as<JsonArray>();
            JsonObject sunCycleToday = daysArray[1].as<JsonObject>(); // Получаем первый объект из массива
            weatherRightNow.sunriseBeginTimestampNow = sunCycleToday["sunriseBeginTimestamp"];
             weatherRightNow.sunsetEndTimestampNow = sunCycleToday["sunsetEndTimestamp"];


            //Weather right now
            JsonObject  weatherNow       = doc["data"]["weatherByPoint"]["now"];
            weatherRightNow.temperatureNow   = weatherNow["temperature"]; // -6
            weatherRightNow.feelsLikeNow     = weatherNow["feelsLike"]; // -12
            weatherRightNow.windSpeedNow     = weatherNow["windSpeed"]; // 4
            weatherRightNow.windDirectionNow = weatherNow["windDirection"];
            weatherRightNow.windGustNow      = weatherNow["windGust"]; // 11
            weatherRightNow.conditionNow     = weatherNow["condition"]; // "OVERCAST"
            weatherRightNow.iconNow          = weatherNow["icon"]; // "ovc"
            
            // Serial.println("--             Погода сейчас:              --");
            // Serial.println("---------------------------------------------");
            // Serial.print("Восход: "); Serial.print(weatherRightNow.sunriseBeginTimestampNow); Serial.println(" Закат: "); Serial.println(weatherRightNow.sunsetEndTimestampNow);
            // Serial.println("---------------------------------------------");
            // Serial.print("Температура сейчас: "); Serial.println(weatherRightNow.temperatureNow);
            // Serial.print("Ощущается как: "); Serial.println(weatherRightNow.feelsLikeNow);
            // Serial.print("Скорость ветра: "); Serial.println(weatherRightNow.windSpeedNow);                                
            // Serial.print("Направление ветра: "); Serial.println(weatherRightNow.windDirectionNow);
            // Serial.print("Скорость порывов ветра: "); Serial.println(weatherRightNow.windGustNow);
            // Serial.print("Название состояния: "); Serial.println(weatherRightNow.conditionNow);
            // Serial.print("Иконка: "); Serial.println(weatherRightNow.iconNow);
            
            int i = 1;
            
            //Two days long forecast
            for (JsonObject forecastDays : doc["data"]["weatherByPoint"]["forecast"]["days"].as<JsonArray>()) {
              JsonObject forecastDay = forecastDays["summary"]["day"];
              weatherDays[i].temperatureDay   = forecastDay["temperature"];
              weatherDays[i].feelsLikeDay     = forecastDay["feelsLike"];
              weatherDays[i].windSpeedDay     = forecastDay["windSpeed"];
              weatherDays[i].windDirectionDay = forecastDay["windDirection"];
              weatherDays[i].windGustDay      = forecastDay["windGust"];
              weatherDays[i].conditionDay     = forecastDay["condition"];
              weatherDays[i].iconDay          = forecastDay["icon"];

            //   Serial.print("--             Погода завтра: "); Serial.print(i); Serial.println("              --");
            //   Serial.println("---------------------------------------------");
            //   Serial.print("Температура завтра: "); Serial.println(temperatureDay);
            //   Serial.print("Ощущается как: "); Serial.println(feelsLikeDay);
            //   Serial.print("Скорость ветра: "); Serial.println(windSpeedDay);
            //   Serial.print("Направление ветра: "); Serial.println(windDirectionDay);
            //   Serial.print("Скорость порывов ветра: "); Serial.println(windGustDay);
            //   Serial.print("Название состояния: "); Serial.println(conditionDay);
            //   Serial.print("Иконка: "); Serial.println(iconDay);
                 ++i;
            }
            
             int j = 1;
            
            //24 Hours forecast. First and last fields little buggy. Shouldn't be touch
            for (JsonObject forecastHours : doc["data"]["weatherByPoint"]["forecast"]["hours"]["edges"].as<JsonArray>()) {
              JsonObject forecastHour = forecastHours["node"];
              weatherHours[j].temperatureHour   = forecastHour["temperature"];
              weatherHours[j].feelsLikeHour     = forecastHour["feelsLike"];
              weatherHours[j].windSpeedHour     = forecastHour["windSpeed"];
              weatherHours[j].windDirectionHour = forecastHour["windDirection"];
              weatherHours[j].windGustHour      = forecastHour["windGust"];
              weatherHours[j].conditionHour     = forecastHour["condition"];
              weatherHours[j].iconHour          = forecastHour["icon"];
              
            //   Serial.print("--             Погода час: "); Serial.print(j); Serial.println("             --");
            //   Serial.println("---------------------------------------------");
            //   Serial.print("Температура завтра: "); Serial.println(temperatureHour);
            //   Serial.print("Ощущается как: "); Serial.println(feelsLikeHour);
            //   Serial.print("Скорость ветра: "); Serial.println(windSpeedHour);
            //   Serial.print("Направление ветра: "); Serial.println(windDirectionHour);
            //   Serial.print("Скорость порывов ветра: "); Serial.println(windGustHour);
            //   Serial.print("Название состояния: "); Serial.println(conditionHour);
            //   Serial.print("Иконка: "); Serial.println(iconHour);
               
               ++j;
            }
            
        } else {
            
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
            
        }
        http.end();
    }
}

