/*
 * tim.h
 *
 *  Created on: Dec 21, 2025
 *      Author: Saravana
 */

#ifndef TIM_H_
#define TIM_H_

#include <stdint.h>
#include "base.h"

typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SMCR;
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
	volatile uint32_t DCR;
	volatile uint32_t DMAR;
	volatile uint32_t OR;
} TIMx_TypeDef;

#define TIM2 ((TIMx_TypeDef *) TIM2_BASE)

void pwm_start(void);

#endif /* TIM_H_ */
