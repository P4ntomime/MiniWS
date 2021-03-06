/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/

#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "bme280.h"
#include "gfx.h"
#include "ssd1351.h"
//#include "OLEDGFX.h"
#include "UI.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

#define UI_TEMP_STD 0
#define UI_HUM_STD  1
#define UI_PRES_STD 2
#define UI_OVERVIEW 3
#define UI_TEMP_ADV 4
#define UI_HUM_ADV  5
#define UI_PRES_ADV 6

#define TIME_LONGCLICK 300000

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN PV */

extern Colors colors;

int8_t rslt = BME280_OK;

struct bme280_dev dev;
struct bme280_data comp_data;

sens_data sdata_all = {0,0,0};

uint16_t datacounter = 595;
uint8_t datachanged = 0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void user_delay_ms(uint32_t period)
{
    /*
     * Return control or wait,
     * for a period amount of milliseconds
     */

   HAL_Delay(period);

}

int8_t user_spi_read(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */

   uint8_t TxDataBuff[1];
      TxDataBuff[0] = reg_addr;

    /*
     * The parameter dev_id can be used as a variable to select which Chip Select pin has
     * to be set low to activate the relevant device on the SPI bus
     */

    /*
     * Data on the bus should be like
     * |----------------+---------------------+-------------|
     * | MOSI           | MISO                | Chip Select |
     * |----------------+---------------------|-------------|
     * | (don't care)   | (don't care)        | HIGH        |
     * | (reg_addr)     | (don't care)        | LOW         |
     * | (don't care)   | (reg_data[0])       | LOW         |
     * | (....)         | (....)              | LOW         |
     * | (don't care)   | (reg_data[len - 1]) | LOW         |
     * | (don't care)   | (don't care)        | HIGH        |
     * |----------------+---------------------|-------------|
     */

   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

   HAL_SPI_Transmit(&hspi2, TxDataBuff, 1, 1000);
   HAL_SPI_Receive(&hspi2, reg_data, len, 1000);

   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

    return rslt;
}

int8_t user_spi_write(uint8_t dev_id, uint8_t reg_addr, uint8_t *reg_data, uint16_t len)
{
    int8_t rslt = 0; /* Return 0 for Success, non-zero for failure */
   uint16_t Ctr = 0;
    uint16_t Ctr2 = 0;
   uint8_t TxDataBuff[20];

    if(len < 11)
    {

        for(Ctr = 0; Ctr < len; Ctr++)
        {
            for(Ctr2 = 0; Ctr2 < 2; Ctr2++)
            {
                if(Ctr2 == 0)
                {
                    TxDataBuff[Ctr] = reg_addr++;
                }
                else
                {
                    TxDataBuff[Ctr + 1] = reg_data[Ctr];
                }
            }
        }
    }

    /*
     * The parameter dev_id can be used as a variable to select which Chip Select pin has
     * to be set low to activate the relevant device on the SPI bus
     */

    /*
     * Data on the bus should be like
     * |---------------------+--------------+-------------|
     * | MOSI                | MISO         | Chip Select |
     * |---------------------+--------------|-------------|
     * | (don't care)        | (don't care) | HIGH        |
     * | (reg_addr)          | (don't care) | LOW         |
     * | (reg_data[0])       | (don't care) | LOW         |
     * | (....)              | (....)       | LOW         |
     * | (reg_data[len - 1]) | (don't care) | LOW         |
     * | (don't care)        | (don't care) | HIGH        |
     * |---------------------+--------------|-------------|
     */

   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

   HAL_SPI_Transmit(&hspi2, TxDataBuff, 2 * len, 1000);

   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

    return rslt;
}

void pin_cs(uint8_t pinstate)
{
	HAL_GPIO_WritePin(GPIOA, OLED_CS, pinstate);
}

void pin_dc(uint8_t pinstate)
{
	HAL_GPIO_WritePin(GPIOA, OLED_DC, pinstate);
}

void pin_rs(uint8_t pinstate)
{
	HAL_GPIO_WritePin(GPIOA, OLED_RESET, pinstate);
}

void transmit_data(uint8_t *data, uint32_t len)
{
	HAL_SPI_Transmit(&hspi1, data, len, 1000);
}

void init_RTC(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_BKPEN | RCC_APB1ENR_PWREN;

    PWR->CR |= PWR_CR_DBP;

    RCC->BDCR |= RCC_BDCR_LSEON;

    while(!READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY));

    MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, RCC_BDCR_RTCSEL_LSE);

    RCC->BDCR |= RCC_BDCR_RTCEN;

    while(!READ_BIT(RTC->CRL, RTC_CRL_RSF));

    while(!READ_BIT(RTC->CRL, RTC_CRL_RTOFF));

    SET_BIT(RTC->CRH, RTC_CRH_SECIE);

    while(!READ_BIT(RTC->CRL, RTC_CRL_RTOFF));

    SET_BIT(RTC->CRL,RTC_CRL_CNF);

    RTC->PRLL=32767;
    RTC->PRLH=0;

    CLEAR_BIT(RTC->CRL,RTC_CRL_CNF);

    while(!READ_BIT(RTC->CRL, RTC_CRL_RTOFF));

    NVIC_EnableIRQ(RTC_IRQn);
}

void RTC_IRQHandler(void)
{
    CLEAR_BIT(RTC->CRL, RTC_CRL_SECF);

    rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, &dev);

    sdata_all.temperature = comp_data.temperature;
    sdata_all.humidity = comp_data.humidity;
    sdata_all.pressure = comp_data.pressure;

    if(datacounter++ == 599)
    {
        histogram_add_data(&sdata_all);
        datacounter = 0;
    }

    datachanged = 1;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */


	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	s_ssd1351 fnptrs_main;
//	struct bme280_dev dev;
//	struct bme280_data comp_data;
//	int8_t rslt = BME280_OK;
	uint8_t settings_sel;

	uint8_t ui_selected = UI_OVERVIEW;

	uint32_t touch_counter = 0;
	uint8_t last_touch_info = 0;

	uint8_t beenhere = 0;
	uint8_t laststate = 0xFF;

//	sens_data sdata_all = {0,0,0};

//	int32_t temperature = 0;
//	uint32_t humidity = 0;
//	uint32_t pressure = 0;

//	uint16_t datacounter = 0;
//	uint8_t datachanged = 0;

	/* Sensor_0 interface over SPI with native chip select line */
	dev.dev_id = 0;
	dev.intf = BME280_SPI_INTF;
	dev.read = user_spi_read;
	dev.write = user_spi_write;
	dev.delay_ms = user_delay_ms;

	fnptrs_main.pin_cs = pin_cs;
	fnptrs_main.pin_rs = pin_rs;
	fnptrs_main.pin_dc = pin_dc;
	fnptrs_main.transmit_data = transmit_data;
	fnptrs_main.delay = user_delay_ms;

	/* Recommended mode of operation: Indoor navigation */
	dev.settings.osr_h = BME280_OVERSAMPLING_1X;
	dev.settings.osr_p = BME280_OVERSAMPLING_16X;
	dev.settings.osr_t = BME280_OVERSAMPLING_2X;
	dev.settings.filter = BME280_FILTER_COEFF_16;
	dev.settings.standby_time = BME280_STANDBY_TIME_1000_MS;

	settings_sel = BME280_OSR_PRESS_SEL | BME280_OSR_TEMP_SEL | BME280_OSR_HUM_SEL | BME280_FILTER_SEL | BME280_STANDBY_SEL;

  /* USER CODE END Init */

  /* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	init_RTC();

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_SPI1_Init();
	MX_SPI2_Init();
	/* USER CODE BEGIN 2 */
	//	DisplayInit();
	init_oled(1,1, &fnptrs_main);
	//	BlankScreen(colors.blue);

	blankscreen(colors.black);

	rslt = bme280_init(&dev);

	//    rslt = stream_sensor_data_forced_mode(&dev);

	rslt = bme280_set_sensor_settings(settings_sel, &dev);
	rslt = bme280_set_sensor_mode(BME280_NORMAL_MODE, &dev);

	//TODO: implement timer interrupt for measuring (~1 second interrupt, save every 60th measurement for histograms) (may not be needed due to automatic periodic measuring on BME280)

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (42)
	{

	    switch(ui_selected)
	    {

	    case UI_TEMP_STD:

	        if((laststate != UI_TEMP_STD) || datachanged)
	        {

	            filled_rect_xy_ab(0,0,128,128,colors.black, 0);
                UI_display_temperature(sdata_all.temperature);

                datachanged = 0;

	        }
	        laststate = UI_TEMP_STD;
	        break;

	    case UI_HUM_STD:

	        if((laststate != UI_HUM_STD) || datachanged)
	        {
	            filled_rect_xy_ab(0,0,128,128,colors.black, 0);


                UI_display_humidity(sdata_all.humidity);

                datachanged = 0;

	        }
	        laststate = UI_HUM_STD;
	        break;

	    case UI_PRES_STD:

	        if((laststate != UI_PRES_STD) || datachanged)
	        {
	            filled_rect_xy_ab(0,0,128,128,colors.black, 0);

                UI_display_pressure(sdata_all.pressure);

                datachanged = 0;

	        }
	        laststate = UI_PRES_STD;
	        break;

	    case UI_OVERVIEW:

	        if((laststate != UI_OVERVIEW) || datachanged)
	        {

	            if((datacounter == 1) || (laststate != UI_OVERVIEW))
	                histogram_display_overview();

	            histogram_display_overhead(OH_OVW, &sdata_all);

                datachanged = 0;
	        }
	        laststate = UI_OVERVIEW;
	        break;

        case UI_TEMP_ADV:

            if((laststate != UI_TEMP_ADV) || datachanged)
            {
                if((datacounter == 1) || (laststate != UI_TEMP_ADV))
                    histogram_display_single(TEMPERATURE);


                histogram_display_overhead(TEMPERATURE, &sdata_all);
                datachanged = 0;

            }
            laststate = UI_TEMP_ADV;
            break;

        case UI_HUM_ADV:

            if((laststate != UI_HUM_ADV)  || datachanged)
            {
                if((datacounter == 1) || (laststate != UI_HUM_ADV))
                    histogram_display_single(HUMIDITY);

                histogram_display_overhead(HUMIDITY, &sdata_all);
                datachanged = 0;

            }
            laststate = UI_HUM_ADV;
            break;

        case UI_PRES_ADV:

            if((laststate != UI_PRES_ADV)  || datachanged)
            {
                if((datacounter == 1) || (laststate != UI_PRES_ADV))
                    histogram_display_single(PRESSURE);

                histogram_display_overhead(PRESSURE, &sdata_all);

                datachanged = 0;

            }
            laststate = UI_PRES_ADV;
            break;

	    default:

	        blankscreen(colors.white);

	        stringxy("DEFAULT",10, 60, colors.black, colors.yellow, 0, 1);
	        break;
	    }

	    if(HAL_GPIO_ReadPin(GPIOB, TOUCH_SNS_Pin) && (touch_counter < 0xFFFFFFFF))
	    {
	        touch_counter++;
	        last_touch_info = 1;
	    }
	    else
	    {
	        if((touch_counter < TIME_LONGCLICK) && !HAL_GPIO_ReadPin(GPIOB, TOUCH_SNS_Pin) && last_touch_info)
	        {
	            if(ui_selected < UI_OVERVIEW) ui_selected++;
	            else if(ui_selected == UI_OVERVIEW) ui_selected = UI_TEMP_STD;
	            touch_counter = 0;
	            last_touch_info = 0;
	        }
	        else if(touch_counter >= TIME_LONGCLICK && !HAL_GPIO_ReadPin(GPIOB, TOUCH_SNS_Pin) && last_touch_info)
	        {
	            if(ui_selected < UI_OVERVIEW)
	            {
	                ui_selected += 4;
	                touch_counter = 0;
	                last_touch_info = 0;
	            }
	            else if(ui_selected > UI_OVERVIEW)
	            {
	                ui_selected -= 4;
	                touch_counter = 0;
	                last_touch_info = 0;
	            }
	        }
	        touch_counter = 0;
	        last_touch_info = 0;
	    }

	/* USER CODE END WHILE */

	/* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV5;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_PLL2;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL2_ON;
  RCC_OscInitStruct.PLL2.PLL2MUL = RCC_PLL2_MUL8;
  RCC_OscInitStruct.PLL2.HSEPrediv2Value = RCC_HSE_PREDIV2_DIV5;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the Systick interrupt time 
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SPI1_RST_Pin|SPI1_DC_Pin|SPI1_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SPI1_RST_Pin SPI1_DC_Pin SPI1_CS_Pin */
  GPIO_InitStruct.Pin = SPI1_RST_Pin|SPI1_DC_Pin|SPI1_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_SNS_Pin */
  GPIO_InitStruct.Pin = TOUCH_SNS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TOUCH_SNS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_CS_Pin */
  GPIO_InitStruct.Pin = SPI2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI2_CS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
