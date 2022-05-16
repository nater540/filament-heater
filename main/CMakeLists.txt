set(CMAKE_CXX_STANDARD 17)

set(SOURCES
  main.cpp
  config.cpp
  config.h
  singleton.h
  app.cpp
  app.h
)

idf_component_register(SRCS ${SOURCES}
  INCLUDE_DIRS
    "."
  REQUIRES
    smooth_component
)

spiffs_create_partition_image(storage ../spiff FLASH_IN_PROJECT)
