/*
 * Diffretial input ADC.c
 *
 * Created: 28-01-2023 08:20:15
 * Author : Abhishek Vishwakarma
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	ADMUX = 0b01010000;
	ADCSRA = 0b10000110;
	DDRC = 0b11111111;
	DDRD = 0b00000011;	
  
    while (1) 
    {
		ADCSRA = 0b11000110;  //Start of conversion
		while((ADCSRA & (1<<4)) ==0)
		{
			//wait untill conversion
		}		
		PORTC = ADCL;
		PORTD = ADCH;
		_delay_ms(100);
    }
}


