/**
 * @file lightsensor.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the lightsensor class
 *
 */
 
#include "mbed.h"
#include "LCD_DISCO_F746NG.h"
#include "lightsensor.h"

AnalogIn light(A2);

LightSensor::LightSensor()
{
}

void LightSensor::runSensor()
{
 
    globalLux = light.read();
    
}
float LightSensor::getLightValue()
{

    float lightvalue = globalLux;

    return lightvalue;
}