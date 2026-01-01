/*
 * it.c
 *
 *  Created on: Dec 28, 2025
 *      Author: Saravana
 */

#include "it.h"

void exti_init(void) {
	// Route PA0 to EXTI0
	SYSCFG->EXTICR[0] &= ~(15U << 0);

	// Trigger configuration - Falling Edge
	EXTI->RTSR &= ~ (1U << 0);
	EXTI->FTSR |= (1U << 0);

	// To prevent potential false interrupt on startup
	EXTI->PR |= (1U << 0);

	// Enable Interrupt for EXTI0
	EXTI->IMR |= (1U << 0);

	// Enable NVIC Interrupt
	NVIC->ISER[0] |=(1U << 6);
}
