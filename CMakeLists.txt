cmake_minimum_required(VERSION 3.13)

# Set up the project name
project(Pico2W-FreeRTOS)

# Include the Pico SDK
include(${CMAKE_CURRENT_LIST_DIR}/lib/pico-sdk/external/pico_sdk_import.cmake)
pico_sdk_init()

# Define the path to the FreeRTOS-Kernel
set(FREERTOS_KERNEL_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeRTOS-Kernel)

# Add FreeRTOS source files
set(FREERTOS_SOURCES
	${FREERTOS_KERNEL_PATH}/list.c
	${FREERTOS_KERNEL_PATH}/queue.c
	${FREERTOS_KERNEL_PATH}/tasks.c
	${FREERTOS_KERNEL_PATH}/timers.c
	${FREERTOS_KERNEL_PATH}/event_groups.c
	${FREERTOS_KERNEL_PATH}/portable/MemMang/heap_4.c
	${FREERTOS_KERNEL_PATH}/portable/GCC/ARM_CM0/port.c
)

# Add the src directory to the include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${FREERTOS_KERNEL_PATH}/include)
include_directories(${FREERTOS_KERNEL_PATH}/portable/GCC/ARM_CM0)

# Add the src directory
add_subdirectory(src)

# Add your executable
add_executable(Pico2W-FreeRTOS src/main.c ${FREERTOS_SRC})
target_sources(${PROJECT_NAME} PRIVATE ${FREERTOS_SOURCES})

# Link libraries
target_link_libraries(Pico2W-FreeRTOS pico_stdlib)

# Enable USB output
pico_enable_stdio_usb(Pico2W-FreeRTOS 1)
pico_enable_stdio_uart(Pico2W-FreeRTOS 0)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(Pico2W-FreeRTOS)
