/*
 * usart.c
 *
 *  Created on: Jan 1, 2026
 *      Author: Saravana
 */

#include "usart.h"

void usart_init(void) {
	// Baud rate
	USART1->BRR = (84000000 + 115200/2) / 115200;

	// Enable Reciever, Transmitter, USART
	USART1->CR1 |= (1U << 2) | (1U << 3) | (1U << 13);
}

void uart_transmit(const uint8_t *pData, uint32_t len) {
	for (uint32_t i = 0; i < len; i++) {

		// Wait until Transmit data register is empty
		while (!(USART1->SR & (1 << 7)));

		// Write the Byte into Data Register
		USART1->DR = pData[i];
	}

	// Wait until Transmission is Complete
	while (!(USART1->SR & (1 << 6)));
}
