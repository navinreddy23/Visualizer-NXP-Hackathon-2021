/*
 * PCA9957.h
 *
 *  Created on: May 19, 2021
 *      Author: navin
 */

#ifndef LED_PCA9957_H_
#define LED_PCA9957_H_

/* PCA9957HN Registers */

typedef enum
{
	MODE1 = 0x00,
	MODE2 = 0x01,
	EFLAG0 = 0x02,
	EFLAG1 = 0x03,
	EFLAG2 = 0x04,
	EFLAG3 = 0x05,
	EFLAG4 = 0x06,
	EFLAG5 = 0x07,
	LEDOUT0 = 0x08,
	LEDOUT1 = 0x09,
	LEDOUT2 = 0x0a,
	LEDOUT3 = 0x0b,
	LEDOUT4 = 0x0c,
	LEDOUT5 = 0x0d,
	GRPPWM = 0x0e,
	GRPFREQ = 0x0f,
	PWM_0 = 0x10,
	PWM_1 = 0x11,
	PWM_2 = 0x12,
	PWM_3 = 0x13,
	PWM_4 = 0x14,
	PWM_5 = 0x15,
	PWM_6 = 0x16,
	PWM_7 = 0x17,
	PWM_8 = 0x18,
	PWM_9 = 0x19,
	PWM_10 = 0x1a,
	PWM_11 = 0x1b,
	PWM_12 = 0x1c,
	PWM_13 = 0x1d,
	PWM_14 = 0x1e,
	PWM_15 = 0x1f,
	PWM_16 = 0x20,
	PWM_17 = 0x21,
	PWM_18 = 0x22,
	PWM_19 = 0x23,
	PWM_20 = 0x24,
	PWM_21 = 0x25,
	PWM_22 = 0x26,
	PWM_23 = 0x27,
	IREF0 = 0x28,
	IREF1 = 0x29,
	IREF2 = 0x2a,
	IREF3 = 0x2b,
	IREF4 = 0x2c,
	IREF5 = 0x2d,
	IREF6 = 0x2e,
	IREF7 = 0x2f,
	IREF8 = 0x30,
	IREF9 = 0x31,
	IREF10 = 0x32,
	IREF11 = 0x33,
	IREF12 = 0x34,
	IREF13 = 0x35,
	IREF14 = 0x36,
	IREF15 = 0x37,
	IREF16 = 0x38,
	IREF17 = 0x39,
	IREF18 = 0x3a,
	IREF19 = 0x3b,
	IREF20 = 0x3c,
	IREF21 = 0x3d,
	IREF22 = 0x3e,
	IREF23 = 0x3f,
	RAMP_RATE_GRP0 = 0x40,
	STEP_TIME_GRP0 = 0x41,
	HOLD_CNTL_GRP0 = 0x42,
	IREF_GRP0 = 0x43,
	RAMP_RATE_GRP1 = 0x44,
	STEP_TIME_GRP1 = 0x45,
	HOLD_CNTL_GRP1 = 0x46,
	IREF_GRP1 = 0x47,
	RAMP_RATE_GRP2 = 0x48,
	STEP_TIME_GRP2 = 0x49,
	HOLD_CNTL_GRP2 = 0x4a,
	IREF_GRP2 = 0x4b,
	RAMP_RATE_GRP3 = 0x4c,
	STEP_TIME_GRP3 = 0x4d,
	HOLD_CNTL_GRP3 = 0x4e,
	IREF_GRP3 = 0x4f,
	RAMP_RATE_GRP4 = 0x50,
	STEP_TIME_GRP4 = 0x51,
	HOLD_CNTL_GRP4 = 0x52,
	IREF_GRP4 = 0x53,
	RAMP_RATE_GRP5 = 0x54,
	STEP_TIME_GRP5 = 0x55,
	HOLD_CNTL_GRP5 = 0x56,
	IREF_GRP5 = 0x57,
	GRAD_MODE_SEL0 = 0x58,
	GRAD_MODE_SEL1 = 0x59,
	GRAD_MODE_SEL2 = 0x5a,
	GRAD_GRP_SEL0 = 0x5b,
	GRAD_GRP_SEL1 = 0x5c,
	GRAD_GRP_SEL2 = 0x5d,
	GRAD_GRP_SEL3 = 0x5e,
	GRAD_GRP_SEL4 = 0x5f,
	GRAD_GRP_SEL5 = 0x60,
	GRAD_GRP_SEL6 = 0x61,
	GRAD_GRP_SEL7 = 0x62,
	GRAD_GRP_SEL8 = 0x63,
	GRAD_GRP_SEL9 = 0x64,
	GRAD_GRP_SEL10 = 0x65,
	GRAD_GRP_SEL11 = 0x66,
	GRAD_CNTL0 = 0x67,
	GRAD_CNTL1 = 0x68,
	OFFSET = 0x69,
	PWMALL = 0x6a,
	IREFALL = 0x6b,
}PCA9957_reg_t;


#endif /* LED_PCA9957_H_ */
