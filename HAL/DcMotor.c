/*
 * DcMotor.c
 *
 *	Description: source file for Dc motor module.
 *  Created on: Feb 19, 2024
 *      Author: Shamel Radwan
 */

#include "DcMotor.h"
#include "../MCAL/gpio.h"
#include "../MCAL/PWM.h"
#include "../common_macros.h"
#include "../Atmega32_Registers.h"
void DcMotor_Init(void)
{
	/*set the direction of the 2 motor pins as input*/
	GPIO_setupPinDirection(PORTB_ID, MOTOR_IN1, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, MOTOR_IN2, PIN_OUTPUT);

	/*Stop the motor at the beginning*/
	CLEAR_BIT(PORTB,MOTOR_IN1);
	CLEAR_BIT(PORTB,MOTOR_IN2);


}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	/*Motor direction*/
	if (state == CW)
	{
		SET_BIT(PORTB,MOTOR_IN1);
		CLEAR_BIT(PORTB,MOTOR_IN2);

	}
	else
	{
		CLEAR_BIT(PORTB,MOTOR_IN1);
		SET_BIT(PORTB,MOTOR_IN2);

	}
	if (speed == 0)
	{
		CLEAR_BIT(PORTB,MOTOR_IN1);
		CLEAR_BIT(PORTB,MOTOR_IN2);

	}
	/*Motor speed*/
	Timer0_Fast_PWM_Init(speed);
}


