//to explore data types in embedded c (or c)  using LED interface
#include<reg51.h> 	//including this library to use the various registers
int b,f;	       //integer data type
float a; 	      //float data type
double d;	     // double data type 
char c;		    //character data type
sfr j=0x80;	   //special function register data type						
sbit LED1=P3^2;   //single bit data type
sbit LED2=P3^3;
void delay(unsigned int i);	//prototype of function with definition later int the program

void main(void)
{
		// sbit data type
	  LED1=0;	LED2=1;		//LED1 is ON and LED2 is OFF
	  delay(150);			//calling the delay function with 150  input
	  LED1=1;	LED2=0;		//LED1 is OFF and LED2 is ON
	  delay(150);			//calling the delay function with 150  input
		//integer data type
	  for(b=0;b<=7;b++)		 //for loop to give values to variable b from 0-7
	  {
		  P3=61;		//both the LEDs on port 3 are off
		  delay(75);	       //calling the delay function with 75  input
		  P3=b;		      //binary equivalent of decimal nos. stored in port 
		  delay(150);	     //calling the delay function with 150  input
	  }
	  //character data type-CAPITAL LETTERS
		for(c='A';c<='Z';c++)			//for loop to give values to variable c from 'A' to 'Z'
	  {
		  P3=61;
		  delay(75);
		  P3=c;				      //binary equivalent of ASCII code stored in port 3
		  delay(150);
	  }
	 //character data type-SMALL LETTERS
	 for(c='a';c<='z';c++)			    //for loop to give values to variable c from 'a' to 'z'
	 {
		  P3=61;
		  delay(75);
		  P3=c;				 //binary equivalent of ASCII code stored in to port 3
		  delay(150);
	 }
	 //float data type
         for(a=0.6;a<=7.6;a++)			//for loop to give values to variable a from 0.6 to 7.6
	 {
		 P3=61;
		 delay(75);
		 P3=a;				//binary code stored in port 3
		 delay(150);
	 }
	 //double data type
	 for(d=0.2;d<=7.2;d++)		
	 {
		  P3=61;
		  delay(75);
		  P3=d;				//binary code stored in port 3	
		  delay(150);
	 }
	 //sfr data type
	 for(f=0;f<=61;f+=61)		
	 {
	    P0=f;
	    P3=j;
	   delay(150);
	 }
}
//delay function to cause some delay to observe LED glowing
void delay(unsigned int i)		
{
	unsigned int k;
	unsigned int j;
	for(j=0;j<i;j++)		//for loop till the number passed to function
	for(k=0;k<7500;k++);		//for loop to cause delay of 7500 
}
