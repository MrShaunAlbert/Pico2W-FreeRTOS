cmake_minimum_required(VERSION 3.13)

# Include the Pico SDK
include(${CMAKE_CURRENT_LIST_DIR}/lib/pico-sdk/external/pico_sdk_import.cmake)

# Set up the project
project(Pico2W-FreeRTOS)
pico_sdk_init()

# Add the src directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS/FreeRTOS-Kernel/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM0)

# Specify the source files 
file(GLOB FREERTOS_SRC lib/FreeRTOS/FreeRTOS-Kernel/Source/*.c lib/FreeRTOS/FreeRTOS-Kernel/Source/portable/MemMang/heap_4.c)

# Add the src directory
add_subdirectory(src)

# Add your executable
add_executable(Pico2W-FreeRTOS src/main.c ${FREERTOS_SRC})

# Include FreeRTOS
target_include_directories(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/include)
target_sources(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/MemMang/heap_4.c)
target_sources(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CM0/port.c)
target_include_directories(Pico2W-FreeRTOS PRIVATE ${CMAKE_CURRENT_LIST_DIR}/lib/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CM0)

# Link libraries
target_link_libraries(Pico2W-FreeRTOS pico_stdlib)

# Enable USB output
pico_enable_stdio_usb(Pico2W-FreeRTOS 1)
pico_enable_stdio_uart(Pico2W-FreeRTOS 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(Pico2W-FreeRTOS)
