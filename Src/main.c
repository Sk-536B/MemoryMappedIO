#include "main.h"

int main(void)
{
	clock_init();
	gpio_init();
	pwm_start();
	exti_init();

	/* Loop forever */
	while(1) {
		// Loop does nothing
	}
}

void EXTI0_IRQHandler(void) {
	// Clear Interrupt
	EXTI->PR |= (1U << 0);

	// Configure PWM
	if (TIM2->CCR2 >= 1000) {
		TIM2->CCR2 = 0;
	} else {
		TIM2->CCR2 += 100;
	}

	gpio_toggle();
}
