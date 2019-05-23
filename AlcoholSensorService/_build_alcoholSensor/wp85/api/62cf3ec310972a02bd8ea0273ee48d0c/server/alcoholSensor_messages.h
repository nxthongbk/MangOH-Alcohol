/*
 * ====================== WARNING ======================
 *
 * THE CONTENTS OF THIS FILE HAVE BEEN AUTO-GENERATED.
 * DO NOT MODIFY IN ANY WAY.
 *
 * ====================== WARNING ======================
 */


#ifndef ALCOHOLSENSOR_MESSAGES_H_INCLUDE_GUARD
#define ALCOHOLSENSOR_MESSAGES_H_INCLUDE_GUARD


#include "legato.h"

#define PROTOCOL_ID_STR "92c3cd37d7f8927125b83c81b3f7f27e"

#ifdef MK_TOOLS_BUILD
    extern const char** alcoholSensor_ServiceInstanceNamePtr;
    #define SERVICE_INSTANCE_NAME (*alcoholSensor_ServiceInstanceNamePtr)
#else
    #define SERVICE_INSTANCE_NAME "alcoholSensor"
#endif


#define _MAX_MSG_SIZE 20

// Define the message type for communicating between client and server
typedef struct __attribute__((packed))
{
    uint32_t id;
    uint8_t buffer[_MAX_MSG_SIZE];
}
_Message_t;

#define _MSGID_alcoholSensor_Read 0


// Define type-safe pack/unpack functions for all enums, including included types

// Define pack/unpack functions for all structures, including included types


#endif // ALCOHOLSENSOR_MESSAGES_H_INCLUDE_GUARD