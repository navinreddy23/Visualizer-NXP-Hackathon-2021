// Process Image File
// Generated by CANopen Architect Mini 8.25.5874 on 10/05/2021 05:50:05 PM
// Generated from project C:\Users\navin\Desktop\CanOpen\SlaveWorkingEDS.caxe
// Generated from EDS 'CANopen_NXP_SDK_CiA401' 04-27-2021 05:51PM by Pf
// Use with MicroCANopen Plus CANopen stack
// For more information visit www.esacademy.com and www.microcanopen.com

// Check for warnings below before using this file

#ifndef _PIMGH_
#define _PIMGH_

// EDS configuration usage
// 1 = configuration was used when this file was generated
#define EDSCONFIGURATION_ALL_ENTRIES 1
#define EDSCONFIGURATION_UNTITLED 0

// EDS group usage
// 1 = group was used when this file was generated

// set to 1 to use this stack config
#define AUTO_GENERATED_STACK_CONFIG 1

#if (AUTO_GENERATED_STACK_CONFIG == 1)
// stack configuration

// if no stack version defined then assume version 5.xx
#ifndef _MCOPVERSION_
#define _MCOPVERSION_ 5
#endif

// Maximum number of receive PDOs
#define NR_OF_RPDOS       1

// Maximum number of transmit PDOs
#define NR_OF_TPDOS       0

// Default Node ID of this node
#if _MCOPVERSION_ >= 6
#define NODEID_DCF         0x03
#define DEFAULT_EMCY_COBID 0x00000080L + NODEID_DCF
#else
#define NODE_ID            0x03
#define DEFAULT_EMCY_COBID 0x00000080L + NODE_ID
#endif

// device type
#define OD_DEVICE_TYPE    0x00000191L

// Identity Object data [1018]
// Note: the values in Device -> Information are not used for this piece of code,
// only the values in [1018] are used
#define OD_VENDOR_ID      0xAF0002DCL
#define OD_PRODUCT_CODE   0xC0DE0010L
#define OD_REVISION       0x20201014L
#define OD_SERIAL_NUMBER  0x00000000L

// Specify the default heartbeat here
#define DEFAULT_HEARTBEAT 1000

// Defines the maximum number of heartbeat consumers
#define NR_OF_HB_CONSUMER 3

// Defines the maximum number of emergency consumers
#define NR_OF_EMCY_CONSUMERS 0

// Defines the emergency inhibit time (x100us)
#define EMCY_INHIBIT_TIME 100

#endif // AUTO_GENERATED_STACK_CONFIG == 1

// [6100,01] Unsigned8
#define P610001_VC_Command 0x00000000
#define PVC_Command_610001 P610001_VC_Command
#define P610001 P610001_VC_Command
#define P0x61000x01 P610001_VC_Command
// The uppercase versions are deprecated
#define P610001_VC_COMMAND P610001_VC_Command
#define PVC_COMMAND_610001 P610001_VC_Command
// [6100,02] Unsigned8
#define P610002_VC_Accuracy 0x00000001
#define PVC_Accuracy_610002 P610002_VC_Accuracy
#define P610002 P610002_VC_Accuracy
#define P0x61000x02 P610002_VC_Accuracy
// The uppercase versions are deprecated
#define P610002_VC_ACCURACY P610002_VC_Accuracy
#define PVC_ACCURACY_610002 P610002_VC_Accuracy
// [1002,00] Unsigned32
#define P100200_Manufacturer_Status_Register 0x00000004
#define PManufacturer_Status_Register_100200 P100200_Manufacturer_Status_Register
#define P100200 P100200_Manufacturer_Status_Register
#define P0x10020x00 P100200_Manufacturer_Status_Register
// The uppercase versions are deprecated
#define P100200_MANUFACTURER_STATUS_REGISTER P100200_Manufacturer_Status_Register
#define PMANUFACTURER_STATUS_REGISTER_100200 P100200_Manufacturer_Status_Register
// [1003,00] Unsigned8
#define P100300_Number_of_Errors 0x00000008
#define PNumber_of_Errors_100300 P100300_Number_of_Errors
#define P100300 P100300_Number_of_Errors
#define P0x10030x00 P100300_Number_of_Errors
// The uppercase versions are deprecated
#define P100300_NUMBER_OF_ERRORS P100300_Number_of_Errors
#define PNUMBER_OF_ERRORS_100300 P100300_Number_of_Errors
// [1003,01] Unsigned32
#define P100301_Pre_Defined_Error_Field_1 0x00000009
#define PPre_Defined_Error_Field_1_100301 P100301_Pre_Defined_Error_Field_1
#define P100301 P100301_Pre_Defined_Error_Field_1
#define P0x10030x01 P100301_Pre_Defined_Error_Field_1
// The uppercase versions are deprecated
#define P100301_PRE_DEFINED_ERROR_FIELD_1 P100301_Pre_Defined_Error_Field_1
#define PPRE_DEFINED_ERROR_FIELD_1_100301 P100301_Pre_Defined_Error_Field_1
// [1003,02] Unsigned32
#define P100302_Pre_Defined_Error_Field_2 0x0000000D
#define PPre_Defined_Error_Field_2_100302 P100302_Pre_Defined_Error_Field_2
#define P100302 P100302_Pre_Defined_Error_Field_2
#define P0x10030x02 P100302_Pre_Defined_Error_Field_2
// The uppercase versions are deprecated
#define P100302_PRE_DEFINED_ERROR_FIELD_2 P100302_Pre_Defined_Error_Field_2
#define PPRE_DEFINED_ERROR_FIELD_2_100302 P100302_Pre_Defined_Error_Field_2
// [1003,03] Unsigned32
#define P100303_Pre_Defined_Error_Field_3 0x00000011
#define PPre_Defined_Error_Field_3_100303 P100303_Pre_Defined_Error_Field_3
#define P100303 P100303_Pre_Defined_Error_Field_3
#define P0x10030x03 P100303_Pre_Defined_Error_Field_3
// The uppercase versions are deprecated
#define P100303_PRE_DEFINED_ERROR_FIELD_3 P100303_Pre_Defined_Error_Field_3
#define PPRE_DEFINED_ERROR_FIELD_3_100303 P100303_Pre_Defined_Error_Field_3
// [1003,04] Unsigned32
#define P100304_Pre_Defined_Error_Field_4 0x00000015
#define PPre_Defined_Error_Field_4_100304 P100304_Pre_Defined_Error_Field_4
#define P100304 P100304_Pre_Defined_Error_Field_4
#define P0x10030x04 P100304_Pre_Defined_Error_Field_4
// The uppercase versions are deprecated
#define P100304_PRE_DEFINED_ERROR_FIELD_4 P100304_Pre_Defined_Error_Field_4
#define PPRE_DEFINED_ERROR_FIELD_4_100304 P100304_Pre_Defined_Error_Field_4
// [1008,00] VisibleString
#define P100800_Manufacturer_Device_Name 0x00000019
#define PManufacturer_Device_Name_100800 P100800_Manufacturer_Device_Name
#define P100800 P100800_Manufacturer_Device_Name
#define P0x10080x00 P100800_Manufacturer_Device_Name
// The uppercase versions are deprecated
#define P100800_MANUFACTURER_DEVICE_NAME P100800_Manufacturer_Device_Name
#define PMANUFACTURER_DEVICE_NAME_100800 P100800_Manufacturer_Device_Name
// [1009,00] VisibleString
#define P100900_Manufacturer_Hardware_Version 0x00000038
#define PManufacturer_Hardware_Version_100900 P100900_Manufacturer_Hardware_Version
#define P100900 P100900_Manufacturer_Hardware_Version
#define P0x10090x00 P100900_Manufacturer_Hardware_Version
// The uppercase versions are deprecated
#define P100900_MANUFACTURER_HARDWARE_VERSION P100900_Manufacturer_Hardware_Version
#define PMANUFACTURER_HARDWARE_VERSION_100900 P100900_Manufacturer_Hardware_Version
// [100A,00] VisibleString
#define P100A00_Manufacturer_Software_Version 0x0000004A
#define PManufacturer_Software_Version_100A00 P100A00_Manufacturer_Software_Version
#define P100A00 P100A00_Manufacturer_Software_Version
#define P0x100A0x00 P100A00_Manufacturer_Software_Version
// The uppercase versions are deprecated
#define P100A00_MANUFACTURER_SOFTWARE_VERSION P100A00_Manufacturer_Software_Version
#define PMANUFACTURER_SOFTWARE_VERSION_100A00 P100A00_Manufacturer_Software_Version
// [1010,01] Unsigned32
#define P101001_Save_All_Parameters 0x00000063
#define PSave_All_Parameters_101001 P101001_Save_All_Parameters
#define P101001 P101001_Save_All_Parameters
#define P0x10100x01 P101001_Save_All_Parameters
// The uppercase versions are deprecated
#define P101001_SAVE_ALL_PARAMETERS P101001_Save_All_Parameters
#define PSAVE_ALL_PARAMETERS_101001 P101001_Save_All_Parameters
// [1010,02] Unsigned32
#define P101002_Save_Communication_Parameters 0x00000067
#define PSave_Communication_Parameters_101002 P101002_Save_Communication_Parameters
#define P101002 P101002_Save_Communication_Parameters
#define P0x10100x02 P101002_Save_Communication_Parameters
// The uppercase versions are deprecated
#define P101002_SAVE_COMMUNICATION_PARAMETERS P101002_Save_Communication_Parameters
#define PSAVE_COMMUNICATION_PARAMETERS_101002 P101002_Save_Communication_Parameters
// [1010,03] Unsigned32
#define P101003_Save_Application_Parameters 0x0000006B
#define PSave_Application_Parameters_101003 P101003_Save_Application_Parameters
#define P101003 P101003_Save_Application_Parameters
#define P0x10100x03 P101003_Save_Application_Parameters
// The uppercase versions are deprecated
#define P101003_SAVE_APPLICATION_PARAMETERS P101003_Save_Application_Parameters
#define PSAVE_APPLICATION_PARAMETERS_101003 P101003_Save_Application_Parameters
// [1010,04] Unsigned32
#define P101004_Save_Manufacturer_Parameters 0x0000006F
#define PSave_Manufacturer_Parameters_101004 P101004_Save_Manufacturer_Parameters
#define P101004 P101004_Save_Manufacturer_Parameters
#define P0x10100x04 P101004_Save_Manufacturer_Parameters
// The uppercase versions are deprecated
#define P101004_SAVE_MANUFACTURER_PARAMETERS P101004_Save_Manufacturer_Parameters
#define PSAVE_MANUFACTURER_PARAMETERS_101004 P101004_Save_Manufacturer_Parameters
// [1011,01] Unsigned32
#define P101101_Save_All_Parameters 0x00000073
#define PSave_All_Parameters_101101 P101101_Save_All_Parameters
#define P101101 P101101_Save_All_Parameters
#define P0x10110x01 P101101_Save_All_Parameters
// The uppercase versions are deprecated
#define P101101_SAVE_ALL_PARAMETERS P101101_Save_All_Parameters
#define PSAVE_ALL_PARAMETERS_101101 P101101_Save_All_Parameters
// [1011,02] Unsigned32
#define P101102_Restore_Communication_Parameters 0x00000077
#define PRestore_Communication_Parameters_101102 P101102_Restore_Communication_Parameters
#define P101102 P101102_Restore_Communication_Parameters
#define P0x10110x02 P101102_Restore_Communication_Parameters
// The uppercase versions are deprecated
#define P101102_RESTORE_COMMUNICATION_PARAMETERS P101102_Restore_Communication_Parameters
#define PRESTORE_COMMUNICATION_PARAMETERS_101102 P101102_Restore_Communication_Parameters
// [1011,03] Unsigned32
#define P101103_Restore_Application_Parameters 0x0000007B
#define PRestore_Application_Parameters_101103 P101103_Restore_Application_Parameters
#define P101103 P101103_Restore_Application_Parameters
#define P0x10110x03 P101103_Restore_Application_Parameters
// The uppercase versions are deprecated
#define P101103_RESTORE_APPLICATION_PARAMETERS P101103_Restore_Application_Parameters
#define PRESTORE_APPLICATION_PARAMETERS_101103 P101103_Restore_Application_Parameters
// [1011,04] Unsigned32
#define P101104_Restore_Manufacturer_Parameters 0x0000007F
#define PRestore_Manufacturer_Parameters_101104 P101104_Restore_Manufacturer_Parameters
#define P101104 P101104_Restore_Manufacturer_Parameters
#define P0x10110x04 P101104_Restore_Manufacturer_Parameters
// The uppercase versions are deprecated
#define P101104_RESTORE_MANUFACTURER_PARAMETERS P101104_Restore_Manufacturer_Parameters
#define PRESTORE_MANUFACTURER_PARAMETERS_101104 P101104_Restore_Manufacturer_Parameters
// [1016,01] Unsigned32
#define P101601_Consumer_Heartbeat_Time_1 0x00000083
#define PConsumer_Heartbeat_Time_1_101601 P101601_Consumer_Heartbeat_Time_1
#define P101601 P101601_Consumer_Heartbeat_Time_1
#define P0x10160x01 P101601_Consumer_Heartbeat_Time_1
// The uppercase versions are deprecated
#define P101601_CONSUMER_HEARTBEAT_TIME_1 P101601_Consumer_Heartbeat_Time_1
#define PCONSUMER_HEARTBEAT_TIME_1_101601 P101601_Consumer_Heartbeat_Time_1
// [1016,02] Unsigned32
#define P101602_Consumer_Heartbeat_Time_2 0x00000087
#define PConsumer_Heartbeat_Time_2_101602 P101602_Consumer_Heartbeat_Time_2
#define P101602 P101602_Consumer_Heartbeat_Time_2
#define P0x10160x02 P101602_Consumer_Heartbeat_Time_2
// The uppercase versions are deprecated
#define P101602_CONSUMER_HEARTBEAT_TIME_2 P101602_Consumer_Heartbeat_Time_2
#define PCONSUMER_HEARTBEAT_TIME_2_101602 P101602_Consumer_Heartbeat_Time_2
// [1016,03] Unsigned32
#define P101603_Consumer_Heartbeat_Time_3 0x0000008B
#define PConsumer_Heartbeat_Time_3_101603 P101603_Consumer_Heartbeat_Time_3
#define P101603 P101603_Consumer_Heartbeat_Time_3
#define P0x10160x03 P101603_Consumer_Heartbeat_Time_3
// The uppercase versions are deprecated
#define P101603_CONSUMER_HEARTBEAT_TIME_3 P101603_Consumer_Heartbeat_Time_3
#define PCONSUMER_HEARTBEAT_TIME_3_101603 P101603_Consumer_Heartbeat_Time_3
// [1017,00] Unsigned16
#define P101700_Producer_Heartbeat_Time 0x0000008F
#define PProducer_Heartbeat_Time_101700 P101700_Producer_Heartbeat_Time
#define P101700 P101700_Producer_Heartbeat_Time
#define P0x10170x00 P101700_Producer_Heartbeat_Time
// The uppercase versions are deprecated
#define P101700_PRODUCER_HEARTBEAT_TIME P101700_Producer_Heartbeat_Time
#define PPRODUCER_HEARTBEAT_TIME_101700 P101700_Producer_Heartbeat_Time
// [1019,00] Unsigned8
#define P101900_SYNC_counter_overflow_value 0x00000091
#define PSYNC_counter_overflow_value_101900 P101900_SYNC_counter_overflow_value
#define P101900 P101900_SYNC_counter_overflow_value
#define P0x10190x00 P101900_SYNC_counter_overflow_value
// The uppercase versions are deprecated
#define P101900_SYNC_COUNTER_OVERFLOW_VALUE P101900_SYNC_counter_overflow_value
#define PSYNC_COUNTER_OVERFLOW_VALUE_101900 P101900_SYNC_counter_overflow_value
// [1400,01] Unsigned32
#define P140001_COB_ID_used_by_PDO 0x00000092
#define PCOB_ID_used_by_PDO_140001 P140001_COB_ID_used_by_PDO
#define P140001 P140001_COB_ID_used_by_PDO
#define P0x14000x01 P140001_COB_ID_used_by_PDO
// The uppercase versions are deprecated
#define P140001_COB_ID_USED_BY_PDO P140001_COB_ID_used_by_PDO
#define PCOB_ID_USED_BY_PDO_140001 P140001_COB_ID_used_by_PDO
// [1400,02] Unsigned8
#define P140002_Transmission_Type 0x00000096
#define PTransmission_Type_140002 P140002_Transmission_Type
#define P140002 P140002_Transmission_Type
#define P0x14000x02 P140002_Transmission_Type
// The uppercase versions are deprecated
#define P140002_TRANSMISSION_TYPE P140002_Transmission_Type
#define PTRANSMISSION_TYPE_140002 P140002_Transmission_Type
// [1400,03] Unsigned16
#define P140003_Inhibit_Time 0x00000097
#define PInhibit_Time_140003 P140003_Inhibit_Time
#define P140003 P140003_Inhibit_Time
#define P0x14000x03 P140003_Inhibit_Time
// The uppercase versions are deprecated
#define P140003_INHIBIT_TIME P140003_Inhibit_Time
#define PINHIBIT_TIME_140003 P140003_Inhibit_Time
// [1400,05] Unsigned16
#define P140005_Event_Timer 0x00000099
#define PEvent_Timer_140005 P140005_Event_Timer
#define P140005 P140005_Event_Timer
#define P0x14000x05 P140005_Event_Timer
// The uppercase versions are deprecated
#define P140005_EVENT_TIMER P140005_Event_Timer
#define PEVENT_TIMER_140005 P140005_Event_Timer
// [5FFF,00] VisibleString
#define P5FFF00_EmSA 0x0000009B
#define PEmSA_5FFF00 P5FFF00_EmSA
#define P5FFF00 P5FFF00_EmSA
#define P0x5FFF0x00 P5FFF00_EmSA
// The uppercase versions are deprecated
#define P5FFF00_EMSA P5FFF00_EmSA
#define PEMSA_5FFF00 P5FFF00_EmSA

// last byte used in process image
#define PIMGEND 0x000000C4

// sizes for entries in the process image in bytes
#define SIZEOF_6100_01_VC_COMMAND 1
#define SIZEOF_6100_02_VC_ACCURACY 1
#define SIZEOF_1002_00_MANUFACTURER_STATUS_REGISTER 4
#define SIZEOF_1003_00_NUMBER_OF_ERRORS 1
#define SIZEOF_1003_01_PRE_DEFINED_ERROR_FIELD_1 4
#define SIZEOF_1003_02_PRE_DEFINED_ERROR_FIELD_2 4
#define SIZEOF_1003_03_PRE_DEFINED_ERROR_FIELD_3 4
#define SIZEOF_1003_04_PRE_DEFINED_ERROR_FIELD_4 4
#define SIZEOF_1008_00_MANUFACTURER_DEVICE_NAME 31
#define SIZEOF_1009_00_MANUFACTURER_HARDWARE_VERSION 18
#define SIZEOF_100A_00_MANUFACTURER_SOFTWARE_VERSION 25
#define SIZEOF_1010_01_SAVE_ALL_PARAMETERS 4
#define SIZEOF_1010_02_SAVE_COMMUNICATION_PARAMETERS 4
#define SIZEOF_1010_03_SAVE_APPLICATION_PARAMETERS 4
#define SIZEOF_1010_04_SAVE_MANUFACTURER_PARAMETERS 4
#define SIZEOF_1011_01_SAVE_ALL_PARAMETERS 4
#define SIZEOF_1011_02_RESTORE_COMMUNICATION_PARAMETERS 4
#define SIZEOF_1011_03_RESTORE_APPLICATION_PARAMETERS 4
#define SIZEOF_1011_04_RESTORE_MANUFACTURER_PARAMETERS 4
#define SIZEOF_1016_01_CONSUMER_HEARTBEAT_TIME_1 4
#define SIZEOF_1016_02_CONSUMER_HEARTBEAT_TIME_2 4
#define SIZEOF_1016_03_CONSUMER_HEARTBEAT_TIME_3 4
#define SIZEOF_1017_00_PRODUCER_HEARTBEAT_TIME 2
#define SIZEOF_1019_00_SYNC_COUNTER_OVERFLOW_VALUE 1
#define SIZEOF_1400_01_COB_ID_USED_BY_PDO 4
#define SIZEOF_1400_02_TRANSMISSION_TYPE 1
#define SIZEOF_1400_03_INHIBIT_TIME 2
#define SIZEOF_1400_05_EVENT_TIMER 2
#define SIZEOF_5FFF_00_EMSA 42

// default values for process image
#define PIMGDEFAULTS { \
/*[6100,01]*/        0x00, \
/*[6100,02]*/        0x00, \
/* padding */        0x00, 0x00, \
/*[1002,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,00]*/        0x00, \
/*[1003,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1008,00]*/        0x43, 0x41, 0x4E, 0x6F, 0x70, 0x65, 0x6E, 0x4C, 0x69, 0x62, \
                     0x4E, 0x58, 0x50, 0x53, 0x44, 0x4B, 0x20, 0x43, 0x69, 0x41, \
                     0x34, 0x30, 0x31, 0x20, 0x45, 0x78, 0x61, 0x6D, 0x70, 0x6C, \
                     0x65, \
/*[1009,00]*/        0x53, 0x6F, 0x6D, 0x65, 0x20, 0x4E, 0x58, 0x50, 0x20, 0x45, \
                     0x76, 0x61, 0x6C, 0x62, 0x6F, 0x61, 0x72, 0x64, \
/*[100A,00]*/        0x45, 0x6D, 0x53, 0x41, 0x20, 0x4D, 0x43, 0x4F, 0x50, 0x20, \
                     0x37, 0x2E, 0x31, 0x30, 0x20, 0x32, 0x30, 0x32, 0x30, 0x2D, \
                     0x31, 0x30, 0x2D, 0x31, 0x34, \
/*[1010,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,01]*/        0xE8, 0x03, 0x01, 0x00, \
/*[1016,02]*/        0xE8, 0x03, 0x02, 0x00, \
/*[1016,03]*/        0xE8, 0x03, 0x03, 0x00, \
/*[1017,00]*/        0xE8, 0x03, \
/*[1019,00]*/        0x00, \
/*[1400,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1400,02]*/        0xFF, \
/*[1400,03]*/        0x00, 0x00, \
/*[1400,05]*/        0x00, 0x00, \
/*[5FFF,00]*/        0x45, 0x6D, 0x53, 0x41, 0x20, 0x77, 0x77, 0x77, 0x2E, 0x65, \
                     0x6D, 0x2D, 0x73, 0x61, 0x2E, 0x63, 0x6F, 0x6D, 0x2C, 0x20, \
                     0x43, 0x41, 0x4E, 0x6F, 0x70, 0x65, 0x6E, 0x20, 0x41, 0x72, \
                     0x63, 0x68, 0x69, 0x74, 0x65, 0x63, 0x74, 0x20, 0x4D, 0x69, \
                     0x6E, 0x69, \
                     }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGDEFAULTS 

// minimum values for process image
#define PIMGMINS { \
/*[6100,01]*/        0x00, \
/*[6100,02]*/        0x00, \
/* padding */        0x00, 0x00, \
/*[1002,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,00]*/        0x00, \
/*[1003,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1008,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1009,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[100A,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1017,00]*/        0x00, 0x00, \
/*[1019,00]*/        0x00, \
/*[1400,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1400,02]*/        0x00, \
/*[1400,03]*/        0x00, 0x00, \
/*[1400,05]*/        0x00, 0x00, \
/*[5FFF,00]*/        0x00, 0x00, 0x00, 0x00, \
                     }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGMINS 

// maximum values for process image
#define PIMGMAXS { \
/*[6100,01]*/        0x00, \
/*[6100,02]*/        0x00, \
/* padding */        0x00, 0x00, \
/*[1002,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,00]*/        0x04, \
/*[1003,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1003,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1008,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1009,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[100A,00]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1010,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1011,04]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,02]*/        0x00, 0x00, 0x00, 0x00, \
/*[1016,03]*/        0x00, 0x00, 0x00, 0x00, \
/*[1017,00]*/        0x00, 0x00, \
/*[1019,00]*/        0x00, \
/*[1400,01]*/        0x00, 0x00, 0x00, 0x00, \
/*[1400,02]*/        0x00, \
/*[1400,03]*/        0x00, 0x00, \
/*[1400,05]*/        0x00, 0x00, \
/*[5FFF,00]*/        0x00, 0x00, 0x00, 0x00, \
                     }

// 1 MACROS WERE GENERATED TO HOLD THE PROCESS IMAGE
// USE THE FOLLOWING INITIALIZER:
// PIMGMAXS 

// Example usage: PIMG_OFFSET(0x1000, 0x00)
#define PIMG_OFFSET(index, subindex) P##index##subindex

#endif // _PIMGH_
