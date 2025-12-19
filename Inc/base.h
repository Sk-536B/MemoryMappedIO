/*
 * base.h
 *
 *  Created on: Dec 18, 2025
 *      Author: Saravana
 */

#ifndef BASE_H_
#define BASE_H_

#define PERIPH_BASE			(0x40000000)

// Peripheral Memory Map
#define AHB1PERIPH_BASE	(PERIPH_BASE + 0x00020000)

// AHB1 Peripherals (GPIO & RCC)
#define GPIOA_BASE			(AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASE			(AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASE			(AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASE			(AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASE			(AHB1PERIPH_BASE + 0x1000)
#define GPIOH_BASE			(AHB1PERIPH_BASE + 0x1C00)

#define RCC_BASE				(AHB1PERIPH_BASE + 0x3800)

#endif /* BASE_H_ */
