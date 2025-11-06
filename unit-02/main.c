/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "init.h"

/* Global variables **********************************************************/
int speed = 0;
int rpm = 0;

void can_send_engine_on(void)
{

	/* TO-DO: your task implementations **************************************/

	// set payload bytes, if necessary
	// CAN_0.BUF[8].DATA.B[1] = 1;

	// write the correct CODE value to this register to instruct the CAN controller to transmit the CAN message
	CAN_0.BUF[8].CS.B.CODE = 0xC;

	LED_Tx = !LED_Tx;
}

void can_send_speed(int value)
{
	/* TO-DO: your task implementations **************************************/

	// TASK 3
	// speed = POT;

	// int speed_kmh = (int)(speed * 240 / 4095);

	// CAN_0.BUF[9].DATA.B[0] = speed_kmh;

	// CAN_0.BUF[9].CS.B.CODE = 0xC;
}

void can_send_rpm(int value)
{
	/* TO-DO: your task implementations **************************************/
}

void can_send_lights(void)
{
	/* TO-DO: your task implementations **************************************/
}

void can_send(void)
{

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}

/*
 * @brief	Main program
 *
 * @param	void
 * @retval	int
 */
int main(void)
{
	/* peripherals initialization */
	peripheralsInit();

	/* TO-DO: your task implementations **************************************/

	/* Configure and start timer channels */
	/* PIT timer channel 1, period = 1000 ms */
	PIT_ConfigureTimer(1, 100);
	// PIT_StartTimer(1); // for task 1

	/*************************************************************************/

	/* main program */
	while (1)
	{
		/* System function */
		systemFunction();

		/* TO-DO: your task implementations **********************************/

		// Task 1 and 2
		LED_Rx = 0;
		LED_U1 = 0;
		LED_Tx = 0;

		// Task 3
		// speed = POT;

		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
	}
}

/*
 * @brief	CAN receive interrupt
 *
 * @param   CANDriver   canp	The CAN controller which received a message
 * @param	CANRxFrame	crfp	The message which was received
 * @retval	void
 */
void can_receive(CANRxFrame crfp)
{
	if (crfp.IDE == CAN_IDE_STD) // a standard message frame has been received
	{
		/* TO-DO: your task implementations ******************************/
		LED_Rx = !LED_Rx; // toggle every time a message is received

		// toggle LED U1 every time ID 0x11 is received
		if (crfp.SID == 0x11) // check the Message ID
		{
			LED_U1 = !LED_U1;
		}

		if (crfp.SID == 0x11)
		{
			// LED_P = !LED_P; // TASK 3
			PIT_StartTimer(1);
		}
		else if (crfp.SID == 0x10)
		{
			// LED_P = !LED_P; // TASK 3
			PIT_StopTimer(1);
		}
	}
}

/*
 * @brief	PIT timer channel 1 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_1(void)
{
	/* TO-DO: your task implementations **************************************/
	can_send_engine_on();
	// can_send_speed(speed); // TASK 3
}

/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void)
{
	/* TO-DO: your task implementations **************************************/
}

/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void)
{
	/* TO-DO: your task implementations **************************************/
}
