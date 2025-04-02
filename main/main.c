#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "display.h"
#include "buttons.h"

#define TIME_DELAY 300

void app_main() {
  disp_init();
  btns_init();

  disp_test();

  int state = 0;
  while (true) {
    disp_show(state);
    if (btns_increment_debounce()) {
      if (++state >= 0x0F) state = 0x0F;
    }
    if (btns_decrement()) {
      if (--state <= 0) state = 0;
      disp_show(state);
      vTaskDelay(TIME_DELAY / portTICK_PERIOD_MS);
    }
  }
}
