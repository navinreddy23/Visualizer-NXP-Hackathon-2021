/*
 * LED_CMD.h
 *
 *  Created on: 30 May 2021
 *      Author: navin
 */

#ifndef LED_LED_CMD_H_
#define LED_LED_CMD_H_

/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
	BACKGROUND,
	BRIGHTER,
	DIMMER,
	DOWN,
	GO,
	LEFT,
	NO,
	OFF,
	ON,
	RIGHT,
	STOP,
	UP,
	YES
}cmd_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void LED_CMD_Init(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const char* cmdLabels[] = {
		"background",
		"brighter",
		"dimmer",
		"down",
		"go",
		"left",
		"no",
		"off",
		"on",
		"right",
		"stop",
		"up",
		"yes"
};

#endif /* LED_LED_CMD_H_ */
