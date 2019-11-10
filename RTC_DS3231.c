#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <stdio.h>
int main(void)
{
	int rt;
	wiringPiSetup();
	rt=wiringPiI2CSetup(0x68);
	
	//cai thoi gian-set time
	/*wiringPiI2CWriteReg8(rt,0x00,0x00);//second
	wiringPiI2CWriteReg8(rt,0x01,0x15);//minute
	wiringPiI2CWriteReg8(rt,0x02,0x00);//hour
	wiringPiI2CWriteReg8(rt,0x03,0x02);//day
	wiringPiI2CWriteReg8(rt,0x04,0x11);//date
	wiringPiI2CWriteReg8(rt,0x05,0x11);//month
	wiringPiI2CWriteReg8(rt,0x06,0x16);//year*/
	
	while(1)
	{
		int year, month, date, day, h, m ,s;
		
		year=wiringPiI2CReadReg8(rt,0x06);
		month=wiringPiI2CReadReg8(rt,0x05);
		date=wiringPiI2CReadReg8(rt,0x04);
		day=wiringPiI2CReadReg8(rt,0x03);
		h=wiringPiI2CReadReg8(rt,0x02);
		m=wiringPiI2CReadReg8(rt,0x01);
		s=wiringPiI2CReadReg8(rt,0x00);
		
		year = (year >> 4 ) * 10 + (year & 0x0F) ;
		month = (month >> 4 ) * 10 + (month & 0x0F);
		date = (date >>4) * 10 + (date & 0x0F);
		h = ( h >> 4 ) * 10 + (h & 0x0F);
		m = ( m >> 4 ) * 10 + (m & 0x0F);
		s = ( s >> 4 ) * 10 + (s & 0x0F);
		
		printf("\nNgay: %d, Thang: %d, Nam 20%d\n",date,month,year);
		printf("Thu: %d\n",day);
		printf("Thoi gian: %d:%d:%d\n",h,m,s);
	}
	
}
