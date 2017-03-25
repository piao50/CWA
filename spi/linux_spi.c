//  gcc linux_spi.c -o spi
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include "spi.h"

static const char *DEVICE = "/dev/spidev0.0";
#define BUFFERSIZE 20

int main(int argc, char** argv)
{
  unsigned char send[BUFFERSIZE] = "hello";
  unsigned char recv[BUFFERSIZE] = {0};
  unsigned char info[BUFFERSIZE+1] = {0};
	uint8_t mode = 3, bits = 8;
	uint32_t speed = 1 * 100 * 1000;
	int file;
	struct spi_ioc_transfer transfer = {
		.tx_buf = (unsigned long) send,
		.rx_buf = (unsigned long) recv,
		.len = BUFFERSIZE,
	};
	uint64_t count = 0;
	int i = 0;

	if ((file = open(DEVICE, O_RDWR)) < 0){
		perror("SPI: Can't open device.");
		return -1;
	}
	if (ioctl(file, SPI_IOC_WR_MODE, &mode) == -1){
		perror("SPI: Can't set SPI mode.");
		return -1;
	}
	if (ioctl(file, SPI_IOC_RD_MODE, &mode) == -1){
		perror("SPI: Can't set SPI mode.");
		return -1;
	}
	if (ioctl(file, SPI_IOC_WR_BITS_PER_WORD, &bits) == -1){
		perror("SPI: Can't set bits per word.");
		return -1;
	}
	if (ioctl(file, SPI_IOC_RD_BITS_PER_WORD, &bits) == -1){
		perror("SPI: Can't set bits per word.");
		return -1;
	}	
	if (ioctl(file, SPI_IOC_WR_MAX_SPEED_HZ, &speed) == -1){
		perror("SPI: Can't set max speed HZ");
		return -1;
	}
	if (ioctl(file, SPI_IOC_RD_MAX_SPEED_HZ, &speed) == -1){
		perror("SPI: Can't set max speed HZ");
		return -1;
	}

	printf("SPI mode: %d\n", mode);
	printf("Bits per word: %d\n", bits);
	printf("Speed: %d Hz\n", speed);

	//	for(i = 0; i < BUFFERSIZE; i++)
	//	send[i] = '0' + (i % 10);

	while(1)
	{

		if (ioctl(file, SPI_IOC_MESSAGE(1), &transfer) < 0){
			perror("Failed to send SPI message");
			return -1;
		}
		
		if(++count % 100 == 0)
		{
			for(i = 0; i < BUFFERSIZE; i++)
				printf("%02X ", send[i]);
			printf("\n");
			for(i = 0; i < BUFFERSIZE; i++)
			  printf("%02X ", recv[i]);
			printf("count: %llu\n", count);
			memset(info, 0, sizeof(info));
			memcpy(info, recv, sizeof(recv));
			printf("  %s\r\n", recv);

			//			memset(send, 0, BUFFERSIZE);
			if(strcmp(send, "hello") == 0)
			{
			  memset(send , 0, BUFFERSIZE);
			  sprintf(send, "VALUE_xx1");
			}
			else
			{
			  memset(send, 0, BUFFERSIZE);
			  sprintf(send, "hello");
			}
		}
		usleep(10 * 1000);
	}

	close(file);
	return 0;
}
