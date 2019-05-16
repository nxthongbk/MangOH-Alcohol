/*
 * AUTO-GENERATED _componentMain.c for the AlcoholSensorComponent component.

 * Don't bother hand-editing this file.
 */

#include "legato.h"
#include "../liblegato/eventLoop.h"
#include "../liblegato/log.h"

#ifdef __cplusplus
extern "C" {
#endif

extern const char* _AlcoholSensorComponent_le_adc_ServiceInstanceName;
const char** le_adc_ServiceInstanceNamePtr = &_AlcoholSensorComponent_le_adc_ServiceInstanceName;
void le_adc_ConnectService(void);
extern const char* _AlcoholSensorComponent_ma_alcoholSensor_ServiceInstanceName;
const char** ma_alcoholSensor_ServiceInstanceNamePtr = &_AlcoholSensorComponent_ma_alcoholSensor_ServiceInstanceName;
void ma_alcoholSensor_AdvertiseService(void);
// Component log session variables.
le_log_SessionRef_t AlcoholSensorComponent_LogSession;
le_log_Level_t* AlcoholSensorComponent_LogLevelFilterPtr;

// Component initialization function (COMPONENT_INIT).
void _AlcoholSensorComponent_COMPONENT_INIT(void);

// Library initialization function.
// Will be called by the dynamic linker loader when the library is loaded.
__attribute__((constructor)) void _AlcoholSensorComponent_Init(void)
{
    LE_DEBUG("Initializing AlcoholSensorComponent component library.");

    // Advertise server-side IPC interfaces.
    ma_alcoholSensor_AdvertiseService();

    // Connect client-side IPC interfaces.
    le_adc_ConnectService();

    // Register the component with the Log Daemon.
    AlcoholSensorComponent_LogSession = log_RegComponent("AlcoholSensorComponent", &AlcoholSensorComponent_LogLevelFilterPtr);

    //Queue the COMPONENT_INIT function to be called by the event loop
    event_QueueComponentInit(_AlcoholSensorComponent_COMPONENT_INIT);
}


#ifdef __cplusplus
}
#endif
