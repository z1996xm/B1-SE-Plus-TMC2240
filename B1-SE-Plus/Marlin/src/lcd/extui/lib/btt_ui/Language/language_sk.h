#ifndef _LANGUAGE_SK_H_
#define _LANGUAGE_SK_H_
#include "../../../../../inc/MarlinConfigPre.h"
#if ENABLED(BTT_UI_SPI)

    #define SK_LANGUAGE             "Slovensky"
    #define SK_HEAT                 "Teplota"
    #define SK_MOVE                 "Posunúť"
    #define SK_HOME                 "Domov"
    #define SK_PRINT                "Tlačiť"
    #define SK_EXTRUDE              "Extrúder"
    #define SK_FAN                  "Ofuk"
    #define SK_SETTINGS             "Nastavenia"
    #define SK_SCREEN_SETTINGS      "Obrazovka"
    #define SK_MACHINE_SETTINGS     "Tlačireň"
    #define SK_FEATURE_SETTINGS     "Funkcie"
    #define SK_SILENT_ON            "Zapnúť"
    #define SK_SILENT_OFF           "Stíšiť"
    #define SK_SHUT_DOWN            "Vypnúť"
    #define SK_RGB_SETTINGS         "Farba LED"
    #define SK_RGB_RED              "Červená"
    #define SK_RGB_GREEN            "Zelená"
    #define SK_RGB_BLUE             "Modrá"
    #define SK_RGB_WHITE            "Biela"
    #define SK_RGB_OFF              "Vypnúť LED"
    #define SK_GCODE                "Gcode"
    #define SK_CUSTOM               "Vlastné"
    #define SK_LEVELING             "Vyrovnanie"
    #define SK_POINT_1              "Bod 1"
    #define SK_POINT_2              "Bod 2"
    #define SK_POINT_3              "Bod 3"
    #define SK_POINT_4              "Bod 4"
    #define SK_ABL                  "ABL"
    #define SK_BLTOUCH              "Bltouch"
    #define SK_BLTOUCH_TEST         "Test"
    #define SK_BLTOUCH_DEPLOY       "Vystrčiť"
    #define SK_BLTOUCH_STOW         "Stiahnuť"
    #define SK_BLTOUCH_REPEAT       "Opakovať"
    #define SK_PROBE_OFFSET         "Offset"
    #define SK_EEPROM_SAVE          "Uložiť"
    #define SK_INC                  "Pridať"
    #define SK_DEC                  "Ubrať"
    #define SK_NOZZLE               "Tryska"
    #define SK_BED                  "Podložka"
    #define SK_STOP                 "Stop"
    #define SK_BACK                 "Naspäť"
    #define SK_PAGE_UP              "Ďalej"
    #define SK_PAGE_DOWN            "Naspäť"
    #define SK_PAUSE                "Pauza"
    #define SK_RESUME               "Pokračovať"
    #define SK_LOAD                 "Zaviesť"
    #define SK_UNLOAD               "Vysunúť"
    #define SK_SLOW_SPEED           "Pomaly"
    #define SK_NORMAL_SPEED         "Normálne"
    #define SK_FAST_SPEED           "Rýchlo"
    #define SK_FAN_FULL_SPEED       "Naplno"
    #define SK_FAN_HALF_SPEED       "Polovičná"
    #define SK_ROTATE_UI            "Otočiť"
    #define SK_TOUCHSCREEN_ADJUST   "Kalibrácia"
    #define SK_MORE                 "Viacej"
    #define SK_SCREEN_INFO          "Info"
    #define SK_WHITE                "Biela"
    #define SK_BLACK                "Čierna"
    #define SK_BLUE                 "Modrá"
    #define SK_RED                  "Červená"
    #define SK_GREEN                "Zelená"
    #define SK_CYAN                 "Tyrkysová"
    #define SK_YELLOW               "Žltá"
    #define SK_BROWN                "Hnedá"
    #define SK_GRAY                 "Šedá"
    #define SK_DISCONNECT           "Odpojiť"
    #define SK_BAUDRATE_115200      "115200"
    #define SK_BAUDRATE_250000      "250000"
    #define SK_RUNOUT_OFF           "Runout VYP"
    #define SK_RUNOUT_ON            "Runout ZAP"
    #define SK_SMART_RUNOUT_ON      "Smart ZAP"
    #define SK_PERCENTAGE           "Percentá"
    #define SK_BABYSTEP             "BabyStep"
    #define SK_PERCENTAGE_SPEED     "Rýchlosť"
    #define SK_PERCENTAGE_FLOW      "Prietok"    
    #define SK_VALUE_ZERO           "Vypnúť"
    #define SK_1_DEGREE             "1°C"
    #define SK_5_DEGREE             "5°C"
    #define SK_10_DEGREE            "10°C"
    #define SK_X_INC                "X+"
    #define SK_Y_INC                "Y+"
    #define SK_Z_INC                "Z+"
    #define SK_X_DEC                "X-"
    #define SK_Y_DEC                "Y-"
    #define SK_Z_DEC                "Z-"
    #define SK_X_HOME               "X"
    #define SK_Y_HOME               "Y"
    #define SK_Z_HOME               "Z"
    #define SK_001_MM               "0.01mm"
    #define SK_01_MM                "0.1mm"
    #define SK_1_MM                 "1mm"
    #define SK_5_MM                 "5mm"
    #define SK_10_MM                "10mm"
    #define SK_100_MM               "100mm"
    #define SK_1_PERCENT            "1%"
    #define SK_5_PERCENT            "5%"
    #define SK_10_PERCENT           "10%"
    #define SK_READY                "Tlačiareň pripravená"
    #define SK_PRINTING             "Tlačím"
    #define SK_BUSY                 "Počkajte prosím..."
    #define SK_UNCONNECTED          "Tlačiareň odpojená!"
    #define SK_DISCONNECT_INFO      "Teraz môžete tlačiareň ovládať z počítača!"
    #define SK_LOADING              "Načítavam..."
    #define SK_POWER_FAILED         "Pokračovať v tlači?"
    #define SK_CONTINUE             "Pokračovať"
    #define SK_CANNEL               "Zrušiť"
    #define SK_ADJUST_TITLE         "Kalibrácia obrazovky"
    #define SK_ADJUST_INFO          "Dotknite sa postupne všetkých bodov"
    #define SK_ADJUST_OK            "Kalibrácia úspešná"
    #define SK_ADJUST_FAILED        "Kalibrácia zlyhala, opakovať"
    #define SK_WARNING              "Varovanie"
    #define SK_STOP_PRINT           "Zastaviť tlač?"
    #define SK_CONFIRM              "Potvrdiť"    
    #define SK_TFTSD                "TFT SD"
    #define SK_READ_TFTSD_ERROR     "Chyba pri načítaní SD karty!"
    #define SK_TFTSD_INSERTED       "SD karta vložená!"
    #define SK_TFTSD_REMOVED        "SD karta odstránená!"    
    #define SK_U_DISK               "USB Kľúč"
    #define SK_READ_U_DISK_ERROR    "Chyba při načítaní USB kľúča!"
    #define SK_U_DISK_INSERTED      "USB kľúč  vložený!"
    #define SK_U_DISK_REMOVED       "USB disk odstránený!"    
    #define SK_ONBOARDSD            "SD karta na doske"
    #define SK_READ_ONBOARDSD_ERROR "Chyba pri načítaní SD karty na doske!"
    #define SK_FILAMENT_RUNOUT      "Chýba Filament!"
    #define SK_PREHEAT              "Nahriať"
    #define SK_PREHEAT_BOTH         "Tryska/Podložka"
    #define SK_PREHEAT_PLA          "PLA"
    #define SK_PREHEAT_PETG         "PETG"
    #define SK_PREHEAT_ABS          "ABS"
    #define SK_PREHEAT_CUSTOM1      "Vlastné1"
    #define SK_PREHEAT_CUSTOM2      "Vlastné2"
    #define SK_IS_PAUSE             "Nemožné extrúdovať počas tlače, Pozastaviť tlač?"
    #define SK_AUTO_SHUT_DOWN       "Auto vyp."
    #define SK_MANUAL_SHUT_DOWN     "Manuálne vyp."
    #define SK_UNIFIEDMOVE          "Pohyb"
    #define SK_UNIFIEDHEAT          "Nahriať"
    #define SK_COOLDOWN             "Ochladiť"
    #define SK_EMERGENCYSTOP        "STOP"
    #define SK_TOUCH_TO_EXIT        "Dotknite sa obrazovky pre ukončenie"
    #define SK_MAINMENU             "Menu"
    #define SK_WAIT_TEMP_SHUT_DOWN  "Počkať na teplotu trysky menej ako" STRINGIFY(AUTO_SHUT_DOWN_MAXTEMP) "℃" // Wait for the temperature of hotend to be lower than 50℃
    #define SK_FORCE_SHUT_DOWN      "Vynútené vypnutie"
    #define SK_SHUTTING_DOWN        "Vypínanie..."
    #define SK_PRINTING_COMPLETED   "Printing completed!"
    #define SK_STATUS_INFO          "Info"
    #define SK_ERROR                "Error"
    #define SK_TIPS                 "Tips"
    #define SK_EEPROM_SAVE_SUCCESS  "EEPROM parameters saved successfully"
    #define SK_EEPROM_SAVE_FAILED   "EEPROM parameters saved failed"
    #define SK_SOFTENING            "mäkký"
    #define SK_DEFAULT              "štandardný"
    #define SK_IS_DEFAULT           "Obnoviť štandardné nastavenia?"
    #define SK_DEFAULT_OK           "Štandardné nastavenia obnovené!"
    #define SK_LEVEL_TEMP           "Tepelná prútka 140 stupňov"
    #define SK_PSTOP                "Počkajte na koniec nuly.."
    #define SK_LEVEL_BED_TEMP       "Horúca posteľ je stabilizovaná na 60 stupňov."
    #define SK_LEVELING_OVEL        "Úroveň dokončená!"
    #define SK_LEVELING_ING         "Vyrovnanie.."
    #define SK_MOVEMENT             "pohyb"
    #define SK_OFF                  "OFF"
    #define SK_ON                   "ON"
    #define SK_COLDEXTRUD           "Žiadne studené extrusie (t0 < 170 stupňov)"
    #define SK_COLDEXTRUD170        "predteplo"
    #define SK_CLEARNOZZ            "Vyčistite trysku!"
    #define SK_MODE_SELECT          "Výber režimu"
    #define SK_POWERLOSS_ON         "PLR ON"
    #define SK_POWERLOSS_OFF        "PLR OFF"
    #define SK_MOTOR_UNLOCK         "Odblokovanie"
    #define SK_MESH_VALID           "skúška"
    #define SK_WAIT_FOR_TEMP        "Počkajte, kým sa teplota zvýši na cieľovú teplotu."
    #define SK_STOP_PLANE_TEST      "Prestaň testovať rovnováhu?"
    #define SK_IS_BABYSTEP          "Si si istý, že si zachrániš hodnotu odrezania?"
    #define SK_IS_LANGUAGE          "Are you sure to save the settings?"
    #define SK_HOT_HOMING_ON        "HOT HOME:ON"
    #define SK_HOT_HOMING_OFF       "HOT HOME:OFF"
    #define SK_HOT_HOMING_START     "HOT HOME:START!"
    #define SK_HOT_HOMING_Z_HOMING  "HOT HOME:Z HOMING!"  
    #define SK_HOT_HOMING_STOP      "HOT HOME:OK!"    
    #define SK_LIST_MODE            "LIST"
    #define SK_ICON_MODE            "ICON"
#endif
#endif