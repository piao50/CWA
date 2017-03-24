/**
  ******************************************************************************
  * @file    FMC_SDRAM/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    11-November-2013
  * @brief   Main Interrupt Service Routines.
  *         This file provides template for all exceptions handler and
  *         peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#ifndef USE_YEHUO
#define USE_YEHUO
#endif
#include "spi.h"

extern __IO uint8_t aTxBuffer[];
extern __IO uint8_t aRxBuffer[];

/** @addtogroup STM32F429I_DISCOVERY_Examples
  * @{
  */

/** @addtogroup FMC_SDRAM
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {}
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{}

/**
  * @brief  This function handles PendSV_Handler exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f429_439xx.s).                         */
/******************************************************************************/
	
typedef enum {FAILED = 0, PASSED = !FAILED} TestStatus;
static TestStatus Buffercmp(uint8_t* pBuffer1, __IO uint8_t* pBuffer2, uint16_t BufferLength)
{
  while (BufferLength--)
  {
    if (*pBuffer1 != *pBuffer2)
    {
      return FAILED;
    }
    pBuffer1++;
    pBuffer2++;
  }

  return PASSED;
}	
	
void DMA2_Stream3_IRQHandler(void)
{
}

void DMA2_Stream0_IRQHandler(void)
{
	uint32_t index;
  /* Disable DMA SPI TX Stream */
  DMA_Cmd(SPIx_TX_DMA_STREAM,DISABLE); 
	DMA_Cmd(SPIx_RX_DMA_STREAM,DISABLE);
  /* Disable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Tx, DISABLE);
	SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Rx, DISABLE);

	memset(aTxBuffer, 0, BUFFERSIZE);
	
	if(Buffercmp(CMD_HELLO, aRxBuffer, strlen(CMD_HELLO)) == PASSED)
	{
		for(index = 0; index < strlen(CMD_HELLO); index++)
			aTxBuffer[index] = aRxBuffer[index];
	}
  if(Buffercmp(CMD_VALUE_xx1, aRxBuffer, strlen(CMD_VALUE_xx1)) == PASSED)
	{
		for(index = 0; index < strlen(CMD_VALUE_xx1); index++)
			aTxBuffer[index] = aRxBuffer[index];
		aTxBuffer[index++] = ':';
		sprintf((aTxBuffer+index), "%f", 88.9f);
	}

//	for(index = 0; index < BUFFERSIZE; index++)
//		aTxBuffer[index] = 'A' + (index % 26);
	
 /* Clear DMA Transfer Complete Flags */
  DMA_ClearFlag(SPIx_TX_DMA_STREAM,SPIx_TX_DMA_FLAG_TCIF);
  DMA_ClearFlag(SPIx_RX_DMA_STREAM,SPIx_RX_DMA_FLAG_TCIF); 
	
	/* Enable DMA SPI TX Stream */
  DMA_Cmd(SPIx_TX_DMA_STREAM,ENABLE);
	DMA_Cmd(SPIx_RX_DMA_STREAM,ENABLE);

  /* Enable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Tx, ENABLE);
	SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Rx, ENABLE);
}

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
