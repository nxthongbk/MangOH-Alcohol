

/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef MA_ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD
#define MA_ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD


#include "legato.h"


//--------------------------------------------------------------------------------------------------
/**
 * Get the server service reference
 */
//--------------------------------------------------------------------------------------------------
le_msg_ServiceRef_t ma_alcoholSensor_GetServiceRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the client session reference for the current message
 */
//--------------------------------------------------------------------------------------------------
le_msg_SessionRef_t ma_alcoholSensor_GetClientSessionRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Initialize the server and advertise the service.
 */
//--------------------------------------------------------------------------------------------------
void ma_alcoholSensor_AdvertiseService
(
    void
);



//--------------------------------------------------------------------------------------------------
/**
 * Read the alcohol measurement in kiloPascals (ppm).
 *
 * @return LE_OK if successful.
 */
//--------------------------------------------------------------------------------------------------
le_result_t ma_alcoholSensor_Read
(
    double* readingPtr
        ///< [OUT] Where the gas reading (kOhm) will be put if LE_OK is returned.
);


#endif // MA_ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD