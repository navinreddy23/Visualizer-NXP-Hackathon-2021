/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v9.0
processor: MIMXRT1021xxxxx
package_id: MIMXRT1021DAG5A
mcu_data: ksdk2_0
processor_version: 9.0.1
board: MIMXRT1020-EVK
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 1f30f694-a7b0-4adf-b8ed-4b0df4df0bfa
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * CAN1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CAN1'
- type: 'flexcan'
- mode: 'interrupts'
- custom_name_enabled: 'false'
- type_id: 'flexcan_5e3926991a26d63f444aa30b3ad6630e'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CAN1'
- config_sets:
  - interruptsCfg:
    - messageBufferIrqs: '0'
    - messageBufferIrqs2: '0'
    - interruptsEnable: ''
    - enable_irq: 'false'
    - interrupt_shared:
      - IRQn: 'CAN1_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
  - fsl_flexcan:
    - can_config:
      - clockSource: 'kFLEXCAN_ClkSrcOsc'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - wakeupSrc: 'kFLEXCAN_WakeupSrcUnfiltered'
      - baudRate: '1000000'
      - maxMbNum: '16'
      - enableLoopBack: 'false'
      - enableTimerSync: 'true'
      - enableSelfWakeup: 'false'
      - enableIndividMask: 'false'
      - disableSelfReception: 'false'
      - enableListenOnlyMode: 'false'
      - timingConfig:
        - propSeg: '2'
        - phaseSeg1: '4'
        - phaseSeg2: '3'
        - rJumpwidth: '2'
        - bitTime: []
    - enableRxFIFO: 'false'
    - rxFIFO:
      - idFilterTable: ''
      - idFilterNum: 'num0'
      - idFilterType: 'kFLEXCAN_RxFifoFilterTypeA'
      - priority: 'kFLEXCAN_RxFifoPrioLow'
    - channels:
      - 0:
        - mbID: '0'
        - mbType: 'mbRx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
      - 1:
        - mbID: '1'
        - mbType: 'mbTx'
        - rxMb:
          - id: '0'
          - format: 'kFLEXCAN_FrameFormatStandard'
          - type: 'kFLEXCAN_FrameTypeData'
    - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const flexcan_config_t CAN1_config = {
  .wakeupSrc = kFLEXCAN_WakeupSrcUnfiltered,
  .baudRate = 1000000UL,
  .maxMbNum = 16U,
  .enableLoopBack = false,
  .enableTimerSync = true,
  .enableSelfWakeup = false,
  .enableIndividMask = false,
  .disableSelfReception = false,
  .enableListenOnlyMode = false,
  .timingConfig = {
    .preDivider = 3,
    .propSeg = 1,
    .phaseSeg1 = 3,
    .phaseSeg2 = 2,
    .rJumpwidth = 1
  }
};
/* Message buffer 0 configuration structure */
const flexcan_rx_mb_config_t CAN1_rx_mb_config_0 = {
  .id = 0UL,
  .format = kFLEXCAN_FrameFormatStandard,
  .type = kFLEXCAN_FrameTypeData
};

static void CAN1_init(void) {
  FLEXCAN_Init(CAN1_PERIPHERAL, &CAN1_config, CAN1_CLOCK_SOURCE);

  /* Message buffer 0 initialization */
  FLEXCAN_SetRxMbConfig(CAN1_PERIPHERAL, 0, &CAN1_rx_mb_config_0, true);
  /* Message buffer 1 initialization */
  FLEXCAN_SetTxMbConfig(CAN1_PERIPHERAL, 1, true);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  CAN1_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
