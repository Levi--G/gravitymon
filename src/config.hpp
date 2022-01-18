/*
MIT License

Copyright (c) 2021-22 Magnus

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
#ifndef SRC_CONFIG_HPP_
#define SRC_CONFIG_HPP_

// Includes
#include <Arduino.h>
#include <ArduinoJson.h>
#include <stdlib.h>

#include <helper.hpp>

// defintions
#define CFG_JSON_BUFSIZE 3192

#define CFG_APPNAME "GravityMon "        // Name of firmware
#define CFG_FILENAME "/gravitymon.json"  // Name of config file

#define WIFI_DEFAULT_SSID "GravityMon"  // Name of created SSID
#define WIFI_DEFAULT_PWD "password"     // Password for created SSID
#define WIFI_MDNS "gravitymon"          // Prefix for MDNS name
#define WIFI_PORTAL_TIMEOUT \
  120  // Number of seconds until the config portal is closed

// These are used in API + Savefile
#define CFG_PARAM_ID "id"
#define CFG_PARAM_MDNS "mdns"  // Device name
#define CFG_PARAM_OTA "ota-url"
#define CFG_PARAM_SSID "wifi-ssid"
#define CFG_PARAM_PASS "wifi-pass"

#define CFG_PARAM_PUSH_BREWFATHER "brewfather-push"
#define CFG_PARAM_PUSH_HTTP "http-push"
#define CFG_PARAM_PUSH_HTTP2 "http-push2"
#define CFG_PARAM_PUSH_INFLUXDB2 "influxdb2-push"
#define CFG_PARAM_PUSH_INFLUXDB2_ORG "influxdb2-org"
#define CFG_PARAM_PUSH_INFLUXDB2_BUCKET "influxdb2-bucket"
#define CFG_PARAM_PUSH_INFLUXDB2_AUTH "influxdb2-auth"
#define CFG_PARAM_PUSH_MQTT "mqtt-push"
#define CFG_PARAM_PUSH_MQTT_USER "mqtt-user"
#define CFG_PARAM_PUSH_MQTT_PASS "mqtt-pass"
#define CFG_PARAM_PUSH_MQTT_TOPIC "mqtt-topic"
#define CFG_PARAM_SLEEP_INTERVAL "sleep-interval"  // Sleep interval
#define CFG_PARAM_TEMPFORMAT "temp-format"         // C or F
#define CFG_PARAM_VOLTAGEFACTOR \
  "voltage-factor"  // Factor to calculate the battery voltage
#define CFG_PARAM_GRAVITY_FORMULA \
  "gravity-formula"  // Formula for calculating gravity
#define CFG_PARAM_GRAVITY_FORMAT "gravity-format"  // Gravity format G or P
#define CFG_PARAM_GRAVITY_TEMP_ADJ \
  "gravity-temp-adjustment"  // True/False. Adjust gravity for temperature
#define CFG_PARAM_TEMP_ADJ \
  "temp-adjustment-value"  // Correction value for temp sensor
#define CFG_PARAM_GYRO_CALIBRATION "gyro-calibration-data"  // READ ONLY
#define CFG_PARAM_GYRO_TEMP \
  "gyro-temp"  // True/False. Use temp sensor in gyro (only in gravity mode)

#define CFG_PARAM_FORMULA_DATA \
  "formula-calculation-data"  // Raw data for the formula calculation

// These are used in API's
#define CFG_PARAM_APP_NAME "app-name"
#define CFG_PARAM_APP_VER "app-ver"
#define CFG_PARAM_ANGLE "angle"
#define CFG_PARAM_GRAVITY "gravity"
#define CFG_PARAM_TEMP_C "temp-c"
#define CFG_PARAM_TEMP_F "temp-f"
#define CFG_PARAM_BATTERY "battery"
#define CFG_PARAM_SLEEP_MODE "sleep-mode"
#define CFG_PARAM_RSSI "rssi"
#define CFG_PARAM_ERROR "error"

// Used for holding sensordata or sensoroffsets
struct RawGyroData {
  int16_t ax;  // Raw Acceleration
  int16_t ay;
  int16_t az;

  int16_t gx;  // Raw Position
  int16_t gy;
  int16_t gz;

  int16_t temp;  // Only for information (temperature of chip)
};

// Used for holding formulaData (used for calculating formula on device)
struct RawFormulaData {
  double a[5];
  double g[5];
};

// Main configuration class
class Config {
 private:
  bool saveNeeded;

  // Device configuration
  String id;
  String mDNS;
  String otaURL;
  char tempFormat;
  float voltageFactor;
  float tempSensorAdjC;
  int sleepInterval;
  bool gyroTemp;

  // Wifi Config
  String wifiSSID;
  String wifiPASS;

  // Push target settings
  String brewfatherPushUrl;

  String httpPushUrl;
  String httpPushUrl2;

  String influxDb2Url;
  String influxDb2Org;
  String influxDb2Bucket;
  String influxDb2Token;

  String mqttUrl;
  String mqttTopic;
  String mqttUser;
  String mqttPass;

  // Gravity and temperature calculations
  String gravityFormula;
  bool gravityTempAdj;
  char gravityFormat;

  // Gyro calibration and formula calculation data
  RawGyroData gyroCalibration;
  RawFormulaData formulaData;

  void debug();
  void formatFileSystem();

 public:
  Config();
  const char* getID() { return id.c_str(); }

  const char* getMDNS() { return mDNS.c_str(); }
  void setMDNS(String s) {
    mDNS = s;
    saveNeeded = true;
  }

  const bool isGyroTemp() { return gyroTemp; }
  void setGyroTemp(bool b) {
    gyroTemp = b;
    saveNeeded = true;
  }

  const char* getOtaURL() { return otaURL.c_str(); }
  void setOtaURL(String s) {
    otaURL = s;
    saveNeeded = true;
  }
  bool isOtaActive() { return otaURL.length() ? true : false; }

  const char* getWifiSSID() { return wifiSSID.c_str(); }
  void setWifiSSID(String s) {
    wifiSSID = s;
    saveNeeded = true;
  }
  const char* getWifiPass() { return wifiPASS.c_str(); }
  void setWifiPass(String s) {
    wifiPASS = s;
    saveNeeded = true;
  }

  // Brewfather
  const char* getBrewfatherPushUrl() { return brewfatherPushUrl.c_str(); }
  void setBrewfatherPushUrl(String s) {
    brewfatherPushUrl = s;
    saveNeeded = true;
  }
  bool isBrewfatherActive() {
    return brewfatherPushUrl.length() ? true : false;
  }

  // Standard HTTP
  const char* getHttpPushUrl() { return httpPushUrl.c_str(); }
  void setHttpPushUrl(String s) {
    httpPushUrl = s;
    saveNeeded = true;
  }
  bool isHttpActive() { return httpPushUrl.length() ? true : false; }
  const char* getHttpPushUrl2() { return httpPushUrl2.c_str(); }
  void setHttpPushUrl2(String s) {
    httpPushUrl2 = s;
    saveNeeded = true;
  }
  bool isHttpActive2() { return httpPushUrl2.length() ? true : false; }

  // InfluxDB2
  const char* getInfluxDb2PushUrl() { return influxDb2Url.c_str(); }
  void setInfluxDb2PushUrl(String s) {
    influxDb2Url = s;
    saveNeeded = true;
  }
  bool isInfluxDb2Active() { return influxDb2Url.length() ? true : false; }
  const char* getInfluxDb2PushOrg() { return influxDb2Org.c_str(); }
  void setInfluxDb2PushOrg(String s) {
    influxDb2Org = s;
    saveNeeded = true;
  }
  const char* getInfluxDb2PushBucket() { return influxDb2Bucket.c_str(); }
  void setInfluxDb2PushBucket(String s) {
    influxDb2Bucket = s;
    saveNeeded = true;
  }
  const char* getInfluxDb2PushToken() { return influxDb2Token.c_str(); }
  void setInfluxDb2PushToken(String s) {
    influxDb2Token = s;
    saveNeeded = true;
  }

  // MQTT
  bool isMqttActive() { return mqttUrl.length() ? true : false; }
  const char* getMqttUrl() { return mqttUrl.c_str(); }
  void setMqttUrl(String s) {
    mqttUrl = s;
    saveNeeded = true;
  }
  const char* getMqttTopic() { return mqttTopic.c_str(); }
  void setMqttTopic(String s) {
    mqttTopic = s;
    saveNeeded = true;
  }
  const char* getMqttUser() { return mqttUser.c_str(); }
  void setMqttUser(String s) {
    mqttUser = s;
    saveNeeded = true;
  }
  const char* getMqttPass() { return mqttPass.c_str(); }
  void setMqttPass(String s) {
    mqttPass = s;
    saveNeeded = true;
  }

  int getSleepInterval() { return sleepInterval; }
  void setSleepInterval(int v) {
    sleepInterval = v;
    saveNeeded = true;
  }
  void setSleepInterval(String s) {
    sleepInterval = s.toInt();
    saveNeeded = true;
  }

  char getTempFormat() { return tempFormat; }
  void setTempFormat(char c) {
    if (c == 'C' || c == 'F') {
      tempFormat = c;
      saveNeeded = true;
    }
  }
  bool isTempC() { return tempFormat == 'C'; }
  bool isTempF() { return tempFormat == 'F'; }

  float getVoltageFactor() { return voltageFactor; }
  void setVoltageFactor(float f) {
    voltageFactor = f;
    saveNeeded = true;
  }
  void setVoltageFactor(String s) {
    voltageFactor = s.toFloat();
    saveNeeded = true;
  }

  float getTempSensorAdjC() { return tempSensorAdjC; }
  void setTempSensorAdjC(float f) {
    tempSensorAdjC = f;
    saveNeeded = true;
  }
  void setTempSensorAdjC(String s) {
    tempSensorAdjC = s.toFloat();
    saveNeeded = true;
  }
  void setTempSensorAdjF(String s) {
    tempSensorAdjC = convertFtoC(s.toFloat());
    saveNeeded = true;
  }

  const char* getGravityFormula() { return gravityFormula.c_str(); }
  void setGravityFormula(String s) {
    gravityFormula = s;
    saveNeeded = true;
  }

  bool isGravityTempAdj() { return gravityTempAdj; }
  void setGravityTempAdj(bool b) {
    gravityTempAdj = b;
    saveNeeded = true;
  }

  char getGravityFormat() { return gravityFormat; }
  void setGravityFormat(char c) {
    if (c == 'G' || c == 'P') {
      gravityFormat = c;
      saveNeeded = true;
    }
  }
  bool isGravitySG() { return gravityFormat == 'G'; }
  bool isGravityPlato() { return gravityFormat == 'P'; }

  const RawGyroData& getGyroCalibration() { return gyroCalibration; }
  void setGyroCalibration(const RawGyroData& r) {
    gyroCalibration = r;
    saveNeeded = true;
  }

  const RawFormulaData& getFormulaData() { return formulaData; }
  void setFormulaData(const RawFormulaData& r) {
    formulaData = r;
    saveNeeded = true;
  }

  // IO functions
  void createJson(DynamicJsonDocument& doc);
  bool saveFile();
  bool loadFile();
  void checkFileSystem();
  bool isSaveNeeded() { return saveNeeded; }
  void setSaveNeeded() { saveNeeded = true; }
};

// Global instance created
extern Config myConfig;

#endif  // SRC_CONFIG_HPP_

// EOF
