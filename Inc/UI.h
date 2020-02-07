/*
 * UI.h
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#ifndef INC_UI_H_
#define INC_UI_H_

//#include "OLEDGFX.h"
#include "bme280.h"
#include "main.h"

typedef struct sdata
{
	int32_t temperature;
	uint32_t humidity;
	uint32_t pressure;
	uint8_t measurement_taken;
}sens_data;

void loadUI(struct bme280_dev *dev, struct bme280_data *comp_data);
void refresh_measurements(void);
void refresh_graph(void);
void addmeasurementtostructarray(sens_data *sdata);
void resetmeasurementtaken(void);


#endif /* INC_TEMPINTF_H_ */
