/*******************************************************************
 * Filament Heater
 *
 */

#include "config.h"

#include <fstream>

#include "esp_err.h"
#include "spiffs/include/esp_spiffs.h"

////////////////////////////////////////////////////////////////////

using namespace smooth::core;
using namespace filament_heater;

////////////////////////////////////////////////////////////////////

Config::Config() {
  esp_vfs_spiffs_conf_t conf = {
    .base_path = "/spiffy",
    .partition_label = "storage",
    .max_files = 5,
    .format_if_mount_failed = true
  };

  Log::debug("Config::Config", "Attempting to mount storage...");
  auto result = esp_vfs_spiffs_register(&conf);

  // Uh-oh Spaghettios!
  if (result != ESP_OK) {
    switch (result) {
      case ESP_FAIL:
        Log::warning("Config::Config", "Failed to mount or format filesystem");
        break;

      case ESP_ERR_NOT_FOUND:
        Log::error("Config::Config", "Failed to find SPIFFS partition");
        break;

      default:
        Log::error("Config::Config", "Failed to initialize SPIFFS (%s)", esp_err_to_name(result));
        break;
    }
    throw std::runtime_error("SPIFFS failed to initialize");
  }

  parse_json();
}

void Config::parse_json() {
  Log::debug("Config::Config", "Parsing JSON config...");
  std::fstream file{ "/spiffy/config.json", std::ios::binary | std::ios::in };

  if (!file.is_open()) {
    // TODO: Likely should dump the default config here, but for now just throw up our hands and panic...
    throw std::runtime_error("Failed to open JSON config file");
  }

  // Figure out the file size so we can load it in one go
  auto size = file.seekg(0, std::ios::end).tellg();
  file.seekg(0, std::ios::beg);

  // Allocate a buffer to hold the whole config file
  std::vector<uint8_t> data;
  data.reserve(static_cast<std::vector<uint8_t>::size_type>(size));
  data.resize(static_cast<std::vector<uint8_t>::size_type>(size));

  // Attempt to read the entire file; explode if we don't read the entire file
  auto result = file.read(reinterpret_cast<char*>(data.data()),
    static_cast<std::streamsize>(size)).gcount() == static_cast<std::streamsize>(size);

  if (!result) {
    throw std::runtime_error("Failed to load JSON config file data");
  }

  data.push_back(0);
  raw_json = nlohmann::json::parse(data.data(), nullptr, false);
}
