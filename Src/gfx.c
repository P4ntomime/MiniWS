/*
 * gfx.c
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#include "gfx.h"

extern SPI_HandleTypeDef hspi1;
extern Commands commands;

unsigned char ucDisplayBuff[(128*128*2)];

Colors colors =
{
    //black
    .black.red      = 0x00,//0x1F = maximal value
    .black.green    = 0x00,//0x3F = maximal value
    .black.blue     = 0x00,//0x1F = maximal value

    //gray
    .gray.red       = 0x05,
    .gray.green     = 0x0A,
    .gray.blue      = 0x05,

    //white
    .white.red      = 0x1F,
    .white.green    = 0x3F,
    .white.blue     = 0x1F,

    //red
    .red.red        = 0x3F,
    .red.green      = 0x00,
    .red.blue       = 0x00,

    //green
    .green.red      = 0x00,
    .green.green    = 0x3F,
    .green.blue     = 0x00,

    //blue
    .blue.red       = 0x00,
    .blue.green     = 0x00,
    .blue.blue      = 0x3F,

    //yellow
    .yellow.red     = 0x3F,
    .yellow.green   = 0x3F,
    .yellow.blue    = 0x00,

    //magenta
    .magenta.red    = 0x3F,
    .magenta.green  = 0x00,
    .magenta.blue   = 0x3F,

    //cyan
    .cyan.red       = 0x00,
    .cyan.green     = 0x3F,
    .cyan.blue      = 0x3F

};

/**
 *  @name   sendfullscreen
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void sendfullscreen(void)
{
    setcursorstandard();

    sendcommand(commands.WriteRAM);

    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_RESET);              //select display (chipselect)
    HAL_GPIO_WritePin(GPIOA, OLED_DC, GPIO_PIN_SET);                //tell display that next transmission is data and not command

    HAL_SPI_Transmit(&hspi1, ucDisplayBuff, (128*128*2), 1000);     //send the full screen at once

    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_SET);                //release the chipselect
}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void blankscreen(Color color)
{
    uint16_t Ctr = 0;

    for(Ctr = 0; Ctr < 32768; Ctr+=2)
    {
        ucDisplayBuff[Ctr + 0] = (color.blue << 3) | (0x07 & (color.green >> 3));
        ucDisplayBuff[Ctr + 1] = (color.green << 5) | (0x1F & (color.red));
    }

    sendfullscreen();
}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void plotdotxy(uint8_t x, uint8_t y, Color color, uint8_t dwdot)
{
    if((x < 128) && (y < 128))      //check if coordinates are legal
    {
        x = 127 - x;
        y = 127 - y;
    }

    if((x < 128) && (y < 128))
    {
        ucDisplayBuff[(x*2) + (y*128*2) + 0] = (color.blue << 3) | (0x07 & (color.green >> 3));     //blue subpixel and first part of green subpixel
        ucDisplayBuff[(x*2) + (y*128*2) + 1] = (color.green << 5) | (0x1F & (color.red));           //second part of green subpixel and red subpixel
    }

    if(dwdot) sendfullscreen();
}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void filledrectxyab(uint8_t x, uint8_t y, uint8_t a, uint8_t b, Color color, uint8_t dwrect)
{
    uint8_t aCtr = 0;
    uint8_t bCtr = 0;

    uint8_t NextX = x;

    if((x + a - 1) < 128 && (y + b - 1) < 128)  //check if coordinates are legal
    {
        for(bCtr = 0; bCtr < b; bCtr++)
        {
            for(aCtr = 0; aCtr < a; aCtr++)
            {
                plotdotxy(x + aCtr, y + bCtr, color, 0);
            }
        }

        if(dwrect) sendfullscreen();
    }
}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void linefromto(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color, uint8_t dwline)
{
    if((x1 < 128) && (x2 < 128) && (y1 < 128) && (y2 < 128))        //check if coordinates are legal
    {
        if(((x1 > x2) && (y1 > y2)) || ((x1 > x2) && (y1 < y2)))
        {
            uint8_t tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }

        int16_t dx = x2 - x1;
        int16_t dy = y2 - y1;

        int16_t ctr = 0;

        float mx = (dy/dx);
        float my = (dx/dy);

//        if(y2 < y1) dy = y1 - y2;
//        if(x2 < x1) dx = x1 - x2;

    }
}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void charxy(char c, uint8_t x, uint8_t y, Color fgcolor, Color bgcolor, uint8_t dwbgcolor, uint8_t dwchar)
{

}

/**
 *  @name
 *  @brief
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void stringxy(char *string, uint8_t x, uint8_t y, Color fgcolor, Color bgcolor, uint8_t dwbgcolor)
{

}
