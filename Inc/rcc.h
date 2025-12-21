/*
 * rcc.h
 *
 *  Created on: Dec 19, 2025
 *      Author: Saravana
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>
#include "base.h"

typedef struct {
    volatile uint32_t CR;             /* 0x00 */
    volatile uint32_t PLLCFGR;        /* 0x04 */
    volatile uint32_t CFGR;           /* 0x08 */
    volatile uint32_t CIR;            /* 0x0C */
    volatile uint32_t AHB1RSTR;       /* 0x10 */
    volatile uint32_t AHB2RSTR;       /* 0x14 */
    uint32_t RESERVED0[2];            /* 0x18, 0x1C */
    volatile uint32_t APB1RSTR;       /* 0x20 */
    volatile uint32_t APB2RSTR;       /* 0x24 */
    uint32_t RESERVED1[2];            /* 0x28, 0x2C */
    volatile uint32_t AHB1ENR;        /* 0x30 */
    volatile uint32_t AHB2ENR;        /* 0x34 */
    uint32_t RESERVED2[2];            /* 0x38, 0x3C */
    volatile uint32_t APB1ENR;        /* 0x40 */
    volatile uint32_t APB2ENR;        /* 0x44 */
    uint32_t RESERVED3[2];            /* 0x48, 0x4C */
    volatile uint32_t AHB1LPENR;      /* 0x50 */
    volatile uint32_t AHB2LPENR;      /* 0x54 */
    uint32_t RESERVED4[2];            /* 0x58, 0x5C */
    volatile uint32_t APB1LPENR;      /* 0x60 */
    volatile uint32_t APB2LPENR;      /* 0x64 */
    uint32_t RESERVED5[2];            /* 0x68, 0x6C */
    volatile uint32_t BDCR;           /* 0x70 */
    volatile uint32_t CSR;            /* 0x74 */
    uint32_t RESERVED6[2];            /* 0x78, 0x7C */
    volatile uint32_t SSCGR;          /* 0x80 */
    volatile uint32_t PLLI2SCFGR;     /* 0x84 */
    uint32_t RESERVED7;               /* 0x88 */
    volatile uint32_t DCKCFGR;        /* 0x8C */
} RCC_TypeDef;

typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CSR;
} PWR_TypeDef;

typedef struct {
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
}SYSTICK_TypeDef;

#define RCC 		((RCC_TypeDef *) RCC_BASE)
#define PWR 		((PWR_TypeDef *) PWR_BASE)
#define SYSTICK ((SYSTICK_TypeDef *) SYSTICK_BASE)

void clock_init(void);
void systick_init(void);
void systick_deinit(void);
void systick_delay_ms(uint32_t delay);

#endif /* RCC_H_ */
