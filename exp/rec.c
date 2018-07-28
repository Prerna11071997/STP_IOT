#include<reg51.h>
sbit led=P3^2;
char str;
void main(){
	while(1){
		TMOD=0x20;
		SCON=0x50;
		TH1=0xFD;
		TR1=1;
		while(!RI);
		str=SBUF;
		RI=0;
		if(str=='1'){
		led=0;
		}
		if(str='2'){
		led=1;
		}
	}
}