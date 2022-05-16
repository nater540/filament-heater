/*******************************************************************
 * Filament Heater
 *
 */

#include "app.h"

////////////////////////////////////////////////////////////////////

using namespace std::chrono;
using namespace smooth::core;
using namespace filament_heater;

////////////////////////////////////////////////////////////////////

App::App() : Application(APPLICATION_BASE_PRIO, seconds(1)) {
  i2c_master = std::make_shared<io::i2c::Master>(
    I2C_NUM_0,        // I2C Port 0
    GPIO_NUM_22,      // SCL pin
    false,            // SCL internal pullup NOT enabled
    GPIO_NUM_21,      // SDA pin
    false,            // SDA internal pullup NOT enabled
    100 * 1000        // clock frequency - 100kHz
  );
}

void App::init() {
  Application::init();
  Log::info("App::Init", "Starting...");
}

void App::tick() {

}
