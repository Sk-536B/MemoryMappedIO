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

	// GPIOA and GPIOC Clock Enable
	RCC->AHB1ENR |= (1U<<0);
	RCC->AHB1ENR |= (1U<<2);

	(void)RCC->AHB1ENR;

	// TIM2 Clock Enable
	RCC->APB1ENR &= ~(3U << 0);
	RCC->APB1ENR |= (1U << 0);

	(void)RCC->APB1ENR;
}

void systick_init(void) {
	// For 1ms Tick
	SYSTICK->LOAD = 24999;

	// Clears the Val register
	SYSTICK->VAL = 0;

	// Enable Counter, Disable Interrupt, Clock source - Processor Clock
	SYSTICK->CTRL = 5;
}

void systick_deinit(void) {
	// Disable Counter
	SYSTICK->CTRL = 0;
}

void systick_delay_ms(uint32_t delay) {
	systick_init();

	uint32_t count = 0;

	while(count != delay) {
		while(!(SYSTICK->CTRL & (1U << 16)));
		count++;
	}

	systick_deinit();
}
