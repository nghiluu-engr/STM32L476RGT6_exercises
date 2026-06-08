#ifndef buzzer_h
#define buzzer_h
#include "stm32l4xx_hal.h"

typedef enum
{
	BUZZER_OFF,
	BUZZER_ON,
} BUZZER_STATE;

typedef struct
{
	TIM_HandleTypeDef *htim;
	uint32_t channel;
	
	BUZZER_STATE state;
	
	uint32_t time_start;
	
} BUZZER;



void buzzer_init(BUZZER *buzzer, TIM_HandleTypeDef *htim, uint32_t channel);
void pwm_set_duty(BUZZER *buzzer, uint8_t duty);
void buzzer_SetState(BUZZER *buzzer, BUZZER_STATE state);
void buzzer_toggle(BUZZER *buzzer);
void buzzer_BeepTick(BUZZER *buzzer, uint32_t time_ms);



#endif