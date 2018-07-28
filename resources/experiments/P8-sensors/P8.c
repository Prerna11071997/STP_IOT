//interfacing sensors
#include<reg51.h>  //include library to use registers defined in it
sbit sensor=P3^5;  //sensor is connected to pin 5 of port 3
sbit LED1=P3^2;  //
sbit LED2=P3^3;
sbit buzzer=P3^7;  //buzzer is connected to pin 7 of port 3
void main()
{
	if(sensor)   //if change is sensed
	{
	LED1=0;  //ON
	LED2=0;  //ON
	buzzer=0;   //buzzer sounds
	}
	else 
	{
		LED1=1;  //OFF
		LED2=1;  //OFF
		buzzer=1;  //buzzer off
	}
}