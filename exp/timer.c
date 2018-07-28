#include<reg51.h>
sbit led1=P3^2;
sbit led2=P3^3;
void delay();

void main(void){	
	led1=0;
	led2=1;
	while(1){
		led1=0;
	  led2=1;
		delay();
		led1=1;
		led2=0;
		delay();
	}
	

}


void delay(void){
	TMOD=0x11;
	TH0=00;
	TL0=00;
	TR0=1;
	while(TF0==00);
	TR0=0;
	TF0=0;
}