#include<reg51.h>
sbit trig=P0^0;
sbit echo=P0^1;
sbit led1=P3^2;
sbit led2=P3^3;
void delay(unsigned int x);
void send_pulse();
int cms;

void send_pulse(){
	TH0=0x00;
	TL0=0x00;
	trig=1;
	delay(10);
	trig=0;
}

void get_range(){
	long int timer_val;
	send_pulse();
	while(!INT0);
	while(INT0);
	
	timer_val=(TH0<<8)+TL0;
	

	if(timer_val<38000){
		cms=timer_val/59;
		if(cms!=0)
		{
			led1=0;
		}
	
	}else{
	led2=0;
	}
}

void main(){
	TMOD=0x44;
	TR0=1;
	TH0=0x00;
	TL0=0x00;
	while(1){
	get_range();
		delay(2);
	}
}

void delay(unsigned int msec)
{
	int i,j;
	for(i=0;i<msec;i++)
	for(j=0;j<1275;j++);
}
