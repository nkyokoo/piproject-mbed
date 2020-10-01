
/**
 * @file loghtsensor.h
 * @author Valon
 * @date 24-01-2019
 *  class offers access to the light sensor
 *
 */


#include "mbed.h"
#include "LCD_DISCO_F746NG.h"

  
 
class LightSensor{

  
    
 public:
  
      LightSensor();
     /**
      * runs the temperature sensor.
      *    
      */                         
      void runSensor();
    /**
     * getter for globalLux
     * (the returned value is not actually in lux since I coudn't find a formal for it).
     * used for the alert system to check if the light is under a certain level
     * 
     * @return Decibel as float
     */
      float getLightValue();
    
     private: 
         float globalLux;
        
    
    };