#pragma once
#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H
#include <WeatherClient.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include <string.h>
#include <FontsRus/RobotoBold8.h>
#include <FontsRus/RobotoBold18.h>
#include <icons/wind.h>
#include <icons/icons24.h>
#include "icons/icons48.h"

class MenuSystem{
public:

  MenuSystem(Adafruit_ILI9341* tft, const long utcOffsetInSeconds);
  void MainMenu();
  void weatherNow(const WeatherClient& weatherClient);
  void weatherNowHours(const WeatherClient& weatherClient, int requestHour);
  void weatherForecast(const WeatherClient& weatherClient);
  const uint16_t* getIcon(const char* iconName, byte size);
  const char* getConditionName(const char* conditionName, bool formatted);
  const char* getGustName(float windGust); //https://en.wikipedia.org/wiki/Beaufort_scale
  const char* getWindName(const char* windName, bool formatted);
  String getFormattedTime(const char* timeStamp);
  int lastHour = 0;
  const uint16_t* icons48_allArray[42] = {
	icons48_bkn__plus_ra_d,
	icons48_bkn__minus_ra_d,
	icons48_bkn__plus_ra_n,
	icons48_bkn__minus_ra_n,
	icons48_bkn__plus_sn_d,
	icons48_bkn__minus_sn_d,
	icons48_bkn__plus_sn_n,
    icons48_bkn__sn_n,
	icons48_bkn__minus_sn_n,
	icons48_bkn_d,
	icons48_bkn_n,
	icons48_bkn_ra_d,
	icons48_bkn_ra_n,
	icons48_bkn_sn_d,
    icons48_ovc,
	icons48_ovc__plus_ra,
	icons48_ovc__minus_ra,
	icons48_ovc__plus_sn,
	icons48_ovc__minus_sn,
	icons48_ovc_h,
	icons48_ovc_ra,
	icons48_ovc_ra_sn,
	icons48_ovc_sn,
	icons48_ovc_ts,
	icons48_ovc_ts_h,
	icons48_ovc_ts_ra,
	icons48_skc_d,
	icons48_skc_n,
	icons48_bl,
	icons48_bl_minus,
	icons48_fct__plus_ra,
	icons48_fct__minus_ra,
	icons48_fct__plus_sn,
	icons48_fct__minus_sn,
	icons48_fct_ra,
	icons48_fct_ra_sn,
	icons48_fct_sn,
	icons48_fct_ts,
	icons48_fct_ts_ra,
	icons48_fg_d,
	icons48_fg_n,
	icons48_ic_air_q
	
};

const uint16_t* icons24_allArray[42] = {
	icons24_bkn__plus_ra_d,
	icons24_bkn__minus_ra_d,
	icons24_bkn__plus_ra_n,
	icons24_bkn__minus_ra_n,
	icons24_bkn__plus_sn_d,
	icons24_bkn__minus_sn_d,
	icons24_bkn__plus_sn_n,
    icons24_bkn__sn_n,
	icons24_bkn__minus_sn_n,
	icons24_bkn_d,
	icons24_bkn_n,
	icons24_bkn_ra_d,
	icons24_bkn_ra_n,
	icons24_bkn_sn_d,
    icons24_ovc,
	icons24_ovc__plus_ra,
	icons24_ovc__minus_ra,
	icons24_ovc__plus_sn,
	icons24_ovc__minus_sn,
	icons24_ovc_h,
	icons24_ovc_ra,
	icons24_ovc_ra_sn,
	icons24_ovc_sn,
	icons24_ovc_ts,
	icons24_ovc_ts_h,
	icons24_ovc_ts_ra,
	icons24_skc_d,
	icons24_skc_n,
	icons24_bl,
	icons24_bl_minus,
	icons24_fct__plus_ra,
	icons24_fct__minus_ra,
	icons24_fct__plus_sn,
	icons24_fct__minus_sn,
	icons24_fct_ra,
	icons24_fct_ra_sn,
	icons24_fct_sn,
	icons24_fct_ts,
	icons24_fct_ts_ra,
	icons24_fg_d,
	icons24_fg_n,
	icons24_ic_air_q
};
  private:  
  Adafruit_ILI9341* tft;
  const long utcOffsetInSeconds;
};
#endif