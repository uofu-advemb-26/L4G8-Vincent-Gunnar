#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
    xSemaphoreTake(request, portMAX_DELAY);
    printf("Request accepted, processing data");
    data->output = data->input + 5;
    printf("Data processing complete");
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
    SemaphoreHandle_t response,
    struct signal_data *data)
{
    xSemaphoreGive(request);
    xSemaphoreTake(response, portMAX_DELAY);

    signal_handle_calculation(request, response, data);
    return xSemaphoreGive(response);
}
