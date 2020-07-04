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

struct scaling{
    double temperature;
    uint8_t offset_temp;
    double pressure;
    uint8_t offset_pres;
    double humidity;
    uint8_t offset_hum;
}scaling;

void histogram_load_raster(uint8_t type)
{

//    blankscreen(colors.black);


    switch(type)
    {

    case SINGLE:

        filled_rect_xy_ab(0,0,128,101,colors.black, 0);

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

        filled_rect_xy_ab(0,0,128,84,colors.black, 0);

        line_from_to(0, 83, 127, 83, colors.gray, 0);
        line_from_to(15, 0, 15, 83, colors.gray, 0);
        line_from_to(31, 0, 31, 83, colors.gray, 0);
        line_from_to(47, 0, 47, 83, colors.gray, 0);
        line_from_to(63, 0, 63, 83, colors.gray, 0);
        line_from_to(79, 0, 79, 83, colors.gray, 0);
        line_from_to(95, 0, 95, 83, colors.gray, 0);
        line_from_to(111, 0, 111, 83, colors.gray, 1);
        break;

    default:

        break;
    }
}

void UI_display_temperature(int32_t temperature)
{

    uint16_t ctr = 0;
    uint8_t xpos = 7;

    uint8_t tmp = 0;

    if(temperature < 0)
    {
        filled_rect_xy_ab(0, 65, 12, 5, colors.green, 0);
        xpos += 5;
        temperature = temperature * -1;
    }

    for(ctr = 1000; ctr > 1; ctr = ctr / 10)
    {
        tmp = temperature / ctr %10;
        if(!((ctr == 1000) && (tmp == 0)))
        {
            switch(tmp)
            {
            case 0: bignumxy(0, xpos, 97, colors.green, colors.black, 1,0); break;
            case 1: bignumxy(1, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 2: bignumxy(2, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 3: bignumxy(3, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 4: bignumxy(4, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 5: bignumxy(5, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 6: bignumxy(6, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 7: bignumxy(7, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 8: bignumxy(8, xpos, 97, colors.green, colors.black, 1,0);; break;
            case 9: bignumxy(9, xpos, 97, colors.green, colors.black, 1,0);; break;

            default:

                break;
            }
        xpos += 33;
        }

        if(ctr == 100)
        {
            filled_rect_xy_ab(xpos + 1, 46, 9, 9, colors.green, 0);
            filled_rect_xy_ab(xpos + 1, 38, 2, 4, colors.green, 0);
            filled_rect_xy_ab(xpos + 2, 39, 3, 5, colors.green, 0);
            filled_rect_xy_ab(xpos + 3, 40, 3, 5, colors.green, 0);
            filled_rect_xy_ab(xpos + 4, 41, 3, 4, colors.green, 0);
            filled_rect_xy_ab(xpos + 5, 42, 3, 3, colors.green, 0);
            filled_rect_xy_ab(xpos + 8, 43, 1, 3, colors.green, 0);
            filled_rect_xy_ab(xpos + 1, 45, 7, 1, colors.green, 0);
            xpos += 11;
        }
    }

    symbol_std_temperature(47, 30, colors.green, colors.black, 0);

    send_full_screen();
}
void UI_display_humidity(uint32_t humidity)
{
    uint16_t ctr = 0;
    uint8_t xpos = 7;

    uint8_t tmp = 0;

    humidity = (uint32_t)((float)humidity * 1000) / 1024;

    for(ctr = 10000; ctr > 10; ctr = ctr / 10)
    {
        tmp = humidity / ctr %10;
        if(!((ctr == 10000) && (tmp == 0)))
        {
            switch(tmp)
            {
            case 0: bignumxy(0, xpos, 97, colors.blue, colors.black, 1,0); break;
            case 1: bignumxy(1, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 2: bignumxy(2, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 3: bignumxy(3, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 4: bignumxy(4, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 5: bignumxy(5, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 6: bignumxy(6, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 7: bignumxy(7, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 8: bignumxy(8, xpos, 97, colors.blue, colors.black, 1,0);; break;
            case 9: bignumxy(9, xpos, 97, colors.blue, colors.black, 1,0);; break;

            default:

                break;
            }
        xpos += 33;
        }

        if(ctr == 1000)
        {
            filled_rect_xy_ab(xpos + 1, 46, 9, 9, colors.blue, 0);
            filled_rect_xy_ab(xpos + 1, 38, 2, 4, colors.blue, 0);
            filled_rect_xy_ab(xpos + 2, 39, 3, 5, colors.blue, 0);
            filled_rect_xy_ab(xpos + 3, 40, 3, 5, colors.blue, 0);
            filled_rect_xy_ab(xpos + 4, 41, 3, 4, colors.blue, 0);
            filled_rect_xy_ab(xpos + 5, 42, 3, 3, colors.blue, 0);
            filled_rect_xy_ab(xpos + 8, 43, 1, 3, colors.blue, 0);
            filled_rect_xy_ab(xpos + 1, 45, 7, 1, colors.blue, 0);
            xpos += 11;
        }
    }

    symbol_std_humidity(36, 30, colors.blue, colors.black, 0);

    send_full_screen();
}
void UI_display_pressure(uint32_t pressure)
{
    uint16_t ctr = 0;
    uint8_t xpos = 7;

    uint8_t tmp = 0;

    pressure = pressure / 10;

    for(ctr = 10000; ctr > 1; ctr = ctr / 10)
    {
        tmp = pressure / ctr %10;
        if(!((ctr == 10000) && (tmp == 0)))
        {
            switch(tmp)
            {
            case 0: bignumxy(0, xpos, 97, colors.red, colors.black, 1,0); break;
            case 1: bignumxy(1, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 2: bignumxy(2, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 3: bignumxy(3, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 4: bignumxy(4, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 5: bignumxy(5, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 6: bignumxy(6, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 7: bignumxy(7, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 8: bignumxy(8, xpos, 97, colors.red, colors.black, 1,0);; break;
            case 9: bignumxy(9, xpos, 97, colors.red, colors.black, 1,0);; break;

            default:

                break;
            }
            xpos += 33;
        }


        if(ctr == 100)
        {
            filled_rect_xy_ab(xpos + 1, 46, 9, 9, colors.red, 0);
            filled_rect_xy_ab(xpos + 1, 38, 2, 4, colors.red, 0);
            filled_rect_xy_ab(xpos + 2, 39, 3, 5, colors.red, 0);
            filled_rect_xy_ab(xpos + 3, 40, 3, 5, colors.red, 0);
            filled_rect_xy_ab(xpos + 4, 41, 3, 4, colors.red, 0);
            filled_rect_xy_ab(xpos + 5, 42, 3, 3, colors.red, 0);
            filled_rect_xy_ab(xpos + 8, 43, 1, 3, colors.red, 0);
            filled_rect_xy_ab(xpos + 1, 45, 7, 1, colors.red, 0);
            xpos += 11;
        }
    }

    symbol_std_pressure(39, 30, colors.red, colors.black, 0);

    send_full_screen();
}

void histogram_display_overhead(uint8_t type, sens_data *sdata)
{
    int32_t temperature = 0;
    uint32_t humidity = 0;
    uint32_t pressure = 0;

    char string0[10];
    char string1[30];
    char string2[30];

    switch(type)
    {
    case OH_TEMP:

        temperature = sdata->temperature;

        if(temperature < 0)
        {
            string_temperature(temperature, string0);

            filled_rect_xy_ab(0,101,127,26,colors.black,0);

            line_from_to(38, 112, 43, 112, colors.green, 0);

            stringxy(string0, 45, 105, colors.green, colors.black, 1,1);
        }
        else
        {
            string_temperature(temperature, string0);

            filled_rect_xy_ab(0,101,127,26,colors.black,0);

            stringxy(string0, 45, 105, colors.green, colors.black, 1,1);
        }
        break;

    case OH_HUM:

        humidity = sdata->humidity;

        string_humidity(humidity, string1);

        filled_rect_xy_ab(0,101,127,26,colors.black,0);

        stringxy(string1, 40, 105, colors.blue, colors.black, 1,1);

        break;

    case OH_PRES:

        pressure = sdata->pressure;

        string_pressure(pressure, string2);

        filled_rect_xy_ab(0,101,127,26,colors.black,0);

        stringxy(string2, 40, 105, colors.red, colors.black, 1,1);

        break;

    case OH_OVW:

        temperature = sdata->temperature;
        humidity = sdata->humidity;
        pressure = sdata->pressure;

        string_temperature(temperature, string0);
        string_humidity(humidity, string1);
        string_pressure(pressure, string2);

        filled_rect_xy_ab(0,84,127,43,colors.black,0);

        stringxy(string0, 4, 105, colors.green, colors.black, 1,0);
        stringxy(string1, 70, 105, colors.blue, colors.black, 1,0);
        stringxy(string2, 38, 87, colors.red, colors.black, 1,0);

        send_full_screen();
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

//    get_scaling(101);     //will be used in future for adaptive scaling

    switch(datatype)
    {

    case TEMPERATURE:

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,(sensdata[ctr].temperature - 1500) * TEMP_FACTOR,offset + 15, (sensdata[ctr - 1].temperature - 1500) * TEMP_FACTOR, colors.green, 0);

            offset += 16;
        }

        send_full_screen();

        break;

    case HUMIDITY:

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,(sensdata[ctr].humidity - 30720) * HUM_FACTOR,offset + 15, (sensdata[ctr - 1].humidity - 30720) * HUM_FACTOR, colors.blue, 0);

            offset += 16;
        }

        send_full_screen();

        break;

    case PRESSURE:

        for(ctr = 8; ctr > 0; ctr--)
        {
            if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))  //check for first few (empty) datapoints
            line_from_to(offset,(sensdata[ctr].pressure - 80000) * PRES_FACTOR,offset + 15, (sensdata[ctr - 1].pressure - 80000) * PRES_FACTOR, colors.red, 0);

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

    uint8_t ctr = 0;

    uint8_t offset = 0;

    histogram_load_raster(OVERVIEW);

//    get_scaling(84);     //will be used in future for adaptive scaling

    for(ctr = 8; ctr > 0; ctr--)
    {
        if((sensdata[ctr].pressure != 0) && (sensdata[ctr - 1].pressure != 0))
        {
            line_from_to(offset,(sensdata[ctr].temperature - 1500) * TEMP_FACTOR,offset + 15, (sensdata[ctr - 1].temperature - 1500) * TEMP_FACTOR, colors.green, 0);
            line_from_to(offset,(sensdata[ctr].humidity - 30720) * HUM_FACTOR,offset + 15, (sensdata[ctr - 1].humidity - 30720) * HUM_FACTOR, colors.blue, 0);
            line_from_to(offset,(sensdata[ctr].pressure - 80000) * PRES_FACTOR,offset + 15, (sensdata[ctr - 1].pressure - 80000) * PRES_FACTOR, colors.red, 0);
        }

        offset += 16;
    }

    send_full_screen();
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

    uint16_t ctr = 0;
    uint8_t strctr = 0;

    humidity = (uint32_t)((float)humidity * 1000) / 1024;   //convert format humidity * 1024 to humidity * 1000

    for(ctr = 10000; ctr > 10; ctr = ctr / 10)
    {
        switch(humidity / ctr %10)
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

        if((ctr == 10000) && (string[0] == '0'))
        {
            strctr = 0;
        }
        if(ctr == 1000)
        {
            string[strctr++] = '.';
        }
    }

    string[strctr++] = '%';
    string[strctr++] = 'r';
    string[strctr++] = 'H';
    string[strctr++] = 0;

}

void string_pressure(uint32_t pressure, char *string)
{

    uint16_t ctr = 0;
    uint8_t strctr = 0;

    pressure = pressure / 10;  //pascal to kilopascal conversion

    for(ctr = 10000; ctr > 1; ctr = ctr / 10)
        {
            switch(pressure / ctr %10)
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

            if((ctr == 10000) && (string[0] == '0'))
            {
                strctr = 0;
            }
            if(ctr == 100)
            {
                string[strctr++] = '.';
            }
        }

        string[strctr++] = 'k';
        string[strctr++] = 'P';
        string[strctr++] = 'a';
        string[strctr++] = 0;
}

void get_scaling(uint8_t histogram_max_point)
{
    int32_t temp_max = 0;
    int32_t temp_min = 0;

    uint32_t hum_max = 0;
    uint32_t hum_min = 0;

    uint32_t pres_max = 0;
    uint32_t pres_min = 0;

    uint8_t ctr = 0;

    for (ctr = 1; ctr < 9; ctr++)
    {
        if(sensdata[ctr].temperature > sensdata[ctr - 1].temperature)
        {
            temp_max = sensdata[ctr].temperature;
        }

        if(sensdata[ctr].temperature < sensdata[ctr - 1].temperature)
        {
            temp_min = sensdata[ctr].temperature;
        }


        if(sensdata[ctr].humidity > sensdata[ctr - 1].humidity)
        {
            hum_max = sensdata[ctr].humidity;
        }

        if(sensdata[ctr].humidity < sensdata[ctr - 1].humidity)
        {
            hum_min = sensdata[ctr].humidity;
        }


        if(sensdata[ctr].pressure > sensdata[ctr - 1].pressure)
        {
            pres_max = sensdata[ctr].pressure;
        }

        if(sensdata[ctr].pressure < sensdata[ctr - 1].pressure)
        {
            pres_min = sensdata[ctr].pressure;
        }
    }

    if(!((pres_max == 0) || (pres_min == 0)))
    {

        scaling.offset_temp = 10*((temp_min / 1000) - 1);

        scaling.temperature = histogram_max_point / (10*((temp_max / 1000) + 1)) - scaling.offset_temp;

        scaling.offset_hum = 10*((hum_min / 10240) - 1);

        if(scaling.offset_hum < 0) scaling.offset_hum = 0;

        scaling.humidity = histogram_max_point / 10*((hum_max / 10240) + 1) - scaling.offset_hum;

        scaling.offset_pres = 10*(pres_min / 100000) - 1;

        if(scaling.offset_pres < 0) scaling.offset_pres = 0;

        scaling.pressure = histogram_max_point / (10*((pres_max / 100000) + 1)) - scaling.offset_pres;
    }
}
