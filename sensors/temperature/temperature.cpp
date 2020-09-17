
/**
 * @file temperature.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the temperature class
 *
 */


#include "mbed.h"
#include "LCD_DISCO_F746NG.h"
#include "Grove_temperature.h"
#include "temperature.h"
#include <string>
using namespace std;

Grove_temperature sensor(A0);
temperature::temperature()
{
    tempType = 'c';
}

 
void temperature::runSensor()
{
    tempType = 'c';
    while (1)
    {

            globalTemperature = sensor.getTemperature(); // the default output from the library is celsius
        
            ThisThread::sleep_for(5);

        
    }
}

 
 float temperature::getTemp(){
     
     float temp = globalTemperature;
     return temp;

 }
 