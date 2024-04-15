/*
 * my_printf.c
 *
 * 	MK MINI PRINTF  v.1.0
 *
 *  Created on: 21 wrz 2022
 *      Author: Miros³aw Kardaœ
 */
#include <avr/io.h>
#include <stdio.h>
#include "mk_uart_printf.h"

#define __UBRR ((F_CPU+UART_BAUD*8UL)/(16UL*UART_BAUD)-1UL)

#ifndef UBRRL
    #define UBRRL UBRR0L
#endif
#ifndef UBRRH
    #define UBRRH UBRR0H
#endif

#ifndef UCSRB
    #define UCSRB UCSR0B
#endif

#ifndef TXEN
    #define TXEN TXEN0
#endif

#ifndef UCSRA
    #define UCSRA UCSR0A
#endif

#ifndef UDRE
    #define UDRE UDRE0
#endif

#ifndef UDR
    #define UDR UDR0
#endif

static void uart_init(void) {
    UBRRH = (uint8_t)(__UBRR >> 8);
    UBRRL = (uint8_t)__UBRR;
    UCSRB = (1 << TXEN);
}

static void uart_putc(char byte) {
    while (!(UCSRA & (1 << UDRE)));
    UDR = byte;
}

static int put(char c, FILE *file) {
    uart_putc(c);
    return 0;
}

/* Initialize printf function */
/* Should be called in the main() function's INIT section */
void printf_init(void) {
    uart_init();
    fdevopen(&put, NULL);
}
