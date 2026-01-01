/*
 * it.h
 *
 *  Created on: Dec 28, 2025
 *      Author: Saravana
 */

#ifndef IT_H_
#define IT_H_

#include "base.h"
#include <stdint.h>

typedef struct {
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR[4];
	volatile uint32_t CMPCR;
} SYSCFG_TypeDef;

typedef struct {
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
} EXTI_TypeDef;

typedef struct {
	volatile uint32_t ISER[8];
	uint32_t RESERVED0[24];
	volatile uint32_t ICER[8];
	uint32_t RESERVED1[24];
	volatile uint32_t ISPR[8];
	uint32_t RESERVED2[24];
	volatile uint32_t ICPR[8];
	uint32_t RESERVED3[24];
	volatile uint32_t IABR[8];
	uint32_t RESERVED4[56];
	volatile uint8_t IP[240];
} NVIC_TypeDef;

#define SYSCFG	((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI		((EXTI_TypeDef *) EXTI_BASE)
#define NVIC		((NVIC_TypeDef *) NVIC_BASE)

void exti_init(void);

#endif /* IT_H_ */
