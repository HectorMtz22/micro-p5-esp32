#include <stdio.h>
#include "display.h"
#include "driver/gpio.h" 
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
#include <rom/ets_sys.h>

void disp_init(void) {
  gpio_set_direction(DISP_7_SEG_A, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_B, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_C, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_D, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_E, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_F, GPIO_MODE_OUTPUT);
  gpio_set_direction(DISP_7_SEG_G, GPIO_MODE_OUTPUT);
}

void disp_show(int number) {
  uint8_t segments[] = {
		0b00111111,
		0b00000110,
		0b01011011,
		0b01001111,
		0b01100110,
		0b01101101,
		0b01111101,
		0b00000111,
		0b01111111,
		0b01101111,
		0b01110111,
		0b01111100,
		0b00111001,
		0b01011110,
		0b01111001,
		0b01110001
	};

  if (number < 0 || number > 15) {
    // Invalid number, turn off all segments
    gpio_set_level(DISP_7_SEG_A, 0);
    gpio_set_level(DISP_7_SEG_B, 0);
    gpio_set_level(DISP_7_SEG_C, 0);
    gpio_set_level(DISP_7_SEG_D, 0);
    gpio_set_level(DISP_7_SEG_E, 0);
    gpio_set_level(DISP_7_SEG_F, 0);
    gpio_set_level(DISP_7_SEG_G, 0);
    return;
  }

  int segment = segments[number];
  gpio_set_level(DISP_7_SEG_A, segment & 0b00000001);
  gpio_set_level(DISP_7_SEG_B, segment & 0b00000010);
  gpio_set_level(DISP_7_SEG_C, segment & 0b00000100);
  gpio_set_level(DISP_7_SEG_D, segment & 0b00001000);
  gpio_set_level(DISP_7_SEG_E, segment & 0b00010000);
  gpio_set_level(DISP_7_SEG_F, segment & 0b00100000);
  gpio_set_level(DISP_7_SEG_G, segment & 0b01000000);
  return;
}

void disp_test(void) {
  for (int i = 0; i < 3; i++) {
    disp_show(8);
    ets_delay_us(TEST_DELAY * 1000);
    // vTaskDelay(TEST_DELAY / portTICK_PERIOD_MS);
    disp_show(-1);
    ets_delay_us(TEST_DELAY * 1000);
    // vTaskDelay(TEST_DELAY / portTICK_PERIOD_MS);
  }
}
