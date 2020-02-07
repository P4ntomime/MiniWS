/*
 * UI.c
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#include "UI.h"

//extern Colors colors;

uint8_t UIlddone = 0;
sens_data sensdata[9];

void loadUI(struct bme280_dev *dev, struct bme280_data *comp_data)
{
//	if(!UIlddone)
//	{

		resetmeasurementtaken();

		uint8_t rslt;

		rslt = bme280_set_sensor_mode(BME280_FORCED_MODE, dev);
		/* Wait for the measurement to complete and print data @25Hz */
		dev->delay_ms(40);
		rslt = bme280_get_sensor_data(BME280_ALL, comp_data, dev);

		sensdata[0].measurement_taken = 1;
		sensdata[0].humidity = comp_data->humidity;
		sensdata[0].temperature = comp_data->temperature;
		sensdata[0].pressure = comp_data->pressure;

//		TempAtXY(comp_data->temperature, 	10,100,	colors.red, 	1, 	colors.black);
//		HumAtXY(comp_data->humidity, 		49, 80, colors.blue, 	1, 	colors.black);
//		PresAtXY(comp_data->pressure / 100,	60, 100, colors.green, 	1, 	colors.black);
		UIlddone = 1;
//	}
}

void refresh_measurements(void)
{

}
void refresh_graph(void)
{

}
void addmeasurementtostructarray(sens_data *sdata)
{

}

void resetmeasurementtaken(void)
{
	uint8_t Ctr = 0;

	for(Ctr = 0; Ctr < 9; Ctr++)
	{
		sensdata[Ctr].measurement_taken = 0;
	}
}
