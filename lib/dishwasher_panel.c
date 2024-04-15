/**
 * ---------------------------------------------------------------+
 * @desc        Dishwasher Panel
 * ---------------------------------------------------------------+
 * @copyright (C) 2024 Pawe³ Stanek
 * @author      Pawe³ Stanek
 * @email       pawel.ryszard.stank@gmail.com
 * @date        05.04.2024
 * @file        dishwasher_panel.c
 * @tested      AVR Atmega328p
 *
 * @depend      dishwasher_panel.h, hd44780pcf8574.h
 *
 */

#include "dishwasher_panel.h"
#include "hd44780pcf8574.h"
#include <string.h>

#define PCF8574_ADDRESS 0x27

// Previous LED states array
static int prevLedStatesInt = 0;


void DishwasherPanel() {
    char addr = PCF8574_ADDRESS;

    char TopText[20] = "Bosh";             // Top text initialization
    char BottomText[20] = "Select Mode";   // Bottom text initialization

    HD44780_PCF8574_Init(addr);            // Initialize LCD

    HD44780_PCF8574_DisplayClear(addr);    			 // Clear display
    HD44780_PCF8574_DisplayOn(addr);     			 // Turn on display
    HD44780_PCF8574_DrawString(addr, TopText);       // Draw top text
    HD44780_PCF8574_PositionXY(addr, 0, 1);          // Set cursor position
    HD44780_PCF8574_DrawString(addr, BottomText);    // Draw bottom text
}


void DishwasherPanel_Update(_Bool ledStates[]) {
    char addr = PCF8574_ADDRESS;

    // Initialize variables at the beginning of the function
    static char TopText[20] = "Bosh";           // Top text initialization
    static char BottomText[20] = "Select Mode"; // Bottom text initialization

    // Convert the ledStates array to a single integer value
    int ledStatesInt = 0;
    for (int i = 0; i < 5; ++i) {
        ledStatesInt |= ledStates[i] << i;
    }

    // Check if the content of the ledStatesInt array has changed
    if (ledStatesInt != prevLedStatesInt) {
        prevLedStatesInt = ledStatesInt;

        // Check and update text based on LED states
        switch (ledStatesInt) {
            case 0b00001:
                strcpy(TopText, "Mode: Auto");
                strcpy(BottomText, "Time: 2:45");
                break;
            case 0b00010:
                strcpy(TopText, "Mode: Hot");
                strcpy(BottomText, "Time: 3:30");
                break;
            case 0b00100:
                strcpy(TopText, "Mode: ECO");
                strcpy(BottomText, "Time: 2:30");
                break;
            case 0b01001:
                strcpy(TopText, "Mode: Auto");
                strcpy(BottomText, "Time: 1:34");
                break;
            case 0b10001:
                strcpy(TopText, "Mode: Auto");
                strcpy(BottomText, "Time: 2:25");
                break;
            case 0b11001:
                strcpy(TopText, "Mode: Auto");
                strcpy(BottomText, "Time: 1:25");
                break;
            case 0b01010:
                strcpy(TopText, "Mode: Hot");
                strcpy(BottomText, "Time: 1:45");
                break;
            case 0b10010:
                strcpy(TopText, "Mode: Hot");
                strcpy(BottomText, "Time: 2:05");
                break;
            case 0b11010:
                strcpy(TopText, "Mode: Hot");
                strcpy(BottomText, "Time: 1:25");
                break;
            case 0b01100:
                strcpy(TopText, "Mode: Eco");
                strcpy(BottomText, "Time: 1:19");
                break;
            case 0b10100:
                strcpy(TopText, "Mode: Eco");
                strcpy(BottomText, "Time: 2:10");
                break;
            case 0b11100:
                strcpy(TopText, "Mode: Eco");
                strcpy(BottomText, "Time: 1:17");
                break;

        }

        // Update the display
        HD44780_PCF8574_Init(addr);
        HD44780_PCF8574_DisplayClear(addr);
        HD44780_PCF8574_DisplayOn(addr);
        HD44780_PCF8574_DrawString(addr, TopText);
        HD44780_PCF8574_PositionXY(addr, 0, 1);
        HD44780_PCF8574_DrawString(addr, BottomText);
    }
}
