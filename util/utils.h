 
 
/**
 * @file utils.h
 * @author Valon
 * @date 24-01-2019
 *  class offers a list of useful functions for which can be reused
 *
 */

 
 
  #include <string>
 // using namespace std;  
 class utils{ 
    public:
      /**
       * resets the sound values
       * 
       * this is important! 
       *  without this function the sound sensor value will just continue going up!
       *  
       * 
       */
        void resetSoundLevel();
      /**
       * a normal member that takes float value.
       * converts raw sound levels(voltage) to decibel.
       *
       *  @param a float value/variable
       * 
       * 
       * 
       * 
       * @return decibel as float
       */
        float calculateSoundLevel(float rawValue);
       
        
    private:
        float sum;
        float average;
        float decibels;
        float values[1001];
};