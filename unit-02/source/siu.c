/*
 *	Project Owner	: TU Chemnitz
 *	Project Name	: ASE Tutorial Unit-2
 *	File Name		: siu.c
 *	Author			: ASE Admin
 *  Created on		: 25 Feb 2024
 */

/* Includes ******************************************************************/
#include "siu.h"

/*
 * @brief	SIU pin configuration function
 *
 * @param	void
 * @retval	void
 */
void SIU_Init(void)
{

	/* Input pin configurations */
	SIU.PCR[PCR_BT1].R = 0x0100;
	SIU.PCR[PCR_BT2].R = 0x0100;
	SIU.PCR[PCR_SW1].R = 0x0100;
	SIU.PCR[PCR_SW2].R = 0x0100;
	SIU.PCR[PCR_SW3].R = 0x0100;
	SIU.PCR[PCR_SW4].R = 0x0100;

	/* Output pin configurations */
	SIU.PCR[PCR_LED_P].R = 0x0200;
	SIU.PCR[PCR_LED_Rx].R = 0x0200;
	SIU.PCR[PCR_LED_Tx].R = 0x0200;
	SIU.PCR[PCR_LED_U1].R = 0x0200;
	SIU.PCR[PCR_LED_U2].R = 0x0200;
	SIU.PCR[PCR_LED_U3].R = 0x0200;

	/* Analog pin configurations */
	SIU.PCR[PCR_POT].R = 0x2500;
	SIU.PCR[PCR_LDR].R = 0x2500;

	/* TO-DO: your task implementations **************************************/

	/* Setup CAN controller pins */

	/* TX - transmitting */
	SIU.PCR[16].B.PA = 0x1;
	SIU.PCR[16].B.OBE = 0x1;
	SIU.PCR[16].B.IBE = 0x0;

	/* RX - receiving */
	SIU.PCR[17].B.PA = 0x1;
	SIU.PCR[17].B.OBE = 0x0;
	SIU.PCR[17].B.IBE = 0x1;

	SIU.PSMI[0].B.PADSEL = 0x1;
	SIU.PSMI[33].B.PADSEL = 0x1;

	/*************************************************************************/
}
