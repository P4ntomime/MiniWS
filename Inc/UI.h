/*
 * UI.h
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#ifndef INC_UI_H_
#define INC_UI_H_

#include "gfx.h"
#include "bme280.h"
#include "main.h"

#define SINGLE 0
#define OVERVIEW 1

#define TEMPERATURE 0
#define HUMIDITY 1
#define PRESSURE 2

#define OH_TEMP 0
#define OH_HUM  1
#define OH_PRES 2
#define OH_OVW  3

#define TEMP_FACTOR 0.03366667
#define HUM_FACTOR  0.00219184
#define PRES_FACTOR 0.00336667

typedef struct sdata
{
	int32_t temperature;
	uint32_t humidity;
	uint32_t pressure;
//	uint8_t measurement_taken;
}sens_data;

void UI_display_temperature(int32_t temperature);
void UI_display_humidity(uint32_t humidity);
void UI_display_pressure(uint32_t pressure);
void histogram_display_overhead(uint8_t type, sens_data *sdata); //displays the overhead information (current temperature[0], humidity[1], pressure[2], overview[3])
void histogram_add_data(sens_data *sdata);
void histogram_load_raster(uint8_t type);   //loads background raster for the histogram, type specifies if overview[1] or single[0]
void histogram_display_single(uint8_t datatype);   //displays the histogram with specified data (0: temperature, 1: humidity, 2: pressure)
void histogram_display_overview(void);
void string_temperature(int32_t temperature, char *string);
void string_humidity(uint32_t humidity, char *string);
void string_pressure(uint32_t pressure, char *string);
void get_scaling(uint8_t histogram_max_point);


#endif /* INC_TEMPINTF_H_ */
