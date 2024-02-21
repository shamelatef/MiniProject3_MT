
 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Shamel Radwan
 *
 *******************************************************************************/

#include "PWM.h"
#include "gpio.h"
void PWM_Timer0_Start(uint8 duty_cycle)
{

	TCNT0 = 0;

	/* Set timer0 initial count to zero */

	if (duty_cycle > 100)
	{
		OCR0 =255;
	}

	else
	{
		OCR0 = duty_cycle;/**MAX_COMPARE/100;*/ /* Set the compare value */
	}
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);


	/* Configure timer control register TCCR0
	 *
	 * Fast PMW MODE ((1<<WGM01) | (1<<WGM00))
	 * non-inverting mode  (COM01)
	 * prescaler of 8  (CS01)
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);





}



