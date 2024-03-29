/**************************************************************************
MODULE:    NODECFG.H
CONTAINS:  MicroCANopen node configuration
HERE:      Slave Device, Full Functionality Configuration
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

#ifndef _NODECFG_H
#define _NODECFG_H

// Hardware configuration
#include "mcohw_cfg.h"

/* CANopen Data Types */
#include "mco_types.h"

/*
 * Note: All settings below are for informational purposes only and
 *       must not be changed in projects that use the NXP SDK library
 *       version of MicroCANopen. Changes here will not affect the
 *       delivered library and may lead to applications that fail to
 *       build or perform.
 */

/**************************************************************************
DEFINES: DEFAULT CONFIGURATION
NOTE:    ESAcademy only tests this code with ENFORCE_DEFAULT_CONFIGURATION
         set to one. Disabling allows setting several optimization features
**************************************************************************/
#define ENFORCE_DEFAULT_CONFIGURATION 1

/**************************************************************************
DEFINES: DEFAULT NODE ID
**************************************************************************/

#define NODEID NODEID_DCF

/**************************************************************************
DEFINES: ENABLING/DISABLING CODE FUNCTIONALITY
**************************************************************************/

// If enabled, node starts up automatically (does not wait for NMT master)
#define AUTOSTART 0

// If enabled, parameters passed to functions are checked for consistency.
// On failures, the user function MCOUSER_FatalError is called.
#define CHECK_PARAMETERS 1

// If enabled, CANopen indicator lights are implemented
#define USE_LEDS 1

/**************************************************************************
DEFINES: ENABLING SYSTEM NEAR CALL-BACK FUNCTIONS,
         DEFAULT IMPLEMENTATION IN user_[hwplatform].c
**************************************************************************/

// If enabled, the call-back function MCOUSER_NMTChange() is called
// everytime the CANopen stack changes its NMT Slave State
#define USECB_NMTCHANGE 1

// If enabled, the call-back function MCOUSER_GetSerial() is called every
// time the CANopen stack receives an SDO Request for the serial number
#define USECB_ODSERIAL 1

// If enabled, call-back MCOUSER_TimeOfDay() is called when time object
// is received
#define USECB_TIMEOFDAY 1

/**************************************************************************
DEFINES: ENABLING CANopen DATA CALL-BACK FUNCTIONS
         DEFAULT IMPLEMENTATION IN user_cbdata.c
**************************************************************************/

// If enabled, the call-back function MCOUSER_EMCY() is called
// everytime the CANopen stack detects a system emergency event
#define USECB_EMCY 1

// If enabled, the call-back function MCOUSER_ODData() is called every
// time data is received
// NOTE: PI Access, RPDO or SDO write
#define USECB_ODDATARECEIVED 1

// If enabled, the call-back function MCOUSER_RPDOReceived() is called
// every time the CANopen stack receives an RPDO
// NOTE: PI Access, RPDO
#define USECB_RPDORECEIVE 1

// If enabled, the call-back function MCOUSER_TPDOReady() is called every
// time right before the CANopen stack sends a TPDO
// NOTE: PI Access, TPDO
#define USECB_TPDORDY 1

// If enabled, the call-back function MCOUSER_SYNCReceived() is called
// every time the CANopen stack receives the SYNC message
// NOTE: No data, RPDO data needs to be applied, TPDO uses USECB_TPDORDY
#define USECB_SYNCRECEIVE 1

// If enabled, the call back functions MCOUSER_SDORdPI(),
// MCOUSER_SDOWrPI(), MCOUSER_SDORdAft() and MCOUSER_SDOWrAft() are called
// before/after every expedited SDO access to the process image
// NOTE: SDO access to PI
#define USECB_SDO_RD_PI    1
#define USECB_SDO_RD_AFTER 1
#define USECB_SDO_WR_PI    1
#define USECB_SDO_WR_AFTER 1

// If enabled, the call back functions MCOUSER_AppSDOReadInit() with
// MCOUSER_AppSDOReadComplete or MCOUSER_AppSDOWriteInit() with
// MCOUSER_AppSDOWriteComplete() are called before/after every segmented
// SDO request. Allows implementation of application specific, custom
// segmented SDOs (e.g dynamic length entries)
// NOTE: segmented SDO access, also outside PI
#define USECB_APPSDO_READ  1
#define USECB_APPSDO_WRITE 1

/**************************************************************************
DEFINES: ADDITIONAL ENABLING/DISABLING CODE FUNCTIONALITY OF PLUS PACKAGE
**************************************************************************/

// If enabled, Emergency Messages are used
#define USE_EMCY 1

// If EMCYs are used, size of error field history [1003h]
#define ERROR_FIELD_SIZE 4

// If enabled, extended SDO handling (segmented transfer) is used
#define USE_EXTENDED_SDO 1

// If enabled, blocked SDO transfers are allowed
#define USE_BLOCKED_SDO 0
// Max size of a block supported (4 to 127)
#define BLK_MAX_SIZE    8
#define BLK_B2B_TIMEOUT 4

// If enabled, the function Store Parameters [1010h] is supported
// The driver must provide funtcions NVOL_ReadByte and NVOL_WriteByte
#define USE_STORE_PARAMETERS 1
// Nr of Subindexes used at [1010h]
#define NROF_STORE_PARAMETERS 4
// Specify offset and size of non-volatile memory,
#define NVOL_STORE_START 16
#define NVOL_STORE_SIZE  1200

// If enabled, Layer Setting Services (Slave) are implemented
#ifndef USE_LSS_SLAVE
#define USE_LSS_SLAVE 0
#endif

// If enabled, LSS Fast Scan is implemented.
// Due to merging LSS and LSS fast-scan slave modules, just follow the LSS setting.
#define USE_MICROLSS (USE_LSS_SLAVE)

// If enabled, supports the sleep mode
#define USE_SLEEP 0

// Number of SDO servers supported
#define NR_OF_SDOSERVER 1

// Support of generic data pointer for OD contents.
// Set to zero, if all data is in process image.
#define USE_GENOD_PTR 0

/**************************************************************************
DEFINES: ADDITIONAL ENABLING/DISABLING CODE FUNCTIONALITY OF XOD PACKAGE
**************************************************************************/
// If enabled, the call-back function MCOUSER_ODData() is called every
#define USE_REMOTE_ACCESS    0
#define USECB_CUSTOM_RAWRITE 1

// time data is received into the process image
// NOTE: PI Access, RPDO or SDO write
#if USE_REMOTE_ACCESS
#define USECB_ODDATACOSONLY 1
#endif

/**************************************************************************
DEFINES: ADDITIONAL ENABLING/DISABLING CODE FUNCTIONALITY OF FD PACKAGE
**************************************************************************/

// The use of CANopen FD extensions shall be set in the project options.
// If not, disable by default.
#if !defined(USE_CANOPEN_FD)
#define USE_CANOPEN_FD 0
#endif

#endif // _NODECFG_H

/*----------------------- END OF FILE ----------------------------------*/
