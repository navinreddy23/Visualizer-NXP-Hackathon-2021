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
#define BRIGHTNESS_DELTA		5
#define CMD_ACCURACY_MIN		90
#define MAX_BRIGHTNESS 			0xFF
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TaskCmdRxPrcoess(void* arg);
static void PreprocessCmd(results_t results);
static void CmdToAction(cmd_t cmd);
static int16_t CheckAndSetBrightness(int16_t val);
static bool IsAccurate(uint8_t accuracy);
/*******************************************************************************
 * Variables
 ******************************************************************************/
extern QueueHandle_t qResults;
static int16_t brightness = DEFAULT_BRIGHTNESS;
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
	static bool paused = false;
	static uint8_t cmdCount = 0;

	uint8_t cmd;
	uint8_t accuracy;

	cmd = results.label;
	accuracy = results.accuracy;

	if (cmd == BACKGROUND)
	{
		paused = true;
		return;
	}

	if (prevCmd != cmd)
	{
		LED_BlinkOff();
		prevCmd = cmd;

		if(!IsAccurate(accuracy))
			return;

		cmdCount++;
		PRINTF("\r\nCommand: %s, Accuracy: %u\r\n", cmdLabels[cmd], accuracy);
		CmdToAction(cmd);
	}
	else if(paused)
	{
		//Check if there was a pause (background) between commands.
		paused = !paused;

		if(cmdCount == 0 && IsAccurate(accuracy))
		{
			LED_BlinkOn(10, 128);
			CmdToAction(cmd);
		}
		cmdCount = 0;
	}
	//Note: The same command is received multiple times due to the CANOpen refresh times.
	//The above condition takes care to filter the CMD and blinks only if the same CMD is
	//spoken twice atleast.
}

static void CmdToAction(cmd_t cmd)
{

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
		brightness = CheckAndSetBrightness(brightness);
		break;
	case DIMMER:
		brightness -= BRIGHTNESS_DELTA;
		brightness = CheckAndSetBrightness(brightness);
		break;
	default:
		break;
	}
}

static int16_t CheckAndSetBrightness(int16_t val)
{
	//Turn-off blink for brighter and dimmer to see the changes.
	LED_BlinkOff();

	if (val < DEFAULT_BRIGHTNESS)
	{
		val = DEFAULT_BRIGHTNESS;
	}



	if(val > MAX_BRIGHTNESS)
	{
		val = MAX_BRIGHTNESS;
	}

	PRINTF("LED Intensity: %.2f %%\r\n", brightness*100/255.0);

	LED_SetBrightness(val);
	return val;

}
static bool IsAccurate(uint8_t accuracy)
{
	return (accuracy >= CMD_ACCURACY_MIN);
}
