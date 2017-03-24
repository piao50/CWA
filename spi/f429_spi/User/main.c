/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2015-xx-xx
  * @brief   用1.5.1版本库建的工程模板
  ******************************************************************************
  * @attention
  *
  * 实验平台:秉火  STM32 F429 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :http://firestm32.taobao.com
  *
  ******************************************************************************
  */
  
#include "stm32f4xx.h"
#include "main.h"
#include "spi.h"

uint8_t aTxBuffer[BUFFERSIZE] = {0};
__IO uint8_t aRxBuffer [BUFFERSIZE] = {0};
__IO uint8_t ubRxIndex = 0;
__IO uint8_t ubTxIndex = 0;
__IO uint32_t TimeOut = 0;

SPI_InitTypeDef  SPI_InitStructure;

__IO uint32_t index;

/* Private function prototypes -----------------------------------------------*/
static void SPI_Config(void);
static void SysTickConfig(void);
//static TestStatus Buffercmp(uint8_t* pBuffer1, __IO uint8_t* pBuffer2, uint16_t BufferLength);

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
	/*!< At this stage the microcontroller clock setting is already configured, 
		 this is done through SystemInit() function which is called from startup
		 files (startup_stm32f40_41xxx.s/startup_stm32f427_437xx.s/startup_stm32f429_439xx.s)
		 before to branch to application main.
	 */ 
  
  /* SPI configuration */
  SPI_Config();
  
  /* SysTick configuration */
  SysTickConfig();
  
#ifdef SPI_MASTER
  /* Master board configuration */    
  /* Initializes the SPI communication */
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_Init(IMS_SPI, &SPI_InitStructure);
  
  /* The Data transfer is performed in the SPI using Direct Memory Access */

  /* Enable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,ENABLE);

  /* Enable DMA SPI RX Stream */
  DMA_Cmd(IMS_SPI_RX_DMA_STREAM,ENABLE);

  /* Enable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Tx, ENABLE);

  /* Enable SPI DMA RX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Rx, ENABLE);
  
//  /* Configure the Tamper Button */
//  STM_EVAL_PBInit(BUTTON_TAMPER,BUTTON_MODE_GPIO);
//  
//  /* Wait until Tamper Button is pressed */
//  while (STM_EVAL_PBGetState(BUTTON_TAMPER));
  
  /* Enable the SPI peripheral */
  SPI_Cmd(IMS_SPI, ENABLE);
  
#endif /* SPI_MASTER */
  
#ifdef SPI_SLAVE	
  /* Slave board configuration */
  /* Initializes the SPI communication */
  SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
  SPI_Init(IMS_SPI, &SPI_InitStructure);

  /* Enable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,ENABLE);

  /* Enable DMA SPI RX Stream */
  DMA_Cmd(IMS_SPI_RX_DMA_STREAM,ENABLE);  
  
  /* Enable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Tx, ENABLE);

  /* Enable SPI DMA RX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Rx, ENABLE);

  /* Enable the SPI peripheral */
  SPI_Cmd(IMS_SPI, ENABLE);
 
#endif /* SPI_SLAVE */

//	while(1) {
////		/* Delay */
//		for (index = 0; index < 10000; index++);
//		SPI_I2S_SendData(IMS_SPI, 0x0A);
//	}

while(1)
{
	
  /* Waiting the end of Data transfer */
//  while (DMA_GetFlagStatus(IMS_SPI_TX_DMA_STREAM,IMS_SPI_TX_DMA_FLAG_TCIF)==RESET);
  while (DMA_GetFlagStatus(IMS_SPI_RX_DMA_STREAM,IMS_SPI_RX_DMA_FLAG_TCIF)==RESET);
	
	// Send Data
	{
		for(index = 0; index < BUFFERSIZE; index++)
			aTxBuffer[index] = 'a' + (index % 26);
		  /* Enable DMA SPI TX Stream */
		DMA_Cmd(IMS_SPI_TX_DMA_STREAM,DISABLE);
		//for (index = 0; index < 100; index++);
		/* Enable DMA SPI TX Stream */
		  DMA_ClearFlag(IMS_SPI_TX_DMA_STREAM,IMS_SPI_TX_DMA_FLAG_TCIF);
		DMA_Cmd(IMS_SPI_TX_DMA_STREAM,ENABLE);
		//for (index = 0; index < 10000; index++);
		while (DMA_GetFlagStatus(IMS_SPI_TX_DMA_STREAM,IMS_SPI_TX_DMA_FLAG_TCIF)==RESET);
	}
	
	
  
  /* Clear DMA Transfer Complete Flags */
  DMA_ClearFlag(IMS_SPI_TX_DMA_STREAM,IMS_SPI_TX_DMA_FLAG_TCIF);
  DMA_ClearFlag(IMS_SPI_RX_DMA_STREAM,IMS_SPI_RX_DMA_FLAG_TCIF);  
  
  /* Disable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,DISABLE);

  /* Disable DMA SPI RX Stream */
  DMA_Cmd(IMS_SPI_RX_DMA_STREAM,DISABLE);  
  
  /* Disable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Tx, DISABLE);

  /* Disable SPI DMA RX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Rx, DISABLE);

  /* Disable the SPI peripheral */
  SPI_Cmd(IMS_SPI, DISABLE);  
	
	
	for (index = 0; index < 10000; index++);
	/* Enable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,ENABLE);

  /* Enable DMA SPI RX Stream */
  DMA_Cmd(IMS_SPI_RX_DMA_STREAM,ENABLE);  
  
  /* Enable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Tx, ENABLE);

  /* Enable SPI DMA RX Requsts */
  SPI_I2S_DMACmd(IMS_SPI, SPI_I2S_DMAReq_Rx, ENABLE);

  /* Enable the SPI peripheral */
  SPI_Cmd(IMS_SPI, ENABLE);
}
	
	while(1);

}

/**
  * @brief  Configures the SPI Peripheral.
  * @param  None
  * @retval None
  */
static void SPI_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  DMA_InitTypeDef DMA_InitStructure;

  /* Peripheral Clock Enable -------------------------------------------------*/
  /* Enable the SPI clock */
  IMS_SPI_CLK_INIT(IMS_SPI_CLK, ENABLE);
  
  /* Enable GPIO clocks */
  RCC_AHB1PeriphClockCmd(IMS_SPI_SCK_GPIO_CLK | IMS_SPI_MISO_GPIO_CLK | IMS_SPI_MOSI_GPIO_CLK, ENABLE);
  
  /* Enable DMA clock */
  RCC_AHB1PeriphClockCmd(IMS_SPI_DMA_CLK, ENABLE);

  /* SPI GPIO Configuration --------------------------------------------------*/
  /* GPIO Deinitialisation */
  GPIO_DeInit(IMS_SPI_SCK_GPIO_PORT);
  GPIO_DeInit(IMS_SPI_MISO_GPIO_PORT);
  GPIO_DeInit(IMS_SPI_MOSI_GPIO_PORT);
  
  /* Connect SPI pins to AF5 */  
  GPIO_PinAFConfig(IMS_SPI_SCK_GPIO_PORT, IMS_SPI_SCK_SOURCE, IMS_SPI_SCK_AF);
  GPIO_PinAFConfig(IMS_SPI_MISO_GPIO_PORT, IMS_SPI_MISO_SOURCE, IMS_SPI_MISO_AF);    
  GPIO_PinAFConfig(IMS_SPI_MOSI_GPIO_PORT, IMS_SPI_MOSI_SOURCE, IMS_SPI_MOSI_AF);

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;

  /* SPI SCK pin configuration */
  GPIO_InitStructure.GPIO_Pin = IMS_SPI_SCK_PIN;
  GPIO_Init(IMS_SPI_SCK_GPIO_PORT, &GPIO_InitStructure);
  
  /* SPI  MISO pin configuration */
  GPIO_InitStructure.GPIO_Pin =  IMS_SPI_MISO_PIN;
  GPIO_Init(IMS_SPI_MISO_GPIO_PORT, &GPIO_InitStructure);  

  /* SPI  MOSI pin configuration */
  GPIO_InitStructure.GPIO_Pin =  IMS_SPI_MOSI_PIN;
  GPIO_Init(IMS_SPI_MOSI_GPIO_PORT, &GPIO_InitStructure);
 
  /* SPI configuration -------------------------------------------------------*/
  SPI_I2S_DeInit(IMS_SPI);
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  
  /* DMA configuration -------------------------------------------------------*/
  /* Deinitialize DMA Streams */
  DMA_DeInit(IMS_SPI_TX_DMA_STREAM);
  DMA_DeInit(IMS_SPI_RX_DMA_STREAM);
  
  /* Configure DMA Initialization Structure */
  DMA_InitStructure.DMA_BufferSize = BUFFERSIZE ;
  DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable ;
  DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_1QuarterFull ;
  DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single ;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_PeripheralBaseAddr =(uint32_t) (&(IMS_SPI->DR)) ;
  DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_Priority = DMA_Priority_High;
  /* Configure TX DMA */
  DMA_InitStructure.DMA_Channel = IMS_SPI_TX_DMA_CHANNEL ;
  DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral ;
  DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)aTxBuffer ;
  DMA_Init(IMS_SPI_TX_DMA_STREAM, &DMA_InitStructure);
  /* Configure RX DMA */
  DMA_InitStructure.DMA_Channel = IMS_SPI_RX_DMA_CHANNEL ;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory ;
  DMA_InitStructure.DMA_Memory0BaseAddr =(uint32_t)aRxBuffer ; 
  DMA_Init(IMS_SPI_RX_DMA_STREAM, &DMA_InitStructure);
}

/**
  * @brief  Configure a SysTick Base time to 10 ms.
  * @param  None
  * @retval None
  */
static void SysTickConfig(void)
{
  /* Setup SysTick Timer for 10ms interrupts  */
  if (SysTick_Config(SystemCoreClock / 100))
  {
    /* Capture error */
    while (1);
  }

  /* Configure the SysTick handler priority */
  NVIC_SetPriority(SysTick_IRQn, 0x0);
}

/*********************************************END OF FILE**********************/

