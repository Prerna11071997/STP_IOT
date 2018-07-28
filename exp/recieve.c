#include<reg51.h>
void main(){
	//int i,j;
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;  //serial communication register 
	TR1=1;      //running the timmer
	while(1){
		/*RI is defalut is 0. it stores in SBUFF register
		when it has recieved the character then it becomes 1
		*/
		while(RI==1);
		P0=SBUFF;
		RI=0;
		
	}
}