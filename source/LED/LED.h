/*
 * LED.h
 *
 *  Created on: May 19, 2021
 *      Author: navin
 */

#ifndef LED_LED_H_
#define LED_LED_H_

#include "PCA9957.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void LED_Init(void);
void LED_Delay(uint32_t delay);
void LED_Delay(uint32_t delay);
void LED_WriteReg(PCA9957_reg_t reg, uint8_t value);
void LED_SetBrightness(uint8_t value);

void LED_AllOn(void);
void LED_AllOff(void);
void LED_BlinkOn(uint8_t freq, uint8_t pwm);
void LED_BlinkOff(void);

void LED_CmdLeft(void);
void LED_CmdRight(void);
void LED_CmdUp(void);
void LED_CmdDown(void);

void LED_CmdYes(void);
void LED_CmdNo(void);

void LED_CmdStop(void);
void LED_CmdGo(void);

void LED_RedTest(void);

#endif /* LED_LED_H_ */
