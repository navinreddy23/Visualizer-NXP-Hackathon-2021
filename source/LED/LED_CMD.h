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
	SILENCE,
	UNKNOWN,
	YES,
	NO,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ON,
	OFF,
	STOP,
	GO,
}cmd_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void LED_CMD_Init(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
static const char* cmdLabels[] = {
    "Silence",
    "Unknown",
    "yes",
    "no",
    "up",
    "down",
    "left",
    "right",
    "on",
    "off",
    "stop",
    "go"
};

#endif /* LED_LED_CMD_H_ */
