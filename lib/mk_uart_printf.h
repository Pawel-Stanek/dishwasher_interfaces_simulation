/*
 * my_printf.h
 *
 * 	MK MINI PRINTF  v.1.0
 *
 *  Created on: 21 wrz 2022
 *      Author: Miros³aw Kardaœ
 */

#ifndef MK_UART_PRINTF_H_
#define MK_UART_PRINTF_H_

/* Required includes for library functions */
#include <stdio.h>

/* UART Configuration */
/* Choose desired baud rate */
/********* baud rate config **********************/
#define UART_BAUD           9600
/*************************************************/

/******** Library Function Prototypes *********/

/* The only public function of the library                     */
/* It should be called in the "INIT" section of the main() function */
extern void printf_init(void);

#endif /* MK_UART_PRINTF_H_ */
