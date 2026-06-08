#include "buzzer.h"

void buzzer_init(BUZZER *buzzer, TIM_HandleTypeDef *htim, uint32_t channel)
{
	buzzer->htim = htim;
	buzzer->channel = channel;

	HAL_TIMEx_PWMN_Start(buzzer->htim, buzzer->channel);

}

void pwm_set_duty(BUZZER *buzzer, uint8_t duty)
{
	if (duty > 90)
	{
		duty = 90;
	}
	uint32_t arr = buzzer->htim->Instance->ARR;
	uint32_t ccr = ((arr + 1)*duty) / 100;
	
	__HAL_TIM_SET_COMPARE(buzzer->htim, buzzer->channel, ccr);
}


void buzzer_SetState(BUZZER *buzzer, BUZZER_STATE state)
{
	buzzer->state = state;
	switch(buzzer->state)
	{
		case BUZZER_ON:
			pwm_set_duty(buzzer, 50);
			break;
		case BUZZER_OFF:
			pwm_set_duty(buzzer, 0);
			break;
		default:
			break;
	}
}

void buzzer_toggle(BUZZER *buzzer)
{
	if(buzzer->state == BUZZER_OFF)
	{
		buzzer_SetState(buzzer, BUZZER_ON);
		buzzer->state = BUZZER_ON;
	}
	else
	{
		buzzer_SetState(buzzer, BUZZER_OFF);
		buzzer->state = BUZZER_OFF;
	}
}

void buzzer_BeepTick(BUZZER *buzzer, uint32_t time_ms)
{
	uint32_t time_now = HAL_GetTick();
	if(time_now - buzzer->time_start >= time_ms)
	{
		buzzer_toggle(buzzer);
		buzzer->time_start = time_now;

	}
}

