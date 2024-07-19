#pragma once 
#include "pros/misc.hpp"

namespace lightning{
namespace util {
    /**
    Boolean function. Very helpul for reverse ports 
    */
    bool is_reversed(double input); 
    bool is_reversed(int input); 
    
    float smooth_Joystick_Output(int joystick_value, int exponent, int max_value=127); 
    
    const bool SD_CARD_ACTIVE = pros::usd::is_installed(); 

    const int DELAY_TIME=10; 
}
}