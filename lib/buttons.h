/**
 * ---------------------------------------------------------------+
 * @desc        Button header file
 * ---------------------------------------------------------------+
 * @copyright (C) 2024 Pawe³ Stanek
 * @author      Pawe³ Stanek
 * @email       pawel.ryszard.stank@gmail.com
 * @date        05.04.2024
 * @file        buttons.h
 * @tested      AVR Atmega328p
 *
 * @version     1.0
 *
 */

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <avr/io.h>
#include <stdbool.h>

// Definition of the size of the lastButtonState array
#define BUTTON_COUNT 5

// Definition of button pins
#define BUTTON_PIN_1 PC1
#define BUTTON_PIN_2 PC2
#define BUTTON_PIN_3 PC3
#define BUTTON_PIN_4 PC0
#define BUTTON_PIN_5 PD7

// Definition of LED pins
#define LED_PIN_1 PD2
#define LED_PIN_2 PD3
#define LED_PIN_3 PD4
#define LED_PIN_4 PD5
#define LED_PIN_5 PD6

// Declaration of the lastButtonState array
extern volatile bool lastButtonState[BUTTON_COUNT];

// Function prototypes
void initializePins(void);
void checkButtons(int ledStates[]);
void handleButtonPress(int pressedButton);

#endif /* BUTTONS_H_ */        // End of header guard
