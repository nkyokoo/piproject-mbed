
/**
 * @file temperature.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the temperature class
 *
 */

#include "temperature.h"
#include "LCD_DISCO_F746NG.h"
#include "mbed.h"
#include <string>

using namespace std;

AnalogIn tempSensor(A0);
temperature::temperature() {
}
void temperature::runSensor() {
  float R = 1.0f / tempSensor.read() - 1.0f;
  R = R0 * R;
  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) -
                      273.15; // convert to temperature via datasheet
  globalTemperature = temperature;
}
float temperature::getTemp() { return globalTemperature; }
