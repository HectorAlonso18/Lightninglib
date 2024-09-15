/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef TANK_CHASSIS_H
#define TANK_CHASSIS_H

namespace lightning {

typedef enum {
  NO_ODOM = 0,

  ADI_ONE_ODOM,
  ADI_TWO_ODOM,
  ADI_TWO_ROTATED_ODOM,

  ROTATION_ONE_ODOM,
  ROTATION_TWO_ODOM,
  ROTATION_TWO_ROTATED_ODOM

} tank_odom_e_t;

typedef enum {
  LEFT_SWING = 0,
  RIGHT_SWING
} swing_direction_e_t;

typedef enum {
  E_TANK_OP_ARCADE_LEFT = 0,  // Left stick configuration
  E_TANK_OP_ARCADE_RIGHT,     // Right stick configuration
  E_TANK_OP_ARCADE_DOUBLE,     // Double stick configuration
  E_TANK_OP_ARCADE_DOUBLE_ALTERNATIVE
} tank_op_arcade_e_t;

}  // namespace lightning

#endif