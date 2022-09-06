/*********************
 * example.cpp *
 *********************/

/****************************************************************************
 *   Written By Marcio Teixeira 2018 - Aleph Objects, Inc.                  *
 *                                                                          *
 *   This program is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by   *
 *   the Free Software Foundation, either version 3 of the License, or      *
 *   (at your option) any later version.                                    *
 *                                                                          *
 *   This program is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   To view a copy of the GNU General Public License, go to the following  *
 *   location: <https://www.gnu.org/licenses/>.                             *
 ****************************************************************************/

#include "../../../../inc/MarlinConfigPre.h"
#if ENABLED(BTT_UI_SPI)
 
#include "../../ui_api.h"
#include "../../../../core/serial.h"
#include "TSC_Menu.h"
// To implement a new UI, complete the functions below and
// read or update Marlin's state using the methods in the
// ExtUI methods in "../ui_api.h"
//
// Although it may be possible to access other state
// variables from Marlin, using the API here possibly
// helps ensure future compatibility.
#ifdef Z_HOT_HOMING
static bool hothoming_lock=false;
static uint32_t hothoming_now_time=0;
#endif




//#if BOTH(EXTUI_EXAMPLE, EXTENSIBLE_UI)

//#include "../ui_api.h"

// To implement a new UI, complete the functions below and
// read or update Marlin's state using the methods in the
// ExtUI methods in "../ui_api.h"
//
// Although it may be possible to access other state
// variables from Marlin, using the API here possibly
// helps ensure future compatibility.

namespace ExtUI {
  void onStartup() {
    /* Initialize the display module here. The following
     * routines are available for access to the GPIO pins:
     *
     *   SET_OUTPUT(pin)
     *   SET_INPUT_PULLUP(pin)
     *   SET_INPUT(pin)
     *   WRITE(pin,value)
     *   READ(pin)
     */
  }
  void onIdle() {
   menuUpdate();
   
   #ifdef VIOLENCE_TEST
   GUI_PrintDispDec(100, 100, Test_num, 8, LEFT);
   #endif
   #ifdef Z_HOT_HOMING
    if(hothoming_lock&&((millis()-hothoming_now_time)>=3000))
    {
      hothoming_lock=false;
      reDrawTitle();
    }
   #endif
  }

  #define PGM_P const char *
  void onPrinterKilled(FSTR_P const error, FSTR_P const component) {
    char context[126];
    sprintf_P(context, "%s %s %s: %s", GET_TEXT(MSG_HALTED), GET_TEXT(MSG_PLEASE_RESET), error, component);
    popupDrawPage(NULL, textSelect(LABEL_ERROR), (uint8_t *)context, NULL, NULL);
  }

  // void onPrinterKilled(PGM_P const error, PGM_P const component) {
  //   char context[126];
  //   sprintf_P(context, "%s %s %s: %s", GET_TEXT(MSG_HALTED), GET_TEXT(MSG_PLEASE_RESET), error, component);
  //   popupDrawPage(NULL, textSelect(LABEL_ERROR), (uint8_t *)context, NULL, NULL);
  // }

  void onMediaInserted() {
    volumeReminderMessage(LABEL_U_DISK_INSERTED, STATUS_NORMAL);
  }

  void onMediaError() {
    if(SD_SUPPORT==1) 
    {
    volumeReminderMessage(LABEL_READ_ONBOARDSD_ERROR, STATUS_NORMAL);
    }
    else
    {
    volumeReminderMessage(LABEL_READ_U_DISK_ERROR, STATUS_NORMAL);
    }
  }


  void onMediaRemoved() {
   volumeReminderMessage(LABEL_U_DISK_REMOVED, STATUS_NORMAL);  
  }


  void onPlayTone(const uint16_t frequency, const uint16_t duration) {
    #ifdef __STM32F1__
      __iSeiRetVal();
      BuzzerTone(frequency,duration);
    #else
     CRITICAL_SECTION_START();
     ::tone(BEEPER_PIN, frequency, duration);
      CRITICAL_SECTION_END();
    #endif
  }

  void onPrintTimerStarted() {}
  void onPrintTimerPaused() {}
  void onPrintTimerStopped() {}
  void onFilamentRunout(const extruder_t extruder) {
    popupReminder(textSelect(LABEL_WARNING), textSelect(LABEL_FILAMENT_RUNOUT));
    Buzzer_play(sound_error);
  }


  void onUserConfirmRequired(const char * const msg) {
    popupDrawPage(&bottomSingleBtn, textSelect(LABEL_CONFIRM), (uint8_t *)msg, textSelect(LABEL_CONFIRM), 0);
    infoMenu.menu[++infoMenu.cur] = menuUsrConfirm;
    Buzzer_play(sound_notify);
  }


  void onStatusChanged(const char * const msg) {
    statusScreen_setMsg(0, (uint8_t *)msg); 
    #ifdef  FIX_MOUNTED_PROBE
     level_setMsg(0, (uint8_t *)msg);
    #endif

  }

  void onHomingStart() {}
  void onHomingDone() {}
  void onPrintDone() {}

  void onFactoryReset() {}

  void onStoreSettings(char *buff) {
    // Called when saving to EEPROM (i.e. M500). If the ExtUI needs
    // permanent data to be stored, it can write up to eeprom_data_size bytes
    // into buff.

    // Example:
    //  static_assert(sizeof(myDataStruct) <= eeprom_data_size);
    //  memcpy(buff, &myDataStruct, sizeof(myDataStruct));
  }

  void onLoadSettings(const char *buff) {
    // Called while loading settings from EEPROM. If the ExtUI
    // needs to retrieve data, it should copy up to eeprom_data_size bytes
    // from buff

    // Example:
    //  static_assert(sizeof(myDataStruct) <= eeprom_data_size);
    //  memcpy(&myDataStruct, buff, sizeof(myDataStruct));
  }

  void onPostprocessSettings() {
    // Called after loading or resetting stored settings
  }

  void onSettingsStored(bool success) {
    // Called after the entire EEPROM has been written,
    // whether successful or not.
  }

  void onSettingsLoaded(bool success) {
    // Called after the entire EEPROM has been read,
    // whether successful or not.
  }

  #if HAS_MESH
    void onLevelingStart() {}
    void onLevelingDone() {}

    void onMeshUpdate(const int8_t xpos, const int8_t ypos, const_float_t zval) {
      // Called when any mesh points are updated
    }

    void onMeshUpdate(const int8_t xpos, const int8_t ypos, const probe_state_t state) {
      // Called to indicate a special condition
    }
  #endif

  #if ENABLED(POWER_LOSS_RECOVERY)
    void onPowerLossResume() {
      // Called on resume from power-loss
      infoMenu.menu[++infoMenu.cur] = menuPowerFailed;
    }
  #endif

  #if HAS_PID_HEATING
    void onPidTuning(const result_t rst) {
      // Called for temperature PID tuning result
      switch (rst) {
        case PID_STARTED:          break;
        case PID_BAD_EXTRUDER_NUM: break;
        case PID_TEMP_TOO_HIGH:    break;
        case PID_TUNING_TIMEOUT:   break;
        case PID_DONE:             break;
      }
    }
  #endif

  void onSteppersDisabled() {}
  void onSteppersEnabled()  {}


  void onEndscript(void)
  {
    char script[50]="";
    sprintf(script,"G1 Y%d F%d\n",(Y_BED_SIZE/4)*3,(60*60));
    queue.enqueue_one_now("G28 XY");
    queue.enqueue_one_now(script);
    queue.enqueue_one_now("M84");
    queue.enqueue_one_now("M500");
  }

  void onM84App(void)
  {
    if(infoMenu.menu[infoMenu.cur] == menuStopMotor)
    {
      VIOLENCE_flag = false;
    }
  }

  bool onGetHotHoming_State(void)
  {
   return infoSettings.hot_homing;
  }

  bool onIsprintfing(void)
  {
   return ExtUI::isPrintingFromMedia() && !card.flag.abort_sd_printing;
  }

#ifdef Z_HOT_HOMING
    bool onIshothoming(void)
    {
    return ((thermalManager.degHotend(0)<=HOT_HOMING_DEFAULT_TEMP)&&(TERN_(EXTENSIBLE_UI, ExtUI::onIsprintfing())));
    }
    void onZHotHomingStart(void)
    {
      reDrawTitle();
      volumeReminderMessage(LABEL_HOT_HOMING_START, STATUS_NORMAL);
      if (!infoSettings.silent)
      {
      Buzzer_play(sound_ok);
      }
    }
    void onZHotHomingRuning(void)
    {
      reDrawTitle();
      volumeReminderMessage(LABEL_HOT_HOMING_Z_HOMING, STATUS_NORMAL);
      if (!infoSettings.silent)
      {
      Buzzer_play(sound_ok);
      }
    }
    void onZHotHomingStop(void)
    {
      reDrawTitle();
      volumeReminderMessage(LABEL_HOT_HOMING_STOP, STATUS_NORMAL);
      if (!infoSettings.silent)
      {
      Buzzer_play(sound_success);
      }
      hothoming_lock=true;
      hothoming_now_time= millis();
    }
  #endif
}

//#endif // EXTUI_EXAMPLE && EXTENSIBLE_UI
#endif