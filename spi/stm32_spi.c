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
