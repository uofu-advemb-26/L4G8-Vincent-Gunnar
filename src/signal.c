#include "signaling.h"
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    /*we want the max delay block time here because if
    it doesn't block indefinitely when there's no semaphore,
    then the rest of this function will run anyway*/
    xSemaphoreTake(request, portMAX_DELAY);
    // printf("Request accepted, processing data");
    data->output = data->input + 5;
    vTaskDelay(10);
    // printf("Data processing complete");
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
    SemaphoreHandle_t response,
    struct signal_data *data)
{
    xSemaphoreGive(request);
    BaseType_t returnData = xSemaphoreTake(response, 100);
    // printf("\nTest\n");
    
    // return xSemaphoreGive(response);
    return returnData;
}
