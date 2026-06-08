#ifndef button_h
#define button_h
#include "stm32l4xx_hal.h"

typedef struct
{
	GPIO_TypeDef *port;
	uint16_t pin;
	
	uint8_t read_btn_current;
	uint8_t btn_filter;
	uint32_t time_debouncing;
	uint8_t is_debouncing; //flag
	uint8_t btn_state; // assigned in button_handle()
} BUTTON;

void button_init(BUTTON *button, GPIO_TypeDef *gpio_port, uint16_t gpio_pin);
void button_handle(BUTTON *button);



#endif