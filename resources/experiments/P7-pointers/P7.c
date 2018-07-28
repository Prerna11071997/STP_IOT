//to explore pointers in embedded c
#include<reg51.h>  //include library to use registers defined in it
void delay(unsigned int i);
void main()
{
 	 int i=1,j=6,k=72;  //integer variable declaration
	  int *a;  //pointer variable declaration
	  a=&i;  //pointer stores the address of variable i
 	 P3=61;  //both LEds OFF
	delay(75); //calling delay() function with input 75
 	 P3=*a;  //the port is given the value of pointer
	delay(150);  //calling delay() function with input 150 
	a=&j; //pointer stores the address of variable j
	  P3=61;
	delay(75);
  	P3=*a;
	delay(150);
	a=&k;  //pointer stores the address of variable k
 	 P3=61;
	delay(75);
 	 P3=*a;
	delay(150);
}
void delay(unsigned int i)  //definition of delay() function
{
	unsigned int j,k;
	for(j=0;j<=i;j++)
	for(k=0;k<=7500;k++);
}