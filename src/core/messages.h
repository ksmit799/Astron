#pragma once
#include <stdint.h>

// Defined types
typedef uint64_t channel_t;

// Channel constants
#define INVALID_CHANNEL 0
#define CONTROL_MESSAGE 1
#define PARENT_PREFIX ((channel_t)(1) << 32)

// DO ID Constants
#define INVALID_DO_ID 0
#define INVALID_ZONE 0

// Message Booleans
#define SUCCESS 1
#define FAILURE 0

// Reserve message-type 0
#define RESERVED_MSG_TYPE 0

// Control message-type constants
#define CONTROL_ADD_CHANNEL			9000
#define CONTROL_REMOVE_CHANNEL		9001
#define CONTROL_ADD_RANGE			9002
#define CONTROL_REMOVE_RANGE		9003
#define CONTROL_ADD_POST_REMOVE 	9010
#define CONTROL_CLEAR_POST_REMOVE	9011
#define CONTROL_SET_CON_NAME		9012
#define CONTROL_SET_CON_URL			2013

// State Server control message-type constants
#define STATESERVER_CREATE_OBJECT_WITH_REQUIRED			2000
#define STATESERVER_CREATE_OBJECT_WITH_REQUIRED_OTHER	2001
#define STATESERVER_DELETE_AI_OBJECTS					2004
// State Server object message-type constants
#define STATESERVER_OBJECT_DELETE_RAM		2008
#define STATESERVER_OBJECT_GET_FIELD		2010
#define STATESERVER_OBJECT_GET_FIELD_RESP	2011
#define STATESERVER_OBJECT_GET_FIELDS		2012
#define STATESERVER_OBJECT_GET_FIELDS_RESP	2013
#define STATESERVER_OBJECT_GET_ALL			2014
#define STATESERVER_OBJECT_GET_ALL_RESP		2015
#define STATESERVER_OBJECT_SET_FIELD		2020
#define STATESERVER_OBJECT_SET_FIELDS		2021
#define STATESERVER_OBJECT_DELETE_FIELD		2030
#define STATESERVER_OBJECT_DELETE_FIELDS	2031
// State Server visibility message-type constants
#define STATESERVER_OBJECT_SET_LOCATION							2040
#define STATESERVER_OBJECT_CHANGING_LOCATION					2041
#define STATESERVER_OBJECT_ENTER_LOCATION_WITH_REQUIRED			2042
#define STATESERVER_OBJECT_ENTER_LOCATION_WITH_REQUIRED_OTHER	2043
#define STATESERVER_OBJECT_GET_LOCATION							2044
#define STATESERVER_OBJECT_GET_LOCATION_RESP					2045
#define STATESERVER_OBJECT_SET_AI								2050
#define STATESERVER_OBJECT_CHANGING_AI							2051
#define STATESERVER_OBJECT_ENTER_AI_WITH_REQUIRED				2052
#define STATESERVER_OBJECT_ENTER_AI_WITH_REQUIRED_OTHER			2053
#define STATESERVER_OBJECT_GET_AI								2054
#define STATESERVER_OBJECT_GET_AI_RESP							2055
#define STATESERVER_OBJECT_SET_OWNER							2060
#define STATESERVER_OBJECT_CHANGING_OWNER						2061
#define STATESERVER_OBJECT_ENTER_OWNER_WITH_REQUIRED			2062
#define STATESERVER_OBJECT_ENTER_OWNER_WITH_REQUIRED_OTHER		2063
#define STATESERVER_OBJECT_GET_OWNER							2064
#define STATESERVER_OBJECT_GET_OWNER_RESP						2065
// State Server parent methods message-type constants
#define STATESERVER_OBJECT_GET_ZONE_OBJECTS		2100
#define STATESERVER_OBJECT_GET_ZONES_OBJECTS	2102
#define STATESERVER_OBJECT_GET_CHILDREN			2104
#define STATESERVER_OBJECT_GET_ZONE_COUNT		2110
#define STATESERVER_OBJECT_GET_ZONE_COUNT_RESP	2111
#define STATESERVER_OBJECT_GET_ZONES_COUNT		2112
#define STATESERVER_OBJECT_GET_ZONES_COUNT_RESP	2113
#define STATESERVER_OBJECT_GET_CHILD_COUNT		2114
#define STATESERVER_OBJECT_GET_CHILD_COUNT_RESP	2115
#define STATESERVER_OBJECT_DELETE_ZONE			2120
#define STATESERVER_OBJECT_DELETE_ZONES			2122
#define STATESERVER_OBJECT_DELETE_CHILDREN		2124
// DBSS object message-type constants
#define DBSS_OBJECT_ACTIVATE	2200
#define DBSS_OBJECT_DELETE_DISK	2208
// Stateserver macros
#define LOCATION2CHANNEL(p, z) ((channel_t)(p)<<32|(channel_t)(z))
#define PARENT2CHILDREN(p) (PARENT_PREFIX|(channel_t)(p))

// Database Server message-type constants
#define DBSERVER_OBJECT_CREATE 4000
#define DBSERVER_OBJECT_CREATE_RESP 4001
#define DBSERVER_OBJECT_DELETE 4002
#define DBSERVER_OBJECT_GET_FIELD 4010
#define DBSERVER_OBJECT_GET_FIELD_RESP 4011
#define DBSERVER_OBJECT_GET_FIELDS 4012
#define DBSERVER_OBJECT_GET_FIELDS_RESP 4013
#define DBSERVER_OBJECT_GET_ALL 4014
#define DBSERVER_OBJECT_GET_ALL_RESP 4015
#define DBSERVER_OBJECT_SET_FIELD 4020
#define DBSERVER_OBJECT_SET_FIELDS 4021
#define DBSERVER_OBJECT_SET_FIELD_IF_EQUALS 4022
#define DBSERVER_OBJECT_SET_FIELD_IF_EQUALS_RESP 4023
#define DBSERVER_OBJECT_SET_FIELDS_IF_EQUALS 4024
#define DBSERVER_OBJECT_SET_FIELDS_IF_EQUALS_RESP 4025
#define DBSERVER_OBJECT_SET_FIELD_IF_EMPTY 4026
#define DBSERVER_OBJECT_SET_FIELD_IF_EMPTY_RESP 4027
#define DBSERVER_OBJECT_DELETE_FIELD 4030
#define DBSERVER_OBJECT_DELETE_FIELDS 4031
