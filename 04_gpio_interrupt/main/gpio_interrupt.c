#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN								(2)
#define BUTTON_PIN						(0)

#define HIGH									(1)
#define LOW										(0)

#define ESP_INTR_FLAG_DEFAULT	(0)


void IRAM_ATTR button_isr_handler(void *arg)
{	
	static int count = 0;
	
	count++;
	
	if(count%2)
		gpio_set_level(LED_PIN, HIGH);
	else
		gpio_set_level(LED_PIN, LOW);	
}

void app_main()
{
	/* Select the desired GPIO */
	gpio_pad_select_gpio(LED_PIN);
	gpio_pad_select_gpio(BUTTON_PIN);
	
	/* Set the GPIO as Output */
	gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
	/* Set the GPIO as Input */
	gpio_set_direction(BUTTON_PIN, GPIO_MODE_INPUT);
	
	/* Set the type of triggering */
	gpio_set_intr_type(BUTTON_PIN, GPIO_INTR_NEGEDGE);
	
	/* install gpio isr service */
	gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
	
	/* Attach ISR handler */
	gpio_isr_handler_add(BUTTON_PIN, button_isr_handler, (void *) BUTTON_PIN);

		
}
