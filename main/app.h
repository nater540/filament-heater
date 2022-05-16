/*******************************************************************
 * Filament Heater
 *
 */

#pragma once

////////////////////////////////////////////////////////////////////

#include "smooth/core/Application.h"
#include "smooth/core/io/i2c/Master.h"
#include "smooth/core/task_priorities.h"
#include <iostream>
#include <memory>

////////////////////////////////////////////////////////////////////

namespace filament_heater {
  class App : public smooth::core::Application {
    public:
      App();

      void init() override;
      void tick() override;

    protected:
      std::shared_ptr<smooth::core::io::i2c::Master> i2c_master;
  };
}
