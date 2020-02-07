/*
 * gfx.h
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#ifndef INC_GFX_H_
#define INC_GFX_H_

#include "ssd1351.h"
#include "main.h"
//#include "myCharSet.h"

typedef struct Color
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}Color;

typedef struct
{
    Color red;
    Color green;
    Color blue;
    Color cyan;
    Color magenta;
    Color yellow;
    Color black;
    Color white;
    Color gray;
}Colors;



void sendfullscreen(void);
void blankscreen(Color color);
void plotdotxy(uint8_t x, uint8_t y, Color color, uint8_t dwdot);
void filledrectxyab(uint8_t x, uint8_t y, uint8_t a, uint8_t b, Color color, uint8_t dwrect);
void linefromto(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color, uint8_t dwline);
void charxy(char c, uint8_t x, uint8_t y, Color fgcolor, Color bgcolor, uint8_t dwbgcolor, uint8_t dwchar);
void stringxy(char *string, uint8_t x, uint8_t y, Color fgcolor, Color bgcolor, uint8_t dwbgcolor);



#endif /* INC_GFX_H_ */
