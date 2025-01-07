cmake_minimum_required(VERSION 3.13)

# Include the Pico SDK
include(${CMAKE_CURRENT_LIST_DIR}/lib/pico-sdk/external/pico_sdk_import.cmake)

# Set up the project
project(Pico2W-FreeRTOS)
pico_sdk_init()

# Add the src directory
add_subdirectory(src)

# Add your executable
add_executable(Pico2W-FreeRTOS main.c)

# Include FreeRTOS
target_include_directories(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/include)
target_sources(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/MemMang/heap_4.c)
target_sources(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c)
target_include_directories(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CM0)

# Link libraries
target_link_libraries(Pico2W-FreeRTOS pico_stdlib)
pico_add_extra_outputs(Pico2W-FreeRTOS)

