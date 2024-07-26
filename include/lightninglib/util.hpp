/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include "pros/misc.hpp"

namespace lightning {
namespace util {
/**
 *@brief: Checks whether a smart port is reversed.
 *@param input: A number
 *@return true if the port it is reversed. Or ``false` if the port it not reversed.
 */
bool is_reversed(double input);

/**
 *@brief: Checks whether a smart port is reversed.
 *@param input: A number
 *@return true if the port it is reversed. Or ``false` if the port it not reversed.
 */
bool is_reversed(int input);

/**
 *@brief: Applies a smoothing function to joystick input values.
 *
 *This function smooths the joystick input based on a specified exponent and maximum value.
 *The smoothing function adjusts the joystick value to create a more gradual response.
 *
 *@param joystick_value Analog joystick value.
 *@param exponent The exponent value; a higher exponent provides more smoothing.
 *@param max_value The maximum value of the joystick. Default value is 127.
 *@return true if the port it is reversed. Or ``false` if the port it not reversed.
 */
float smooth_Joystick_Output(int joystick_value, int exponent, int max_value = 127);

const bool SD_CARD_ACTIVE = pros::usd::is_installed();

const int DELAY_TIME = 10;
}  // namespace util
}  // namespace lightning