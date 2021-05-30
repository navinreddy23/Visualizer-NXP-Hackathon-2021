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
static void Init_HW(void);
void vApplicationStackOverflowHook (TaskHandle_t xTask,
								    signed char *pcTaskName);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

int main(void)
{
    Init_HW();

    PRINTF("\r\n\r\n--------------LED PCA9957-------------\r\n\r\n");

    LED_CmdYes();

    CANOpen_Init();

    LED_CMD_Init();

    vTaskStartScheduler();
}

static void Init_HW()
{
    /* Board pin, clock, debug console init */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    TIMER_Init();
    LED_Init();

#if USE_LEDS
    LIBCB_InitLeds();
#endif

    return;
}

void vApplicationStackOverflowHook (TaskHandle_t xTask, signed char *pcTaskName)
{
	(void)xTask;
	(void)pcTaskName;
	while(1);
}
/*----------------------- END OF FILE ----------------------------------*/
