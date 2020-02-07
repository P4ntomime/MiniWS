/*
 * ssd1351.h
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#ifndef INC_SSD1351_H_
#define INC_SSD1351_H_

#include "main.h"
#include "gfx.h"

#define OLED_RESET  (1<<2)
#define OLED_DC     (1<<3)
#define OLED_CS     (1<<4)



typedef struct
{
    uint8_t SetColumn;
    uint8_t SetRow;
    uint8_t WriteRAM;
    uint8_t ColorDepth;
    uint8_t SetStartLine;
    uint8_t SetDisplayOffset;
    uint8_t DisplayAllOff;
    uint8_t DisplayAllOn;
    uint8_t DisplayGDDRAM;
    uint8_t DisplayInvert;
    uint8_t SleepOn;
    uint8_t SleepOff;
    uint8_t SetPhase;
    uint8_t SetCommandLock;
    uint8_t SetBrightness;
    uint8_t DivSet;
}Commands;




void init_oled(uint8_t orientation, uint8_t framerate);
void sendcommand(uint8_t cmd);
void senddata(uint8_t *data, uint16_t len);
void sendsth(uint8_t sth, uint8_t dc);
void setcursorstandard(void);

#endif /* INC_SSD1351_H_ */
