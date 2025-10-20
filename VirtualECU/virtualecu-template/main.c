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

/* Task-1 implementation *****************************************************/
void task_pot(int x){

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}

/* Task-2 implementation *****************************************************/
void task_ldr(int x){

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}

/* Task-3 implementation *****************************************************/
void task_counter(void){

	/* TO-DO: your task implementations **************************************/

	/*************************************************************************/
}

/*
 * @brief	Main program
 *
 * @param	void
 * @retval	int
 */
int main(void) {
	/* peripherals initialization, do not remove */
	peripheralsInit();


	/* TO-DO: your task implementations **************************************/


	/* Configure and start timer channels */	
    // PIT_ConfigureTimer(<channel>, <interval in milliseconds>);

	/*************************************************************************/

	/* main program */
	while(1){
		/* System function, do not remove */
		systemFunction();
		/* TO-DO: your task implementations **********************************/
        


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
void PIT_Channel_1(void){

	/* TO-DO: your task implementations **************************************/
	

	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 2 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_2(void){

	/* TO-DO: your task implementations **************************************/


	/*************************************************************************/
}


/*
 * @brief	PIT timer channel 3 IRQ callback
 *
 * @param	void
 * @retval	void
 */
void PIT_Channel_3(void){

	/* TO-DO: your task implementations **************************************/


	/*************************************************************************/
}
