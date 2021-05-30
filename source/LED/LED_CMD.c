/*
 * LED_CMD.c
 *
 *  Created on: 30 May 2021
 *      Author: navin
 */
#include "LED.h"
#include "LED_CMD.h"
#include "CANOpen.h"
#include "timer.h"
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEFAULT_BRIGHTNESS	1
#define BRIGHTNESS_DELTA	5
#define CMD_ACCURACY_MIN	80
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TaskCmdRxPrcoess(void* arg);
static void PreprocessCmd(results_t results);
static void CmdToAction(cmd_t cmd);
static void CheckAndSetBrightness(int8_t val);
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern QueueHandle_t qResults;

/*******************************************************************************
 * Code
 ******************************************************************************/
void LED_CMD_Init(void)
{
	xTaskCreate(TaskCmdRxPrcoess, "Rx Cmd Task", 512, NULL, 0, NULL);
}

static void TaskCmdRxPrcoess(void* arg)
{
	results_t results;

	while(1)
	{
		xQueueReceive(qResults, &results, portMAX_DELAY);
		PreprocessCmd(results);
	}
}

static void PreprocessCmd(results_t results)
{
	static uint8_t prevCmd = BACKGROUND;
	uint8_t cmd;
	uint8_t accuracy;

	cmd = results.label;
	accuracy = results.accuracy;

	if (cmd == BACKGROUND)
	{
		prevCmd = cmd;
		return;
	}

	if (prevCmd != cmd)
	{
		prevCmd = cmd;

		if (accuracy >= CMD_ACCURACY_MIN)
		{
			PRINTF("\r\nCommand: %s, Accuracy: %u\r\n", cmdLabels[cmd], accuracy);
			CmdToAction(cmd);
		}
	}
}

static void CmdToAction(cmd_t cmd)
{
	static int8_t brightness = DEFAULT_BRIGHTNESS;

	switch(cmd)
	{
	case YES:
		LED_CmdYes();
		break;
	case NO:
		LED_CmdNo();
		break;
	case UP:
		LED_CmdUp();
		break;
	case DOWN:
		LED_CmdDown();
		break;
	case LEFT:
		LED_CmdLeft();
		break;
	case RIGHT:
		LED_CmdRight();
		break;
	case GO:
		LED_CmdGo();
		break;
	case STOP:
		LED_CmdStop();
		break;
	case ON:
		LED_AllOn();
		break;
	case OFF:
		LED_AllOff();
		break;
	case BRIGHTER:
		brightness += BRIGHTNESS_DELTA;
		CheckAndSetBrightness(brightness);
		break;
	case DIMMER:
		brightness -= BRIGHTNESS_DELTA;
		CheckAndSetBrightness(brightness);
		break;
	default:
		break;
	}
}

static void CheckAndSetBrightness(int8_t val)
{
	if (val < 1)
	{
		val = 1;
	}

	LED_SetBrightness(val);
}
