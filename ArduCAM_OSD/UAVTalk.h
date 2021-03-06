/**
 ******************************************************************************
 *
 * @file       UAVTalk.h
 * @author     Joerg-D. Rothfuchs
 * @brief      Implements a subset of the telemetry communication between
 *             OpenPilot CC, CC3D, Revolution and Ardupilot Mega MinimOSD
 *             with code from OpenPilot and MinimOSD.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/> or write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


#ifndef UAVTALK_H_
#define UAVTALK_H_


#include "OSD_Config.h"


// TODO enhancement:
// Generate the following automatically out of the XML files.
//
// These object constants are version dependent!
//
// Short hints getting them manually:
// http://wiki.openpilot.org/display/Doc/Windows%3A+Building+and+Packaging
// git clone git://git.openpilot.org/OpenPilot.git OpenPilot
// QT Creator > Datei oder Projekt oeffnen... uavobjgenerator
// generate release and copy exe to <top>\ground\uavobjgenerator
// uavobjgenerator -flight ..\..\shared\uavobjectdefinition ..\..\
// //
#if defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1 || defined VERSION_RELEASE_14_06_1 || defined VERSION_RELEASE_14_10_1 || defined VERSION_RELEASE_15_01_1 || defined VERSION_RELEASE_15_02_1 || defined VERSION_RELEASE_15_05 || defined VERSION_RELEASE_LP15_09 || defined VERSION_RELEASE_LP16_04

#define FLIGHTTELEMETRYSTATS_OBJID          0x2F7E2902

#define GCSTELEMETRYSTATS_OBJID             0xABC72744

#define ATTITUDEACTUAL_OBJID                0x33DAD5E6
#define ATTITUDESTATE_OBJID                 0xD7E0D964      // new name since VERSION_RELEASE_14_01_1

#define FLIGHTSTATUS_OBJID                  0x9B6A127E

#define MANUALCONTROLCOMMAND_OBJID          0x1E82C2D2

#define GPSPOSITION_OBJID                   0xE2A323B6
#define GPSPOSITIONSENSOR_OBJID             0x1A5748CE      // new name since VERSION_RELEASE_14_01_1


#define GPSTIME_OBJID                       0xD4478084

#define GPSVELOCITY_OBJID                   0x8245DC80
#define GPSVELOCITYSENSOR_OBJID             0x0BC57454      // new name since VERSION_RELEASE_14_01_1

#define SYSTEMALARMS_OBJID                  0x7BD9C77A


#define FLIGHTTELEMETRYSTATS_OBJ_LEN        21
#define FLIGHTTELEMETRYSTATS_OBJ_STATUS     20
#define FLIGHTTELEMETRYSTATS_OBJ_LEN_001    37              // different since VERSION_RELEASE_14_01_1
#define FLIGHTTELEMETRYSTATS_OBJ_STATUS_001 36 // different since VERSION_RELEASE_14_01_1

#define GCSTELEMETRYSTATS_OBJ_LEN           21
#define GCSTELEMETRYSTATS_OBJ_STATUS        20
#define GCSTELEMETRYSTATS_OBJ_LEN_001       37              // different since VERSION_RELEASE_14_01_1
#define GCSTELEMETRYSTATS_OBJ_STATUS_001    36              // different since VERSION_RELEASE_14_01_1

#define ATTITUDEACTUAL_OBJ_ROLL             16
#define ATTITUDEACTUAL_OBJ_PITCH            20
#define ATTITUDEACTUAL_OBJ_YAW              24

#define FLIGHTSTATUS_OBJ_ARMED              0
#define FLIGHTSTATUS_OBJ_FLIGHTMODE         1

#if defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1

#define MANUALCONTROLCOMMAND_OBJ_THROTTLE   0
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_0  20
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_1  22
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_2  24
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_3  26
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_4  28
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_5  30
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_6  32
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_7  34
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_8  36

#else // since version VERSION_RELEASE_14_06_1

#define MANUALCONTROLCOMMAND_OBJ_THROTTLE   0
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_0  24
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_1  26
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_2  28
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_3  30
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_4  32
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_5  34
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_6  36
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_7  38
#define MANUALCONTROLCOMMAND_OBJ_CHANNEL_8  40

#endif // if defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1

#define GPSPOSITION_OBJ_LAT                 0
#define GPSPOSITION_OBJ_LON                 4
#define GPSPOSITION_OBJ_ALTITUDE            8
#define GPSPOSITION_OBJ_GEOIDSEPARATION     12
#define GPSPOSITION_OBJ_HEADING             16
#define GPSPOSITION_OBJ_GROUNDSPEED         20
#define GPSPOSITION_OBJ_PDOP                24
#define GPSPOSITION_OBJ_HDOP                28
#define GPSPOSITION_OBJ_VDOP                32
#define GPSPOSITION_OBJ_STATUS              36
#define GPSPOSITION_OBJ_SATELLITES          37

#define GPSTIME_OBJ_YEAR                    0
#define GPSTIME_OBJ_MONTH                   2
#define GPSTIME_OBJ_DAY                     3
#define GPSTIME_OBJ_HOUR                    4
#define GPSTIME_OBJ_MINUTE                  5
#define GPSTIME_OBJ_SECOND                  6

#define GPSVELOCITY_OBJ_NORTH               0
#define GPSVELOCITY_OBJ_EAST                4
#define GPSVELOCITY_OBJ_DOWN                8


#if defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1

#define SYSTEMALARMS_ALARM_CPUOVERLOAD      2
#define SYSTEMALARMS_ALARM_EVENTSYSTEM      3
#define SYSTEMALARMS_ALARM_MANUALCONTROL    5

#else // since version VERSION_RELEASE_14_06_1

#define SYSTEMALARMS_ALARM_CPUOVERLOAD      4
#define SYSTEMALARMS_ALARM_EVENTSYSTEM      5
#define SYSTEMALARMS_ALARM_MANUALCONTROL    8
#define SYSTEMALARMS_ALARM_MAGNETOMETER     12

#endif // defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1

#endif // defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2 || defined VERSION_RELEASE_14_01_1 || defined VERSION_RELEASE_14_06_1 || defined VERSION_RELEASE_14_10_1 || defined VERSION_RELEASE_15_01_1 || defined VERSION_RELEASE_15_02_1 || defined VERSION_RELEASE_15_05 || defined VERSION_RELEASE_LP15_09 || defined VERSION_RELEASE_LP16_04


#if defined VERSION_ADDITIONAL_UAVOBJID

#define FLIGHTSTATUS_OBJID_001         0x0ED79A04      // different ID for unreleased next version
#define FLIGHTSTATUS_OBJID_002         0x1B7AEB74      // different ID for unreleased next version and VERSION_RELEASE_13_06_1
#define FLIGHTSTATUS_OBJID_003         0x0B37AA16      // different ID for VERSION_RELEASE_13_06_2
#define FLIGHTSTATUS_OBJID_004         0xC5FF2D54      // different ID for VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1
#define FLIGHTSTATUS_OBJID_005         0x8A80EA52      // different ID for VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1
#define FLIGHTSTATUS_OBJID_006         0x14ECA392      // different ID for git commit "OP-1760 autotakeoff"
#define FLIGHTSTATUS_OBJID_007         0xE33E5D4E      // VERSION_RELEASE_15_05 and VERSION_RELEASE_LP15_09
#define FLIGHTSTATUS_OBJID_008         0x6E3BDB60      // different ID for VERSION_RELEASE_LP16_04 (ASWA status added)

#define SYSTEMALARMS_OBJID_001         0x09C7CBFE      // different ID for unreleased next version
#define SYSTEMALARMS_OBJID_002         0x1D70DB44      // different ID for unreleased next version and VERSION_RELEASE_13_06_1
#define SYSTEMALARMS_OBJID_003         0x34EEACF8      // different ID for VERSION_RELEASE_14_01_1
#define SYSTEMALARMS_OBJID_004         0xBA9B00A4      // different ID for VERSION_RELEASE_14_06_1 and VERSION_RELEASE_15_01_1
#define SYSTEMALARMS_OBJID_005         0xFB867092      // different ID for VERSION_RELEASE_15_02_1
#define SYSTEMALARMS_OBJID_006         0x6B7639EC      // different ID for VERSION_RELEASE_LP15_09

#define FLIGHTTELEMETRYSTATS_OBJID_001 0x6737BB5A // different ID for VERSION_RELEASE_14_01_1 and VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1

#define GCSTELEMETRYSTATS_OBJID_001    0xCAD1DC0A      // different ID for VERSION_RELEASE_14_01_1 and VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1

#define MANUALCONTROLCOMMAND_OBJID_001 0xB8C7F78A // different ID for VERSION_RELEASE_14_01_1
#define MANUALCONTROLCOMMAND_OBJID_002 0x161A2C98 // different ID for VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1
#define MANUALCONTROLCOMMAND_OBJID_003 0xC4107480 // different for VERSION_RELEASE_LP15_09

#define GPSPOSITIONSENSOR_OBJID_001    0x7D26A6E6      // different ID for VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1
#define GPSPOSITIONSENSOR_OBJID_002    0x98A7858C      // different ID for VERSION_RELEASE_15_05 and VERSION_RELEASE_LP15_09
#define GPSPOSITIONSENSOR_OBJID_003    0x9DF1F67A      // different ID for VERSION_RELEASE_LP16_04 (new GPS support)
#endif // VERSION_ADDITIONAL_UAVOBJID


#if defined FLIGHT_BATT_ON_REVO

#define FLIGHTBATTERYSTATE_OBJID                     0xD2083596
#define FLIGHTBATTERYSTATE_OBJID_001                 0x26962352      // different ID for VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1

#define FLIGHTBATTERYSTATE_OBJ_VOLTAGE               0
#define FLIGHTBATTERYSTATE_OBJ_CURRENT               4
#define FLIGHTBATTERYSTATE_OBJ_BOARD_SUPPLY_VOLTAGE  8
#define FLIGHTBATTERYSTATE_OBJ_PEAK_CURRENT          12
#define FLIGHTBATTERYSTATE_OBJ_AVG_CURRENT           16
#define FLIGHTBATTERYSTATE_OBJ_CONSUMED_ENERGY       20
#define FLIGHTBATTERYSTATE_OBJ_ESTIMATED_FLIGHT_TIME 24

#endif // FLIGHT_BATT_ON_REVO


#if defined REVO_ADD_ONS

#define BAROALTITUDE_OBJID                   0x99622E6A
#define BAROSENSOR_OBJID                     0x48120EA6      // new name since VERSION_RELEASE_14_01_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1 and VERSION_RELEASE_15_02_1

#define BAROALTITUDE_OBJ_ALTITUDE            0
#define BAROALTITUDE_OBJ_TEMPERATURE         4
#define BAROALTITUDE_OBJ_PRESSURE            8

#define POSITIONSTATE_OBJID                  0x4AFDB658      // VERSION_RELEASE_LP15_09

#define POSITIONSTATE_OBJ_NORTH              0
#define POSITIONSTATE_OBJ_EAST               4
#define POSITIONSTATE_OBJ_DOWN               8               

#define VELOCITYSTATE_OBJID                  0xC243686C      // VERSION_RELEASE_LP15_09

#define VELOCITYSTATE_OBJ_NORTH              0
#define VELOCITYSTATE_OBJ_EAST               4
#define VELOCITYSTATE_OBJ_DOWN               8   

#define OPLINKSTATUS_OBJID                   0x669C55E2
#define OPLINKSTATUS_OBJID_001               0xBE2584BA      // different ID for VERSION_RELEASE_14_01_1 and VERSION_RELEASE_14_06_1 and VERSION_RELEASE_14_10_1 and VERSION_RELEASE_15_01_1
#define OPLINKSTATUS_OBJID_002               0xB1A94E20      // different ID for VERSION_RELEASE_15_02_1

#define OPLINKSTATUS_OBJ_RSSI                96
#define OPLINKSTATUS_OBJ_LINKQUALITY         97

#endif // REVO_ADD_ONS

#define RECEIVERSTATUS_OBJID                 0xFD24EDF2
#define RECEIVERSTATUS_OBJ_QUALITY           0

#define TXPIDSTATUS_OBJID                    0x18EDDF50
#define TXPIDSTATUS_OBJ_CURPID1              0
#define TXPIDSTATUS_OBJ_CURPID2              4
#define TXPIDSTATUS_OBJ_CURPID3              8

#define UAVTALK_MODE_PASSIVE                 0x01            // do not send any UAVTalk packets

#define FLIGHTTELEMETRYSTATS_CONNECT_TIMEOUT 10000
#define GCSTELEMETRYSTATS_SEND_PERIOD        1000

#if defined VERSION_RELEASE_12_10_1 || defined VERSION_RELEASE_12_10_2 || defined VERSION_RELEASE_13_06_1 || defined VERSION_RELEASE_13_06_2
#define HEADER_LEN                           8
#else
#define HEADER_LEN                           10
#endif

#define RESPOND_OBJ_LEN                      HEADER_LEN
#define REQUEST_OBJ_LEN                      HEADER_LEN

#define UAVTALK_SYNC_VAL                     0x3C

#define UAVTALK_TYPE_MASK                    0xF8
#define UAVTALK_TYPE_VER                     0x20

#define UAVTALK_TYPE_OBJ                     (UAVTALK_TYPE_VER | 0x00)
#define UAVTALK_TYPE_OBJ_REQ                 (UAVTALK_TYPE_VER | 0x01)
#define UAVTALK_TYPE_OBJ_ACK                 (UAVTALK_TYPE_VER | 0x02)
#define UAVTALK_TYPE_ACK                     (UAVTALK_TYPE_VER | 0x03)
#define UAVTALK_TYPE_NACK                    (UAVTALK_TYPE_VER | 0x04)


typedef enum {
    UAVTALK_PARSE_STATE_WAIT_SYNC = 0,
    UAVTALK_PARSE_STATE_GOT_SYNC,
    UAVTALK_PARSE_STATE_GOT_MSG_TYPE,
    UAVTALK_PARSE_STATE_GOT_LENGTH,
    UAVTALK_PARSE_STATE_GOT_OBJID,
    UAVTALK_PARSE_STATE_GOT_INSTID,
    UAVTALK_PARSE_STATE_GOT_DATA,
    UAVTALK_PARSE_STATE_GOT_CRC
} uavtalk_parse_state_t;


typedef enum {
    TELEMETRYSTATS_STATE_DISCONNECTED = 0,
    TELEMETRYSTATS_STATE_HANDSHAKEREQ,
    TELEMETRYSTATS_STATE_HANDSHAKEACK,
    TELEMETRYSTATS_STATE_CONNECTED
} telemetrystats_state_t;


typedef struct __uavtalk_message {
    uint8_t  Sync;
    uint8_t  MsgType;
    uint16_t Length;
    uint32_t ObjID;
    uint16_t InstID;
    uint8_t  Data[255];
    uint8_t  Crc;
} uavtalk_message_t;


int uavtalk_read(void);
int uavtalk_state(void);


#endif /* UAVTALK_H_ */
