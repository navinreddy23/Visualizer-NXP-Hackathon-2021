/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_07 (number 101), UART1_RXD/J17[4] */
/* Routed pin properties */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                              LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                       RX   /*!< Signal name */

/* GPIO_AD_B0_06 (number 105), UART1_TXD/J17[6] */
/* Routed pin properties */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                              LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                       TX   /*!< Signal name */

/* GPIO_SD_B1_01 (number 32), CAN1_RX/U9[4] */
/* Routed pin properties */
#define BOARD_INITPINS_CAN1_RX_PERIPHERAL                                   CAN1   /*!< Peripheral name */
#define BOARD_INITPINS_CAN1_RX_SIGNAL                                         RX   /*!< Signal name */

/* GPIO_SD_B1_00 (number 33), CAN1_TX/U9[1] */
/* Routed pin properties */
#define BOARD_INITPINS_CAN1_TX_PERIPHERAL                                   CAN1   /*!< Peripheral name */
#define BOARD_INITPINS_CAN1_TX_SIGNAL                                         TX   /*!< Signal name */

/* GPIO_AD_B0_11 (number 97), ENET_CRS_DV/U11[18]/J19[3] */
/* Routed pin properties */
#define BOARD_INITPINS_ENET_CRS_DV_PERIPHERAL                             LPSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET_CRS_DV_SIGNAL                                   PCS0   /*!< Signal name */

/* GPIO_AD_B0_10 (number 98), ENET_RXD0/U11[16]/J19[6] */
/* Routed pin properties */
#define BOARD_INITPINS_ENET_RXD0_PERIPHERAL                               LPSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET_RXD0_SIGNAL                                      SCK   /*!< Signal name */

/* GPIO_AD_B0_13 (number 95), ENET_TXEN/U11[23]/J19[5] */
/* Routed pin properties */
#define BOARD_INITPINS_ENET_TXEN_PERIPHERAL                               LPSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET_TXEN_SIGNAL                                      SDI   /*!< Signal name */

/* GPIO_AD_B0_12 (number 96), ENET_RXER/U11[20]/J19[4] */
/* Routed pin properties */
#define BOARD_INITPINS_ENET_RXER_PERIPHERAL                               LPSPI1   /*!< Peripheral name */
#define BOARD_INITPINS_ENET_RXER_SIGNAL                                      SDO   /*!< Signal name */

/* GPIO_AD_B0_15 (number 93), ENET_TXD1/U11[25]/J19[2] */
/* Routed pin properties */
#define BOARD_INITPINS_PCA_OE_PERIPHERAL                                   GPIO1   /*!< Peripheral name */
#define BOARD_INITPINS_PCA_OE_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_PCA_OE_CHANNEL                                        15U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_PCA_OE_GPIO                                         GPIO1   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_PCA_OE_GPIO_PIN                                       15U   /*!< GPIO pin number */
#define BOARD_INITPINS_PCA_OE_GPIO_PIN_MASK                          (1U << 15U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_PCA_OE_PORT                                         GPIO1   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_PCA_OE_PIN                                            15U   /*!< PORT pin number */
#define BOARD_INITPINS_PCA_OE_PIN_MASK                               (1U << 15U)   /*!< PORT pin mask */

/* GPIO_AD_B1_07 (number 83), SD0_VSELECT/J19[1] */
/* Routed pin properties */
#define BOARD_INITPINS_PCA_RESET_PERIPHERAL                                GPIO1   /*!< Peripheral name */
#define BOARD_INITPINS_PCA_RESET_SIGNAL                                  gpio_io   /*!< Signal name */
#define BOARD_INITPINS_PCA_RESET_CHANNEL                                     23U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_PCA_RESET_GPIO                                      GPIO1   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_PCA_RESET_GPIO_PIN                                    23U   /*!< GPIO pin number */
#define BOARD_INITPINS_PCA_RESET_GPIO_PIN_MASK                       (1U << 23U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_PCA_RESET_PORT                                      GPIO1   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_PCA_RESET_PIN                                         23U   /*!< PORT pin number */
#define BOARD_INITPINS_PCA_RESET_PIN_MASK                            (1U << 23U)   /*!< PORT pin mask */


/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
