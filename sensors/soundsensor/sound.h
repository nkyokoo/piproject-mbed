/**
 * @file sound.h
 * @author Valon
 * @date 24-01-2019
 *  class offers access to the sound sensor
 *
 */

#include <LCD_DISCO_F746NG.h>
#include <mbed.h>

class SoundSensor {

public:
  /*
   simple constructor
   
  **/
  SoundSensor();
  /**
   * runs the temperature sensor.
   *
   */
  void runSensor();
  /**
   * getter for globalDB
   * gets the current value that the sensor has read.
   * used for the alert system to check if the sound is too loud
   *
   * @return Decibel as float
   */
  float getSoundValue();

private:
  float globalSoundValue;
  float sum;
  float average;
  float decibels;
  float values[1001];
  /**
   * resets the sound values
   *
   * this is important!
   *  without this function the sound sensor value will just continue going up!
   *
   *
   */
  void resetSoundLevel();
};