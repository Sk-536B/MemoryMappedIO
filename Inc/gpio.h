/*
 * gpio.h
 *
 *  Created on: Dec 18, 2025
 *      Author: Saravana
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "base.h"

/* GPIO register map
 *
 * Each GPIO register is 32-bit wide and located at a fixed offset from the
 * GPIO base address. Since C structure members are laid out sequentially
 * in memory, defining the registers as consecutive uint32_t members allows
 * the structure layout to match the hardware register map exactly.
 *
 * By casting the GPIO base address to this structure type, individual
 * registers can be accessed directly without explicitly defining offsets.
 */
typedef struct {
    volatile uint32_t MODER;    /* offset 0x00 */
    volatile uint32_t OTYPER;   /* offset 0x04 */
    volatile uint32_t OSPEEDR;  /* offset 0x08 */
    volatile uint32_t PUPDR;    /* offset 0x0C */
    volatile uint32_t IDR;      /* offset 0x10 */
    volatile uint32_t ODR;      /* offset 0x14 */
    volatile uint32_t BSRR;     /* offset 0x18 */
    volatile uint32_t LCKR;     /* offset 0x1C */
    volatile uint32_t AFRL;     /* offset 0x20 */
    volatile uint32_t AFRH;     /* offset 0x24 */
} GPIO_TypeDef;

#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)

// Function prototypes
void gpio_init(void);
void gpio_toggle(void);

#endif /* GPIO_H_ */
