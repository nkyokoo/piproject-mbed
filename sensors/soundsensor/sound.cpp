/**
 * @file sound.cpp
 * @author Valon
 * @date 24-01-2019
 *  logic for the sound class
 *
 */

#include "sound.h"
#include "LCD_DISCO_F746NG.h"
#include "mbed.h"

AnalogIn sound(A1);

SoundSensor::SoundSensor() {}

void SoundSensor::runSensor() { 
    float rawValue = sound.read(); 
     resetSoundLevel();
    
    for(int i=0;i<1000;i++){
        values[i] = rawValue * 3.3;
    }
 
    for(int j=0;j<1000;j++){
         sum += values[j];   
    }
    average = sum/1000;
    globalSoundValue = decibels = average * 29;   
}

float SoundSensor::getSoundValue() {
  float soundValue = globalSoundValue;
  printf("%f \n", soundValue);
  return soundValue;
}
void SoundSensor::resetSoundLevel(){
    sum = 0;
    average = 0;
    decibels = 0;
}