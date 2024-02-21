/*
 * FanController.c
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



int main(void)

{

	uint8 temp;

	ADC_ConfigType config;
	config.ref_volt = INTERNAL;
	config.prescaler = PRESCALER_8;
	ADC_init(&config);



	LCD_init();


	DcMotor_Init();

	LCD_moveCursor(0,1);
	LCD_displayString("FAN is ");

	LCD_moveCursor(1,4);
	LCD_displayString("Temp=   c");



	//Timer0_Fast_PWM_Init(25);
	while (1)
	{
		temp = LM35_getTemperature();

		LCD_moveCursor(0,8);


		if (temp < 30)
		{
			LCD_displayString("OFF(0%)");
			LCD_displayCharacter(' ');

			DcMotor_Rotate(ACW,0);

		}
		else if (temp >= 30 && temp <60)
		{
			LCD_displayString("ON(25%)");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);

		}
		else if (temp >= 60 && temp <90)
		{
			LCD_displayString("ON(50%)");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
		}

		else if (temp >= 90 && temp <120)
		{
			LCD_displayString("ON(75%)");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
		}

		else if (temp >=120)
		{
			LCD_displayString("ON(100%)");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);
		}

		LCD_moveCursor(1,9);



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
