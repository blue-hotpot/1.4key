#include "bsp_key.h"


void key_config(void)
{
	rcu_periph_clock_enable(BSP_KEY_RCU);
	gpio_mode_set(BSP_KEY_PORT,GPIO_MODE_INPUT,GPIO_PUPD_PULLDOWN,BSP_KEY_PIN);
	
}
FlagStatus key_scanf(void)
{
	if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN)==SET)
	{
		delay_1ms(20);
		if(gpio_input_bit_get(BSP_KEY_PORT,BSP_KEY_PIN)==SET)
		{
			return SET;
		}
	}
	return RESET;
	
}




