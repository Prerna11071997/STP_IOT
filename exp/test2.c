#include<reg51.h>
sbit Led1=P3^2;
sbit smoke=P1^0;

void main(){
	while(1){
	if(smoke==1){
		Led1=0;
	}
	else{
		Led1=1;
	}

}}