/*
 * tim.c
 *
 *  Created on: Dec 21, 2025
 *      Author: Saravana
 */

#include "tim.h"

void pwm_start(void) {
	// Prescaler
	TIM2->PSC = 83;

	// Length of each cycle, Each cycle is ARR * PSC long
	TIM2->ARR = 999;

	// Setting Duty Cycle
	TIM2->CCR2 = 0;

	// Configure Channel 2 for PWM mode 1
	TIM2->CCMR1 &= ~(7U << 12);
	TIM2->CCMR1 |= (6U << 12);

	// Enable Preload
	TIM2->CCMR1 |= (1U << 11);

	// Enables the output on Pin and Start Timer
	TIM2->CCER |= (1U << 4);
	TIM2->CR1 |= (1U << 0);
}
