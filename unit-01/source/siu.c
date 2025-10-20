/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "siu.h"
#include "xpc56el.h"

/*
 * @brief	SIU pin configuration function
 *
 * @param	void
 * @retval	void
 */
void SIU_Init(void)
{
	// Configure all pins which are required for your task here

	/* TO-DO: your task implementations **************************************/

	/* Input pin configurations */

	// SIU.PCR[...].R = ...;
	SIU.PCR[60].R = 0x0100; // BT1 - D[12]
	SIU.PCR[62].R = 0x0100; // BT2 - D[14]
	SIU.PCR[52].R = 0x0100; // SW1 - D[4]
	SIU.PCR[53].R = 0x0100; // SW2 - D[5]
	SIU.PCR[54].R = 0x0100; // SW3 - D[6]
	SIU.PCR[55].R = 0x0100; // SW4 - D[7]

	/* Output pin configurations */

	// SIU.PCR[...].R = ...;
	SIU.PCR[56].R = 0x0200; // P - Red LED
	SIU.PCR[57].R = 0x0200; // Rx - Yellow LED
	SIU.PCR[58].R = 0x0200; // Tx - Yellow LED
	SIU.PCR[59].R = 0x0200; // U1 - Green LED
	SIU.PCR[43].R = 0x0200; // U2 - Green LED
	SIU.PCR[6].R = 0x0200;	// U3 - Green LED

	/* Analog pin configurations */

	// SIU.PCR[...].R = ...;
	SIU.PCR[66].R = 0x2500; // POT
	SIU.PCR[32].R = 0x2500; // LDR

	/*************************************************************************/
}
