/**
 * ---------------------------------------------------------------+
 * @desc        Dishwasher Panel Header
 * ---------------------------------------------------------------+
 * @copyright (C) 2024 [Author's Name]
 * @file        dishwasher_panel.h
 *
 * @version     1.0
 *
 */

#ifndef DISHWASHER_PANEL_H_
#define DISHWASHER_PANEL_H_

#include <stdbool.h>

// Initialization of the dishwasher panel
void DishwasherPanel(void);

// Update of the dishwasher panel based on LED states
void DishwasherPanel_Update(_Bool ledStates[]);

#endif /* DISHWASHER_PANEL_H_ */
