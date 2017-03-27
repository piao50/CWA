//SPI5 for IMS
#define IMS_SPI						  SPI5
#define IMS_SPI_CLK 				  RCC_APB2Periph_SPI5
#define IMS_SPI_CLK_INIT              RCC_APB2PeriphClockCmd
#define IMS_SPI_IRQn                  SPI5_IRQn
#define IMS_SPI_IRQHANDLER            SPI5_IRQHandler

#define IMS_SPI_SCK_PIN               GPIO_Pin_7                  
#define IMS_SPI_SCK_GPIO_PORT         GPIOF                        
#define IMS_SPI_SCK_GPIO_CLK          RCC_AHB1Periph_GPIOF
#define IMS_SPI_SCK_SOURCE            GPIO_PinSource7
#define IMS_SPI_SCK_AF                GPIO_AF_SPI5

#define IMS_SPI_MISO_PIN              GPIO_Pin_8                  
#define IMS_SPI_MISO_GPIO_PORT        GPIOF                    
#define IMS_SPI_MISO_GPIO_CLK         RCC_AHB1Periph_GPIOF 
#define IMS_SPI_MISO_SOURCE           GPIO_PinSource8
#define IMS_SPI_MISO_AF               GPIO_AF_SPI5

#define IMS_SPI_MOSI_PIN              GPIO_Pin_9                    
#define IMS_SPI_MOSI_GPIO_PORT        GPIOF                         
#define IMS_SPI_MOSI_GPIO_CLK         RCC_AHB1Periph_GPIOF
#define IMS_SPI_MOSI_SOURCE           GPIO_PinSource9
#define IMS_SPI_MOSI_AF               GPIO_AF_SPI5

#define IMS_SPI_CS_PIN                GPIO_Pin_6                 
#define IMS_SPI_CS_GPIO_PORT          GPIOF                      
#define IMS_SPI_CS_GPIO_CLK           RCC_AHB1Periph_GPIOF
#define IMS_SPI_CS_SOURCE             GPIO_PinSource6

#define IMS_SPI_DMA                       DMA2
#define IMS_SPI_DMA_CLK                   RCC_AHB1Periph_DMA2
#define IMS_SPI_TX_DMA_CHANNEL            DMA_Channel_7
#define IMS_SPI_TX_DMA_STREAM             DMA2_Stream6
#define IMS_SPI_TX_DMA_FLAG_TCIF          DMA_FLAG_TCIF6
#define IMS_SPI_RX_DMA_CHANNEL            DMA_Channel_7
#define IMS_SPI_RX_DMA_STREAM             DMA2_Stream5
#define IMS_SPI_RX_DMA_FLAG_TCIF          DMA_FLAG_TCIF5

#define SPI5_RX_DMA_STREAM          DMA2_Stream3
#define SPI5_RX_DMA_CHANNEL         DMA_Channel_2
#define SPI5_RX_DMA_FLAG			DMA_FLAG_TCIF3
#define SPI5_RX_DMA_ALLFLAG			DMA_FLAG_TCIF3|DMA_FLAG_FEIF3|DMA_FLAG_DMEIF3|DMA_FLAG_TEIF3|DMA_FLAG_HTIF3
#define	SPI5_RX_ADDRESS             0x4001500C	
#define	SPI5_RX_DMA_IRQn			DMA2_Stream3_IRQn
#define SPI5_RX_DMA_IRQHandler		DMA2_Stream3_IRQHandler

#define SPI5_TX_DMA_STREAM          DMA2_Stream4
#define SPI5_TX_DMA_CHANNEL         DMA_Channel_2
#define SPI5_TX_DMA_FLAG			DMA_FLAG_TCIF4
#define SPI5_TX_DMA_ALLFLAG			DMA_FLAG_TCIF4|DMA_FLAG_FEIF4|DMA_FLAG_DMEIF4|DMA_FLAG_TEIF4|DMA_FLAG_HTIF4
#define	SPI5_TX_ADDRESS             0x4001500C	
#define	SPI5_TX_DMA_IRQn			DMA2_Stream4_IRQn
#define SPI5_TX_DMA_IRQHandler		DMA2_Stream4_IRQHandler

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


// SPI for YEHUO
#if defined (USE_YEHUO)
// SPI1 (NSS, SCK, MISO, MOSI) -> (PA4, PA5, PA6, PA7)
  #define SPIx                           SPI1
  #define SPIx_CLK                       RCC_APB2Periph_SPI1
  #define SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd
  #define SPIx_IRQn                      SPI1_IRQn
  #define SPIx_IRQHANDLER                SPI1_IRQHandler

  #define SPIx_SCK_PIN                   GPIO_Pin_5
  #define SPIx_SCK_GPIO_PORT             GPIOA
  #define SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
  #define SPIx_SCK_SOURCE                GPIO_PinSource5
  #define SPIx_SCK_AF                    GPIO_AF_SPI1

  #define SPIx_MISO_PIN                  GPIO_Pin_6
  #define SPIx_MISO_GPIO_PORT            GPIOA
  #define SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
  #define SPIx_MISO_SOURCE               GPIO_PinSource6
  #define SPIx_MISO_AF                   GPIO_AF_SPI1

  #define SPIx_MOSI_PIN                  GPIO_Pin_7
  #define SPIx_MOSI_GPIO_PORT            GPIOA
  #define SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
  #define SPIx_MOSI_SOURCE               GPIO_PinSource7
  #define SPIx_MOSI_AF                   GPIO_AF_SPI1
	
  #define SPIx_DMA                       DMA2
  #define SPIx_DMA_CLK                   RCC_AHB1Periph_DMA2
  #define SPIx_TX_DMA_CHANNEL            DMA_Channel_3
  #define SPIx_TX_DMA_STREAM             DMA2_Stream3
  #define SPIx_TX_DMA_FLAG_TCIF          DMA_FLAG_TCIF3
  #define SPIx_RX_DMA_CHANNEL            DMA_Channel_3
  #define SPIx_RX_DMA_STREAM             DMA2_Stream0
  #define SPIx_RX_DMA_FLAG_TCIF          DMA_FLAG_TCIF0
	
  #define SPIx_TX_DMA_IRQn               DMA2_Stream3_IRQn
  #define SPIx_TX_DMA_IRQHandler         DMA2_Stream3_IRQHandler
  #define SPIx_RX_DMA_IRQn               DMA2_Stream0_IRQn
  #define SPIx_RX_DMA_IRQHandler         DMA2_Stream0_IRQHandler	
	
	//SPI2 (NSS, SCK, MISO, MOSI) -> (PB12, PB13, PB14, PB15)
//  #define SPIy                           SPI2
//  #define SPIy_CLK                       RCC_APB1Periph_SPI2
//  #define SPIy_CLK_INIT                  RCC_APB1PeriphClockCmd
//  #define SPIy_IRQn                      SPI2_IRQn
//  #define SPIy_IRQHANDLER                SPI2_IRQHandler

//  #define SPIy_SCK_PIN                   GPIO_Pin_13
//  #define SPIy_SCK_GPIO_PORT             GPIOB
//  #define SPIy_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
//  #define SPIy_SCK_SOURCE                GPIO_PinSource13
//  #define SPIy_SCK_AF                    GPIO_AF_SPI2

//  #define SPIy_MISO_PIN                  GPIO_Pin_14
//  #define SPIy_MISO_GPIO_PORT            GPIOB
//  #define SPIy_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
//  #define SPIy_MISO_SOURCE               GPIO_PinSource14
//  #define SPIy_MISO_AF                   GPIO_AF_SPI2

//  #define SPIy_MOSI_PIN                  GPIO_Pin_15
//  #define SPIy_MOSI_GPIO_PORT            GPIOB
//  #define SPIy_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
//  #define SPIy_MOSI_SOURCE               GPIO_PinSource15
//  #define SPIy_MOSI_AF                   GPIO_AF_SPI2

// Communication Protocol
#define CMD_HELLO     "hello"
#define CMD_VALUE_xx1 "VALUE_xx1"
#define CMD_VALUE_xx2 "VALUE_xx2"
#define CMD_DATA      "DATA"
#define CMD_STATUS    "STATUS"
#define REPLY_SUCCESS "SUCCESS"
#define REPLY_FAIL    "FAIL"
#define SPLIT         ":"

#endif

void DMA2_Stream4_IRQHandler(void)
{
	
}

void DMA2_Stream5_IRQHandler(void)
{
		uint32_t index;
  /* Disable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,DISABLE); 
	DMA_Cmd(IMS_SPI_RX_DMA_STREAM,DISABLE);
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
  DMA_ClearFlag(IMS_SPI_TX_DMA_STREAM,IMS_SPI_TX_DMA_FLAG_TCIF);
  DMA_ClearFlag(IMS_SPI_RX_DMA_STREAM,IMS_SPI_RX_DMA_FLAG_TCIF); 
	
	/* Enable DMA SPI TX Stream */
  DMA_Cmd(IMS_SPI_TX_DMA_STREAM,ENABLE);
	DMA_Cmd(IMS_SPI_RX_DMA_STREAM,ENABLE);

  /* Enable SPI DMA TX Requsts */
  SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Tx, ENABLE);
	SPI_I2S_DMACmd(SPIx, SPI_I2S_DMAReq_Rx, ENABLE);
}
