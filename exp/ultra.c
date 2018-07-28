#include<reg51.h>

int cms;
sbit trig=P3^5;
sbit RS=P2^0;
sbit EN=P2^2;

void delay(unsigned int msec)
{
	int i,j;
	for(i=0;i<msec;i++)
	for(j=0;j<1275;j++);
}


void lcd_cmd(unsigned char item){
	P0=item;
	RS=0;
	EN=1;
	delay(1);
	EN=0;

}

void lcd_data(unsigned char str){
	
	int i=0;
	while(str[i]!='\0'){
		lcd_data(str[i]);
		i++;
		delay(1);
	
	}
}

void send_pulse(){
	TH0=0x00;
	TL0=0x00;
	trig=1;
	delay(5);
	trig=0;

}

unsigned int get range(){
	long int timer_val;
	send_pulse();
	while(!INT0);
	while(INT0);
	
	timer_val=(TH0<<8)+TL0;
	
	lcd_cmd(0x81);
	lcd_data_string("output");
	lcd_cmd(0x82);
	if(timer_val<38000){
		cms=timer_val/59;
		if(cms!=0)
		{
			lcd_data(cms);
		}
	
	}else{
	lcd_cmd(0x06);
	lcd_data_string("out of range");
	}
	return cms;
}

void main(){
	cmdtolcd(0x38);
		delay(50);
	  cmdtolcd(0x0E);
		delay(80);
	  cmdtolcd(0x01);
		delay(80);
	  cmdtolcd(0x81);
	  delay(80);
	lcd_data_string("start");
	delay(20);
	TMOD=0x44;
	TR0=1;
	TH0=0x00;
	TL0=0x00;
	while(1){
	get_range();
		delay(2);
	}
}