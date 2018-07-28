#include<REG51.h>
sbit trig=P0^5;
sbit led=P3^3;

void main(){
	unsigned int target_range=0,timer_val;
	P3|=0x04;		//P3.2 as INPUT
	while(1){
		TMOD=0x0l;
		TH0=0xFF;TL0=0xF5;
		trig=1;
		TR0=1;
		while(!TF0);
		TR0=0;
		TF0=0;
		TMOD=0x09;		//timer0 in 16 bit mode with gate enable
		TH0=0x00; TL0=0x00;
		TR0=1;		//timer0 run enabled
		trig=0;
		while(!INT0);
		while (INT0);
		TR0=0;
		timer_val=TH0<<8|TL0;
		if(timer_val<35000)
			target_range=timer_val*0.01860775;
		else
			target_range=0; // indicates that there is no obstacle in front of the sensor
		
		if (target_range<10)
			led=0;
		else
			led=1;
	}
}