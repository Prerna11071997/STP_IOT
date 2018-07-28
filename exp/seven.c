#include<reg51.h>
void delay();

unsigned int i;

void main(void)
{
	while(1){
  P1=0x67;
	delay();
	P1=0x78;
	delay();
	P1=0x07;
	delay();
	P1=0x7D;
	delay();
	P1=0x6D;
	delay();
	P1=0x66;
	delay();
	P1=0x4F;
	delay();
	P1=0x5B;
	delay();
	P1=0x06;
	delay();
	P1=0x3F;
	delay();
	}
}

void delay(){
	for(i=0;i<400;i++);
}