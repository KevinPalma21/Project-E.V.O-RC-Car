#ifndef LCDInstruction_h
#define LCDInstruction_h

#include <GxEPD2_BW.h>
#include <GxEPD2_3C.h>
#include <Fonts/FreeMonoBold9pt7b.h>

// LCD Definitions
//#define EPD_CS     5
//#define EPD_DC     17
//#define EPD_RST    16
//#define EPD_BUSY   4

//extern GxEPD2_BW<GxEPD2_213_B73, GxEPD2_213_B73::HEIGHT> display;
#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS GxEPD2_213_B74 // GDEM0213B74 128x250, SSD1680
#define GxEPD2_BW_IS_GxEPD2_BW true
#define MAX_DISPLAY_BUFFER_SIZE 65536ul
#define MAX_HEIGHT(EPD) (EPD::HEIGHT <= MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8) ? EPD::HEIGHT : MAX_DISPLAY_BUFFER_SIZE / (EPD::WIDTH / 8))

// Display constructor
extern GxEPD2_BW<GxEPD2_213_B74, MAX_HEIGHT(GxEPD2_213_B74)> display;

void lcdSetup();
void lcdInstruction(bool isPs4Connected);

#endif
