/*
 * LED.c
 *
 *  Created on: May 19, 2021
 *      Author: navin
 */

#include "fsl_lpspi.h"
#include "LED.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LPSPI_TRANSFER_SIZE     64U     /*! Transfer dataSize */
#define LPSPI_TRANSFER_BAUDRATE 500000U /*! Transfer baudrate - 500k */

#define BOARD_EEPROM_LPSPI_BASEADDR (LPSPI1)
#define BOARD_LPSPI_IRQN            LPSPI1_IRQn
#define BOARD_LPSPI_IRQHandler      LPSPI1_IRQHandler

#define BOARD_LPSPI_PCS_FOR_INIT     (kLPSPI_Pcs0)
#define BOARD_LPSPI_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

/* Select USB1 PLL PFD0 (392.72 MHz) as lpspi clock source */
#define BOARD_LPSPI_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master lpspi clock source */
#define BOARD_LPSPI_CLOCK_SOURCE_DIVIDER (7U)

#define BOARD_LPSPI_CLK_FREQ (CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk) / (BOARD_LPSPI_CLOCK_SOURCE_DIVIDER + 1U))

#define BLINK_MODE 0xFF
#define PWM_MODE 0xAA
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
lpspi_transfer_t masterXfer;
uint8_t masterRxData[LPSPI_TRANSFER_SIZE] = {0};
uint8_t masterTxData[LPSPI_TRANSFER_SIZE] = {0};
static uint8_t m_brightness = 1;

static void LED_SPI_Init(void);
static void LED_SPI_Transfer(uint8_t* pArray, uint8_t size);
/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initialise the SPI driver.
 */
void LED_Init(void)
{
	LED_SPI_Init();
}

/**
 * @brief A simple for-loop delay to provide a brief interval between two
 * 				SPI transcations.
 * @param delay The loop count value.
 */
void LED_Delay(uint32_t delay)
{
	for(uint32_t i = 0; i < delay; i++);
}

/**
 * @brief This function writes the register address followed by the value
 *       to PCA9957.
 * @param reg Register address value from PCA9957.h
 * @param value The value of the reg to be set.
 */
void LED_WriteReg(PCA9957_reg_t reg, uint8_t value)
{
	masterTxData[0] = (uint8_t)reg << 1;
	masterTxData[1] = value;

	LED_SPI_Transfer(masterTxData, 2);
	LED_Delay(400);
}

/**
 * @brief Function to set the brightness of all the LED's on PCA9957
 */
void LED_SetBrightness(uint8_t value)
{
	m_brightness = value;
	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turns-off all the LED's on PCA9957
 */
void LED_AllOff(void)
{
	LED_WriteReg(IREFALL, 0x00);
}

/**
 * @brief Turns-on all the LED's on PCA9957
 */
void LED_AllOn(void)
{
	LED_WriteReg(IREFALL, 0xFF);
	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Sets all the LED's to blink mode.
 * @param frequency The blink frequency in the range 0-255
 * @param pwm The duty cycle for blinking in the range 0-255
 */
void LED_BlinkOn(uint8_t frequency, uint8_t pwm)
{
	LED_WriteReg(LEDOUT0, BLINK_MODE);
	LED_WriteReg(LEDOUT1, BLINK_MODE);
	LED_WriteReg(LEDOUT2, BLINK_MODE);
	LED_WriteReg(LEDOUT3, BLINK_MODE);
	LED_WriteReg(LEDOUT4, BLINK_MODE);
	LED_WriteReg(LEDOUT5, BLINK_MODE);

	LED_WriteReg(MODE2, 0x21);
	LED_WriteReg(GRPFREQ, frequency);
	LED_WriteReg(GRPPWM, pwm);
}

/**
 * @brief Turn-off the blink mode.
 */
void LED_BlinkOff(void)
{
	LED_WriteReg(LEDOUT0, PWM_MODE);
	LED_WriteReg(LEDOUT1, PWM_MODE);
	LED_WriteReg(LEDOUT2, PWM_MODE);
	LED_WriteReg(LEDOUT3, PWM_MODE);
	LED_WriteReg(LEDOUT4, PWM_MODE);
	LED_WriteReg(LEDOUT5, PWM_MODE);
}

/**
 * @brief Turns on the Left four LED's on PCA9957-ARD board.
 */
void LED_CmdLeft(void)
{
	LED_AllOff();

	LED_WriteReg(IREF16, 0xFF);
	LED_WriteReg(IREF17, 0xFF);
	LED_WriteReg(IREF15, 0xFF);
	LED_WriteReg(IREF19, 0xFF);

	LED_WriteReg(IREF10, 0xFF);
	LED_WriteReg(IREF11, 0xFF);
	LED_WriteReg(IREF1, 0xFF);
	LED_WriteReg(IREF2, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the Right four LED's on PCA9957-ARD board.
 */
void LED_CmdRight(void)
{
	LED_AllOff();

	LED_WriteReg(IREF20, 0xFF);
	LED_WriteReg(IREF21, 0xFF);
	LED_WriteReg(IREF22, 0xFF);
	LED_WriteReg(IREF23, 0xFF);

	LED_WriteReg(IREF4, 0xFF);
	LED_WriteReg(IREF5, 0xFF);
	LED_WriteReg(IREF7, 0xFF);
	LED_WriteReg(IREF8, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the top four LED's on PCA9957-ARD board.
 */
void LED_CmdUp(void)
{
	LED_AllOff();

	LED_WriteReg(IREF4, 0xFF);
	LED_WriteReg(IREF5, 0xFF);
	LED_WriteReg(IREF10, 0xFF);
	LED_WriteReg(IREF11, 0xFF);
	LED_WriteReg(IREF19, 0xFF);
	LED_WriteReg(IREF23, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the bottom four LED's on PCA9957-ARD board.
 */
void LED_CmdDown(void)
{
	LED_AllOff();

	LED_WriteReg(IREF1, 0xFF);
	LED_WriteReg(IREF2, 0xFF);
	LED_WriteReg(IREF7, 0xFF);
	LED_WriteReg(IREF8, 0xFF);
	LED_WriteReg(IREF16, 0xFF);
	LED_WriteReg(IREF20, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the Green LED on top-right corner on PCA9957-ARD board.
 */
void LED_CmdYes(void)
{
	LED_AllOff();

	LED_WriteReg(IREF10, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the Blue LED on top-right corner on PCA9957-ARD board.
 */
void LED_CmdNo(void)
{
	LED_AllOff();

	LED_WriteReg(IREF11, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the four Blue LED's on four corners of PCA9957-ARD board.
 */
void LED_CmdStop(void)
{
	LED_AllOff();

	LED_WriteReg(IREF11, 0xFF);
	LED_WriteReg(IREF2, 0xFF);
	LED_WriteReg(IREF8, 0xFF);
	LED_WriteReg(IREF5, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Turn-on the four Green LED's on four corners of PCA9957-ARD board.
 */
void LED_CmdGo(void)
{
	LED_AllOff();

	LED_WriteReg(IREF10, 0xFF);
	LED_WriteReg(IREF1, 0xFF);
	LED_WriteReg(IREF7, 0xFF);
	LED_WriteReg(IREF4, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Test function to check if the Red LED's are functional.
 */
void LED_RedTest(void)
{
	LED_AllOff();

	LED_WriteReg(IREF9, 0xFF);
	LED_WriteReg(IREF0, 0xFF);
	LED_WriteReg(IREF6, 0xFF);
	LED_WriteReg(IREF3, 0xFF);

	LED_WriteReg(PWMALL, m_brightness);
}

/**
 * @brief Initialize SPI.
 */
static void LED_SPI_Init(void)
{
	/*Set clock source for LPSPI*/
	CLOCK_SetMux(kCLOCK_LpspiMux, BOARD_LPSPI_CLOCK_SOURCE_SELECT);
	CLOCK_SetDiv(kCLOCK_LpspiDiv, BOARD_LPSPI_CLOCK_SOURCE_DIVIDER);

	lpspi_master_config_t masterConfig;

	/* Master config */
	masterConfig.baudRate                      = 500000U;
	masterConfig.bitsPerFrame                  = 8;
	masterConfig.cpol                          = kLPSPI_ClockPolarityActiveHigh;
	masterConfig.cpha                          = kLPSPI_ClockPhaseFirstEdge;
	masterConfig.direction                     = kLPSPI_MsbFirst;
	masterConfig.whichPcs                      = BOARD_LPSPI_PCS_FOR_INIT;
	masterConfig.pcsActiveHighOrLow            = kLPSPI_PcsActiveLow;
	masterConfig.pinCfg                        = kLPSPI_SdiInSdoOut;
	masterConfig.dataOutConfig                 = kLpspiDataOutTristate;
	masterConfig.pcsToSckDelayInNanoSec        = 1000000000 / masterConfig.baudRate;
	masterConfig.lastSckToPcsDelayInNanoSec    = 1000000000 / masterConfig.baudRate;
	masterConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.baudRate;

	LPSPI_MasterInit(BOARD_EEPROM_LPSPI_BASEADDR, &masterConfig, BOARD_LPSPI_CLK_FREQ);
}

/**
 * @brief Transfer data on the SPI bus.
 * @param pArray pointer to the array that has to be sent
 * @param size The length of the array.
 */
static void LED_SPI_Transfer(uint8_t* pArray, uint8_t size)
{
	masterXfer.txData      = pArray;
	masterXfer.rxData      = NULL;
	masterXfer.dataSize    = size;
	masterXfer.configFlags = BOARD_LPSPI_PCS_FOR_TRANSFER | kLPSPI_MasterPcsContinuous;
	LPSPI_MasterTransferBlocking(BOARD_EEPROM_LPSPI_BASEADDR, &masterXfer);
}
