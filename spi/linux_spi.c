//  gcc linux_spi.c -o spi
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>

#include "cwa_spi.h"

static const char *DEVICE = "/dev/spidev0.0";

int main(int argc, char** argv)
{
	unsigned char send[2], recv[2];
	uint8_t mode = 3, bits = 8;
	uint32_t speed = 5 * 1000 * 1000;
	int file;
	struct spi_ioc_transfer transfer = {
		.tx_buf = (unsigned long) send,
		.rx_buf = (unsigned long) recv,
		.len = 2,
	};

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

	if (ioctl(file, SPI_IOC_MESSAGE(1), &transfer) < 0){
		perror("Failed to send SPI message");
		return -1;
	}

	close(file);
	return 0;
}