#ifndef BLINK_LED_RGB_H
#define BLINK_LED_RGB_H
#include "stm32l4xx_hal.h"

typedef enum
{
	OFF,
	RED,
	GREEN, 
	BLUE,
	YELLOW, //RED+GREEN
	PURPLE, //RED+BLUE
	WHITE, //RED+GREEN+BLUE
} COLOR;

typedef struct
{
	GPIO_TypeDef *red_port;
	GPIO_TypeDef *green_port;
	GPIO_TypeDef *blue_port;
	
	uint16_t red_pin;
	uint16_t green_pin;
	uint16_t blue_pin;
	
	COLOR color;
	
	uint8_t state;
	
	uint32_t time_start;
} RGB;


void led_rgb_init(RGB *rgb, GPIO_TypeDef *ports[], uint16_t pins[]); // variables in the struct doesn't have any values -> assigning them
// to use or update variables in the struct -> use 'RGB *rgb'; if use 'RGB rgb', we don't use or update, we just copy the variables in the struct
// GPIO_TypeDef *ports: create a pointer called 'ports' to point to GPIO port registers; bcz each port (GPIOA, GPIOS,..) is an address in hardware register -> use pointer
// uint16_t pins: each pin (GPIO_PIN_0, GPIO_PIN_1,..) has a number, it's an unsigned 16-bit integer, showing the position of that pin in a port -> use uint16_t
void led_rgb_SetColor(RGB *rgb, COLOR color); 
// set a color for a led at a pin of a port; add 'color' to let people type the color they want to set
static void led_rgb_toggle(RGB *rgb, COLOR color);
// switch the state (between off and on) of a led whenever it's called; add 'color' to let people type the color they want to toggle
void led_rgb_blink(RGB *rgb, COLOR color, uint16_t time_ms);
// blink the led without using hal_delay(); add 'color' to let people type the color they want to blink; ; add 'time_ms' to let people type the time in milliseconds they want to blink (if they type 100 -> 100ms off, 100ms color)

#endif