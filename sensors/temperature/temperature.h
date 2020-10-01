
/**
 * @file temperature.h
 * @author Valon
 * @date 24-01-2019
 *  class offers access to the temperature sensor
 *
 */

#include "LCD_DISCO_F746NG.h"
#include "mbed.h"
#include "EthernetInterface.h"


class temperature {

public:
  /*
   simple constructor
  
  **/
  temperature();
  /**
   * runs the temperature sensor.
   *
   */
  void runSensor();

  float getTemp();

private:
  float globalTemperature;
  const int B = 4275;    // B value of the thermistor
  const int R0 = 100000; // R0 = 100k
  int previousTemp = 0;
  SocketAddress a;
  EthernetInterface net;
};