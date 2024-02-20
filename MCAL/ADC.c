 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Shamel Radwan
 *
 *******************************************************************************/

#include "ADC.h"
#include "../common_macros.h"
#include "../Atmega32_Registers.h" /* To use the IO Ports Registers */


/*
 * Description : function takes a struct of type ADC_ConfigType
 * Parameters: const ADC_ConfigType *Config_Ptr
 *
 */
void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	 /*  writing in the last 2 bits to choose the reference voltage   */
	ADMUX = (ADMUX &0x3F) | (Config_Ptr->ref_volt <<6);


	/*   ADC enable and writing in the first 3 bits to choose the prescaler */
	ADCSRA = (1<<ADEN) | ((ADCSRA&0xF8)| Config_Ptr->prescaler);



}


/*
 * Description : function takes the channel number to read the analog data from
 * Parameters: uint8 ch_num
 *
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/*choose channel number*/
	ADMUX =(ADMUX&0xE0) | (ch_num&0x07);

	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);

	/* wait till the flag is set*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/*  then clear it for future use*/
	CLEAR_BIT(ADCSRA,ADIF);


	return ADC;
}


