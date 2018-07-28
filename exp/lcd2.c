
#include<reg51.h>
//sfr info=0x80;
sbit RS=P2^0;
sbit EN=P2^2;
void cmdtolcd(unsigned char cmd);
void datatolcd(unsigned char info[6]);
void delay(unsigned int x);

void main(){
//	unsigned int x;
	char arr[10]={'P' , 'R', 'E', 'R', 'N', 'A'};
	
	while(1){
		cmdtolcd(0x38);
		delay(50);
	  cmdtolcd(0x0E);
		delay(80);
	  cmdtolcd(0x01);
		delay(80);
	  cmdtolcd(0x80); //to print in the second line the use 0xC0
	  delay(80);
		datatolcd(arr);
		delay(100);
}
	}

void cmdtolcd(unsigned char cmd){
	P0=cmd;
	RS=0;
	EN=1;
	delay(1);
	EN=0;
}
void datatolcd(unsigned char info[6]){
	int i;
	for(i=0;i<=5;++i){
	P0= info[i];
	RS=1;
	EN=1;
	delay(1);
	EN=0;
	}
}

void delay(unsigned int x){
	unsigned int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<1275;j++);
	}
}
/*#include<reg51.h>
sfr dat=0x80;
sbit RS=P2^0;
sbit EN=P2^2;
void cmdtolcd(unsigned char cmd);
void datatolcd(unsigned char data);
void delay();

void main(){
	unsigned int x;
	char arr[10]={'P' , 'R', 'E', 'R', 'N', 'A'};
	
	while(1){
		cmdtolcd(0x38);
		delay(250)
	  cmdtolcd(0x0E);
		delay(250);
	  cmdtolcd(0x01);
		delay(250);
	  cmdtolcd(0x80); //to print in the second line the use 0xC0
	  delay(1000);
		datatolcd('S');
		delay(1000);
		datatolcd('T');
		delay(1000);
		datatolcd('P');
		delay(1000);
		for(x=0;x<1000;x++){
			delay(1000);
		}			
	}
}

void cmdtolcd(unsigned char cmd){
	P0=cmd;
	RS=0;
	EN=1;
	delay(250);
	EN=0;
}
void datatolcd(unsigned char info){
	for(int i=0;i<5;i++){
	P0= info[i];
	RS=1;
	EN=1;
	delay(250);
	EN=0;
	}
}

void delay(unsigned int x){
	int i,j;
	for(i=0;i<x;i++){
		for(j=0;j<750;j++);
	}
}
*/