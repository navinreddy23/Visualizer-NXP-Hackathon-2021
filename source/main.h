/*
 * main.h
 *
 *  Created on: 30 May 2021
 *      Author: navin
 */
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

#ifndef MAIN_H_
#define MAIN_H_

/*******************************************************************************
 * Prototypes
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



#endif /* MAIN_H_ */
