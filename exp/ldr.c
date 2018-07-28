

#include<reg51.h>
sbit ldr=P3^4;
sbit ir=P3^5;

void main(void){
	TMOD=0x44;
  TH1=0;
  TL1=0;
  TH0=0;
  TL0=0;
  TR0=1;
  TR1=1;
	P0=TL0;
	
	while(1){
		P0=TL0;
		P3=TL1;
		
	}
	
}
