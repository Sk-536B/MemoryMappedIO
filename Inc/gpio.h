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

// Configuring GPIO and RCC Registers
#define GPIOA_MODER	(*(volatile uint32_t *) (GPIOA_BASE + 0x00))
#define GPIOA_PUPDR	(*(volatile uint32_t *) (GPIOA_BASE + 0x0C))
#define GPIOA_IDR		(*(volatile uint32_t *) (GPIOA_BASE + 0x10))

#define GPIOC_MODER	(*(volatile uint32_t *) (GPIOC_BASE + 0x00))
#define GPIOC_ODR		(*(volatile uint32_t *) (GPIOC_BASE + 0x14))

#define RCC_AHB1ENR	(*(volatile uint32_t *) (RCC_BASE + 0x30))

// Setting up GPIO pins
#define KEY_BTN		(1U<<0)
#define USER_LED 	(1U<<13)

// Function prototypes
void gpio_init(void);
void gpio_toggle(void);

#endif /* GPIO_H_ */
