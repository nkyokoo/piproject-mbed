/**
 * @file sound.h
 * @author Valon
 * @date 24-01-2019
 *  class offers access to the sound sensor
 *
 */

#include <mbed.h>
#include <LCD_DISCO_F746NG.h>


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

    /**
     * setter for showing
     * sets the showing value.
     * sets if the sensor is supposed to show it's reading to the display
     * takes bool
     * @param bool
     */
    void setShowing(bool passedBool);


private:
    LCD_DISCO_F746NG lcd;
    bool showing;
    float globalDB;
    float average;
    float values[1001];
    float sum;
    char text[30];

};