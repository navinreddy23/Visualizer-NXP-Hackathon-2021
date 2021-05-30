#include "mcop_inc.h"
#include "LED.h"
#include "main.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void Init_HW(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

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

int main(void)
{
    Init_HW();

    PRINTF("\r\n\r\n--------------LED PCA9957-------------\r\n\r\n");

    LED_CmdYes();

    MCOUSER_ResetCommunication();

    while (1)
    {
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
    }
}

static void Init_HW()
{
    /* Board pin, clock, debug console init */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    LED_Init();

#if USE_LEDS
    LIBCB_InitLeds();
#endif

    // initialize timer interrupt - 1ms period
    SysTick_Config(SystemCoreClock / 1000U);

    return;
}

void SysTick_Handler(void)
{
    MCOHW_Tick();
}
/*----------------------- END OF FILE ----------------------------------*/
