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

	// PWREN - Enable Power peripheral Clock
	RCC->APB1ENR |= (1U << 28);

	/*
	 *	Voltage Scaling
	 *	0x10 - Scale 2 for upto 84MHZ
	 */
	PWR->CR &= ~(3U << 14);
	PWR->CR |= (2U << 14);

	// Flash Latency - 2, Enable Prefetch, Instruction Cache, Data Cache
	FLASH->ACR = (2U << 0) | (1U << 8) | (1U << 9) | (1U << 10);

	// Configure APB1 max Clock speed - AHB/2
	RCC->CFGR |= (4 << 10);

	/* PLL Configuration */
	// Clear Necessary bits before setting
	RCC->PLLCFGR &= ~((63U << 0) | (511U << 6) | (3U << 16) | (15U << 24));

	// PLLM | PLLN | PLLP | PLLQ | PLLSRC - HSE
	RCC->PLLCFGR |= (25U << 0) | (336U << 6) | (1U << 16) | (7U << 24) | (1U << 22);

	// PLLON
	RCC->CR |= (1U << 24);

	// PLLRDY - Wait until PLL is Ready
	while(!(RCC->CR & (1U << 25)));

	// SW - Select PLL as System Clock Source
	RCC->CFGR &= ~(3U << 0);
	RCC->CFGR |= (2U << 0);

	// SWS - Wait for status
	while (((RCC->CFGR >> 2) & 3U) != 2);

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
	// For 1ms Tick from 25MHZ
	SYSTICK->LOAD = 83999;

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
