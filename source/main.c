/**************************************************************************
MODULE:    MAIN
CONTAINS:  Example application using MicroCANopen
           NXP i.MX RT 10xx derivatives with CAN interface.
COPYRIGHT: (c) Embedded Systems Academy (EmSA) 2002-2020
           All rights reserved. www.em-sa.com/nxp
DISCLAIM:  Read and understand our disclaimer before using this code!
           www.esacademy.com/disclaim.htm
           This software was written in accordance to the guidelines at
           www.esacademy.com/software/softwarestyleguide.pdf
LICENSE:   THIS IS THE NXP SDK VERSION OF MICROCANOPEN PLUS
           Licensed under a modified BSD License. See LICENSE.INFO
           file in the project root for full license information.
VERSION:   7.10, ESA 20-SEP-02
           $LastChangedDate: 2020-09-03 22:04:52 +0200 (Thu, 03 Sep 2020) $
           $LastChangedRevision: 5038 $
***************************************************************************/

#include "mcop_inc.h"
#include "LED.h"

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
void Init_HW(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
const char* labels[] = {
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

static uint8_t prevCmd = BACKGROUND;
static int8_t brightness = 10;
static uint8_t brightness_delta = 5;
/*******************************************************************************
 * Code
 ******************************************************************************/
void ProcessCmd(cmd_t cmd)
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
		brightness += brightness_delta;
		break;
	case DIMMER:
		brightness -= brightness_delta;
		break;
	default:
		break;
	}

	if (brightness < 1)
	{
		brightness = 1;
	}

	LED_SetBrightness(brightness);
}

/*******************************************************************************
 * DOES:    USER Process, here simple I/O example
 * RETURNS: nothing
 ******************************************************************************/
void USER_Process(void)
{
	uint8_t cmd;
	uint8_t accuracy;
   // Process all output data from CANopen, COS change of state detection
    MCO_ReadProcessData(&(cmd), 1, P610001_VC_Command);
    MCO_ReadProcessData(&(accuracy), 1, P610002_VC_Accuracy);

    if (cmd == BACKGROUND)
    {
    	prevCmd = cmd;
    	return;
    }

    if (prevCmd != cmd)
    {
    	prevCmd = cmd;

    	if (accuracy >= 80)
    	{
    		PRINTF("\r\nCommand: %s, Accuracy: %u\r\n", labels[cmd], accuracy);
    		ProcessCmd(cmd);
    	}
    }
}

/**************************************************************************
DOES:    The main function
RETURNS: nothing
**************************************************************************/
int main(void)
{
    // Initialize hardware components needed for this example
    Init_HW();

#if USE_CANOPEN_FD
    PRINTF("\r\nStarting CANopen FD Library slave example\r\n");
#else
    PRINTF("\r\n\r\n--------------------------Slave-----------------------------\r\n\r\n");
#endif
    PRINTF("Provided by EmSA - www.em-sa.com/nxp\r\n");

    // Reset/Initialize CANopen communication
    MCOUSER_ResetCommunication();

    // foreground loop
    while (1)
    {
#if (USE_REMOTE_ACCESS)
        MCORA_ProcessHost();
#endif

        // Operate on CANopen protocol stack
        MCO_ProcessStack();

        // Operate on application
        if (MY_NMT_STATE == NMTSTATE_OP)
        { // only when we are operational
            USER_Process();
        }

        // Check for CAN Err, auto-recover
        if (MCOHW_GetStatus() & HW_BOFF)
        {
            MCOUSER_FatalError(0xF6F6);
        }

    } // end of while(1)
} // end of main

/*******************************************************************************
 * DOES:    Initialize hardware components needed for this example
 * RETURNS: nothing
 ******************************************************************************/
void Init_HW()
{
    /* Board pin, clock, debug console init */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    /* Update the core clock */
//    SystemCoreClockUpdate();

//    /* Set PERCLK_CLK source to OSC_CLK*/
//    CLOCK_SetMux(kCLOCK_PerclkMux, 1U);
//    /* Set PERCLK_CLK divider to 2 */
//    CLOCK_SetDiv(kCLOCK_PerclkDiv, 1U);
//
//    /* Avoiding CAN_CLOCK_CHECK_NO_AFFECTS error in case semihosting console is used */
//    CLOCK_EnableClock(kCLOCK_Lpuart1);

    LED_Init();

#if USE_LEDS
    // Initialize status LEDs
    LIBCB_InitLeds();
#endif

    // initialize timer interrupt - 1ms period
    SysTick_Config(SystemCoreClock / 1000U);

    LED_CmdYes();

    return;
}

/*******************************************************************************
 * DOES:    System Tick handler, execute every 1 ms
 * RETURNS: nothing
 ******************************************************************************/
void SysTick_Handler(void)
{
    MCOHW_Tick(); // Call CANopen stack tick function
}

#if (defined(__CC_ARM)) || (defined(__ARMCC_VERSION)) || (defined(__ICCARM__)) || \
    (defined(__GNUC__) && !defined(__REDLIB__))
void __assertion_failed(char *failedExpr)
{
    PRINTF("ASSERT ERROR \" %s \n", failedExpr);
    for (;;)
    {
        __BKPT(0);
    }
}
#endif

/*----------------------- END OF FILE ----------------------------------*/
