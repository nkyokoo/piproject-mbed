
/**
 * @file temperature.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the temperature class
 *
 */


#include "mbed.h"
#include "LCD_DISCO_F746NG.h"
#include "temperature.h"
#include <string>
using namespace std;

AnalogIn tempSensor(D5);
temperature::temperature()
{
}

 
void temperature::runSensor()
{
    while (1)
    {

            //const int B = 4275;               // B value of the thermistor
            //const int R0 = 100000;            // R0 = 100k
            //float R = 1.0f/tempSensor.read() - 1.0f;
            //R = R0*R;

            //float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15; // convert to temperature via datasheet
            globalTemperature = tempSensor.read();
             printf("aa %f \n", globalTemperature);


            ThisThread::sleep_for(5s);

        
    }
}

 
 float temperature::getTemp(){
     
     float temp = globalTemperature;
     return temp;

 }
 