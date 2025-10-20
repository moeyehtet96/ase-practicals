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
int counter = 0;
int is_increasing = 1; // true - increasing, false - decreasing

/* Task-1 implementation *****************************************************/
void task_pot(int x)
{

	/* TO-DO: your task implementations **************************************/
	if (x < 682)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 0;
		SIU.GPDO[58].R = 0;
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
	}
	else if (x >= 682 && x < 1364)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 0;
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
	}
	else if (x >= 1364 && x < 2046)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
	}
	else if (x >= 2046 && x < 2728)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
	}
	else if (x >= 2728 && x < 3410)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 0;
	}
	else if (x >= 3420)
	{
		SIU.GPDO[56].R = 1;
		SIU.GPDO[57].R = 1;
		SIU.GPDO[58].R = 1;
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 1;
	}

	/*************************************************************************/
}

/* Task-2 implementation *****************************************************/
void task_ldr(int x)
{

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}

/* Task-3 implementation *****************************************************/
void task_counter(void)
{

	/* TO-DO: your task implementations **************************************/
	switch (counter)
	{
	case 0:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
		break;
	case 1:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 0;
		break;
	case 2:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 0;
		break;
	case 3:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 0;
		break;
	case 4:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 1;
		break;
	case 5:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 0;
		SIU.GPDO[59].R = 1;
		break;
	case 6:
		SIU.GPDO[6].R = 0;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 1;
		break;
	case 7:
		SIU.GPDO[6].R = 1;
		SIU.GPDO[43].R = 1;
		SIU.GPDO[59].R = 1;
		break;
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
	/* peripherals initialization, do not remove */
	peripheralsInit();

	/* TO-DO: your task implementations **************************************/

	/* Configure and start timer channels */
	// PIT_ConfigureTimer(<channel>, <interval in milliseconds>);
	PIT_ConfigureTimer(1, 1000); // timer channel 1, 1s
	// PIT_StartTimer(1);

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

		int is_BT1_pressed = SIU.GPDI[60].R;
		int is_BT2_pressed = SIU.GPDI[62].R;

		if (is_BT1_pressed)
		{
			is_increasing = 1;
		}
		else if (is_BT2_pressed)
		{
			is_increasing = 0;
		}

		if (is_sw1_on && !is_sw2_on)
		{
			int pot_value = (ADC0.CDR[5].R & 0x00000FFF);
			task_pot(pot_value);
		}
		else if (!is_sw1_on && is_sw2_on && !is_sw3_on)
		{
			int ldr_value = (ADC1.CDR[3].R & 0x00000FFF);
			task_pot(ldr_value);
		}
		else if (!is_sw1_on && !is_sw2_on && is_sw3_on)
		{
			if (!is_sw4_on)
			{
				PIT_StopTimer(1);
			}
			else
			{
				PIT_StartTimer(1);
			}
			task_counter();
		}
		else
		{
			SIU.GPDO[56].R = 0;
			SIU.GPDO[57].R = 0;
			SIU.GPDO[58].R = 0;
			SIU.GPDO[6].R = 0;
			SIU.GPDO[43].R = 0;
			SIU.GPDO[59].R = 0;
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
	if (is_increasing)
	{
		if (counter == 7)
		{
			counter = 0;
		}
		else
		{
			counter += 1;
		}
	}
	else
	{
		if (counter == 0)
		{
			counter = 7;
		}
		else
		{
			counter -= 1;
		}
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
