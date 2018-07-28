//to explore functions in embedded c (or c)
#include<reg51.h>    //include library to access registers defined in it
int a=1,b=3,c,d; //global integer variable
//function prototypes
void delay(unsigned int i);  //prototype of delay function
int add(); //no parameters passed but returns an integer value
int subtract(int, int);   //integer data types passed to the function and returns an integer value
void multiply(); //no parameters passed and returns no value
void divide(); //no parameters passed and returns no value
int recursive(int);  //an integer parameter passed and returns an integer value
void main()  //main function starts 
{
	c=add();     //calling function add() and giving the value to variable c
	P3=0;  //LEds ON
	delay(150); //delay function called with input 150
	P3=c;  //return value of add() function given to port
	delay(150);
	d=subtract(c,a);   //calling function subtract() by passing parameters and assigning return value to variable d
	P3=61;  //LEDs OFF
	delay(150);
	P3=d;  //return value of subtract() function given to port
	delay(150);
	multiply();  //multiply() function called
	divide();  //divide() function called
	c=recursive(a);  //recursive() function called by passing a parameter and return value assigned to variable c
	P3=61;  
	delay(150);
	P3=c;  //return value of recursive() function given to port
	delay(75);
}	
int add()   //definition of add() function
{
	int c;   //local variable to this function
	c=a+b;
	return c;
}
int subtract(int a,int b)  //definition of subtract() function
{
	int c;
	c=a-b;
	return c;
}
void multiply()  //definition of multiply() function
{
	int a=1,b=1,c;
	c=a*b;
	P3=61;
	delay(150);
	P3=c; 
	delay(150);
}
void divide()  //definition of divide() function
{
	int a=1,b=1,c;
	c=a/b;
	P3=61;
	delay(150);
	P3=c;
	delay(150);
}
int recursive(int a)  //definition of recursive() function
{
	int c;
	while(a>=0)   //loop works till value of a is greater or equal to 0
	{
	  c = a*1;
	  recursive(--a); //calling the recursive function from its body by decremented value of a
	}
	return c;  //returning the value to the calling parameter
}
void delay(unsigned int i)
{
	unsigned int j;
	unsigned int k;
	for(j=0;j<=i;j++)
	for(k=0;k<=7500;k++);
}
