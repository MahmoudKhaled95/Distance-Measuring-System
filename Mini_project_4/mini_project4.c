/******************************************************************************
 *
 * [File Name]: mini_project4.c
 *
 * [Description]: Measure the distance using Ultrasonic sensor
 *
 * [Author]: Mahmoud Khaled
 *
 * [Microcontroller]: Atmega 16
 *
 * [Created on]: Jun 29, 2022
 *
 *******************************************************************************/


#include "ultrasonic.h"
#include "lcd.h"
#include "icu.h"
#include <avr/io.h> /* To use the SREG register */

#define F_CPU 8000000

uint16 g_distance = 0;

int main(void)
{
	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	Ultrasonic_init();		/* initialize Ultrasonic sensor driver */

	LCD_init();				/* initialize LCD driver */

	/* Display this string "Distance = " only once on LCD at the first row */
	LCD_displayStringRowColumn(0,0,"Distance =    cm");


	while(1)
	{
		g_distance = Ultrasonic_readDistance();
		LCD_moveCursor(0,10);
		/* Display the distance value every time at same position */
		if(g_distance >= 100)
		{
			LCD_intgerToString(g_distance);
		}
		else
		{
			LCD_intgerToString(g_distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}
