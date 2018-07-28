// 8 bit data - any port
// vss-gnd
// R/w(bar above w)- gnd
//vcc-vcc(5v)
//RS-any pin(P0.0)
//E-any pin(P0.1)
//LCD connections

#include<reg51.h>

sbit RS=P2^0;
sbit E=P2^1;
void delay();
void cmdtolcd(unsigned char);
void datatolcd(char ar[25]);

void main()
{ while(1)
	{ cmdtolcd(0x38);	
		delay();
		cmdtolcd(0x0E);
		delay();
		cmdtolcd(0x01);
		delay();
		cmdtolcd(0x81);
		delay();
		datatolcd("triptisaini");
		delay();
		delay();
		delay();
	}
}

void cmdtolcd(unsigned char cmd)
{ P1=cmd;
	RS=0;
	E=1;
	delay();
	E=0;
}

void datatolcd(char ar[12])
{  int i,info;
	for(i=0;i<12;i++)
	{ info=ar[i];
		P1=info;
		RS=1;
		E=1;
		delay();
		E=0;
	}
}

void delay()
{ unsigned int j;
	for(j=0;j<25000;j++);
}