#include>reg51.h>
sbit trig=P0^0;
sbit echo=P0^1;
void delay(unsigned int x);
void den_pulse();

void main(){
	TMOD=0x44;
	TR0=1;
	TH0=0x00; 
	TL0=0x00;
	
	


}
	
void send_pulse(){
	TH0=0x00;
	TL0=0x00;
	trig=1;
	delay(10);
	trig=0;
}

unsigned char get_range(){
	unsigned char range;
	send_pulse();
	while(!INT0);
	while(INT0);
	DPH=TH0;
	DPL=TL0;
	TH0=0xFF;
	TL0=0xFF;
	if(DPTR<38000){
		range=DPTR/59;
	}else{
		range=0;
	}
	return range;
	
}
