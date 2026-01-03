/*
 * usart.h
 *
 *  Created on: Jan 1, 2026
 *      Author: Saravana
 */

#ifndef USART_H_
#define USART_H_

#include <stdint.h>
#include "base.h"

typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;
} USARTx_TypeDef;

#define USART1 ((USARTx_TypeDef *) USART1_BASE)

void usart_init(void);
void uart_transmit(const uint8_t *pData, uint32_t len);
void uart_receive(uint8_t *pData, uint32_t len);

#endif /* USART_H_ */
