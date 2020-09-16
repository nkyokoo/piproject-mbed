/**
 * @file sound.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the sound class
 *
 */

#include "mbed.h"
#include "LCD_DISCO_F746NG.h"
#include "sound.h"
#include "utils.h"

utils util = utils();

AnalogIn sound(A2);

SoundSensor::SoundSensor()
{
}

void SoundSensor::runSensor()
{ 

    while (1)
    {
        globalDB = util.calculateSoundLevel(sound.read());
        if (showing == true)
        {
            sprintf(text, "Sound: %f ", globalDB);

            lcd.DisplayStringAt(0, LINE(6), (uint8_t *)text, CENTER_MODE);
        }
        ThisThread::sleep_for(5);
    }
}
float SoundSensor::getSoundValue()
{

    float soundvalue = globalDB;

    return soundvalue;
}

void SoundSensor::setShowing(bool passedBool)
{

    showing = passedBool;
}
