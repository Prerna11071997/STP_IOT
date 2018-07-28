#include<reg51.h>
void main(){
	int i,j;
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;  //serial communication register 
	TR1=1;      //running the timmer
	while(1){
		SBUF='A'; 	
		while(TI==1);
		TI=0;		
		for(i=0;i<100;i++){
			for(j=0;j<10;j++);
		}
		
	}
}

	/*special serial function register(8 bit) used for transmit character by character -serial asynchronous comm. 
		frame=start+data bit+stop bit
		==10 bit(1bit+8 bit+1 bit)
		SBUF does the framing i.e. start bit then bit by bit 8 bit then stop bit , recievving is in the same manner.
		TI flash: when transimssion is over the  TI becomes 1. otherwise it is 0
		when transmission is occuring then 0
		initially TI=0 default
		the TI changes
		*/