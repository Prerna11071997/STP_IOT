//to explore control structures in embedded c (or c)
#include<reg51.h>  //library included so as to use registers defined in it
int a,b; //integer data type
void delay( unsigned int i);  //prototype of delay function
void main()  //main function starts here
{
  //for loop
	for(a=0;a<=5;a++)
	{
		P3=61;  //both LEDs on port 3 are OFF
		delay(75);  //calling the delay function with input 75
	  P3=a;  //assigning number to the port 
		delay(150);  //calling the delay function with input 150
	}
	//while loop
	a=0;
	while(a<=5)     //till a is less than or equal to 5
	{
		P3=61;
		delay(75);
		P3=a;
		delay(150);
		a++;  //incrementing value of a by 1
	}
	//switch 
	for(b=0;b<=3;b++)   //for loop for different cases 
	{
	  switch(b)
	  {
	  	case 0: 
		  {
		  	P3=61;
			  delay(75);
		  	P3=b;
		  	delay(150);
		  }
		  case 1: 
		  {
			  P3=61;
			  delay(75);
			  P3=b;
			  delay(150);
		  }
		  case 2: 
		  {
			  P3=61;
			  delay(75);
			  P3=b;
			  delay(150);
		  }
		  case 3: 
		  {
			  P3=61;
			  delay(75);
			  P3=b;
			  delay(150);
		  }
		  default: P3=0;
	 }
 }
//IF-ELSE
 for(a=0;a<=1;a++)
 {
	if(a==0)
	{
		P3=61;
		delay(75);
	  P3=a;
    delay(150);
	}
	else
	{ 
		P3=61;
		delay(75);
	  P3=0; 
		delay(150);
	}
 }
}
//definition of delay function
void delay(unsigned int i)
{
	unsigned int j;
	unsigned int k;
	for(j=0;j<=i;j++)   //for loop goes from 0 to number passed to function
	for(k=0;k<=7500;k++);  //for loop goes from 0 to 7500
}
	
			