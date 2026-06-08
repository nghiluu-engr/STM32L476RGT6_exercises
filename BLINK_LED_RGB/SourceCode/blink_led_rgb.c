#include "LED_RGB.h"
#include "main.h"

#include "blink_led_rgb.h"

void led_rgb_init(RGB *rgb, GPIO_TypeDef *ports[], uint16_t pins[]) // variables in the struct don't have values yet -> update them
{
	rgb->red_port = ports[0];
	rgb->green_port = ports[1];
	rgb->blue_port = ports[2];

	rgb->red_pin = pins[0];
	rgb->green_pin = pins[1];
	rgb->blue_pin = pins[2];

	rgb->color = OFF;
	rgb->state = 0;
}

void led_rgb_SetColor(RGB *rgb, COLOR color) // there are 3 leds: green, red, blue
{
	switch(color)
	{
		case OFF: // if off, 3 leds off
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_RESET);
			break;
		case RED: // if red, led_red on and others off
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_RESET);
			break;
		case GREEN: // if green, led_green on and others off
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_RESET);
			break;
		case BLUE: // if blue, led_blue on and others off
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_SET);
			break;
		case YELLOW: // if yellow, led_blue off and others on (yellow = red + green)
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_RESET);
			break;
		case PURPLE: // if purple, led_green off and others on (purple = red + blue)
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_SET);
			break;
		case WHITE: // if white, 3 leds on (white = red + green + blue)
			HAL_GPIO_WritePin(rgb->red_port, rgb->red_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->green_port, rgb->green_pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(rgb->blue_port, rgb->blue_pin, GPIO_PIN_SET);
			break;
	}
}

static void led_rgb_toggle(RGB *rgb, COLOR color) // whenever the led_rgb_toggle() is called -> switch the state from off to on or from on to off
{
	if (rgb->state == 0) // if state of the led equals to 0 -> set the led to 'off' -> update the state to 'on'
	{
		led_rgb_SetColor(rgb, color);
		rgb->state = 1;
	}
	else
	{
		led_rgb_SetColor(rgb, OFF);
		rgb->state = 0;
	}
	
}

void led_rgb_blink(RGB *rgb, COLOR color, uint16_t time_ms) // blink the led in the given time (milliseconds)
{
	if (HAL_GetTick() - rgb->time_start >= time_ms) // if HAL_GetTick() (present time) - time_start (time counted after switching) >= time_ms (time given by people) -> toggle
	{
		led_rgb_toggle(rgb, color);
		rgb->time_start = HAL_GetTick(); // after switching the state -> start to count the time
	}
	// both HAL_GetTick() and time_ms are uint32_t
}