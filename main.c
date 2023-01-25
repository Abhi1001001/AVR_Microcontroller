/*
 * 2 Temprature Senser Interface.c
 *
 * Created: 25-01-2023 15:54:49
 * Author : Abhishek Vishwakarma
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

void ADC_Init(uint8_t channel)
{
	ADMUX = 0b01000000;
	ADCSRA = 0b10000110;
	ADMUX = ADMUX | channel;
}

uint16_t ADC_result()
{
	ADCSRA = ADCSRA | (0b01000000); //add start bit on existing ADCSRA Value
	while ((ADCSRA & (1<<4))==0)
	{
		//Wait till conversion Completes
	}
	//PORTC = ADCL;
	//PORTD = ADCH;
	return ADC;
}
int main(void)
{
	DDRC = 0b00000111;
	DDRD = 0b00000111;
	
	int reading1;
	int reading2;
	while (1)
	{
		ADC_Init(0);
		reading1 = ADC_result();
		_delay_ms(100);
		
		if (reading1 >= 62 )
		{
			//if temp > 30
			//Fan1+Fan2+Compressor
			PORTC = 0b00000111;
		}
		else if (reading1 < 62 && reading1 >= 52)
		{
			//if 30 > temp > 25
			//Fan1+Compressor
			PORTC = 0b00000101;
		}
		else if (reading1 < 52 && reading1 >= 41)
		{
			//if 25 > temp > 20
			//Fan1+Fan2
			PORTC = 0b00000011;
		}
		else if (reading1 < 41 && reading1 >= 31)
		{
			//if 20 > temp > 15
			//Fan1+Compressor
			PORTC = 0b00000001;
		}
		else
		{
			//Everything off
			PORTC = 0b00000000;
		}
		
		ADC_Init(4);
		reading2 = ADC_result();
		_delay_ms(100);
		
		if (reading2 >= 62 )
		{
			//if temp > 30
			//Fan1+Fan2+Compressor
			PORTD = 0b00000111;
		}
		else if (reading2 < 62 && reading2 >= 52)
		{
			//if 30 > temp > 25
			//Fan1+Compressor
			PORTD = 0b00000101;
		}
		else if (reading2 < 52 && reading2 >= 41)
		{
			//if 25 > temp > 20
			//Fan1+Fan2
			PORTD = 0b00000011;
		}
		else if (reading2 < 41 && reading2 >= 31)
		{
			//if 20 > temp > 15
			//Fan1+Compressor
			PORTD = 0b00000001;
		}
		else
		{
			//Everything off
			PORTD = 0b00000000;
		}
		
	}
	
}


