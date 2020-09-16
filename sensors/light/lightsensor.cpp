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

AnalogIn light(A1);

LightSensor::LightSensor()
{
}

void LightSensor::runSensor()
{
    while (1)
    {
        globalLux = light.read();
        if (showing == true)
        {
            sprintf(text, "Light: %f ", globalLux);

            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)text, CENTER_MODE);
        }
                ThisThread::sleep_for(5);
    }
}
float LightSensor::getLightValue()
{

    float lightvalue = globalLux;

    return lightvalue;
}

void LightSensor::setShowing(bool passedBool)
{

    showing = passedBool;
}
