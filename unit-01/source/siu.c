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
	SIU.PCR[60].R = 0x0100; // BT1 - D[12] - PCR[60]
	SIU.PCR[62].R = 0x0100; // BT2 - D[14] - PCR[62]
	SIU.PCR[52].R = 0x0100; // SW1 - D[4] - PCR[52]
	SIU.PCR[53].R = 0x0100; // SW2 - D[5] - PCR[53]
	SIU.PCR[54].R = 0x0100; // SW3 - D[6] - PCR[54]
	SIU.PCR[55].R = 0x0100; // SW4 - D[7] - PCR[55]

	/* Output pin configurations */

	// SIU.PCR[...].R = ...;
	SIU.PCR[56].R = 0x0200; // P - Red LED - PCR[56]
	SIU.PCR[57].R = 0x0200; // Rx - Yellow LED - PCR[57]
	SIU.PCR[58].R = 0x0200; // Tx - Yellow LED - PCR[58]
	SIU.PCR[59].R = 0x0200; // U1 - Green LED - PCR[59]
	SIU.PCR[43].R = 0x0200; // U2 - Green LED - PCR[43]
	SIU.PCR[6].R = 0x0200;	// U3 - Green LED - PCR[6]

	/* Analog pin configurations */

	// SIU.PCR[...].R = ...;
	SIU.PCR[66].R = 0x2500; // POT - PCR[66]
	SIU.PCR[32].R = 0x2500; // LDR - PCR[32]

	/*************************************************************************/
}
