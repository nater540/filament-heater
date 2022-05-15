cmake_minimum_required(VERSION 3.20)

set(OUTPUT_JSON "1")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Include the Smooth framework
set(EXTRA_COMPONENT_DIRS
  externals/smooth/smooth_component
)

project(filament-heater)
