/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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
#include "lcd.h"
#include <stdbool.h>

bool col1,col2,col3,col4;

void key(void);

Lcd_PortType ports[] = {GPIOA,GPIOA,GPIOA,GPIOA};
Lcd_PinType pins[] = {GPIO_PIN_3,GPIO_PIN_2,GPIO_PIN_1,GPIO_PIN_0};
Lcd_HandleTypeDef lcd;


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
	  key();
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

//void key() {
//    // Declare variables if not global
//    lcd = Lcd_create(ports, pins, GPIOB, GPIO_PIN_0, GPIOB, GPIO_PIN_1, LCD_4_BIT_MODE);
//
//    for (int row = 0; row < 4; row++) {
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, (row == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, (row == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, (row == 2) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, (row == 3) ? GPIO_PIN_RESET : GPIO_PIN_SET);
//
//        // Read columns
//        col1 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4);
//        col2 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);
//        col3 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);
//        col4 = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7);
//
//        // Move cursor
//        Lcd_cursor(&lcd, row, 1);
//
//        // Key mapping
//        if (!col1) Lcd_string(&lcd, (row == 0) ? "Key 7\n" : (row == 1) ? "Key 4\n" : (row == 2) ? "Key 1\n" : "Key ON/C\n");
//        else if (!col2) Lcd_string(&lcd, (row == 0) ? "Key 8\n" : (row == 1) ? "Key 5\n" : (row == 2) ? "Key 2\n" : "Key 0\n");
//        else if (!col3) Lcd_string(&lcd, (row == 0) ? "Key 9\n" : (row == 1) ? "Key 6\n" : (row == 2) ? "Key 3\n" : "Key =\n");
//        else if (!col4) Lcd_string(&lcd, (row == 0) ? "Key %\n" : (row == 1) ? "Key x\n" : (row == 2) ? "Key -\n" : "Key +\n");
//
//        HAL_Delay(200);  // Reduce delay
//    }
//}

void key(){
	lcd=Lcd_create(ports,pins,GPIOB,GPIO_PIN_0,GPIOB,GPIO_PIN_1,LCD_4_BIT_MODE);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

	col1=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4);
	col2=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5);
	col3=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6);
	col4=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7);
	Lcd_cursor(&lcd,0,1);

	if(!col1){
		Lcd_string(&lcd,"Key 7\n");
		HAL_Delay(1000);
	}else if(!col2){
		Lcd_string(&lcd,"Key 8\n");
		HAL_Delay(1000);
	}else if(!col3){
		Lcd_string(&lcd,"Key 9\n");
		HAL_Delay(1000);
	}else if(!col4){
		Lcd_string(&lcd,"Key % \n");
		HAL_Delay(1000);
	}

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

	col1=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4);
	col2=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5);
	col3=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6);
	col4=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7);
	Lcd_cursor(&lcd,0,1);

	if(!col1){
		Lcd_string(&lcd,"Key 4\n");
		HAL_Delay(1000);
	}else if(!col2){
		Lcd_string(&lcd,"Key 5\n");
		HAL_Delay(1000);
	}else if(!col3){
		Lcd_string(&lcd,"Key 6\n");
		HAL_Delay(1000);
	}else if(!col4){
		Lcd_string(&lcd,"Key x \n");
		HAL_Delay(1000);
	}

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);

	col1=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4);
	col2=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5);
	col3=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6);
	col4=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7);
	Lcd_cursor(&lcd,0,1);

	if(!col1){
		Lcd_string(&lcd,"Key 1\n");
		HAL_Delay(1000);
	}else if(!col2){
		Lcd_string(&lcd,"Key 2\n");
		HAL_Delay(1000);
	}else if(!col3){
		Lcd_string(&lcd,"Key 3\n");
		HAL_Delay(1000);
	}else if(!col4){
		Lcd_string(&lcd,"Key - \n");
		HAL_Delay(1000);
	}

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);

	col1=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4);
	col2=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5);
	col3=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6);
	col4=HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7);
	Lcd_cursor(&lcd,0,1);

	if(!col1){
		Lcd_string(&lcd,"Key ON/C \n");
		HAL_Delay(1000);
	}else if(!col2){
		Lcd_string(&lcd,"Key 0\n");
		HAL_Delay(1000);
	}else if(!col3){
		Lcd_string(&lcd,"Key =\n");
		HAL_Delay(1000);
	}else if(!col4){
		Lcd_string(&lcd,"Key + \n");
		HAL_Delay(1000);
	}
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
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
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PC4 PC5 PC6 PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
