#include "rcc.h"
#include "gpio.h"

int main(void)
{
	clock_init();
	gpio_init();

	uint8_t prev_btn_state = 1;

	/* Loop forever */
	while(1) {
		// Gets the GPIO pin A0 state by using KEY_BTN as mask
		uint8_t curr_btn_state = (GPIOA->IDR & KEY_BTN) ? 1 : 0;

		if (prev_btn_state == 1 && curr_btn_state == 0) {
			gpio_toggle();

			// Debouncing
			for (int i = 0; i < 200000; i++);
		}

		prev_btn_state = curr_btn_state;
	}
}
