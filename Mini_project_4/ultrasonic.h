/******************************************************************************
 *
 * [Module]: HC-SR04
 *
 * [File Name]: ultrasonic.h
 *
 * [Description]: Header file for the AVR HC-SR04 driver
 *
 * [Author]: Mahmoud Khaled
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"


/************************************************************************
 * 							Functions Declaration						*
 ************************************************************************/
/*
 * Description:
 	 * Initialize the ICU driver as required.
 	 * Setup the ICU call back function.
 	 * Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void);


/*
 * Description:
 	 * Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_Trigger(void);


/*
Description
 	 * Send the trigger pulse by using Ultrasonic_Trigger function.
 	 * Start the measurements by the ICU from this moment.
 * Inputs: None
 * Return: The measured distance in Centimeter.
*/
uint16 Ultrasonic_readDistance(void);


/*
 * Description:
 	 * This is the call back function called by the ICU driver.
 	 * This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);

#endif /* ULTRASONIC_H_ */
