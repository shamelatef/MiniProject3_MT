/*
 * main.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Shamel Radwan
 */

#include "HAL/DcMotor.h"
#include "HAL/lcd.h"
#include "HAL/lm35_sensor.h"
#include "MCAL/ADC.h"
#include "std_types.h"
#include "MCAL/gpio.h"


#define STRINGIFY(x) #x

int main(void)

{

	uint8 temp;

	ADC_ConfigType config;
	config.ref_volt = INTERNAL;
	config.prescaler = PRESCALER_8;
	ADC_init(&config);



	LCD_init();


	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	DcMotor_Init();

	LCD_moveCursor(0,4);
	LCD_displayString("FAN is ");

	LCD_moveCursor(1,4);
	LCD_displayString("Temp=   c");



	//Timer0_Fast_PWM_Init(25);
	while (1)
	{
		temp = LM35_getTemperature();

		LCD_moveCursor(1,9);


		if (temp < 30)
		{
			LCD_moveCursor(0,11);
			LCD_displayString(STRINGIFY(OFF));
			DcMotor_Rotate(ACW,0);
			LCD_moveCursor(1,9);

		}
		else if (temp >= 30 && temp <60)
		{
			LCD_moveCursor(0,11);
			LCD_displayString(STRINGIFY(ON));
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(1,9);

		}
		else if (temp >= 60 && temp <90)
		{
			LCD_moveCursor(0,11);
			LCD_displayString(STRINGIFY(ON));
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(1,9);		}

		else if (temp >= 90 && temp <120)
		{
			LCD_moveCursor(0,11);
			LCD_displayString(STRINGIFY(ON));
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(1,9);
		}

		else if (temp >=120)
		{
			LCD_moveCursor(0,11);
			LCD_displayString(STRINGIFY(ON));
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(1,9);
		}




		if(temp >= 100)
		{
			LCD_intgerToString(temp);

		}
		else
		{
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
		}


	}



	return 0;
}
