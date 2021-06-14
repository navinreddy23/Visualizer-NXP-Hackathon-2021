#include "pin_mux.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "LED.h"
#include "CANOpen.h"
#include "LED_CMD.h"
#include "timer.h"

#include "FreeRTOS.h"
#include "task.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void InitializeHardware(void);
void vApplicationStackOverflowHook (TaskHandle_t xTask,
		signed char *pcTaskName);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Application entry point. Init hardware, create tasks, and start the OS.
 */
int main(void)
{
	InitializeHardware();

	PRINTF("\r\n\r\n--------------LED PCA9957-------------\r\n\r\n");

	//Turn on an LED to show that the system has booted.
	LED_CmdYes();

	//Create tasks and queues.
	CANOpen_Init();
	LED_CMD_Init();

	//Starts the OS
	vTaskStartScheduler();

	while(1);

	return 0;
}

/**
 * @brief Initialise the necessary peripherals, clock etc.
 */
static void InitializeHardware(void)
{
	/* Board pin, clock, debug console init */
	BOARD_ConfigMPU();
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	TIMER_Init();
	LED_Init();

	return;
}

/**
 * @brief FreeRTOS hook function to catch Stack Overflow issues.
 */
void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName)
{
	(void)xTask;
	(void)pcTaskName;
	while(1);
}
/*----------------------- END OF FILE ----------------------------------*/
