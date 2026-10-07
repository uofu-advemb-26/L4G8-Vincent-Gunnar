#include "signaling.h"
#include <stdio.h>

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    xSemaphoreTake(request, 500);
    // printf("Request accepted, processing data");
    data->output = data->input + 5;
    // printf("Data processing complete");
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
    SemaphoreHandle_t response,
    struct signal_data *data)
{
    xSemaphoreGive(request);
    BaseType_t returnData = xSemaphoreTake(response, 500);
    // printf("\nTest\n");
    
    // return xSemaphoreGive(response);
    return returnData;
}
