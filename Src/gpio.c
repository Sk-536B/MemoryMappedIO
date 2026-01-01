/*
 * gpio.c
 *
 *  Created on: Dec 18, 2025
 *      Author: Saravana
 */

#include "gpio.h"

void gpio_init(void) {
	// Set Pin A0 mode to Input
	GPIOA->MODER &= ~(3U << 0);

	// Set Pin A9, A10 to AF
	GPIOA->MODER &= ~(15U << 18);
	GPIOA->MODER |= (10U << 18);

	// Set GPIO pin C13 mode to Output
	GPIOC->MODER |= (1U << 26);
	GPIOC->MODER &= ~(1U << 27);

	// Set AF mode for pin A1
	GPIOA->MODER &= ~(3U << 2);
	GPIOA->MODER |= (2U << 2);

	// Enable Internal Pull-up for PA0
	GPIOA->PUPDR |= (1U << 0);
	GPIOA->PUPDR &= ~(1U << 1);

	// Select AF1 mode for pin A1 - TIM2_CH2
	GPIOA->AFRL &= ~(15U << 4);
	GPIOA->AFRL |= (1U << 4);

	// Select AF7 mode for pins A9 and A10 - USART1 RX and TX
	GPIOA->AFRH &= ~(255U << 4);
	GPIOA->AFRH |= (7U << 4) | (7U << 8);
}

void gpio_toggle(void) {
	GPIOC->ODR ^= (1U << 13);
}
