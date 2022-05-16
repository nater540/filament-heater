/*******************************************************************
 * Filament Heater
 *
 */

#pragma once

////////////////////////////////////////////////////////////////////

#include <string>
#include <nlohmann/json.hpp>

#include "smooth/core/filesystem/File.h"
#include "smooth/core/filesystem/Path.h"

#include "singleton.h"

////////////////////////////////////////////////////////////////////

namespace filament_heater {
  class Config : public Singleton<Config> {
    public:
      Config();
      Config(Config&&) = delete;
      Config(Config const&) = delete;
      Config& operator=(Config&&) = delete;
      Config& operator=(Config const&) = delete;
      virtual ~Config() = default;

    protected:
      void parse_json();

    private:
      nlohmann::json raw_json {};
  };
}
