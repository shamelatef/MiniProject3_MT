

 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Shamel Radwan
 *
 *******************************************************************************/


#include "../Atmega32_Registers.h"

#define MAX_COMPARE 255
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


/*
 * Description : function takes duty cycle from 0-100 and convert it to 0--255
 * Parameters: uint8 duty_cycle

 *
 */
void PWM_Timer0_Start(uint8 duty_cycle);
