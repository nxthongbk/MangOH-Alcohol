#include "legato.h"
#include "interfaces.h"


le_result_t alcoholSensor_Read(double *rs)
{
    int32_t sensorValue;
    double sensor_volt;
    double RS; //Sensing Resistance: resistance of the sensor reduce when gas concentration increases

    le_result_t res = le_adc_ReadValue("EXT_ADC0", &sensorValue);

    if (res != 0)
    {
        return LE_FAULT;
    }

    LE_DEBUG("ADC value: %d ", sensorValue);

    sensor_volt = sensorValue/1024*5.0;

    //Get Sensing Resistance value 
    //Rs is a dimensionless ratio that is useful for calculating the sensed alcohol concentration
    RS = sensor_volt/(5.0 - sensor_volt);

    LE_DEBUG("RS: %f", RS);

    *rs = RS;
    
    return LE_OK;
}


COMPONENT_INIT
{
}