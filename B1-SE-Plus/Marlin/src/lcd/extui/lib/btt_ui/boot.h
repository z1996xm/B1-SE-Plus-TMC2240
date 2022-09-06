#ifndef _BOOT_H_
#define _BOOT_H_

#include "../../../../inc/MarlinConfig.h"
#if ENABLED(BTT_UI_SPI)
#include "stdbool.h"
#include "stdint.h"

typedef  uint8_t u8;
typedef  uint16_t u16;
typedef  uint32_t u32;

#define W25QXX_PAGE_SIZE (0x100) // 256
#define W25QXX_SECTOR_SIZE (0x1000) // 4096-4K

//address in spiflash W25Qxx 800000
#define LOGO_ADDR               0x0
#define ICON_ADDR(num)          ((num)*0x5000+0x4B000)
#define STATUS_ADDR             0x704000
#define MINI_ICON_ADDR(num)     ((num)*0x1000+0x720000)
#define WORD_UNICODE            0x280000 // unicode (+0x480000 4.5M)
#define BYTE_ASCII_ADDR         0x700000 // ascii (+0x1000 4K)

#define BMP		(1<<1)
#define FONT	(1<<2)

#define ROOT_DIR     "TFT35"
#define ROOT_DIR_CUR "TFT35CUR"

#define BMP_ROOT_DIR ROOT_DIR "/bmp"
#define FONT_ROOT_DIR ROOT_DIR "/font"
#define TFT_RESET_FILE "reset.txt"

#define MODEL_PREVIEW_OFFSET 0xC529

enum
{
  ICON_HEAT = 0,
  ICON_MOVE,
  ICON_HOME,
  ICON_PRINT,
  ICON_EXTRUDE,
  ICON_FAN,
  ICON_SETTINGS,
  ICON_LEVELING,  
  ICON_INC,
  ICON_DEC,
  ICON_NOZZLE,
  ICON_BED,
  ICON_1_DEGREE,
  ICON_5_DEGREE,
  ICON_10_DEGREE,
  ICON_STOP,
  ICON_BACK,
  ICON_X_INC,
  ICON_Y_INC,
  ICON_Z_INC,
  ICON_01_MM,
  ICON_1_MM,
  ICON_10_MM,
  ICON_X_DEC,
  ICON_Y_DEC,
  ICON_Z_DEC,  
  ICON_X_HOME,
  ICON_Y_HOME,
  ICON_Z_HOME,
  ICON_FOLDER,
  ICON_FILE,
  ICON_PAGE_UP,
  ICON_PAGE_DOWN,
  ICON_PAUSE,
  ICON_RESUME,  
  ICON_LOAD,
  ICON_UNLOAD,
  ICON_SLOW_SPEED,
  ICON_NORMAL_SPEED,
  ICON_FAST_SPEED,
  ICON_E_1_MM,
  ICON_E_5_MM,
  ICON_E_10_MM,  
  ICON_FAN_FULL_SPEED,
  ICON_FAN_HALF_SPEED,
  ICON_ROTATE_UI,
  ICON_LANGUAGE,
  ICON_TOUCHSCREEN_ADJUST,
  ICON_LISTMODE,
  ICON_SCREEN_INFO,
  ICON_ABLR1,
  ICON_ABLR2,
  ICON_ABLR3,
  ICON_ABLR4,  
  ICON_ABLB1,
  ICON_BABYSTEP,
  ICON_001_MM,
  ICON_BSD_SOURCE,
  ICON_RECORD_SOURCE,
  ICON_U_DISK,
  ICON_RUNOUT_ON,  
  ICON_RUNOUT_OFF, 
  ICON_POWERLOSS_ON,
  ICON_POWERLOSS_OFF,
  ICON_MOTOR_UNLOCK,
  ICON_MARLIN,
  ICON_BTT,
  ICON_GCODE,
  ICON_BLTOUCH,
  ICON_BLTOUCH_DEPLOY,
  ICON_BLTOUCH_STOW,
  ICON_BLTOUCH_TEST,
  ICON_BLTOUCH_REPEAT,
  ICON_SCREEN_SETTINGS,
  ICON_MACHINE_SETTINGS,
  ICON_FEATURE_SETTINGS,
  ICON_PROBE_OFFSET,
  ICON_EEPROM_SAVE,
  ICON_SILENT_ON,
  ICON_SHUT_DOWN,
  ICON_RGB_SETTINGS,
  ICON_RGB_RED,
  ICON_RGB_GREEN,
  ICON_RGB_BLUE,
  ICON_RGB_WHITE,
  ICON_RGB_OFF,
  ICON_PBOTH,
  ICON_PREPLA,
  ICON_PREPETG,
  ICON_PREABS,
  ICON_PSON,
  ICON_PSOFF,
  ICON_ABLB2,
  ICON_ABLB3,
  ICON_ABLB4,
  ICON_MVALID,
  ICON_ICONMODE,
  ICON_M001,
  ICON_M100,
  ICON_HOME_MOVE,
  ICON_HEAT_FAN,
  ICON_MANUAL_LEVEL,
  ICON_COOLDOWN,
  ICON_SILENT_OFF,
  ICON_STATUSNOZZLE,
  ICON_STATUSBED,
  ICON_STATUSFAN,
  ICON_MAINMENU,
  ICON_STATUS_SPEED,
  ICON_STATUS_FLOW,
  ICON_FLOWPER,
  ICON_SPEEDPER,
  ICON_EM_STOP,
// Preview should be in the last place
  ICON_PREVIEW,
// Back ground sign
  ICON_BACKGROUND,
};
enum {
  MINI_ICON_BABYSTEP=0,
  MINI_ICON_BED,
  MINI_ICON_FAN,
  MINI_ICON_FL,
  MINI_ICON_PRO,
  MINI_ICON_SP,
  MINI_ICON_T,
  MINI_ICON_T0,
  MINI_ICON_NUM,
};

typedef union
{
	uint16_t color;
	struct{
	uint16_t  b:5;
	uint16_t  g:6;
	uint16_t  r:5;
 }RGB;
}GUI_COLOR;

class TSCBoot {
  public:
    void scanUpdates(void);
 
  private:
    uint8_t scanUpdateFile(void);
    bool bmpDecode(char *bmp, uint32_t addr) ;
    void updateIcon(void);
    void updateFont(char *font, uint32_t addr);
};
bool preview_file_Decode(char *gcode,uint8_t keyicon);
void lcd_frame_display(uint16_t sx, uint16_t sy, uint16_t w, uint16_t h, uint32_t addr);
void LOGO_ReadDisplay(void);
void ICON_ReadDisplay(uint16_t sx,uint16_t sy, uint8_t icon);
void ICON_PressedDisplay(uint16_t sx, uint16_t sy, uint8_t icon);
void STATUS_ReadDisplay(uint16_t sx, uint16_t sy);
void MINIICON_ReadDisplay(uint16_t sx, uint16_t sy, uint8_t icon);
#endif 

#endif

