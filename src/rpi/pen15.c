#include <bcm2835.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "image.h"

#define NLEDS (64)
#define BYTES (NLEDS * 4 + 8)

char buf[BYTES];
uint8_t order_lut[NLEDS];


typedef struct 
{
	int16_t acc_x;
	int16_t acc_y;
	int16_t acc_z;
	int16_t temp;
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;
} __attribute__((packed)) imu_data_t;

imu_data_t imudata;

void readimu() {
	uint8_t reg = 0x3B;
if(bcm2835_i2c_read_register_rs(&reg, (char*)&imudata, sizeof(imudata)) == BCM2835_I2C_REASON_OK) {
		imudata.acc_x = ntohs(imudata.acc_x);
		imudata.acc_y = ntohs(imudata.acc_y);
		imudata.acc_z = ntohs(imudata.acc_z);
		imudata.gyro_x =ntohs(imudata.gyro_x);
		imudata.gyro_y =ntohs(imudata.gyro_y);
		imudata.gyro_z =ntohs(imudata.gyro_z);
	}
		else
	printf("fail\n");
}

void setled(int num, uint8_t glob, uint8_t r, uint8_t g, uint8_t b) {
  int led = order_lut[num];
  if(led == 0xff)
	  return;

   	buf[led*4+4] = glob;
  buf[led*4+5] = b;
  buf[led*4+6] = g;
  buf[led*4+7] = r;
}



void init() {
	int i;
	for(i=0; i<NLEDS; ++i) {
		order_lut[i] = i;//0xff;
		buf[4+4*i] = 128+64+32+1;
		buf[5+4*i] = 0;
		buf[6+4*i] = 0;
		buf[7+4*i] = 0;
	}/*
	order_lut[0] = 35;
	order_lut[1] = 18;
	order_lut[2] = 17;
	order_lut[3] = 32;
	order_lut[4] = 36;
	order_lut[5] = 20;
	order_lut[6] = 19;
	order_lut[7] = 34;
	order_lut[8] = 21;
	order_lut[9] = 33;
	order_lut[10] = 37;
	order_lut[11] = 51;
	order_lut[12] = 49;
	order_lut[13] = 48;
	order_lut[14] = 22;
	order_lut[15] = 50;
	order_lut[16] = 1;
	order_lut[17] = 38;
	order_lut[18] = 2;
	order_lut[19] = 23;
	order_lut[20] = 39;
	order_lut[21] = 54;
	order_lut[22] = 53;
	order_lut[23] = 40;
	order_lut[24] = 25;
	order_lut[25] = 0;
	order_lut[26] = 52;
	order_lut[27] = 41;
	order_lut[28] = 24;
	order_lut[29] = 55;
	order_lut[30] = 57;
	order_lut[31] = 56;
	order_lut[32] = 42;
	order_lut[33] = 4;
	order_lut[34] = 26;
	order_lut[35] = 3;
	order_lut[36] = 6;
	order_lut[37] = 27;
	order_lut[38] = 5;
	order_lut[39] = 28;
	order_lut[40] = 7;
	order_lut[41] = 8;
	order_lut[42] = 58;
	order_lut[43] = 9;
	order_lut[44] = 60;
	order_lut[45] = 11;
	order_lut[46] = 10;
	order_lut[47] = 13;
	order_lut[48] = 59;
	order_lut[49] = 14;
	order_lut[50] = 44;
	order_lut[51] = 43;
	order_lut[52] = 45;
	order_lut[53] = 15;
	order_lut[54] = 61;
	order_lut[55] = 47;
	order_lut[56] = 31;
	order_lut[57] = 29;
	order_lut[58] = 30;
	order_lut[59] = 63;
	order_lut[60] = 62;
	order_lut[61] = 12;
	order_lut[62] = 46;
	order_lut[63] = 0xff;
*/
	/*

	for(i=0; i<NLEDS; ++i) {
		int f;
		int found = 0;
		for(f=0; f<NLEDS; ++f) {
			if(order_lut[f] == i) {
				found=1;
				break;
			}
		}
		if(!found)printf("NF: %d\n", i);
	}*/
}


void senddata() {
  char tmpbuf[BYTES];
  buf[0] = 0x00; buf[1] = 0x00; buf[2] = 0x00; buf[3] = 0x00;
  buf[BYTES-4] = 0xff; buf[BYTES-3] = 0xff; buf[BYTES-2] = 0xff; buf[BYTES-1] = 0xff;
  memcpy(tmpbuf, buf, sizeof(tmpbuf));
  
  bcm2835_spi_transfern(tmpbuf, BYTES);
}

int main(int argc, char **argv)
  {
	init();

	  if (!bcm2835_init()) return 1;   /* Bibliothek initialisieren */
    
  /* Schnittstenneparameter setzen */
  bcm2835_spi_begin();
  bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      /* default */
  bcm2835_spi_setDataMode(BCM2835_SPI_MODE1);                   /* default */
  bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_8); /* default */
  bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                      /* default */
  bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);      /* default */


for(;;){
  int i;
  for(i=48; i<64; ++i) {
	  int y;
	  printf("%d\n", i%64);
	  for(y=0; y<NLEDS; ++y) {
		  setled(y, 0xe7,0,0, 0xff);
	  }
	 senddata();
	 //usleep(500000);
	 getchar();
  }
  }


 bcm2835_i2c_begin();
 bcm2835_i2c_setSlaveAddress(0x68);
 char pwr[] = {0x6b, 0};
 bcm2835_i2c_write(pwr, sizeof(pwr));

	const int t = 300;
	
  for(;;) {
	int col;


	//forward direction
	for(;;) {
		readimu();
		if(imudata.gyro_z < -14000)
			break;
	}
	printf("fwd\n");
	for(col=0; col < gimp_image.width; ++col) {
		int row;
		for(row=0; row<gimp_image.height; ++row) {
			setled(63-row, 0xe7, gimp_image.pixel_data[(gimp_image.width*row+col)*3], gimp_image.pixel_data[(gimp_image.width*row+col)*3+1], gimp_image.pixel_data[(gimp_image.width*row+col)*3+2]);
		}
		senddata();
		usleep(t);
	}
	for(col=0; col<NLEDS; ++col) {
		setled(col, 0xff, 0,0,0);
	}
	senddata();
	//reverse direction
	for(;;) {
		readimu();
		if(imudata.gyro_z > 14000)
			break;
	}
	printf("rev\n");
	for(col=gimp_image.width; col >= 0; --col) {
		int row;
		for(row=0; row<gimp_image.height; ++row) {
			setled(63-row, 0xe7, gimp_image.pixel_data[(gimp_image.width*row+col)*3], gimp_image.pixel_data[(gimp_image.width*row+col)*3+1], gimp_image.pixel_data[(gimp_image.width*row+col)*3+2]);
		}
		senddata();
		usleep(t);
	}
	for(col=0; col<NLEDS; ++col) {
		setled(col, 0xff, 0,0,0);
	}
	senddata();
  }

  bcm2835_i2c_end();
  bcm2835_spi_end();
  return 0;
  }
