/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/util.hpp"
#include "Math.h"
#include <cmath>

namespace lightning{
namespace util {
    /**
    Boolean function. Very helpul for reverse ports 
    */
    bool is_reversed(double input){
        if(input < 0) return true; 
        return false; 
    }

    bool is_reversed(int input){
        if(input < 0) return true; 
        return false; 

    } 

    float smooth_Joystick_Output(int joystick_value, int exponent, int max_value){
        int sign_joystick_value = sign(joystick_value); 
    
        //If the exponent is pair we need to multiply the joystick sign to the smooth function. 
        if(exponent%2==0){
            return  ((pow(joystick_value,exponent)) /(pow(max_value, exponent-1))) * sign_joystick_value; 
        }
        
        //If the exponent is odd we just need to use the smooth function. 
        return ((pow(joystick_value,exponent)) /(pow(max_value, exponent-1))); 
    } 
   
}
}