#include<reg51.h>
sbit led1=P3^2;
sbit led2=P1^0;
sbit led3=P1^1;

void delay();

void main(){
	int i;
	led1=0;
	led2=1;
	led3=1;
	while(1){
		led1=0;
		led2=1;
		led3=1;
		delay();
		for(i=0;i<20000;i++);
		led1=1;
		led2=0;
		led3=1;
		delay();
		for(i=0;i<20000;i++);
		led1=1;
		led2=1;
		led3=0;
		delay();
		for(i=0;i<20000;i++);
	
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