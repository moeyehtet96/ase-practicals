/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-1
 *	File Name		: main.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "init.h"

#include "xpc56el.h"
#include "siu.h"

/* Global variables **********************************************************/

// put any global variables you need here
#define P_PCR 56
#define Rx_PCR 57
#define Tx_PCR 58
#define U1_PCR 59
#define U2_PCR 43
#define U3_PCR 6

int counter = 0;	 // counter initialization
int counter_dir = 1; // 1 if increasing, -1 if decreasing

/* Helper function */
void set_led_states(bool u1_state, bool u2_state, bool u3_state, bool tx_state, bool rx_state, bool p_state)
{
	SIU.GPDO[P_PCR].R = p_state;
	SIU.GPDO[Rx_PCR].R = rx_state;
	SIU.GPDO[Tx_PCR].R = tx_state;
	SIU.GPDO[U3_PCR].R = u3_state;
	SIU.GPDO[U2_PCR].R = u2_state;
	SIU.GPDO[U1_PCR].R = u1_state;
}

/* Task-1 implementation *****************************************************/
void task_pot(int x)
{

	/* TO-DO: your task implementations **************************************/

	// map potentiometer readings to LEDs
	// set_led_s
	if (x < 682)
	{
		set_led_states(false, false, false, false, false, true);
	}
	else if (x >= 682 && x < 1364)
	{
		set_led_states(false, false, false, false, true, true);
	}
	else if (x >= 1364 && x < 2046)
	{
		set_led_states(false, false, false, true, true, true);
	}
	else if (x >= 2046 && x < 2728)
	{
		set_led_states(false, false, true, true, true, true);
	}
	else if (x >= 2728 && x < 3410)
	{
		set_led_states(false, true, true, true, true, true);
	}
	else if (x >= 3420)
	{
		set_led_states(true, true, true, true, true, true);
	}

	/*************************************************************************/
}

/* Task-2 implementation *****************************************************/
void task_ldr(int x)
{

	/* TO-DO: your task implementations **************************************/

	// reuse task_pot()

	/*************************************************************************/
}

/* Task-3 implementation *****************************************************/
void task_counter(void)
{

	/* TO-DO: your task implementations **************************************/

	SIU.GPDO[U3_PCR].R = counter & 0x01;
	SIU.GPDO[U2_PCR].R = (counter >> 1) & 0x01;
	SIU.GPDO[U1_PCR].R = (counter >> 2) & 0x01;

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
	/* peripherals initialization, do not remove */
	peripheralsInit();

	/* TO-DO: your task implementations **************************************/

	/* Configure and start timer channels */
	// PIT_ConfigureTimer(<channel>, <interval in milliseconds>);
	PIT_ConfigureTimer(1, 1000); // timer channel 1, 1s

	/*************************************************************************/

	/* main program */
	while (1)
	{
		/* System function, do not remove */
		systemFunction();
		/* TO-DO: your task implementations **********************************/
		int is_sw1_on = SIU.GPDI[52].R;
		int is_sw2_on = SIU.GPDI[53].R;
		int is_sw3_on = SIU.GPDI[54].R;
		int is_sw4_on = SIU.GPDI[55].R;

		int total_sw_on = is_sw1_on + is_sw2_on + is_sw3_on;

		int is_BT1_pressed = SIU.GPDI[60].R;
		int is_BT2_pressed = SIU.GPDI[62].R;

		if (is_BT1_pressed == 1)
		{
			counter_dir = 1;
		}
		else if (is_BT2_pressed == 1)
		{
			counter_dir = -1;
		}

		if (total_sw_on == 1)
		{
			if (is_sw1_on == 1)
			{
				// task 1
				int pot_value = (ADC0.CDR[5].R & 0x00000FFF);
				task_pot(pot_value);
			}
			else if (is_sw2_on == 1)
			{
				// task 2
				int ldr_value = (ADC1.CDR[3].R & 0x00000FFF);
				task_pot(ldr_value);
			}
			else if (is_sw3_on == 1)
			{
				// task 3
				if (is_sw4_on == 0)
				{
					PIT_StopTimer(1);
				}
				else
				{
					PIT_StartTimer(1);
				}
				task_counter();
			}
		}
		else
		{
			set_led_states(0, 0, 0, 0, 0, 0);
		}

		/*********************************************************************/

		/* 10 ms OS delay */
		osalThreadDelayMilliseconds(10UL);
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

	if (counter == 7 && counter_dir == 1)
	{
		counter = 0;
	}
	else if (counter == 0 && counter_dir == -1)
	{
		counter = 7;
	}
	else
	{
		counter += counter_dir;
	}

	/*************************************************************************/
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

	/*************************************************************************/
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

	/*************************************************************************/
}
