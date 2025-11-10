/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "init.h"
#include "stdio.h"

/* Global variables **********************************************************/
int speed = 0;
int rpm = 8000;
int rpm_dir = -1; // rpm decreasing initially

void can_send_engine_on(void)
{

	/* TO-DO: your task implementations **************************************/

	// set payload bytes, if necessary
	// CAN_0.BUF[8].DATA.B[1] = 1; // no payload

	// write the correct CODE value to this register to instruct the CAN controller to transmit the CAN message
	CAN_0.BUF[8].CS.B.CODE = 0xC;
}

void can_send_speed(int value)
{
	/* TO-DO: your task implementations **************************************/

	// TASK 3
	// uint32_t raw_speed = (uint32_t)value;		// converts to uint32_t
	int speed_kmh = ((long)value * 240u + 273u / 2u) / 4095u; // speed in km/h
	// why rounding? - so that decimal values are rounded properly (not truncated)

	CAN_0.BUF[9].DATA.B[0] = speed_kmh;

	CAN_0.BUF[9].CS.B.CODE = 0xC;
}

void can_send_rpm(int value)
{
	/* TO-DO: your task implementations **************************************/
	uint16_t rpm_value = (uint16_t)value; // converts to uint16_t - only lower 16 bits are needed

	CAN_0.BUF[10].DATA.B[0] = (uint8_t)(rpm_value & 0xFF);
	CAN_0.BUF[10].DATA.B[1] = (uint8_t)((rpm_value >> 8) & 0xFF);

	CAN_0.BUF[10].CS.B.CODE = 0xC;
}

void can_send_lights(void)
{
	/* TO-DO: your task implementations **************************************/

	uint8_t lights_status = (SW2 ? 0x01u : 0x00u) | (SW1 ? 0x02u : 0x00u);

	CAN_0.BUF[11].DATA.B[0] = lights_status;

	CAN_0.BUF[11].CS.B.CODE = 0xC;
}

void can_send(void)
{

	/* TO-DO: your task implementations **************************************/
	static int blink_counter = 0;
	static int rpm_counter = 0;

	LED_Tx = !LED_Tx;
	can_send_engine_on();
	can_send_speed(speed); // TASK 3
	can_send_lights();
	can_send_rpm(rpm);

	// Signal Lights LED logic
	blink_counter++;

	if (blink_counter >= 5)
	{
		if (SW1 && SW2)
		{
			LED_U1 = !LED_U1;
			LED_U3 = LED_U1;
		}
		else if (SW2 && !SW1)
		{
			LED_U1 = !LED_U1;
			LED_U3 = 0;
		}
		else if (SW1 && !SW2)
		{
			LED_U3 = !LED_U3;
			LED_U1 = 0;
		}
		else
		{
			LED_U1 = 0;
			LED_U3 = 0;
		}

		blink_counter = 0;
	}

	// RPM logic
	rpm_counter++;

	if (rpm_counter >= 10)
	{
		if (rpm == 0 && rpm_dir == -1)
		{
			rpm_dir = 1;
		}
		else if (rpm == 8000 && rpm_dir == 1)
		{
			rpm_dir = -1;
		}

		rpm += rpm_dir * 250;

		rpm_counter = 0;
	}

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
	// PIT_ConfigureTimer(2, 500); // don't need for now
	// PIT_StartTimer(2);

	/*************************************************************************/

	/* main program */
	while (1)
	{
		/* System function */
		systemFunction();

		/* TO-DO: your task implementations **********************************/

		// Task 1 and 2
		// LED_U1 = 0; // uncomment for Task 1 & 2
		LED_Rx = 0;
		LED_Tx = 0;

		// Task 3
		speed = POT;

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
		// uncomment for task 1 and 2
		// if (crfp.SID == 0x11) // check the Message ID
		// {
		// 	LED_U1 = !LED_U1;
		// }

		if (crfp.SID == 0x11)
		{
			if (!LED_P)
			{
				LED_P = !LED_P; // TASK 3
			}
			PIT_StartTimer(1);
		}
		else if (crfp.SID == 0x10)
		{
			PIT_StopTimer(1);
			LED_P = 0; // TASK 3
			LED_Tx = 0;
			LED_U1 = 0;
			LED_U3 = 0;
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
	can_send();
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
