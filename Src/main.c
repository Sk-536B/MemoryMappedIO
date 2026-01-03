#include <string.h>
#include "main.h"

volatile uint32_t it_pending = 0;
uint8_t rx_buff[5];

int main(void)
{
	clock_init();
	gpio_init();
	pwm_start();
	exti_init();
	usart_init();

	/* Loop forever */
	while(1) {
		if (it_pending) {
			// Clear Flag
			it_pending = 0;

			// Configure PWM - Duty Cycle
			if (TIM2->CCR2 >= 1000) {
				TIM2->CCR2 = 0;
			} else {
				TIM2->CCR2 += 100;
			}

			gpio_toggle();

			char * msg = "Button is Pressed\n\r";
			uart_transmit((uint8_t *)msg, strlen(msg));
		}

		uart_receive(rx_buff, sizeof(rx_buff));
		uart_transmit(rx_buff, sizeof(rx_buff));
	}
}

void EXTI0_IRQHandler(void) {
	// Clear Interrupt and Set Flag
	EXTI->PR |= (1U << 0);
	it_pending = 1;
}
