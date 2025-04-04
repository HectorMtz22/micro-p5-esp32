#include "buttons.h"
#include "driver/gpio.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
#include <rom/ets_sys.h>

uint8_t prev_state_btn = 0;
uint8_t actual_state_btn = 0;


void btns_init(void) {
  gpio_set_direction(BTNS_INCREMENT, GPIO_MODE_INPUT);
  gpio_set_direction(BTNS_DECREMENT, GPIO_MODE_INPUT);
  return;
}

int btns_increment_debounce(void) {
  // vTaskDelay(10 / portTICK_PERIOD_MS);
	ets_delay_us(10 * 1000);			//Stalls execution for #uS
  prev_state_btn = actual_state_btn;
  actual_state_btn = gpio_get_level(BTNS_INCREMENT);

  return !prev_state_btn && actual_state_btn;
}

int btns_decrement(void) {
	ets_delay_us(10 * 1000);			//Stalls execution for #uS
  return gpio_get_level(BTNS_DECREMENT);
}
