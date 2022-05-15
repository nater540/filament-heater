/*******************************************************************
 * Filament Heater
 *
 */

#include <iostream>

#include "app.h"

////////////////////////////////////////////////////////////////////

extern "C" {
  void app_main(void);
}

void app_main(void) {
  filament_heater::App app{};
  app.start();
}
