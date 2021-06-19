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
static void TaskCmdRxProcess(void* arg);
static void PreprocessCmd(results_t results);
static void CmdToAction(cmd_t cmd);
static int16_t CheckAndSetBrightness(int16_t value);
static bool IsAccurate(uint8_t accuracy);

/*******************************************************************************
 * Variables
 ******************************************************************************/
extern QueueHandle_t qResults;
static int16_t brightness = DEFAULT_BRIGHTNESS;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Creates a task to handle the received commands from CANopen.
 */
void LED_CMD_Init(void)
{
	xTaskCreate(TaskCmdRxProcess, "Rx Cmd Task", 512, NULL, 0, NULL);
}

/**
 * @brief This task waits on a queue to get the results from CANopen.
 * 				Once received, the command is pre-processed to check if it is
 * 				a repetitive result. CANopen sends the same result multiple times,
 * 				but it needs to be processed just once.
 */
static void TaskCmdRxProcess(void* arg)
{
	results_t results;

	while(1)
	{
		xQueueReceive(qResults, &results, portMAX_DELAY);
		PreprocessCmd(results);
	}
}

/**
 * @brief Checks if the command/label received is unique. If it is unique,
 * 				then a filter on accuracy is applied. If there was a pause between
 * 				two similar results, then the blink mode is turned on.
 * @param results The results received from CANOpen network.
 */
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

/**
 * @brief On receiving a valid command, PCA9957 LEDs are turned on.
 * @param cmd The command to which a certain action has to be performed.
 */
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

/**
 * @brief The brightness range for PCA9957 LED ranges from 0x00-0xFF.
 *        This function takes care of limiting and resetting the bounds.
 * @value The current value of the \var brightness.
 * @retval Returns the adjusted value, if it is outside the range.
 */
static int16_t CheckAndSetBrightness(int16_t value)
{
	//Turn-off blink for brighter and dimmer to see the changes.
	LED_BlinkOff();

	if (value < DEFAULT_BRIGHTNESS)
	{
		value = DEFAULT_BRIGHTNESS;
	}

	if(value > MAX_BRIGHTNESS)
	{
		value = MAX_BRIGHTNESS;
	}

	PRINTF("LED Intensity: %.2f %%\r\n", brightness*100/255.0);

	LED_SetBrightness(value);
	return value;
}

/**
 * @brief Simple function to check if the accuracy is sufficient.
 * @param accuracy Accuracy of the received label/command.
 * @retval Returns true if the accuracy is sufficient.
 */
static bool IsAccurate(uint8_t accuracy)
{
	return (accuracy >= CMD_ACCURACY_MIN);
}
