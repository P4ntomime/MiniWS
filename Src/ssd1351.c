/**
 * ssd1351.c
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 *  @version    0.1(0.2)
 *  @brief      this and gfx.c/.h are an update to OLEDGFX.h
 *              this library is to be used with an stm32 device and the HAL (Hardware Abstraction Library)
 */

#include "ssd1351.h"


extern SPI_HandleTypeDef hspi1;
extern Colors colors;
extern unsigned char ucDisplayBuff[(128*128*2)];

Commands commands =
{
    .SetColumn              = 0x15,
    .SetRow                 = 0x75,
    .WriteRAM               = 0x5C,
    .ColorDepth             = 0xA0,
    .SetStartLine           = 0xA1,
    .SetDisplayOffset       = 0xA2,
    .DisplayAllOff          = 0xA4,
    .DisplayAllOn           = 0xA5,
    .DisplayGDDRAM          = 0xA6,
    .DisplayInvert          = 0xA7,
    .SleepOn                = 0xAE,
    .SleepOff               = 0xAF,
    .SetPhase               = 0xB1,
    .SetCommandLock         = 0xFD,
    .SetBrightness          = 0xC7,
    .DivSet                 = 0xB3
};

/**
 *  @name   init_oled
 *  @brief  initializes 128x128 OLED with SSD1351 chip
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 * 
 * TODO: implement framerate
 * TODO: implement orientation -> mb. global orientation property for gfx.h + orientation in ssd1351
 *
*/
void init_oled(uint8_t orientation, uint8_t framerate)
{

    uint16_t uiCtr = 0;

    //reset cycle of display
	HAL_GPIO_WritePin(GPIOA, OLED_RESET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, OLED_RESET, GPIO_PIN_RESET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOA, OLED_RESET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_SET);
	HAL_Delay(500);

	for(uiCtr = 0; uiCtr < (128*128*2); uiCtr++) ucDisplayBuff[uiCtr] = 0xFF;

    sendsth(commands.SetCommandLock, 0);   //set command lock
    sendsth(0xB1, 1);                      //unlock locked commands

    //TODO: implement framerate
    sendsth(commands.DivSet, 0);           //freq divset
    sendsth(0xF0, 1);                      //divide freq. by 1

    sendsth(commands.ColorDepth, 0);       //set re-map color depth
    sendsth(0x20, 1);                      //color depth to 262k color (565 rgb)

    sendsth(commands.SetStartLine, 0);     //set display start line
    sendsth(0x00, 1);                      //no offset

    sendsth(commands.SetDisplayOffset, 0); //set offset
    sendsth(0x00, 1);                      //no offset

    sendsth(commands.SetBrightness, 0);    //change brightness, contrast current control
    sendsth(0x0F, 1);                      //0x0F -> brightest, 0x00 -> dimmest

    blankscreen(colors.black);              //blank the screen (set whole GDDRAM to 0)

    setcursorstandard();                    //set cursor to standard limitations (0,0,127,127)

    sendsth(commands.DisplayGDDRAM, 0);    //tell to display GDDRAM
    sendsth(commands.SleepOff, 0);         //turn sleep off

}

/**
 *  @name   sendcommand
 *  @brief  for sending commands to ssd1351
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 * 
*/
void sendcommand(uint8_t cmd)
{
    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_RESET);      //chipselect to low
    HAL_GPIO_WritePin(GPIOA, OLED_DC, GPIO_PIN_RESET);      //dc to low for command instruction

    HAL_SPI_Transmit(&hspi1, &cmd, 1, 1000);                //send command over SPI

    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_SET);        //chipselect to high
}

/**
 *  @name   senddata
 *  @brief  for sending data to ssd1351 (should only be used after a command has been sent)
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 * 
*/
void senddata(uint8_t *data, uint16_t len)
{
    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_RESET);      //chipselect to low
    HAL_GPIO_WritePin(GPIOA, OLED_DC, GPIO_PIN_SET);        //dc to high for data

    HAL_SPI_Transmit(&hspi1, data, len, 1000);              //send data over SPI

    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_SET);        //chipselect to high
}


void sendsth(uint8_t sth, uint8_t dc)
{
    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(GPIOA, OLED_DC, dc);

    HAL_SPI_Transmit(&hspi1, &sth, 1, 1000);

    HAL_GPIO_WritePin(GPIOA, OLED_CS, GPIO_PIN_SET);
}

/**
 *  @name   setcursorstandard
 *  @brief  sets cursor in RAM of ssd1351 to standard (0,0,127,127)
 *  @author Laurin Heitzer
 *  @date   23.12.2019
 *
*/
void setcursorstandard(void)
{
    uint8_t TxBuff[2] = { 0 , 0 };

    TxBuff[0] = 0x00;
    TxBuff[1] = 127;
    sendcommand(commands.SetColumn);
    senddata(&TxBuff, 2);

    TxBuff[1] = 127;
    sendcommand(commands.SetRow);
    senddata(&TxBuff, 2);

}
