set(CMAKE_CXX_STANDARD 17)

set(SOURCES
  main.cpp
)

idf_component_register(SRCS ${SOURCES}
  INCLUDE_DIRS
    "."
  REQUIRES
    smooth_component
)
