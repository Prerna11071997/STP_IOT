//to observe status of LEDs using expressions
#include<reg51.h>  //include this library to use various registers
sbit LED1=P3^2;    //LED1 variable holds data of pin 2 of port 3
sbit LED2=P3^3;   //LED2 variable holds data of pin 3 of port 3
int a,b;  //integer data type variables
void delay(unsigned int i);  //prototype of delay function
void main()  //main function starts here
{
	for(a=0;a<=1;a++)   //for loop gives value 0 and 1 to 'a' variable
	{
		for(b=0;b<=1;b++)  //for loop gives value 0 and 1 to 'b' variable 
		{  
			//LOGICAL AND OPERATOR	
			LED1=(a && b);			//LED1 assigned value of result a&&b 
			//following code so as to observe variations in LED1 clearly 
			LED2=0;      //LED2 ON
			delay(150);  //delay function called with input 150
			LED2=61;     //LED2 OFF
			delay(75);  //delay function called with input 75
			//LOGICAL OR OPERATOR
			LED2=a||b;  //LED2 assigned value of result a||b 
			LED1=0;    
			delay(150);
			LED1=61;
			delay(75);
			//LOGICAL NOT OPERATOR
			LED1=!(a&&b);
			LED2=0;
			delay(150);
			LED2=61;
			delay(75);
			//BOOLEAN AND OPERATOR
			LED1=a&b;    //LED1 assigned value of result a&b as per truth table
			//following code so as to observe variations in LED1 clearly 
			LED2=0;      //LED2 ON
			delay(150);  //delay function called with input 150
			LED2=61;     //LED2 OFF
			delay(75);  //delay function called with input 75
			//BOOLEAN OR OPERATOR
			LED2=a|b;  //LED2 assigned value of result a|b as per truth table
			LED1=0;    
			delay(150);
			LED1=61;
			delay(75);
			//BOOLEAN XOR OPERATOR
			LED1=a^b;  //LED1 assigned value of result a^b as per truth table
			LED2=0;
			delay(150);
			LED2=61;
			delay(75);
			//ARITHMETIC '-' OPERATOR
			LED1=a-b;  //all other values except 0 are taken as OFF
			LED2=0;
			delay(150);
			LED2=61;
			delay(75);
			//ARITHMETIC '/' OPERATOR
			LED2=a/b;  //all other values except 0 are taken as OFF
			LED1=0;
			delay(150);
			LED1=61;
			delay(75);
			//RELATIONAL > OPERATOR
			LED1=0;
			if(a>b)
				LED2=b;
			else 
				LED2=a;
			delay(150);
			LED1=61;
			delay(75);
			//RELATIONAL >= OPERATOR
			LED2=0;
			if(a>=b)
				LED1=a;
			else 
				LED1=b;
			delay(150);
			LED2=61;
			delay(75);
		}  //for loop of 'b' variable ends
	}  //for loop of 'a' variable ends
}  //main function ends
//definition of delay function
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<=i;j++)    // for loop goes from 0 to number passed to the function
	for(k=0;k<=7500;k++);  //for loop goes from 0 to 7500
}
			
