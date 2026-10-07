#include "signaling.h"
#include <stdio.h>

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    xSemaphoreTake(request, portMAX_DELAY);
    printf("Request accepted, processing data");
    printf("Data processing complete");
    xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
    SemaphoreHandle_t response,
    struct signal_data *data)
{
    xSemaphoreGive(request);
    BaseType_t returnData = xSemaphoreTake(response, portMAX_DELAY);
    printf("\nTest\n");
    data->output = data->input + 5;
    // return xSemaphoreGive(response);
    return returnData;
}
