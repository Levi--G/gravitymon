/*
MIT License

Copyright (c) 2021-2024 Magnus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the = "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED = "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */
#ifndef SRC_RESOURCES_HPP_
#define SRC_RESOURCES_HPP_

// Common strings used in json formats.
constexpr auto PARAM_ID = "id";
constexpr auto PARAM_MDNS = "mdns";
constexpr auto PARAM_CONFIG_VER = "config_version";
constexpr auto PARAM_OTA = "ota_url";
constexpr auto PARAM_SSID = "wifi_ssid";
constexpr auto PARAM_PASS = "wifi_pass";
constexpr auto PARAM_SSID2 = "wifi_ssid2";
constexpr auto PARAM_PASS2 = "wifi_pass2";
constexpr auto PARAM_HARDWARE = "hardware";
constexpr auto PARAM_RUNTIME_AVERAGE = "runtime_average";
constexpr auto PARAM_TOKEN = "token";
constexpr auto PARAM_TOKEN2 = "token2";
constexpr auto PARAM_PUSH_HTTP = "http_push";
constexpr auto PARAM_PUSH_HTTP_H1 = "http_push_h1";
constexpr auto PARAM_PUSH_HTTP_H2 = "http_push_h2";
constexpr auto PARAM_PUSH_HTTP2 = "http_push2";
constexpr auto PARAM_PUSH_HTTP2_H1 = "http_push2_h1";
constexpr auto PARAM_PUSH_HTTP2_H2 = "http_push2_h2";
constexpr auto PARAM_PUSH_HTTP3 = "http_push3";
constexpr auto PARAM_PUSH_INFLUXDB2 = "influxdb2_push";
constexpr auto PARAM_PUSH_INFLUXDB2_ORG = "influxdb2_org";
constexpr auto PARAM_PUSH_INFLUXDB2_BUCKET = "influxdb2_bucket";
constexpr auto PARAM_PUSH_INFLUXDB2_AUTH = "influxdb2_auth";
constexpr auto PARAM_PUSH_MQTT = "mqtt_push";
constexpr auto PARAM_PUSH_MQTT_USER = "mqtt_user";
constexpr auto PARAM_PUSH_MQTT_PASS = "mqtt_pass";
constexpr auto PARAM_PUSH_MQTT_PORT = "mqtt_port";
constexpr auto PARAM_SLEEP_INTERVAL = "sleep_interval";
constexpr auto PARAM_TEMPFORMAT = "temp_format";
constexpr auto PARAM_VOLTAGE_FACTOR = "voltage_factor";
constexpr auto PARAM_VOLTAGE_CONFIG = "voltage_config";
constexpr auto PARAM_GRAVITY_FORMULA = "gravity_formula";
constexpr auto PARAM_GRAVITY_FORMAT = "gravity_format";
constexpr auto PARAM_GRAVITY_TEMP_ADJ = "gravity_temp_adjustment";
constexpr auto PARAM_TEMP_ADJ = "temp_adjustment_value";
constexpr auto PARAM_GYRO_CALIBRATION = "gyro_calibration_data";
constexpr auto PARAM_GYRO_TEMP = "gyro_temp";
constexpr auto PARAM_STORAGE_SLEEP = "storage_sleep";
constexpr auto PARAM_FORMULA_DATA = "formula_calculation_data";
constexpr auto PARAM_FILES = "files";
constexpr auto PARAM_FILE_NAME = "file_name";
constexpr auto PARAM_FILE_SIZE = "file_size";
constexpr auto PARAM_APP_VER = "app_ver";
constexpr auto PARAM_APP_BUILD = "app_build";
constexpr auto PARAM_ANGLE = "angle";
constexpr auto PARAM_GRAVITY = "gravity";
constexpr auto PARAM_TEMP = "temp";
// constexpr auto PARAM_TEMP_C = "temp_c";
// constexpr auto PARAM_TEMP_F = "temp_f";
constexpr auto PARAM_BATTERY = "battery";
constexpr auto PARAM_SLEEP_MODE = "sleep_mode";
constexpr auto PARAM_RSSI = "rssi";
constexpr auto PARAM_ERROR = "error";
constexpr auto PARAM_PLATFORM = "platform";
constexpr auto PARAM_BLE = "ble";
constexpr auto PARAM_BLE_FORMAT = "ble_format";
constexpr auto PARAM_ISPINDEL_CONFIG = "ispindel_config";
constexpr auto PARAM_GYRO_READ_COUNT = "gyro_read_count";
// constexpr auto PARAM_GYRO_READ_DELAY = "gyro_read_delay";
constexpr auto PARAM_GYRO_MOVING_THREASHOLD = "gyro_moving_threashold";
constexpr auto PARAM_FORMULA_DEVIATION = "formula_max_deviation";
constexpr auto PARAM_FORMULA_CALIBRATION_TEMP = "formula_calibration_temp";
constexpr auto PARAM_WIFI_PORTAL_TIMEOUT = "wifi_portal_timeout";
constexpr auto PARAM_WIFI_CONNECT_TIMEOUT = "wifi_connect_timeout";
constexpr auto PARAM_TEMPSENSOR_RESOLUTION = "tempsensor_resolution";
constexpr auto PARAM_PUSH_TIMEOUT = "push_timeout";
constexpr auto PARAM_PUSH_INTERVAL_HTTP1 = "int_http1";
constexpr auto PARAM_PUSH_INTERVAL_HTTP2 = "int_http2";
constexpr auto PARAM_PUSH_INTERVAL_HTTP3 = "int_http3";
constexpr auto PARAM_PUSH_INTERVAL_INFLUX = "int_influx";
constexpr auto PARAM_PUSH_INTERVAL_MQTT = "int_mqtt";
constexpr auto PARAM_IGNORE_LOW_ANGLES = "ignore_low_angles";
constexpr auto PARAM_BATTERY_SAVING = "battery_saving";
constexpr auto PARAM_FORMAT_HTTP1 = "http_1";
constexpr auto PARAM_FORMAT_HTTP2 = "http_2";
constexpr auto PARAM_FORMAT_HTTP3 = "http_3";
constexpr auto PARAM_FORMAT_INFLUXDB = "influxdb";
constexpr auto PARAM_FORMAT_MQTT = "mqtt";
constexpr auto PARAM_PUSH_FORMAT = "format";
constexpr auto PARAM_PUSH_SUCCESS = "success";
constexpr auto PARAM_PUSH_CODE = "code";
constexpr auto PARAM_PUSH_ENABLED = "enabled";
constexpr auto PARAM_SELF = "self_check";
constexpr auto PARAM_SELF_GYRO_CONNECTED = "gyro_connected";
constexpr auto PARAM_SELF_GYRO_CALIBRATION = "gyro_calibration";
constexpr auto PARAM_SELF_TEMP_CONNECTED = "temp_connected";
constexpr auto PARAM_SELF_GRAVITY_FORMULA = "gravity_formula";
constexpr auto PARAM_SELF_BATTERY_LEVEL = "battery_level";
constexpr auto PARAM_SELF_PUSH_TARGET = "push_targets";
constexpr auto PARAM_STATUS = "status";

#endif  // SRC_RESOURCES_HPP_
