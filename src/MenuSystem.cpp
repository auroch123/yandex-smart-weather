#include <MenuSystem.h>

MenuSystem::MenuSystem(Adafruit_ILI9341* tft, const long utcOffsetInSeconds) : tft(tft), utcOffsetInSeconds(utcOffsetInSeconds){};



void MenuSystem::MainMenu(){
   tft->fillScreen(ILI9341_WHITE);
    //exampleButton.initButton(&tft, 200, 200, 0x0046, 0x0046, 0, ILI9341_RED, ILI9341_WHITE, "", 1);
    //exampleButton.drawButton();
    tft->drawFastHLine(0, 20,320, ILI9341_LIGHTGREY);
    tft->drawFastHLine(0, 155,211, ILI9341_LIGHTGREY);
    tft->drawFastVLine(211,20,300, ILI9341_LIGHTGREY);
    tft->setTextWrap(true);
    //logo 
    //tft.drawRGBBitmap(100, 0, epd_bitmap_,149,20);
	  //tft.setCursor(100,100);
    //tft.print(20);
};

const uint16_t* MenuSystem::getIcon(const char* iconName, byte size){
  const char* it = iconName;
   //icon size example 24x24
   switch (size)
   {
   case 24:

        if(strcmp(it, "bkn_+ra_d")        == 0){   return icons24_allArray[0]; break;}
        else if((strcmp(it, "bkn_+ra_n")  == 0)){  return icons24_allArray[1]; break;}
        else if((strcmp(it, "bkn_-ra_n")  == 0)){  return icons24_allArray[2]; break;}
        else if((strcmp(it, "bkn_+sn_d")  == 0)){  return icons24_allArray[3]; break;}
        else if((strcmp(it, "bkn_-ra_d")  == 0)){  return icons24_allArray[4]; break;}
        else if((strcmp(it, "bkn_-sn_d")  == 0)){  return icons24_allArray[5]; break;}
        else if((strcmp(it, "bkn_+sn_n")  == 0)){  return icons24_allArray[6]; break;}
        else if((strcmp(it, "bkn_sn_n")   == 0)){  return icons24_allArray[7]; break;}
        else if((strcmp(it, "bkn_-sn_n")  == 0)){  return icons24_allArray[8]; break;}
        else if((strcmp(it, "bkn_d")      == 0)){  return icons24_allArray[9]; break;}
        else if((strcmp(it, "bkn_n")      == 0)){  return icons24_allArray[10]; break;}
        else if((strcmp(it, "bkn_ra_d")   == 0)){  return icons24_allArray[11]; break;}
        else if((strcmp(it, "bkn_ra_n")   == 0)){  return icons24_allArray[12]; break;}
        else if((strcmp(it, "bkn_sn_d")   == 0)){  return icons24_allArray[13]; break;}
        else if((strcmp(it, "ovc")        == 0)){  return icons24_allArray[14]; break;}
        else if((strcmp(it, "ovc_+ra")    == 0)){  return icons24_allArray[15]; break;}
        else if((strcmp(it, "ovc_-ra")    == 0)){  return icons24_allArray[16]; break;}
        else if((strcmp(it, "ovc_+sn")    == 0)){  return icons24_allArray[17]; break;}
        else if((strcmp(it, "ovc_-sn")    == 0)){  return icons24_allArray[18]; break;}
        else if((strcmp(it, "ovc_h")      == 0)){  return icons24_allArray[19]; break;}
        else if((strcmp(it, "ovc_ra")     == 0)){  return icons24_allArray[20]; break;}
        else if((strcmp(it, "ovc_ra_sn")  == 0)){  return icons24_allArray[21]; break;}
        else if((strcmp(it, "ovc_sn")     == 0)){  return icons24_allArray[22]; break;}
        else if((strcmp(it, "ovc_ts")     == 0)){  return icons24_allArray[23]; break;}
        else if((strcmp(it, "ovc_ts_h")   == 0)){  return icons24_allArray[24]; break;}
        else if((strcmp(it, "ovc_ts_ra")  == 0)){  return icons24_allArray[25]; break;}
        else if((strcmp(it, "skc_d")      == 0)){  return icons24_allArray[26]; break;}
        else if((strcmp(it, "skc_n")      == 0)){  return icons24_allArray[27]; break;}
        else if((strcmp(it, "bl")         == 0)){  return icons24_allArray[28]; break;}
        else if((strcmp(it, "bl-")        == 0)){  return icons24_allArray[29]; break;}
        else if((strcmp(it, "fct_+ra")    == 0)){  return icons24_allArray[30]; break;}
        else if((strcmp(it, "fct_-ra")    == 0)){  return icons24_allArray[31]; break;}
        else if((strcmp(it, "fct_+sn")    == 0)){  return icons24_allArray[32]; break;}
        else if((strcmp(it, "fct_-sn")    == 0)){  return icons24_allArray[33]; break;}
        else if((strcmp(it, "fct_ra")     == 0)){  return icons24_allArray[34]; break;}
        else if((strcmp(it, "fct_ra_sn")  == 0)){  return icons24_allArray[35]; break;}
        else if((strcmp(it, "fct_sn")     == 0)){  return icons24_allArray[36]; break;}
        else if((strcmp(it, "fct_ts")     == 0)){  return icons24_allArray[37]; break;}
        else if((strcmp(it, "fct_ts_ra")  == 0)){  return icons24_allArray[38]; break;}
        else if((strcmp(it, "fg_d")       == 0)){  return icons24_allArray[39]; break;}
        else if((strcmp(it, "fg_n")       == 0)){  return icons24_allArray[40]; break;}
        else{break;}

   case 48:

        if(strcmp(it, "bkn_+ra_d")        == 0){   return icons48_allArray[0]; break;}
        else if((strcmp(it, "bkn_+ra_n")  == 0)){  return icons48_allArray[1]; break;}
        else if((strcmp(it, "bkn_-ra_n")  == 0)){  return icons48_allArray[2]; break;}
        else if((strcmp(it, "bkn_+sn_d")  == 0)){  return icons48_allArray[3]; break;}
        else if((strcmp(it, "bkn_-ra_d")  == 0)){  return icons48_allArray[4]; break;}
        else if((strcmp(it, "bkn_-sn_d")  == 0)){  return icons48_allArray[5]; break;}
        else if((strcmp(it, "bkn_+sn_n")  == 0)){  return icons48_allArray[6]; break;}
        else if((strcmp(it, "bkn_sn_n")   == 0)){  return icons48_allArray[7]; break;}
        else if((strcmp(it, "bkn_-sn_n")  == 0)){  return icons48_allArray[8]; break;}
        else if((strcmp(it, "bkn_d")      == 0)){  return icons48_allArray[9]; break;}
        else if((strcmp(it, "bkn_n")      == 0)){  return icons48_allArray[10]; break;}
        else if((strcmp(it, "bkn_ra_d")   == 0)){  return icons48_allArray[11]; break;}
        else if((strcmp(it, "bkn_ra_n")   == 0)){  return icons48_allArray[12]; break;}
        else if((strcmp(it, "bkn_sn_d")   == 0)){  return icons48_allArray[13]; break;}
        else if((strcmp(it, "ovc")        == 0)){  return icons48_allArray[14]; break;}
        else if((strcmp(it, "ovc_+ra")    == 0)){  return icons48_allArray[15]; break;}
        else if((strcmp(it, "ovc_-ra")    == 0)){  return icons48_allArray[16]; break;}
        else if((strcmp(it, "ovc_+sn")    == 0)){  return icons48_allArray[17]; break;}
        else if((strcmp(it, "ovc_-sn")    == 0)){  return icons48_allArray[18]; break;}
        else if((strcmp(it, "ovc_h")      == 0)){  return icons48_allArray[19]; break;}
        else if((strcmp(it, "ovc_ra")     == 0)){  return icons48_allArray[20]; break;}
        else if((strcmp(it, "ovc_ra_sn")  == 0)){  return icons48_allArray[21]; break;}
        else if((strcmp(it, "ovc_sn")     == 0)){  return icons48_allArray[22]; break;}
        else if((strcmp(it, "ovc_ts")     == 0)){  return icons48_allArray[23]; break;}
        else if((strcmp(it, "ovc_ts_h")   == 0)){  return icons48_allArray[24]; break;}
        else if((strcmp(it, "ovc_ts_ra")  == 0)){  return icons48_allArray[25]; break;}
        else if((strcmp(it, "skc_d")      == 0)){  return icons48_allArray[26]; break;}
        else if((strcmp(it, "skc_n")      == 0)){  return icons48_allArray[27]; break;}
        else if((strcmp(it, "bl")         == 0)){  return icons48_allArray[28]; break;}
        else if((strcmp(it, "bl-")        == 0)){  return icons48_allArray[29]; break;}
        else if((strcmp(it, "fct_+ra")    == 0)){  return icons48_allArray[30]; break;}
        else if((strcmp(it, "fct_-ra")    == 0)){  return icons48_allArray[31]; break;}
        else if((strcmp(it, "fct_+sn")    == 0)){  return icons48_allArray[32]; break;}
        else if((strcmp(it, "fct_-sn")    == 0)){  return icons48_allArray[33]; break;}
        else if((strcmp(it, "fct_ra")     == 0)){  return icons48_allArray[34]; break;}
        else if((strcmp(it, "fct_ra_sn")  == 0)){  return icons48_allArray[35]; break;}
        else if((strcmp(it, "fct_sn")     == 0)){  return icons48_allArray[36]; break;}
        else if((strcmp(it, "fct_ts")     == 0)){  return icons48_allArray[37]; break;}
        else if((strcmp(it, "fct_ts_ra")  == 0)){  return icons48_allArray[38]; break;}
        else if((strcmp(it, "fg_d")       == 0)){  return icons48_allArray[39]; break;}
        else if((strcmp(it, "fg_n")       == 0)){  return icons48_allArray[40]; break;}
        else{break;}

   default:
    //leaf icon as error
    return icons48_allArray[41];
    break;
   }
   return icons48_allArray[41];
};

const char* MenuSystem::getConditionName(const char* conditionName, bool formatted){
        // {"CLEAR", "Ясно"},
        // {"PARTLY_CLOUDY", "Облачно с прояснениями"},
        // {"CLOUDY", "Облачно"},
        // {"OVERCAST", "Пасмурно"},
        // {"LIGHT_RAIN", "Небольшой дождь"},
        // {"RAIN", "Дождь"},
        // {"HEAVY_RAIN", "Сильный дождь"},
        // {"SHOWERS", "Ливень"},
        // {"SLEET", "Дождь со снегом"},
        // {"LIGHT_SNOW", "Небольшой снег"},
        // {"SNOW", "Снег"},
        // {"SNOWFALL", "Снегопад"},
        // {"HAIL", "Град"},
        // {"THUNDERSTORM", "Гроза"},
        // {"THUNDERSTORM_WITH_RAIN", "Гроза с дождем"},
        // {"THUNDERSTORM_WITH_HAIL", "Гроза с градом"}
    const char* it = conditionName;
    if(formatted){
      if (strcmp(it,"CLEAR")                      == 0){return PSTR("ЯСН");}
      else if(strcmp(it,"PARTLY_CLOUDY")          == 0){return PSTR("ОБЛ ПР");}
      else if(strcmp(it,"CLOUDY")                 == 0){return PSTR("ОБЛ");}
      else if(strcmp(it,"OVERCAST")               == 0){return PSTR("ПАС");}
      else if(strcmp(it,"LIGHT_RAIN")             == 0){return PSTR("НБ ДОЖ");}
      else if(strcmp(it,"RAIN")                   == 0){return PSTR("ДОЖ");}
      else if(strcmp(it,"HEAVY_RAIN")             == 0){return PSTR("СИЛ ДОЖ");}
      else if(strcmp(it,"SHOWERS")                == 0){return PSTR("ЛИВ");}
      else if(strcmp(it,"SLEET")                  == 0){return PSTR("ДОЖ СН");}
      else if(strcmp(it,"LIGHT_SNOW")             == 0){return PSTR("НБ СНГ");}
      else if(strcmp(it,"SNOW")                   == 0){return PSTR("СНГ");}
      else if(strcmp(it,"SNOWFALL")               == 0){return PSTR("СНГПАД");}
      else if(strcmp(it,"HAIL")                   == 0){return PSTR("ГРД");}
      else if(strcmp(it,"THUNDERSTORM")           == 0){return PSTR("ГРЗ");}
      else if(strcmp(it,"THUNDERSTORM_WITH_RAIN") == 0){return PSTR("ГРЗ ДОЖ");}
      else if(strcmp(it,"THUNDERSTORM_WITH_HAIL") == 0){return PSTR("ГРЗ ГРД");}
    }
    else{
      if (strcmp(it,"CLEAR")                      == 0){return PSTR("Ясно");}
      else if(strcmp(it,"PARTLY_CLOUDY")          == 0){return PSTR("Облачно с\n                                               проясн");}
      else if(strcmp(it,"CLOUDY")                 == 0){return PSTR("Облачно");}
      else if(strcmp(it,"OVERCAST")               == 0){return PSTR("Пасмурно");}
      else if(strcmp(it,"LIGHT_RAIN")             == 0){return PSTR("Небольшой дождь");}
      else if(strcmp(it,"RAIN")                   == 0){return PSTR("Дождь");}
      else if(strcmp(it,"HEAVY_RAIN")             == 0){return PSTR("Сильный дождь");}
      else if(strcmp(it,"SHOWERS")                == 0){return PSTR("Ливень");}
      else if(strcmp(it,"SLEET")                  == 0){return PSTR("Дождь со\n                                                снегом");}
      else if(strcmp(it,"LIGHT_SNOW")             == 0){return PSTR("Небольшой снег");}
      else if(strcmp(it,"SNOW")                   == 0){return PSTR("Снег");}
      else if(strcmp(it,"SNOWFALL")               == 0){return PSTR("Снегопад");}
      else if(strcmp(it,"HAIL")                   == 0){return PSTR("Град");}
      else if(strcmp(it,"THUNDERSTORM")           == 0){return PSTR("Гроза");}
      else if(strcmp(it,"THUNDERSTORM_WITH_RAIN") == 0){return PSTR("Гроза с\n                                                 дождем");}
      else if(strcmp(it,"THUNDERSTORM_WITH_HAIL") == 0){return PSTR("Гроза с\n                                                 градом");}
    }
    
    return "Error";
};

const char* MenuSystem::getWindName(const char* windName, bool formatted){
    
    const char* it = windName;
    if(formatted){

      if (strcmp(it,"CALM")            == 0){return PSTR("БЗВ");}
      else if(strcmp(it,"NORTH")       == 0){return PSTR("СВ");}
      else if(strcmp(it, "NORTH_EAST") == 0){return PSTR("СВ-ВС");}
      else if(strcmp(it,"EAST")        == 0){return PSTR("ВС");}
      else if(strcmp(it,"SOUTH_EAST")  == 0){return PSTR("ЮГ-ВС");}
      else if(strcmp(it,"SOUTH")       == 0){return PSTR("ЮГ");}
      else if(strcmp(it,"SOUTH_WEST")  == 0){return PSTR("ЮГ-ЗП");}
      else if(strcmp(it,"WEST")        == 0){return PSTR("ЗП");}
      else if(strcmp(it,"NORTH_WEST")  == 0){return PSTR("СВ-ЗП");}

    }else{
      
      if (strcmp(it,"CALM")            == 0){return PSTR("Безветренно");}
      else if(strcmp(it,"NORTH")       == 0){return PSTR("Северный");}
      else if(strcmp(it, "NORTH_EAST") == 0){return PSTR("Северо-восточный");}
      else if(strcmp(it,"EAST")        == 0){return PSTR("Восточный");}
      else if(strcmp(it,"SOUTH_EAST")  == 0){return PSTR("Юго-восточный");}
      else if(strcmp(it,"SOUTH")       == 0){return PSTR("Южный");}
      else if(strcmp(it,"SOUTH_WEST")  == 0){return PSTR("Юго-западный");}
      else if(strcmp(it,"WEST")        == 0){return PSTR("Западный");}
      else if(strcmp(it,"NORTH_WEST")  == 0){return PSTR("Северо-западный");}

    }
    
    return "Error";
};

//https://en.wikipedia.org/wiki/Beaufort_scale
const char* MenuSystem::getGustName(float windGust){
    if(windGust < 0.3)       {return PSTR("Штиль");}
    else if(windGust < 1.6)  {return PSTR("Тихий");}
    else if(windGust < 4.0)  {return PSTR("Легкий");}
    else if(windGust < 6.0)  {return PSTR("Слабый");}
    else if(windGust < 8.0)  {return PSTR("Умеренный");}
    else if(windGust < 11.0) {return PSTR("Свежий");}
    else if(windGust < 14.0) {return PSTR("Сильный");}
    else if(windGust < 18.0) {return PSTR("Крепкий");}
    else if(windGust < 21.0) {return PSTR("Очень крепкий");}
    else if(windGust < 25.0) {return PSTR("Шторм");}
    else if(windGust < 29.0) {return PSTR("Сильный шторм");}
    else if(windGust < 33.0) {return PSTR("Жестокий шторм");}
    else if(windGust >= 33.0){return PSTR("Ураган");}
  return "Error";
};

String MenuSystem::getFormattedTime(const char* timeStamp){
    long rawTime = atoi(timeStamp);
    rawTime += utcOffsetInSeconds;
    unsigned long hours = (rawTime % 86400L) / 3600;
    String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

     unsigned long minutes = (rawTime % 3600) / 60;
     String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);
    return hoursStr + ":" + minuteStr;
}

void MenuSystem::weatherNowHours(const WeatherClient& weatherClient, int requestHour){

  bool firstH = true;
  for(int i = requestHour + 1, j = requestHour + 5, k = 1; i <= j; ++i, ++k){
    
    if(firstH){
      if(i < 10){
      tft->setCursor(8,172); tft->printf("0%d:00", i);
      }else{
      tft->setCursor(8,172); tft->printf("%d:00", i);
      }
      firstH = false;
    }else{
      if(i < 10){
       tft->setCursor((42 * k) - 36,172); tft->printf("0%d:00", i);
     }else{
       tft->setCursor((42 * k) - 36,172); tft->printf("%d:00", i);
     }
    }
    
  }
  
  bool first = true;
  for(int i = 1; i <= 5; ++i){
    if(first){
      tft->drawRGBBitmap(12,180,getIcon(weatherClient.weatherHours[i + 1].iconHour,24),24,24);
      tft->setCursor(16,216); tft->print(weatherClient.weatherHours[i + 1].temperatureHour);
      tft->setCursor(16,228); tft->printf("%.1f", weatherClient.weatherHours[i + 1].windSpeedHour);
      first = false;
    }
    else{
      tft->drawRGBBitmap((42 * i) - 32,180,getIcon(weatherClient.weatherHours[i + 1].iconHour,24),24,24);
      tft->setCursor((42 * i) - 28,216); tft->print(weatherClient.weatherHours[i + 1].temperatureHour);
      tft->setCursor((42 * i) - 28,228); tft->printf("%.1f", weatherClient.weatherHours[i + 1].windSpeedHour);
    }
  }

};


void MenuSystem::weatherForecast(const WeatherClient& weatherClient){
  
  tft->setCursor(225,40); tft->print(PSTR("Завтра"));
  tft->setCursor(80,45); tft->drawRGBBitmap(226,76,getIcon(weatherClient.weatherDays[1].iconDay,24),24,24);
  tft->setCursor(260,77); tft->setFont(&RobotoBold12); tft->print(weatherClient.weatherDays[1].temperatureDay);
  tft->setCursor(280,55); tft->setFont(&RobotoBold6); tft->setTextColor(ILI9341_DARKGREY); tft->print(weatherClient.weatherDays[1].feelsLikeDay);
  tft->setCursor(260,94); tft->setTextColor(ILI9341_BLACK); tft->print(getConditionName(weatherClient.weatherDays[1].conditionDay, true));
  tft->setCursor(226,110); tft->printf("%.1f м/с, %s", weatherClient.weatherDays[1].windSpeedDay, getWindName(weatherClient.weatherDays[1].windDirectionDay, true));
  //tft->drawRGBBitmap(226, 125,ic_windic_wind,24,24);

  tft->setCursor(226,146); tft->print(PSTR("Послезавтра"));
  tft->setCursor(80,55); tft->drawRGBBitmap(226,178,getIcon(weatherClient.weatherDays[2].iconDay,24),24,24);
  tft->setCursor(260,184); tft->setFont(&RobotoBold12); tft->print(weatherClient.weatherDays[2].temperatureDay);
  tft->setCursor(280,162); tft->setFont(&RobotoBold6); tft->setTextColor(ILI9341_DARKGREY); tft->print(weatherClient.weatherDays[2].feelsLikeDay);
  tft->setCursor(260,201); tft->setTextColor(ILI9341_BLACK); tft->print(getConditionName(weatherClient.weatherDays[2].conditionDay, true));
  tft->setCursor(226,214); tft->printf("%.1f м/с, %s", weatherClient.weatherDays[2].windSpeedDay, getWindName(weatherClient.weatherDays[2].windDirectionDay, true));
  //tft->drawRGBBitmap(226, 204,ic_windic_wind,24,24);

};

void MenuSystem::weatherNow(const WeatherClient& weatherClient){

    
    tft->setCursor(77,40); tft->print(PSTR("Сегодня"));
    tft->setCursor(24,62); tft->print(PSTR("Восход"));
    tft->setCursor(24,72); tft->print(getFormattedTime(weatherClient.weatherRightNow.sunriseBeginTimestampNow));
    tft->setCursor(24,90); tft->print(PSTR("Закат"));
    tft->setCursor(24,100); tft->print(getFormattedTime(weatherClient.weatherRightNow.sunsetEndTimestampNow));
    tft->setCursor(80,65); tft->drawRGBBitmap(80,60,getIcon(weatherClient.weatherRightNow.iconNow,48),48,48);
    tft->setCursor(140,85); tft->setFont(&RobotoBold12); tft->print(weatherClient.weatherRightNow.temperatureNow);
    tft->setCursor(160,63); tft->setFont(&RobotoBold6); tft->setTextColor(ILI9341_DARKGREY); tft->print(weatherClient.weatherRightNow.feelsLikeNow);
    tft->setCursor(140,105); tft->setTextColor(ILI9341_BLACK); tft->print(getConditionName(weatherClient.weatherRightNow.conditionNow, false));
    tft->setCursor(55,133); tft->printf("%.1f м/с, %s", weatherClient.weatherRightNow.windSpeedNow, getWindName(weatherClient.weatherRightNow.windDirectionNow, false));
    tft->setCursor(55,145); tft->printf("%.1f м/c, %s", weatherClient.weatherRightNow.windGustNow, getGustName(weatherClient.weatherRightNow.windGustNow));
    tft->drawRGBBitmap(24,123,ic_windic_wind,24,24);
    
};