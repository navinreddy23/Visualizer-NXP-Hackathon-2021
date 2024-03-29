/*
 * CANOpen.c
 *
 *  Created on: 30 May 2021
 *      Author: navin
 */

#include "CANOpen.h"
#include "mcop_inc.h"

#include "timer.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void TaskCANOpenProcessPDO(void* arg);
static void TaskCANOpenSlave(void* arg);
static void CANOpenProcessPDO(void);
static void Tick(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/
static TaskHandle_t hTaskPDOProcess;
QueueHandle_t qResults;
/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Create tasks and a queue to process the received data over CANopen.
 * 				Set a callback function to provide a timer source to the CANopen stack.
 */
void CANOpen_Init(void)
{
	xTaskCreate(TaskCANOpenSlave, "CANOpen task", 512, NULL, 2, NULL);
	xTaskCreate(TaskCANOpenProcessPDO, "PDO Task", 256, NULL, 1, &hTaskPDOProcess);
	qResults = xQueueCreate(100, sizeof(results_t));

	if(qResults == NULL)
	{
		PRINTF("Queue creation failed\r\n");
	}

	TIMER_SetCallBack(Tick);
}

/**
 * @brief Task handles the Rx PDO's. Once this task is notified from the
 *        CANopen Slave task, it inserts the results in a queue.
 */
static void TaskCANOpenProcessPDO(void* arg)
{
	results_t results;
	uint32_t notification;

	while(1)
	{
		xTaskNotifyWait(0, 0, &notification, portMAX_DELAY);

		// Process all output data from CANopen
		MCO_ReadProcessData(&(results.label), 1, P610001_VC_Command);
		MCO_ReadProcessData(&(results.accuracy), 1, P610002_VC_Accuracy);

		xQueueSend(qResults, &results, 0);
	}
}

/**
 * @brief This task represents this CAN node on the network as a slave device.
 */
static void TaskCANOpenSlave(void* arg)
{
	MCOUSER_ResetCommunication();

	while (1)
	{
		// Operate on CANopen protocol stack
		MCO_ProcessStack();

		// Operate on application
		if (MY_NMT_STATE == NMTSTATE_OP)
		{
			// only when we are operational, notify the PDO process task to receive the data.
			xTaskNotify(hTaskPDOProcess, 0, eNoAction);
		}

		// Check for CAN Err, auto-recover
		if (MCOHW_GetStatus() & HW_BOFF)
		{
			MCOUSER_FatalError(0xF6F6);
		}

		vTaskDelay(10);
	}
}

/**
 * @brief Provides a tick to the CANopen stack.
 */
static void Tick(void)
{
	MCOHW_Tick();
}
