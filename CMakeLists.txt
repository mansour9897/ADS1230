add_library(ADS1230 INTERFACE)

# target_link_libraries(ADS1230
#   INTERFACE
#   pico_stdlib
# )

target_include_directories(ADS1230 
INTERFACE
${CMAKE_CURRENT_LIST_DIR})

target_sources(ADS1230
INTERFACE
${CMAKE_CURRENT_LIST_DIR}/ads1230.h
${CMAKE_CURRENT_LIST_DIR}/ads1230.cpp
${CMAKE_CURRENT_LIST_DIR}/loadcell.h
${CMAKE_CURRENT_LIST_DIR}/loadcell.cpp
)