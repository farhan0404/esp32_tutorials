#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN     (2)
#define BUTTON_PIN  (0)

#define HIGH        (1)
#define LOW         (0)
#define DELAY       (1000)

void blinky_task(void *pvParameter)
{ 
 while(1)
 {
  if( gpio_get_level( BUTTON_PIN ) == 1 )
  {
   gpio_set_level(LED_GPIO, HIGH);
   vTaskDelay( DELAY / portTICK_RATE_MS );
  }
  else
  {
   gpio_set_level(LED_GPIO, LOW);
   vTaskDelay( DELAY / portTICK_RATE_MS );
  }
 }
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

 /* Create a Task for blinking the Led */
 xTaskCreate(&blinky_task, "blinky_task", 1024, NULL, 5, NULL );
  
}
