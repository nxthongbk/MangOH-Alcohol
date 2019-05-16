#include "legato.h"
#include "interfaces.h"


#define ALCOHOL_SENSOR_NAME "alcohol/rs_air/value"

#define ALCOHOL_SENSOR_DATA "/app/alcoholSensorToDatahub/alcohol/rs_air/value"

#define ALCOHOL_SENSOR_OBS "alcoholSensorOffLimits"

#define ALCOHOL_SENSOR_LOWER_LIMIT 0.0000
#define ALCOHOL_SENSOR_UPPER_LIMIT 100.0000

//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the alcohol sensor value.
 */
//--------------------------------------------------------------------------------------------------
static void AlcoholSensorUpdateHandler
(
	double timestamp,
	double value,
	void* contextPtr
)
{
	LE_DEBUG("alcohol sensor PM: = %lf (timestamped %lf)", value, timestamp);
}


//--------------------------------------------------------------------------------------------------
/**
 * Call-back function called when an update is received from the Data Hub for the alcohol sensor value.
 */
//--------------------------------------------------------------------------------------------------
static void AlcoholSensorObservationUpdateHandler
(
	double timestamp,	///< time stamp
	double value,		///< alcohol sensor value,
	void* contextPtr	///< not used 
)
{
	LE_INFO("Observed filtered alcohol sensor = %lf (timestamped %lf)", value, timestamp);	
}


COMPONENT_INIT
{
	le_result_t result;

	// This will be received from the Data Hub.
	result = io_CreateOutput(ALCOHOL_SENSOR_NAME, IO_DATA_TYPE_NUMERIC, "degrees");
	LE_ASSERT(result == LE_OK);

	// Register for notification of updates to the counter value.
	io_AddNumericPushHandler(ALCOHOL_SENSOR_NAME, AlcoholSensorUpdateHandler, NULL);

	// Connect to the sensor
	result = admin_SetSource("/app/alcoholSensorDisplay/" ALCOHOL_SENSOR_NAME, ALCOHOL_SENSOR_DATA);
	LE_ASSERT(result == LE_OK);

	// Create observation (filter) for alcohol sensor. To set up the "dead band" filter,
	// lower limit assigned to high limit and vice versa (see admin.io doc for details).
	admin_CreateObs(ALCOHOL_SENSOR_OBS);
	admin_SetLowLimit(ALCOHOL_SENSOR_OBS, ALCOHOL_SENSOR_LOWER_LIMIT);
	admin_SetHighLimit(ALCOHOL_SENSOR_OBS, ALCOHOL_SENSOR_UPPER_LIMIT);
	result = admin_SetSource("/obs/" ALCOHOL_SENSOR_OBS, ALCOHOL_SENSOR_DATA);
	LE_ASSERT(result == LE_OK);
	admin_AddNumericPushHandler("/obs/" ALCOHOL_SENSOR_OBS, AlcoholSensorObservationUpdateHandler, NULL);

	LE_ASSERT(result == LE_OK);
}
