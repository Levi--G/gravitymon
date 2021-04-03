/*
MIT License

Copyright (c) 2021 Magnus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */
#ifndef _CONFIG_H
#define _CONFIG_H

// Includes
#include "helper.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <stdlib.h>

// defintions
#define CFG_JSON_BUFSIZE    1000

#define CFG_APPNAME         "GravityMon "       // Name of firmware
#define CFG_FILENAME        "/gravitymon.json"  // Name of config file

#define WIFI_DEFAULT_SSID   "GravityMon"        // Name of created SSID
#define WIFI_DEFAULT_PWD    "password"          // Password for created SSID
#define WIFI_MDNS           "gravitymon"        // Prefix for MDNS name
#define WIFI_PORTAL_TIMEOUT 120                 // Number of seconds until the config portal is closed

// These are used in API + Savefile
#define CFG_PARAM_ID                 "id"
#define CFG_PARAM_MDNS               "mdns"                           // Device name
#define CFG_PARAM_OTA                "ota-url"                        // Base URL for OTA
#define CFG_PARAM_PUSH_BREWFATHER    "brewfather-push"                // URL (brewfather format)
#define CFG_PARAM_PUSH_HTTP          "http-push"                      // URL (iSpindle format)
#define CFG_PARAM_PUSH_HTTP2         "http-push2"                     // URL (iSpindle format)
#define CFG_PARAM_SLEEP_INTERVAL     "sleep-interval"                 // Sleep interval 
// TODO: @deprecated setting
#define CFG_PARAM_PUSH_INTERVAL      "push-interval"                  // Time between push 
#define CFG_PARAM_TEMPFORMAT         "temp-format"                    // C or F
#define CFG_PARAM_VOLTAGEFACTOR      "voltage-factor"                 // Factor to calculate the battery voltage
#define CFG_PARAM_GRAVITY_FORMULA    "gravity-formula"                // Formula for calculating gravity
#define CFG_PARAM_GRAVITY_TEMP_ADJ   "gravity-temp-adjustment"        // True/False. Adjust gravity for temperature
#define CFG_PARAM_TEMP_ADJ           "temp-adjustment-value"          // Correction value for temp sensor
#define CFG_PARAM_GYRO_CALIBRATION   "gyro-calibration-data"          // READ ONLY

// These are used in API's
#define CFG_PARAM_APP_NAME           "app-name"
#define CFG_PARAM_APP_VER            "app-ver"
#define CFG_PARAM_ANGLE              "angle"
#define CFG_PARAM_GRAVITY            "gravity"
#define CFG_PARAM_TEMP_C             "temp-c"
#define CFG_PARAM_TEMP_F             "temp-f"
#define CFG_PARAM_BATTERY            "battery"
#define CFG_PARAM_SLEEP_MODE         "sleep-mode"
#define CFG_PARAM_RSSI               "rssi"

// Used for holding sensordata or sensoroffsets
struct RawGyroData { 
    int16_t ax;     // Raw Acceleration
    int16_t ay;
    int16_t az;

    int16_t gx;     // Raw Position
    int16_t gy;
    int16_t gz;

    int16_t temp;   // Only for information (temperature of chip)
};

// Main configuration class
class Config {
    private:
        bool saveNeeded;

        // Device configuration
        String id;
        String mDNS;
        String otaURL;
        char   tempFormat;                      // C, F
        float  voltageFactor;
        float  tempSensorAdj;                   // This value will be added to the read sensor value
        int    sleepInterval;                
 
        // Push target settings
        String brewfatherPushTarget;
        String httpPushTarget;               
        String httpPushTarget2;               

        // Gravity and temperature calculations
        String gravityFormula;
        bool   gravityTempAdj;                  // true, false      
        char   gravityFormat;                   // G, P

        // Gyro calibration data
        RawGyroData gyroCalibration;          // Holds the gyro calibration constants (6 * int16_t)

        void debug();
        void formatFileSystem();

    public:
        Config();
        const char*  getID() { return id.c_str(); };

        const char*  getMDNS() { return mDNS.c_str(); }
        void         setMDNS( String s ) { mDNS = s; saveNeeded = true; }

        const char*  getOtaURL() { return otaURL.c_str(); }
        void         setOtaURL( String s ) { otaURL = s; saveNeeded = true; }
        bool         isOtaActive() { return otaURL.length()>0?true:false; }

        const char*  getBrewfatherPushTarget() { return brewfatherPushTarget.c_str(); }
        void         setBrewfatherPushTarget( String s ) { brewfatherPushTarget = s; saveNeeded = true; }
        bool         isBrewfatherActive() { return brewfatherPushTarget.length()>0?true:false; }

        const char*  getHttpPushTarget() { return httpPushTarget.c_str(); }
        void         setHttpPushTarget( String s ) { httpPushTarget = s; saveNeeded = true; }
        bool         isHttpActive() { return httpPushTarget.length()>0?true:false; }

        const char*  getHttpPushTarget2() { return httpPushTarget2.c_str(); }
        void         setHttpPushTarget2( String s ) { httpPushTarget2 = s; saveNeeded = true; }
        bool         isHttpActive2() { return httpPushTarget2.length()>0?true:false; }

        int          getSleepInterval() { return sleepInterval; }
        void         setSleepInterval( int v ) { sleepInterval = v; saveNeeded = true; }
        void         setSleepInterval( String s ) { sleepInterval = s.toInt(); saveNeeded = true; }

        char         getTempFormat() { return tempFormat; }
        void         setTempFormat( char c ) { tempFormat = c; saveNeeded = true; }
        bool         isTempC() { return tempFormat=='C'?false:true; };
        bool         isTempF() { return tempFormat=='F'?false:true; };

        float        getVoltageFactor() { return voltageFactor; }
        void         setVoltageFactor( float f ) { voltageFactor = f; saveNeeded = true; }
        void         setVoltageFactor( String s ) { voltageFactor = s.toFloat(); saveNeeded = true; }

        float        getTempSensorAdj() { return tempSensorAdj; }
        void         setTempSensorAdj( float f ) { tempSensorAdj = f; saveNeeded = true; }
        void         setTempSensorAdj( String s ) { tempSensorAdj = s.toFloat(); saveNeeded = true; }

        const char*  getGravityFormula() { return gravityFormula.c_str(); }
        void         setGravityFormula( String s ) { gravityFormula = s; saveNeeded = true; }

        bool         isGravityTempAdj() { return gravityTempAdj; }
        void         setGravityTempAdj( bool b ) { gravityTempAdj = b; saveNeeded = true; }

        char         getGravityFormat() { return gravityFormat; }
        void         setGravityFormat( char c ) { gravityFormat = c; saveNeeded = true; }
        bool         isGravitySG() { return gravityFormat=='G'?false:true; };
        bool         isGravityPlato() { return gravityFormat=='P'?false:true; };

        const RawGyroData& getGyroCalibration() { return gyroCalibration; }
        void               setGyroCalibration( const RawGyroData &r ) { gyroCalibration = r; saveNeeded = true; }

        // IO functions
        void createJson(DynamicJsonDocument& doc);
        bool saveFile();
        bool loadFile();
        void checkFileSystem();
        bool isSaveNeeded() { return saveNeeded; };
        void setSaveNeeded() { saveNeeded = true; };
};

// Global instance created
extern Config myConfig;

#endif // _CONFIG_H

// EOF