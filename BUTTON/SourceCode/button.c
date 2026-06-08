#include "button.h"

void button_init(BUTTON *button, GPIO_TypeDef *gpio_port, uint16_t gpio_pin)
{
	button->port = gpio_port;
	button->pin = gpio_pin;
	
	uint8_t read_btn_current = HAL_GPIO_ReadPin(button->port, button->pin);
	uint8_t btn_filter = 1;
	uint8_t is_debouncing = 0; // flag
}

__weak void press_callback(void)
{
}
__weak void release_callback(void)
{
}
__weak void press_short_callback(void)
{
}
__weak void press_long_callback(void)
{
}


void button_handle(BUTTON *button)
{
	if (button->read_btn_current != button->btn_filter)
	{
		button->btn_filter = button->read_btn_current;
		button->time_debouncing = HAL_GetTick();
		button->is_debouncing = 1;
	}
	
	if (button->is_debouncing == 1 && HAL_GetTick() - button->time_debouncing > 15)
	{
		button->btn_state = button->btn_filter;
		button->is_debouncing = 2;
	}
	
	if (button->is_debouncing == 2)
	{
		if (button->btn_state == 0)
		{
			press_callback();
		}
		else
		{
			release_callback();
			button->is_debouncing = 0;
		}
		
	}
}