/*
 * gpio.c
 *
 *  Created on: Dec 18, 2025
 *      Author: Saravana
 */

#include "gpio.h"

void gpio_init(void) {
	// Enable RCC for GPIOA and GPIOC
	RCC_AHB1ENR |= (1U<<0);
	RCC_AHB1ENR |= (1U<<2);

	(void)RCC_AHB1ENR;

	// Set GPIO pin A0 mode to Input
	GPIOA_MODER &= ~(3U<<0);

	// Enable Internal Pull-up for PA0
	GPIOA_PUPDR |= (1U<<0);
	GPIOA_PUPDR &= ~(1U<<1);

	// Set GPIO pin C13 mode to Output
	GPIOC_MODER |= (1U<<26);
	GPIOC_MODER &= ~(1U<<27);
}

void gpio_toggle(void) {
	GPIOC_ODR ^= USER_LED;
}
