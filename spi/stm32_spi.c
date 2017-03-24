//SPI5 for IMS
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

#define IMS_SPI                       SPI5
#define IMS_SPI_CLK                   RCC_APB2Periph_SPI5

	//SPI5 DMA·¢ËÍÖÐ¶Ï
	NVIC_InitStructure.NVIC_IRQChannel = SPI5_TX_DMA_IRQn;  
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SPI5_TX_DMA_NVIC_PreemptionPriority;  
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SPI5_TX_DMA_NVIC_SubPriority;  
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
	NVIC_Init(&NVIC_InitStructure); 
	//SPI5 DMA½ÓÊÕÖÐ¶Ï
	NVIC_InitStructure.NVIC_IRQChannel = SPI5_RX_DMA_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = SPI5_RX_DMA_NVIC_PreemptionPriority;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = SPI5_RX_DMA_NVIC_SubPriority;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

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
