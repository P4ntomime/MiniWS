/*
 * UI.c
 *
 *  Created on: 22.12.2019
 *      Author: Laurin
 */

#include "UI.h"

extern Colors colors;

//TODO: implement seven different UIs (Overview UI with all histograms on one and all data on one, temperature UI with big font temperature -> temperature histogram, same as degree but with humidity and pressure)
//TODO: switch UIs with Tap-Button (short-tap for general switch(temperature to humidity to pressure to overview), long-tap for histogram of current UI (no switch for overview, though maybe implement easteregg))

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

//		sensdata[0].measurement_taken = 1;
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

void histogram_load_raster(uint8_t type)
{

//    blankscreen(colors.black);

    filled_rect_xy_ab(0,0,127,101,colors.black, 0);

    switch(type)
    {

    case SINGLE:

        line_from_to(0, 100, 127, 100, colors.gray, 0);
        line_from_to(15, 0, 15, 100, colors.gray, 0);
        line_from_to(31, 0, 31, 100, colors.gray, 0);
        line_from_to(47, 0, 47, 100, colors.gray, 0);
        line_from_to(63, 0, 63, 100, colors.gray, 0);
        line_from_to(79, 0, 79, 100, colors.gray, 0);
        line_from_to(95, 0, 95, 100, colors.gray, 0);
        line_from_to(111, 0, 111, 100, colors.gray, 1);
        break;

    case OVERVIEW:

        line_from_to(0, 68, 127, 68, colors.gray, 0);
        line_from_to(15, 0, 15, 68, colors.gray, 0);
        line_from_to(31, 0, 31, 68, colors.gray, 0);
        line_from_to(47, 0, 47, 68, colors.gray, 0);
        line_from_to(63, 0, 63, 68, colors.gray, 0);
        line_from_to(79, 0, 79, 68, colors.gray, 0);
        line_from_to(95, 0, 95, 68, colors.gray, 0);
        line_from_to(111, 0, 111, 68, colors.gray, 1);
        break;

    default:

        break;
    }
}

void UI_display_temperature(int32_t temperature)
{

}
void UI_display_humidity(uint32_t humidity)
{

}
void UI_display_pressure(uint32_t pressure)
{

}

void histogram_display_overhead(uint8_t type, sens_data *sdata)
{
    int32_t temperature = 0;
    uint32_t humidity = 0;
    uint32_t pressure = 0;

    char string0[10];
//    char string1[10];
//    char string2[10];

    switch(type)
    {
    case OH_TEMP:

        temperature = sdata->temperature;

        if(temperature < 0)
        {
            string_temperature(temperature, string0);

            filled_rect_xy_ab(0,101,127,26,colors.black,0);

            line_from_to(38, 112, 43, 112, colors.green, 0);

            stringxy(string0, 45, 105, colors.green, colors.black, 1);
        }
        else
        {
            string_temperature(temperature, string0);

            filled_rect_xy_ab(0,101,127,26,colors.black,0);

            stringxy(string0, 45, 105, colors.green, colors.black, 1);
        }
        break;

    case OH_HUM:

        break;

    case OH_PRES:

        break;

    case OH_OVW:

        break;

    default:

        break;
    }
}

void histogram_add_data(sens_data *sdata)
{
    for(int8_t ctr = 7; ctr >= 0; ctr--)
    {
        sensdata[ctr + 1] = sensdata[ctr];  //shift the whole array
    }
    sensdata[0] = *sdata;   //add latest measurement to array
}

void histogram_display_single(uint8_t datatype)
{

    uint8_t ctr = 0;
    uint8_t offset = 0;

    histogram_load_raster(SINGLE);

    switch(datatype)
    {

    case TEMPERATURE:

        //TODO: show current temperature above

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,sensdata[ctr].temperature * TEMP_FACTOR,offset + 15, sensdata[ctr - 1].temperature * TEMP_FACTOR, colors.green, 0);

            offset += 16;
        }

        send_full_screen();

        break;

    case HUMIDITY:

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,sensdata[ctr].humidity * HUM_FACTOR,offset + 15, sensdata[ctr - 1].humidity * HUM_FACTOR, colors.blue, 0);

            offset += 16;
        }

        send_full_screen();

        break;

    case PRESSURE:

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,sensdata[ctr].pressure * PRES_FACTOR,offset + 15, sensdata[ctr - 1].pressure * PRES_FACTOR, colors.red, 0);

            offset += 16;
        }

        send_full_screen();

        break;

    default:

        break;
    }
}

void histogram_display_overview(void)
{

    histogram_load_raster(OVERVIEW);
}

void string_temperature(int32_t temperature, char *string)
{
    uint16_t ctr = 0;
    uint8_t strctr = 0;

//    if(temperature < 0)
//    {
//
//    }
//    else
//    {
        for(ctr = 1000; ctr > 1; ctr = ctr / 10)
        {
            switch(temperature / ctr %10)
            {
            case 0: string[strctr] = '0'; break;
            case 1: string[strctr] = '1'; break;
            case 2: string[strctr] = '2'; break;
            case 3: string[strctr] = '3'; break;
            case 4: string[strctr] = '4'; break;
            case 5: string[strctr] = '5'; break;
            case 6: string[strctr] = '6'; break;
            case 7: string[strctr] = '7'; break;
            case 8: string[strctr] = '8'; break;
            case 9: string[strctr] = '9'; break;

            default:

                break;
            }
            strctr++;

            if((ctr == 1000) && (string[0] == '0'))
            {
                strctr = 0;
            }
            if(ctr == 100)
            {
                string[strctr++] = '.';
            }
        }
        string[strctr++] = '*';
        string[strctr++] = 'C';
        string[strctr] = 0;

//    }
}

void string_humidity(uint32_t humidity, char *string)
{

}

void string_pressure(uint32_t pressure, char *string)
{

}

void resetmeasurementtaken(void)
{
	uint8_t Ctr = 0;

	for(Ctr = 0; Ctr < 9; Ctr++)
	{
//		sensdata[Ctr].measurement_taken = 0;
	}
}
