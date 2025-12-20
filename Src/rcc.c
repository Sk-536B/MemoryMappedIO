/*
 * rcc.c
 *
 *  Created on: Dec 19, 2025
 *      Author: Saravana
 */

#include "rcc.h"

void clock_init(void) {

	// HSEON - Enables HSE
	RCC->CR |= (1U << 16);

	// HSERDY - Wait until HSE is Ready
	while(!(RCC->CR & (1U << 17)));

	// PWREN - Power Enable Clock
	RCC->APB1ENR |= (1U << 28);

	// SW - Selects HSE as System Clock
	RCC->CFGR &= ~(3U << 0);
	RCC->CFGR |= (1U << 0);

	// SWS - Wait Until HSE is being used
	while (((RCC->CFGR >> 2) & 3U) != 1);
}
