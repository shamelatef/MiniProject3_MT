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


#ifndef ADC_H_
#define ADC_H_
#include "../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/



#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


/* ......Enum contains values for the ADMUX register for bits 6,7..............     */
typedef enum{

	EXTERNAL,AVCC,RESERVED,INTERNAL

}ADC_ReferenceVoltage;

/* ......Enum contains values for the ADRSA register for bits 0,1,2,3 ..............     */

typedef enum{

	PRESCALER_2=1,PRESCALER_4,PRESCALER_8,PRESCALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128
}ADC_Prescaler;

/*
 * Description:
 * 				Structure with 2 parameters that should be passed to the
 * 				init function to choose the reference voltage and the prescaler
 *
 * */

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;




/*
 * Description : function takes a struct of type ADC_ConfigType
 * Parameters: const ADC_ConfigType *Config_Ptr
 *
 */
void ADC_init(const ADC_ConfigType *Config_Ptr);

/*
 * Description : function takes the channel number to read the analog data from
 * Parameters: uint8 ch_num
 *
 */
uint16 ADC_readChannel(uint8 ch_num);





#endif /* ADC_H_ */
