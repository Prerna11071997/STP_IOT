#include<reg51.h>
sbit Led1= P3^3;
sbit Led2=P3^2;


void main(){	
	unsigned int x;
	Led1=0;
	Led2=1;
	for(x=0;x<9000;x++);
	Led1=1;
	Led2=0;
	for(x=0;x<9000;x++);
}



