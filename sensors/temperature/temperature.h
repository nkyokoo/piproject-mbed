 
/**
 * @file temperature.h
 * @author Valon
 * @date 24-01-2019
 *  class offers access to the temperature sensor
 *
 */

#include "mbed.h"
#include "LCD_DISCO_F746NG.h"



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
    LCD_DISCO_F746NG lcd;
    float globalTemperature;
 

};