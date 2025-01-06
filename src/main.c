#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"

// Task function
void vTaskFunction(void *pvParameters) {
    while (true) {
        printf("Hello from FreeRTOS task!\n");
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay for 1000ms
    }
}

int main() {
    // Initialize the Pico SDK
    stdio_init_all();

    // Create the task
    xTaskCreate(vTaskFunction, "Task 1", 256, NULL, 1, NULL);

    // Start the scheduler
    vTaskStartScheduler();

    // The program should never reach here
    for (;;) {
    }

    return 0;
}

