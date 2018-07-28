							  		

#include<lpc214x.h>		
#define LCD_D7      21// Connect pin D7 of LCD to PORTx.21 (where PORTx is PORT0 or PORT1)
#define LCD_D6      20// Connect pin D6 of LCD to PORTx.20 (where PORTx is PORT0 or PORT1)
#define LCD_D5      19// Connect pin D5 of LCD to PORTx.19 (where PORTx is PORT0 or PORT1)
#define LCD_D4      18// Connect pin D4 of LCD to PORTx.18 (where PORTx is PORT0 or PORT1)
#define LCD_EN      17// Connect pin EN of LCD to PORTx.17 (where PORTx is PORT0 or PORT1)
#define LCD_RS      16// Connect pin RS of LCD to PORTx.16 (where PORTx is PORT0 or PORT1)

#define lcd_port_clear IOCLR1 //IOCLR0 if PORT0 is used
#define lcd_port_set   IOSET1 //IOSET0 if PORT0 is used
#define lcd_port_dir   IODIR1 //IODIR0 if PORT0 is used

								/********************Delay Function************************/

void Delay_Ms(unsigned int limit) // delay required for some functions
{
int temp;
	while(--limit) // while loop is used to create the required delay.
	{
	for(temp=1000;temp>0;temp--); // for loop is used to create the required delay.
	}
}

								/*******************Lcd Command Function*******************/

void Lcd_Command(unsigned char cmd) // this function is used to issue a command for LCD
{

lcd_port_clear    = 1 << LCD_RS; // set bit RS of LCD to make the command as Non data command
lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of the LCD
   if(cmd & 0x80) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to MSB of Command received by the function
   if(cmd & 0x40) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to MSB of Command received by the function
   if(cmd & 0x20) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to MSB of Command received by the function
   if(cmd & 0x10) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to MSB of Command received by the function
lcd_port_set      = 1 << LCD_EN; // Enable the LCD
Delay_Ms(2); // delay required for LCD to recognise					
lcd_port_clear    = 1 << LCD_EN; // Disable the LCD
 
   if(cmd & 0x08) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to LCB of Command received by the function
   if(cmd & 0x04) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to LCB of Command received by the function
   if(cmd & 0x02) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to LCB of Command received by the function
   if(cmd & 0x01) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to LCB of Command received by the function
 
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2); // delay required for LCD to recognise
   lcd_port_clear    = 1 << LCD_EN;	// Disable the LCD

   lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/*********************Lcd Data Function********************/

void Lcd_Data(unsigned char datum) // this function is used to issue a data for LCD
{
   if(datum & 0x80) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to MSB of Command received by the function
   if(datum & 0x40) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to MSB of Command received by the function
   if(datum & 0x20) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to MSB of Command received by the function
   if(datum & 0x10) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to MSB of Command received by the function
   lcd_port_set      = 1 << LCD_RS;	// set bit RS of LCD to make the command as data command
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2); // delay required for LCD to recognise
   lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of LCD
   lcd_port_clear    = 1 << LCD_RS; // Clear the RS pin of LCD 
 
   if(datum & 0x08) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to LCB of Command received by the function
   if(datum & 0x04) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to LCB of Command received by the function
   if(datum & 0x02) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to LCB of Command received by the function
   if(datum & 0x01) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to LCB of Command received by the function
 
   lcd_port_set      = 1 << LCD_RS;	// set bit RS of LCD to make the command as data command
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2);
   lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of LCD
   lcd_port_clear    = 1 << LCD_RS; // Clear the RS pin of LCD 

   lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/*************Whole String into Single Character Function**********/

void Lcd_String(unsigned char *str) // this function is used to issue a string to display in LCD
{
	while(*str) // Loop till received string Ends with NULL character
		Lcd_Data(*str++); // Put the datas to the LCD to display one by one
}

								/*************RESET THE LCD AND CLEAR ALL THE CHARACTERS**********/

void lcd_reset(void) // this function is used to Reset the registers of LCD
{
     

	  lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
	  Lcd_Command(0x3f); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x03); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x03); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x02); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
	  lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/********************Configuring Lcd Function*********************/

void Lcd_Config()// Configure the LCD for 4 bit mode
{
		lcd_port_dir|=((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
        lcd_reset();         
		
        Lcd_Command(0x28); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD 
        Lcd_Command(0x0C); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD 
        Lcd_Command(0x06); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD
        Lcd_Command(0x80); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD
        Lcd_Command(0x01); // issue commands to config
        Delay_Ms(1);//delay to recognise by the LCD
		lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
}#define LCD_D7      21// Connect pin D7 of LCD to PORTx.21 (where PORTx is PORT0 or PORT1)
#define LCD_D6      20// Connect pin D6 of LCD to PORTx.20 (where PORTx is PORT0 or PORT1)
#define LCD_D5      19// Connect pin D5 of LCD to PORTx.19 (where PORTx is PORT0 or PORT1)
#define LCD_D4      18// Connect pin D4 of LCD to PORTx.18 (where PORTx is PORT0 or PORT1)
#define LCD_EN      17// Connect pin EN of LCD to PORTx.17 (where PORTx is PORT0 or PORT1)
#define LCD_RS      16// Connect pin RS of LCD to PORTx.16 (where PORTx is PORT0 or PORT1)

#define lcd_port_clear IOCLR1 //IOCLR0 if PORT0 is used
#define lcd_port_set   IOSET1 //IOSET0 if PORT0 is used
#define lcd_port_dir   IODIR1 //IODIR0 if PORT0 is used

								/********************Delay Function************************/

void Delay_Ms(unsigned int limit) // delay required for some functions
{
int temp;
	while(--limit) // while loop is used to create the required delay.
	{
	for(temp=1000;temp>0;temp--); // for loop is used to create the required delay.
	}
}

								/*******************Lcd Command Function*******************/

void Lcd_Command(unsigned char cmd) // this function is used to issue a command for LCD
{

lcd_port_clear    = 1 << LCD_RS; // set bit RS of LCD to make the command as Non data command
lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of the LCD
   if(cmd & 0x80) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to MSB of Command received by the function
   if(cmd & 0x40) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to MSB of Command received by the function
   if(cmd & 0x20) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to MSB of Command received by the function
   if(cmd & 0x10) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to MSB of Command received by the function
lcd_port_set      = 1 << LCD_EN; // Enable the LCD
Delay_Ms(2); // delay required for LCD to recognise					
lcd_port_clear    = 1 << LCD_EN; // Disable the LCD
 
   if(cmd & 0x08) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to LCB of Command received by the function
   if(cmd & 0x04) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to LCB of Command received by the function
   if(cmd & 0x02) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to LCB of Command received by the function
   if(cmd & 0x01) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to LCB of Command received by the function
 
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2); // delay required for LCD to recognise
   lcd_port_clear    = 1 << LCD_EN;	// Disable the LCD

   lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/*********************Lcd Data Function********************/

void Lcd_Data(unsigned char datum) // this function is used to issue a data for LCD
{
   if(datum & 0x80) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to MSB of Command received by the function
   if(datum & 0x40) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to MSB of Command received by the function
   if(datum & 0x20) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to MSB of Command received by the function
   if(datum & 0x10) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to MSB of Command received by the function
   lcd_port_set      = 1 << LCD_RS;	// set bit RS of LCD to make the command as data command
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2); // delay required for LCD to recognise
   lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of LCD
   lcd_port_clear    = 1 << LCD_RS; // Clear the RS pin of LCD 
 
   if(datum & 0x08) lcd_port_set    = 1 << LCD_D7; else lcd_port_clear  = 1 << LCD_D7; //set or clear LCD bit D7 according to LCB of Command received by the function
   if(datum & 0x04) lcd_port_set    = 1 << LCD_D6; else lcd_port_clear  = 1 << LCD_D6; //set or clear LCD bit D6 according to LCB of Command received by the function
   if(datum & 0x02) lcd_port_set    = 1 << LCD_D5; else lcd_port_clear  = 1 << LCD_D5; //set or clear LCD bit D5 according to LCB of Command received by the function
   if(datum & 0x01) lcd_port_set    = 1 << LCD_D4; else lcd_port_clear  = 1 << LCD_D4; //set or clear LCD bit D4 according to LCB of Command received by the function
 
   lcd_port_set      = 1 << LCD_RS;	// set bit RS of LCD to make the command as data command
   lcd_port_set      = 1 << LCD_EN; // Enable the LCD
   Delay_Ms(2);
   lcd_port_clear    = 1 << LCD_EN; // Clear the Enable pin of LCD
   lcd_port_clear    = 1 << LCD_RS; // Clear the RS pin of LCD 

   lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/*************Whole String into Single Character Function**********/

void Lcd_String(unsigned char *str) // this function is used to issue a string to display in LCD
{
	while(*str) // Loop till received string Ends with NULL character
		Lcd_Data(*str++); // Put the datas to the LCD to display one by one
}

								/*************RESET THE LCD AND CLEAR ALL THE CHARACTERS**********/

void lcd_reset(void) // this function is used to Reset the registers of LCD
{
     

	  lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
	  Lcd_Command(0x3f); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x03); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x03); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
      Lcd_Command(0x02); // issue commands to reset
      Delay_Ms(2);//delay to recognise by the LCD
	  lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD

}

								/********************Configuring Lcd Function*********************/

void Lcd_Config()// Configure the LCD for 4 bit mode
{
		lcd_port_dir|=((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
        lcd_reset();         
		
        Lcd_Command(0x28); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD 
        Lcd_Command(0x0C); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD 
        Lcd_Command(0x06); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD
        Lcd_Command(0x80); // issue commands to config      
        Delay_Ms(1);//delay to recognise by the LCD
        Lcd_Command(0x01); // issue commands to config
        Delay_Ms(1);//delay to recognise by the LCD
		lcd_port_clear = ((1<<LCD_EN)|(1<<LCD_RS)|(1<<LCD_D4)|(1<<LCD_D5)|(1<<LCD_D6)|(1<<LCD_D7)); // Clear all the pins of LCD
}
                                                                /***************Port Initialisation Function*****************/
																
																					

void Lcd_Whole_Number(unsigned int number,unsigned int i){
	unsigned char temp;
	for(;i>=1;i/=10){
		temp = number / i;
		Lcd_Data(temp+48);
		number %= i;
	}
}

#define AD0DR AD0GDR
#define pdn_bit 1<<21
#define adcr_start_mask 7<<24
#define adcr_sel_mask 0x000000FF
#define adc0_start 1<<24

				/*****************ADC Channel Selection Function*********************/
unsigned int Adc_Ch_Sel(char ch){
unsigned char clk_div=3;
unsigned int i=0;
unsigned char chn; 
chn=1<<ch;
AD0CR =(1<<ch) | ( ((clk_div-1))<<8 ) | pdn_bit; 
	AD0CR &= ~(adcr_start_mask|adcr_sel_mask);
	
	AD0CR |=chn; 
	AD0CR |=adc0_start; 
		while(!(AD0DR & (0x80000000)));
	
	AD0CR &= ~(adcr_start_mask|adcr_sel_mask); 
	i=((AD0DR)&(0x0000FFC0))>>6 ;
	
return(i);
}

				/****************ADC Configuration Function********************/

void Adc_Config(){
PINSEL1= (PINSEL1 & (~(3<<24)))|(1<<24);
PINSEL1= (PINSEL1 & (~(3<<26)))|(1<<26); 
PINSEL1= (PINSEL1 & (~(3<<28)))|(1<<28); 
PCONP |= 0x00001000; 
}

				/******************Port Initialization Function******************/
void Port_Init(){

}

				/*******************Main Function************************/

int main(){
	unsigned int Adc;
	Port_Init();			
	Adc_Config();			
	Delay_Ms(65000);
	Lcd_Config();			
	Delay_Ms(255);
	Lcd_Command(0X80);		
	Lcd_String("L=");
	while(1){				
		Adc=Adc_Ch_Sel(0);	
		Lcd_Command(0X82);	
		Delay_Ms(10000);
		Lcd_Whole_Number(Adc,100);
	}
}
