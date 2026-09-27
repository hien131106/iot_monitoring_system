#include "hal_sim.h"
#include "hal_timer.h"
#include <stdint.h>
#include <stdio.h>

#define APP_SUCCESS (0)

int32_t main() {
  printf("=== HAL Simulation Demo ===\n");

  hal_sim_init(42U);
  printf("HAL initialized with seed: 42\n");

  hal_sim_update();
  printf("Register[0x%02X] = 0x%04X (raw temp)\n", HAL_REG_TEMP_RAW,
         hal_sim_read_register(HAL_REG_TEMP_RAW));
  printf("Register[0x%02X] = 0x%04X (raw humi)\n", HAL_REG_TEMP_RAW,
         hal_sim_read_register(HAL_REG_HUMI_RAW));

  hal_timer_init();
  for (uint32_t i = 0U; i < 3U; i++) {
    printf("Timer tick: %u\n", hal_timer_get_tick());
    hal_timer_tick();
  }

  return APP_SUCCESS;
}