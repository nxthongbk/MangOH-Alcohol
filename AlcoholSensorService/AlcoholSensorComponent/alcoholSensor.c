#include "legato.h"
#include "interfaces.h"


le_result_t ma_alcoholSensor_Read(double *alcohol)
{
	int32_t valueMv;
	double sensor_volt;
	double RS_air;

	le_result_t res = le_adc_ReadValue("EXT_ADC0", &valueMv);

	if (res != 0)
	{
 		return LE_FAULT;
	}

	sensor_volt = valueMv/1024*5.0;
	RS_air = sensor_volt/(5.0-sensor_volt); // omit *R16

	*alcohol = RS_air;
	
	LE_DEBUG("Read alcohol %f C", *alcohol);
	return LE_OK;
}


COMPONENT_INIT
{
}