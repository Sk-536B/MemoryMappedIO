/*
 * gpio.c
 *
 *  Created on: Dec 18, 2025
 *      Author: Saravana
 */

#include "gpio.h"

void gpio_init(void) {
	// Set GPIO pin A0 mode to Input
	GPIOA->MODER &= ~(3U<<0);

	// Enable Internal Pull-up for PA0
	GPIOA->PUPDR |= (1U<<0);
	GPIOA->PUPDR &= ~(1U<<1);

	// Set GPIO pin C13 mode to Output
	GPIOC->MODER |= (1U<<26);
	GPIOC->MODER &= ~(1U<<27);

	// Set AF mode for pin A1
	GPIOA->MODER &= ~(3U << 2);
	GPIOA->MODER |= (2U << 2);

	// Select AF1 mode for pin A1
	GPIOA->AFRL &= ~(15U << 4);
	GPIOA->AFRL |= (1U << 4);
}

void gpio_toggle(void) {
	GPIOC->ODR ^= USER_LED;
}
