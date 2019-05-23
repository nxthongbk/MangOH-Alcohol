#include "legato.h"
#include "interfaces.h"


le_result_t alcoholSensor_Read(double *alcohol)
{
    int32_t valueMv;
    double sensor_volt;
    double RS_air;

    le_result_t res = le_adc_ReadValue("EXT_ADC0", &valueMv);

    if (res != 0)
    {
        return LE_FAULT;
    }

    LE_DEBUG("ADC value: %d mV", valueMv);

    sensor_volt = valueMv/1000;
    RS_air = sensor_volt/(1.8 - sensor_volt); // omit *R16

    LE_DEBUG("Read RS_air: %f", RS_air);

    *alcohol = RS_air;
    
    return LE_OK;
}


COMPONENT_INIT
{
}