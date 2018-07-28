//to demonstrate arrays by observing status of LEDs
#include<reg51.h>  //include library to use registers defined in it
int a[5], b[2][3]; //a[] is a single dimensional array and b[][] is a multi dimensional array
int i,j,k; 
void delay(unsigned int i);  //prototype of delay function
void main()  //main() starts
{
for(i=0;i<5;i++)
a[i]=i;           //assigning values to array
for(j=0;j<2;j++)
{
	for(k=0;k<3;k++)
	{
		b[j][k]=j*k;  //assigning values to array
	}
}
for(i=0;i<5;i++)
{
	P3=61;  //both LEDs OFF
	delay(75);  //calling delay() function with input 75
  P3=a[i];  //assigning values to port 3
	delay(150);  //calling delay() function with input 150 
}
for(j=0;j<2;j++)
{
	for(k=0;k<3;k++)
	{
		P3=61;
		delay(75);
		P3=b[j][k];  //assigning values to port 3
		delay(150);
	}
}
}
//definition of delay function
void delay(unsigned int i)
{
	unsigned int j,k;
	for(j=0;j<=i;j++)
	for(k=0;k<=7500;k++);
}
