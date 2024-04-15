/**
 * ---------------------------------------------------------------+
 * @desc        Button functions
 * ---------------------------------------------------------------+
 * @copyright (C) 2024 Pawe³ Stanek
 * @author      Pawe³ Stanek
 * @email       pawel.ryszard.stank@gmail.com
 * @date        05.04.2024
 * @file        buttons.c
 * @tested      AVR Atmega328p
 *
 * @depend      buttons.h
 *
 */

#include "buttons.h"
#include <avr/io.h>

// Variable to store the previous button state
volatile bool lastButtonState[BUTTON_COUNT] = {false, false, false, false, false};

// Function to change the button state
void changeButtonState(int buttonIndex) {
    // Turn off all buttons
    for (int i = 0; i < BUTTON_COUNT; i++) {
        lastButtonState[i] = false;
    }

    // Turn on the selected button
    lastButtonState[buttonIndex] = true;
}

// Function to initialize pins
void initializePins() {
    // Buttons as inputs with pull-up
    DDRC &= ~(1 << BUTTON_PIN_1 | 1 << BUTTON_PIN_2 | 1 << BUTTON_PIN_3 | 1 << BUTTON_PIN_4);
    PORTC |= (1 << BUTTON_PIN_1 | 1 << BUTTON_PIN_2 | 1 << BUTTON_PIN_3 | 1 << BUTTON_PIN_4);

    // Button 5 as input with pull-up (PORT D)
    DDRD &= ~(1 << BUTTON_PIN_5);
    PORTD |= (1 << BUTTON_PIN_5);

    // LEDs as outputs
    DDRD |= (1 << LED_PIN_1 | 1 << LED_PIN_2 | 1 << LED_PIN_3 | 1 << LED_PIN_4 | 1 << LED_PIN_5);
}

// Function to check button state and LED state
void checkButtons(int ledStates[]) {
    // Variable to store whether button 4 was previously pressed
    static bool button4Pressed = false;
    // Variable to store whether button 5 was previously pressed
    static bool button5Pressed = false;

    // Check the state of each button
    for (int i = 0; i < BUTTON_COUNT; i++) {
        bool currentButtonState;
        if (i < 3)
            currentButtonState = !(PINC & (1 << (BUTTON_PIN_1 + i)));
        else if (i == 3)
            currentButtonState = !(PINC & (1 << BUTTON_PIN_4));
        else if (i == 4)
            currentButtonState = !(PIND & (1 << BUTTON_PIN_5));

        // If the button is pressed (LOW state) and was released in the previous cycle (HIGH state)
        if (currentButtonState == false && lastButtonState[i] == true) {
            // Turn off all LEDs if button 1, 2, or 3 is pressed
            if (i < 3) {
                for (int j = 0; j < 3; j++) {
                    PORTD &= ~(1 << (LED_PIN_1 + j));
                }
            }

            // Turn on the LED corresponding to the pressed button
            if (i < 3) {
                PORTD ^= (1 << (LED_PIN_1 + i));
            } else if (i == 3 && !button4Pressed) {
                PORTD ^= (1 << LED_PIN_4);
                button4Pressed = true;
            } else if (i == 4 && !button5Pressed) {
                PORTD ^= (1 << LED_PIN_5);
                button5Pressed = true;
            }
        }

        // Save the current button state
        lastButtonState[i] = currentButtonState;

        // Save the current LED state
        ledStates[i] = (PORTD & (1 << (LED_PIN_1 + i))) ? 1 : 0;
    }

    // Reset the button 4 flag if it is released
    if (lastButtonState[3] == true && button4Pressed == true) {
        button4Pressed = false;
    }

    // Reset the button 5 flag if it is released
    if (lastButtonState[4] == true && button5Pressed == true) {
        button5Pressed = false;
    }
}
