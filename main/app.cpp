/*******************************************************************
 * Filament Heater
 *
 */

#include "app.h"

////////////////////////////////////////////////////////////////////

using namespace smooth::core;
using namespace filament_heater;

////////////////////////////////////////////////////////////////////

App::App() : Application(smooth::core::APPLICATION_BASE_PRIO, std::chrono::seconds(1)) {}

void App::init() {
  Log::info("App::Init", "Starting...");
}

void App::tick() {

}
