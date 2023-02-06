/*
 * Software Interrupts Control.c
 *
 * Created: 06-02-2023 16:40:28
 * Author : Abhishek Vishwakarma
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

ISR (ADC_vect)
{
	PORTC = 0b11111111;
	PORTD = 0b00000011;
}

int main(void)
{
	DDRC = 0b11111111;
	DDRD = 0b00000011;

	ADMUX = 0b01000101;// ADC5 is used here
	ADCSRA = 0b10001110;// interrupt ADIE is enabled
	sei();
	while (1)
	{
		ADCSRA |= 0b01000000; // start bit is High
		_delay_ms(300);
		PORTC = ADCL;
		PORTD = ADCH;
		_delay_ms(1000);
		
	}
}

