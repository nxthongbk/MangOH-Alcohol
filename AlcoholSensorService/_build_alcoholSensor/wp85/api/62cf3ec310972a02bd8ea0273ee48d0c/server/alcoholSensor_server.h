

/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD
#define ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD


#include "legato.h"


//--------------------------------------------------------------------------------------------------
/**
 * Get the server service reference
 */
//--------------------------------------------------------------------------------------------------
le_msg_ServiceRef_t alcoholSensor_GetServiceRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Get the client session reference for the current message
 */
//--------------------------------------------------------------------------------------------------
le_msg_SessionRef_t alcoholSensor_GetClientSessionRef
(
    void
);

//--------------------------------------------------------------------------------------------------
/**
 * Initialize the server and advertise the service.
 */
//--------------------------------------------------------------------------------------------------
void alcoholSensor_AdvertiseService
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
le_result_t alcoholSensor_Read
(
    double* readingPtr
        ///< [OUT]
);


#endif // ALCOHOLSENSOR_INTERFACE_H_INCLUDE_GUARD