 
/**
 * @file utils.cpp
 * @author Valon
 * @date 24-01-2019
 * file offers logic for the utils class 
 *
 */
#include "utils.h"
#include <mbed.h>
#include <string>

void utils::resetSoundLevel(){
    sum = 0;
    average = 0;
    decibels = 0;
}


float utils::calculateSoundLevel(float rawValue){
    resetSoundLevel();
    
    for(int i=0;i<1000;i++){
        values[i] = rawValue * 3.3;
      ThisThread::sleep_for(5);
    }
 
    for(int j=0;j<1000;j++){
         sum += values[j];   
    }
    average = sum/1000;
    return decibels = average * 29;   
    
}


