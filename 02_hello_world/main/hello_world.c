#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN     (2)
#define BUTTON_PIN  (0)

#define HIGH        (1)
#define LOW         (0)
#define DELAY       (1000)

void hello_world_task(void *pvParameter)
{ 
 /* NOTE : A Task must never end or return, you can suspend it or 
           delete it if you want but never end or return */
 while(1)
 {
     printf("Hello, world !\n");
     vTaskDelay( DELAY / portTICK_RATE_MS );
 }
}

void app_main()
{
 /* Create a Task for printing Hello, world */
 xTaskCreate(&hello_world_task, "hello world task", 1024, NULL, 5, NULL );  
}
