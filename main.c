/**
 * ---------------------------------------------------------------+
 * @desc        Main file
 * ---------------------------------------------------------------+
 * @copyright (C) 2024 Pawe³ Stanek
 * @author        Pawe³ Stanek
 * @email		  pawel.ryszard.stank@gmail.com
 * @date          05.04.2024
 * @file          main.c
 * @tested        AVR Atmega328p
 *
 * @version      1.0
 *
 * */


#include "lib/dishwasher_panel.h"
#include "lib/buttons.h"
#include "lib/mk_uart_printf.h"

#include <util/delay.h>

int main(void) {
//  printf_init();
    DishwasherPanel();
    initializePins();

    int ledStates[BUTTON_COUNT]; 		// Declare an array to store LED states
    _Bool boolLedStates[BUTTON_COUNT];  // Declare an array to store LED states as boolean values

    while (1) {
        checkButtons(ledStates);		// Check the state of buttons

        // Convert ledStates to _Bool type and printf this as a table.

//        printf("LED_ON [ ");
//        for (int i = 0; i < BUTTON_COUNT; i++) {
//            printf("%d ", ledStates[i]);
//        }   printf("]\r\n");

        // Convert ledStates to _Bool type
        for (int i = 0; i < BUTTON_COUNT; i++) {
            boolLedStates[i] = ledStates[i];
        }

        DishwasherPanel_Update(boolLedStates); // Update dishwasher panel based on button states

        _delay_ms(50);
    }

    return 0;
}


