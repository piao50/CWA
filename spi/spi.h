#ifndef SPI_H
#define SPI_H

#ifdef __cplusplus
 extern "C" {
#endif 

#ifdef STM32
/* SPI_Clock_Polarity */
// #define SPI_CPOL_Low                    ((uint16_t)0x0000)
// #define SPI_CPOL_High                   ((uint16_t)0x0002)
/* SPI_Clock_Phase */
// #define SPI_CPHA_1Edge                  ((uint16_t)0x0000)
// #define SPI_CPHA_2Edge                  ((uint16_t)0x0001)
/* SPI_MSB_LSB_transmission */
//#define SPI_FirstBit_MSB                ((uint16_t)0x0000)
//#define SPI_FirstBit_LSB                ((uint16_t)0x0080)

#endif

#ifdef LINUX
// #define	SPI_CPHA	0x01			/* clock phase */
// #define	SPI_CPOL	0x02			/* clock polarity */
// #define	SPI_MODE_0	(0|0)			 (original MicroWire) 
// #define	SPI_MODE_1	(0|SPI_CPHA)
// #define	SPI_MODE_2	(SPI_CPOL|0)
// #define	SPI_MODE_3	(SPI_CPOL|SPI_CPHA)
#endif

#define CMD_HELLO "hello"
#define REPLY_LEN_CMD_HELLO 5
#define CMD_VALUE_xx1 "VALUE_xx1"
#define REPLY_LEN_CMD_VALUE_xx1 16
#define CMD_DATA "DATA"
#define REPLY_LEN_CMD_DATA 8005   
   
#ifdef __cplusplus
}
#endif   

#endif
