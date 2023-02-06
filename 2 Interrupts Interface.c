/*
 * Interrupts2.c
 *
 * Created: 05-02-2023 13:58:07
 * Author : Abhishek Vishwakarma
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

// Interrupt Service Routine
ISR (INT0_vect)
{
	PORTA = 0b11110000;
	_delay_ms(300);
	PORTA = 0b00001111;
	_delay_ms(300);
	PORTA = 0b11110000;
	_delay_ms(300);
	PORTA = 0b00001111;
	_delay_ms(300);
}
ISR (INT2_vect)
{
	PORTA = 0b11000000;
	_delay_ms(300);
	PORTA = 0b00001100;
	_delay_ms(300);
	PORTA = 0b00110000;
	_delay_ms(300);
	PORTA = 0b00000011;
	_delay_ms(300);
}

int main(void)
{
	MCUCR = 0b00000011; // INT0 -> Rising Edge Trigger
	MCUCSR &= ~0b01000000; // INT2 -> Falling Edge Trigger
	GICR = 0b01100000; // Enabled INT0 and INT2
	DDRA = 0b11111111;
	sei();
	while (1)
	{
		// Default Execution of Main Routine
		for (int i = 0; i<8; i =i+1)
		{
			PORTA = (1<<i);
			_delay_ms(300);
		}
	}
}