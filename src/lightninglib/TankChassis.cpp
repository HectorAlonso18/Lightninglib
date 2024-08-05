/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/TankChassis.hpp"

#include <cmath>
#include <iostream>
#include <vector>

#include "lightninglib/Math.h"
#include "lightninglib/PurePursuit.hpp"
#include "lightninglib/TankChassis.h"
#include "lightninglib/util.hpp"
#include "okapi/api/units/QAngle.hpp"
#include "okapi/api/units/QLength.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "pros/rtos.h"
#include "pros/rtos.hpp"


namespace lightning {

TankChassis::TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t>& right_side_ports,
                         const char gyro_port, const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio)
    : left_side(left_side_ports), right_side(right_side_ports), gyro(gyro_port), Encoder_Forward_tracker(-1, -1, false), Encoder_SideWays_tracker(-1, -1, false),

      Rotation_Forward_tracker(-1),
      Rotation_SideWays_tracker(-1),
      abs_global_x(0),
      abs_global_y(0),
      orientation(0),
      max_accel(0),
      max_rpm(0),
      max_vel(0),
      odom_configuration(odom_config),
      drive_pid(1, 1, 1, lightning::util::DELAY_TIME, 1),
      turn_pid(drive_pid),
      swing_pid(drive_pid)

{
  this->wheels_diameter = wheel_diameter;
  this->cartridge = gearset;
  this->gear_ratio = gear_ratio;

  this->position.reserve(3);
  this->position[0] = 0;
  this->position[1] = 0;

  this->pose.reserve(3);
  this->pose[0] = 0;
  this->pose[1] = 0;
  this->pose[2] = 0;

  this->current_index = 0;

  this->odometry_rotation_deg=0; 

  left_side.set_encoder_units(integrated_encoders_unit);
  right_side.set_encoder_units(integrated_encoders_unit);

  if (this->odom_configuration == NO_ODOM) {
    this->ForwardTracker_center_distance = 0;
    this->ForwardTracker_diameter = 0;
    this->SideWaysTracker_frequency = 0;

    this->SideWays_center_distance = 0;
    this->SideWays_diameter = 0;
    this->SideWaysTracker_frequency = 0;
    odom.set_physical_distances(this->ForwardTracker_center_distance, this->SideWays_center_distance);
  }
}

TankChassis::TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t>& right_side_ports,
                         const char gyro_port, const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio, const std::vector<int>& Encoder_Forward_Tracker_ports, const float Forward_Tracker_diameter, const float Forward_Tracker_distance_to_center,
                         const std::vector<int>& Encoder_SideWays_Tracker_ports, const float SideWays_Tracker_wheel_diameter, const float SideWays_Tracker_distance_to_center)
    : left_side(left_side_ports), right_side(right_side_ports), gyro(gyro_port), Encoder_Forward_tracker(abs(Encoder_Forward_Tracker_ports[0]), abs(Encoder_Forward_Tracker_ports[1]), util::is_reversed(Encoder_Forward_Tracker_ports[0])), Encoder_SideWays_tracker(abs(Encoder_SideWays_Tracker_ports[0]), abs(Encoder_SideWays_Tracker_ports[1]), util::is_reversed(Encoder_SideWays_Tracker_ports[0])), Rotation_Forward_tracker(-1), Rotation_SideWays_tracker(-1), abs_global_x(0), abs_global_y(0), orientation(0), max_accel(0), max_rpm(0), max_vel(0), odom_configuration(odom_config), drive_pid(1, 1, 1, lightning::util::DELAY_TIME, 1), turn_pid(drive_pid), swing_pid(drive_pid) {
  this->wheels_diameter = wheel_diameter;
  this->cartridge = gearset;
  this->gear_ratio = gear_ratio;

  this->position.reserve(3);
  this->position[0] = 0;
  this->position[1] = 0;

  this->pose.reserve(3);
  this->pose[0] = 0;
  this->pose[1] = 0;
  this->pose[2] = 0;

  this->odometry_rotation_deg=0; 


  this->current_index = 0;

  left_side.set_encoder_units(integrated_encoders_unit);
  right_side.set_encoder_units(integrated_encoders_unit);

  if (odom_config == ADI_ONE_ODOM) {
    this->ForwardTracker_center_distance = Forward_Tracker_distance_to_center;
    this->ForwardTracker_diameter = Forward_Tracker_diameter;
    this->ForwardTracker_frequency = (M_PI * Forward_Tracker_diameter) / 360;

    this->SideWays_center_distance = 0;
    this->SideWays_diameter = 0;
    this->SideWaysTracker_frequency = 0;
    odom.set_physical_distances(this->ForwardTracker_center_distance, this->SideWays_center_distance);
  }

  if (odom_config == ADI_TWO_ODOM || odom_config == ADI_TWO_ROTATED_ODOM) {
    this->ForwardTracker_center_distance = Forward_Tracker_distance_to_center;
    this->ForwardTracker_diameter = Forward_Tracker_diameter;
    this->ForwardTracker_frequency = (M_PI * Forward_Tracker_diameter) / 360;

    this->SideWays_center_distance = SideWays_Tracker_distance_to_center;
    this->SideWays_diameter = SideWays_Tracker_wheel_diameter;
    this->SideWaysTracker_frequency = (M_PI * SideWays_Tracker_wheel_diameter) / 360;

    odom.set_physical_distances(this->ForwardTracker_center_distance, this->SideWays_center_distance);
  }
}

TankChassis::TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t> right_side_ports, const char gyro_port,
                         const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio, const int Rotation_Forward_Tracker_port, const float Forward_Tracker_diameter, const float Forward_Tracker_distance_to_center, const int Rotation_SideWays_Tracker_port, const float SideWays_Tracker_wheel_diameter, const float SideWays_Tracker_distance_to_center)
    : left_side(left_side_ports), right_side(right_side_ports), gyro(gyro_port),

      Encoder_Forward_tracker(-1, -1, false),
      Encoder_SideWays_tracker(-1, -1, false),

      Rotation_Forward_tracker(abs(Rotation_Forward_Tracker_port)),
      Rotation_SideWays_tracker(abs(Rotation_SideWays_Tracker_port)),
      abs_global_x(0),
      abs_global_y(0),
      orientation(0),
      max_accel(0),
      max_rpm(0),
      max_vel(0),
      odom_configuration(odom_config),
      drive_pid(1, 1, 1, lightning::util::DELAY_TIME, 1),
      turn_pid(drive_pid),
      swing_pid(drive_pid)

{
  this->Rotation_Forward_tracker.set_reversed(util::is_reversed(Rotation_Forward_Tracker_port));
  this->Rotation_SideWays_tracker.set_reversed(util::is_reversed(Rotation_SideWays_Tracker_port));

  this->wheels_diameter = wheel_diameter;
  this->cartridge = gearset;
  this->gear_ratio = gear_ratio;

  this->position.reserve(3);
  this->position[0] = 0;
  this->position[1] = 0;

  this->pose.reserve(3);
  this->pose[0] = 0;
  this->pose[1] = 0;
  this->pose[2] = 0;

  this->odometry_rotation_deg=0; 

  this->current_index = 0;

  left_side.set_encoder_units(integrated_encoders_unit);
  right_side.set_encoder_units(integrated_encoders_unit);

  if (odom_config == ROTATION_ONE_ODOM) {
    this->ForwardTracker_center_distance = Forward_Tracker_distance_to_center;
    this->ForwardTracker_diameter = Forward_Tracker_diameter;
    this->ForwardTracker_frequency = (M_PI * Forward_Tracker_diameter) / 36000;

    this->SideWays_center_distance = 0;
    this->SideWays_diameter = 0;
    this->SideWaysTracker_frequency = 0;

    odom.set_physical_distances(this->ForwardTracker_center_distance, this->SideWays_center_distance);
  }

  if (odom_config == ROTATION_TWO_ODOM || odom_config == ROTATION_TWO_ROTATED_ODOM) {
    this->ForwardTracker_center_distance = Forward_Tracker_distance_to_center;
    this->ForwardTracker_diameter = Forward_Tracker_diameter;
    this->ForwardTracker_frequency = (M_PI * Forward_Tracker_diameter) / 36000;

    this->SideWays_center_distance = SideWays_Tracker_distance_to_center;
    this->SideWays_diameter = SideWays_Tracker_wheel_diameter;
    this->SideWaysTracker_frequency = (M_PI * SideWays_Tracker_wheel_diameter) / 36000;

    odom.set_physical_distances(this->ForwardTracker_center_distance, this->SideWays_center_distance);
  }
}

void TankChassis::track_pose() {
  const float cos_theta = cos(to_rad(this->odometry_rotation_deg));
  const float sin_theta = sin(to_rad(this->odometry_rotation_deg));

  while (1) {
    odom.update_position(get_ForwardTracker_position(), get_SideWays_position(), get_orientation());

    // Rotated odometry is easy, we just need to apply a 2d rotation matrix to our odometry coordinates, rotating -45 degrees.
    if (this->odom_configuration == ADI_TWO_ROTATED_ODOM || this->odom_configuration == ROTATION_TWO_ROTATED_ODOM) {
      this->position[0] = odom.x_position * cos_theta - odom.y_position * sin_theta;
      this->position[1] = odom.x_position * sin_theta + odom.y_position * cos_theta;
      this->orientation = odom.orientation_degrees;
      this->pose = {position[0], position[1], orientation};
    }

    else {
      this->position = {odom.x_position, odom.y_position};
      this->orientation = odom.orientation_degrees;
      this->pose = {odom.x_position, odom.y_position, odom.orientation_degrees};
    }

    pros::delay(lightning::util::DELAY_TIME);
  }
}

void TankChassis::set_coordinates(const okapi::QLength x, const okapi::QLength y, const okapi::QAngle orientation_deg) {
  odom.set_position(x.convert(okapi::inch), y.convert(okapi::inch), orientation_deg.convert(okapi::degree), get_ForwardTracker_position(), get_SideWays_position());
  set_orientation(orientation_deg);
}

void TankChassis::set_odometry_rotation(const double angle_of_rotation_deg){
  this->odometry_rotation_deg = angle_of_rotation_deg; 
} 

void TankChassis::set_drive_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance) {
  drive_pid.set_kp(kp);
  drive_pid.set_ki(ki);
  drive_pid.set_kd(kd);

  drive_pid.set_max(max);
  drive_pid.set_scale(scale);
  drive_pid.set_integral_power_limit(integral_power_limit);

  drive_pid.set_derivative_tolerance(derivative_tolerance);

  drive_pid.set_sample_time(lightning::util::DELAY_TIME);
}

void TankChassis::set_drive_scale(const float scale) {
  drive_pid.set_scale(scale);
}

void TankChassis::set_drive_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec) {
  drive_pid.set_error_tolerance(error_tolerance);
  drive_pid.set_jump_time(jump_time_msec);
  drive_pid.set_stop_time(stop_time_msec);
}

void TankChassis::set_turn_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance) {
  turn_pid.set_kp(kp);
  turn_pid.set_ki(ki);
  turn_pid.set_kd(kd);

  turn_pid.set_max(max);
  turn_pid.set_scale(scale);
  turn_pid.set_integral_power_limit(integral_power_limit);

  turn_pid.set_derivative_tolerance(derivative_tolerance);

  turn_pid.set_sample_time(lightning::util::DELAY_TIME);
}

void TankChassis::set_turn_scale(const float scale) {
  turn_pid.set_scale(scale);
}

void TankChassis::set_turn_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec) {
  turn_pid.set_error_tolerance(error_tolerance);
  turn_pid.set_jump_time(jump_time_msec);
  turn_pid.set_stop_time(stop_time_msec);
}

void TankChassis::set_swing_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance) {
  swing_pid.set_kp(kp);
  swing_pid.set_ki(ki);
  swing_pid.set_kd(kd);

  swing_pid.set_max(max);
  swing_pid.set_scale(scale);
  swing_pid.set_integral_power_limit(integral_power_limit);

  swing_pid.set_derivative_tolerance(derivative_tolerance);

  swing_pid.set_sample_time(lightning::util::DELAY_TIME);
}

void TankChassis::set_swing_scale(const float scale) {
  swing_pid.set_scale(scale);
}

void TankChassis::set_swing_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec) {
  swing_pid.set_error_tolerance(error_tolerance);
  swing_pid.set_jump_time(jump_time_msec);
  swing_pid.set_stop_time(stop_time_msec);
}

void TankChassis::move_velocity(const int rpm) {
  left_side.move_velocity(rpm);
  right_side.move_velocity(rpm);
}

void TankChassis::move_voltage(const int voltage_mv) {
  left_side.move_voltage(voltage_mv);
  right_side.move_voltage(voltage_mv);
}

void TankChassis::move(const int voltage) {
  left_side.move(voltage);
  right_side.move(voltage);
}

void TankChassis::raw_drive_distance(double distance, const int vel_rpm) {
  float revolutions = distance / (this->wheels_diameter * M_PI);
  float degrees = revolutions * 360;

  float start_average_position = get_average_motors_position_deg();
  left_side.move_absolute(start_average_position + degrees, vel_rpm);
  right_side.move_absolute(start_average_position + degrees, vel_rpm);
}

void TankChassis::raw_drive_distance(const okapi::QLength distance, const int vel_rpm) {
  raw_drive_distance(distance.convert(okapi::inch), vel_rpm);
}

void TankChassis::drive_distance(PID& drive_control, PID& turn_control, double distance, double target_orientation) {
  // drive_control.set_target(distance + this->get_average_motors_position_inches());

  float distance_target = distance + this->get_average_motors_position_inches();
  drive_control.set_integral_zone(distance_target * .45);
  drive_control.initialization();

  // turn_control.set_target(target_orientation);
  turn_control.set_integral_zone(target_orientation * .3);
  turn_control.initialization();

  float current_orientation = get_orientation();
  float distance_travel = this->get_average_motors_position_inches();

  while (!drive_control.target_arrived()) {
    distance_travel = this->get_average_motors_position_inches();
    current_orientation = this->get_orientation();

    drive_control.update(distance_target - distance_travel);
    turn_control.update(reduce_angle_180_to_180(current_orientation - current_orientation));

    left_side.move_velocity(drive_control.get_output() + turn_control.get_output());
    right_side.move_velocity(drive_control.get_output() - turn_control.get_output());

    pros::delay(drive_control.get_sample_time());
  }

  stop();
}

void TankChassis::drive_distance(PID& distance_control, PID& turn_controller, const okapi::QLength distance, const okapi::QAngle target_orientation) {
  drive_distance(distance_control, turn_controller, distance.convert(okapi::inch), target_orientation.convert(okapi::degree));
}

void TankChassis::drive_distance(const double distance, const double target_orientation) {
  drive_distance(this->drive_pid, this->turn_pid, distance, target_orientation);
}

void TankChassis::drive_distance(const okapi::QLength distance, const okapi::QAngle target_orientation) {
  drive_distance(this->drive_pid, turn_pid, distance.convert(okapi::inch), target_orientation.convert(okapi::degree));
}

void TankChassis::drive_to_pose(PID& drive_controller, PID& turn_controller, std::vector<double> target_point, double orientation, float lead){
  double target_orientation =0;
  double turn_error = 0;

  turn_controller.initialization();

  double drive_error =0;
  drive_controller.initialization();

  double h = 0;
  std::vector<double> carrot_point {0,0}; 

  while (!drive_controller.target_arrived() && !turn_controller.target_arrived()) {
    h = distance_btw_points(target_point, this->position);
    carrot_point[0] = target_point[0] - ( h * cos(to_rad(orientation))) * lead;   
    carrot_point[1]= target_point[1] - ( h * sin(to_rad(orientation))) * lead; 
    
    target_orientation = get_angle_btw_points(this->position, carrot_point);    
    turn_error = reduce_angle_180_to_180(target_orientation - get_orientation());

    drive_error = sin(to_rad(turn_error))*distance_btw_points(carrot_point, this->position);
    
    drive_controller.set_integral_zone(drive_error*.45); 
    turn_controller.set_integral_zone(turn_error*.3); 

    turn_controller.update(turn_error);
    drive_controller.update(drive_error);

    left_side.move_velocity(drive_controller.get_output() + turn_controller.get_output());
    right_side.move_velocity(drive_controller.get_output() - turn_controller.get_output());
    
    pros::delay(drive_controller.get_sample_time());
  }

  stop();
}

void TankChassis::drive_to_pose(PID& drive_controller, PID& turn_controller, std::vector<okapi::QLength> target_point, okapi::QAngle orientation, okapi::QLength lead){
  drive_to_pose(drive_controller,turn_controller,{target_point[0].convert(okapi::inch), target_point[1].convert(okapi::inch)}, orientation.convert(okapi::degree), lead.convert(okapi::inch)); 
}

void TankChassis::drive_to_pose(std::vector<double> target_point, double orientation, float lead){
  drive_to_pose(this->drive_pid,this->turn_pid,target_point,orientation,lead); 
}

void TankChassis::drive_to_pose(std::vector<okapi::QLength> target_point, okapi::QAngle orientation, okapi::QLength lead){
  drive_to_pose({target_point[0].convert(okapi::inch), target_point[1].convert(okapi::inch)},orientation.convert(okapi::degree), lead.convert(okapi::inch)); 
}

void TankChassis::drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<double> target, bool reverse) {
  double target_orientation = get_angle_btw_points(this->position, target);

  if (reverse) {
    target_orientation -= 180;
  }
  
  double turn_error = reduce_angle_180_to_180(target_orientation - get_orientation());
  turn_controller.set_integral_zone(target_orientation * .3);
  turn_controller.initialization();

  double drive_error = distance_btw_points(target, this->position);
  drive_controller.set_integral_zone(drive_error * .3);
  drive_controller.initialization();

  int sign = reverse ? -1 : 1;

  while (!drive_controller.target_arrived() && !turn_controller.target_arrived()) {
    turn_error = reduce_angle_180_to_180(target_orientation - get_orientation());
    drive_error = sin(to_rad(turn_error))*distance_btw_points(target, this->position);
    
    turn_controller.update(turn_error);
    drive_controller.update(drive_error);

    left_side.move_velocity(drive_controller.get_output() + turn_controller.get_output());
    right_side.move_velocity(drive_controller.get_output() - turn_controller.get_output());

    pros::delay(drive_controller.get_sample_time());
  }

  stop();
}

void TankChassis::drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<okapi::QLength> target, bool reverse) {
  drive_to_point(drive_controller, turn_controller, {target[0].convert(okapi::inch), target[1].convert(okapi::inch)}, reverse);
}

void TankChassis::drive_to_point(std::vector<double> target, bool reverse) {
  drive_to_point(this->drive_pid, this->turn_pid, {target[0], target[1]}, reverse);
}

void TankChassis::drive_to_point(std::vector<okapi::QLength> target, bool reverse) {
  drive_to_point(this->drive_pid, this->turn_pid, {target[0].convert(okapi::inch), target[1].convert(okapi::inch)}, reverse);
}

void TankChassis::follow_path(Path& path, PID& drive_controller,
                              PID& turn_controller, float look_ahead_distance) {
  std::vector<double> end;
  std::vector<double> start;
  std::vector<double> target;
  std::vector<double> prev_target{0, 0};

  std::vector<double> current = (this->position);

  double target_heading = get_angle_btw_points(this->position, path.get_point_at(0));
  // turn_controller.set_target(target_heading);

  for (int index = 0; index < path.get_size() - 2; index++) {
    this->current_index = index;
    start = (path.get_point_at(index));
    end = (path.get_point_at(index + 1));

    while (distance(current, end) > look_ahead_distance) {
      target = get_intersection(start, end, current, look_ahead_distance);

      if (target[0] == std::numeric_limits<double>::quiet_NaN() &&
          target[1] == std::numeric_limits<double>::quiet_NaN()) {
        target = prev_target;
      }

      if (path.is_reverse()) {
        target_heading = (get_angle_btw_points(current, target)) - 180;

      }

      else {
        target_heading = (get_angle_btw_points(current, target));
      }

      // target_heading = get_angle_btw_points(current,target);
      // turn_controller.set_target(target_heading);
      turn_controller.update(reduce_angle_180_to_180(target_heading - get_orientation()));
      // turn_controller.update(orientation, true);

      double lineal_velocity = path.get_target_lineal_velocity_at(index);

      double left_wheel_velocity = lineal_velocity;
      double right_wheel_velocity = lineal_velocity;

      double left_wheel_rpm =
          linear_to_rpm(left_wheel_velocity, this->wheels_diameter);
      double right_wheel_rpm =
          linear_to_rpm(right_wheel_velocity, this->wheels_diameter);

      if (path.is_reverse()) {
        left_wheel_rpm = -left_wheel_rpm;
        right_wheel_rpm = -right_wheel_rpm;
      }

      double left_motors =
          (left_wheel_rpm * gear_ratio) + turn_controller.get_output();
      double right_motors =
          (right_wheel_rpm * gear_ratio) - turn_controller.get_output();

      // std::cout<<"\theading: "<<target_heading;
      // std::cout<<"\tl: "<<left_motors;
      // std::cout<<"\tr: "<<right_motors;

      this->left_side.move_velocity(left_motors);
      this->right_side.move_velocity(right_motors);

      current = (this->position);
      prev_target = target;
      pros::delay(10);
    }
  }

  current_index = 0;

  drive_to_point(
      drive_controller, turn_controller,
      {path.get_x_at(path.get_size() - 1), path.get_y_at(path.get_size() - 1)},
      path.is_reverse());
}

void TankChassis::follow_path(Path& path, float look_ahead_distance) {
  follow_path(path, this->drive_pid, this->turn_pid, look_ahead_distance);
}

// TE FALTA MODIFICAR LA DE ARRIBA

void TankChassis::move_with_motion_profile(TrapezoidalProfile& profile) {
  float output_motors = 0;
  float output_robot_rpm = 0;

  for (int i = 0; i < profile.get_size(); i++) {
    output_robot_rpm =
        linear_to_rpm(profile.get_velocity_at(i), this->wheels_diameter);
    output_motors = output_robot_rpm * this->gear_ratio;

    move_velocity(output_motors);

    pros::delay(10);
  }

  stop();
}

void TankChassis::turn_absolute(PID& turn_control, double target_orientation) {
  target_orientation = reduce_angle_0_to_360(target_orientation);
  turn_control.set_integral_zone(target_orientation * .3);
  turn_control.initialization();

  float current_orientation = get_orientation();

  while (!turn_control.target_arrived()) {
    current_orientation = get_orientation();
    turn_control.update(reduce_angle_180_to_180(target_orientation - current_orientation));

    left_side.move_velocity(turn_control.get_output());
    right_side.move_velocity(-turn_control.get_output());

    pros::delay(turn_control.get_sample_time());
  }

  stop();
}

// The target units are okapi units, The function run with custom pid
void TankChassis::turn_absolute(PID& turn_control, okapi::QAngle target_orientation) {
  turn_absolute(turn_control, target_orientation.convert(okapi::degree));
}

// The units must be in degrees
void TankChassis::turn_absolute(double target_orientation) {
  turn_absolute(this->turn_pid, target_orientation);
}

// The target units are okapi units , The functions runs with turn_control
void TankChassis::turn_absolute(okapi::QAngle target_orientation) {
  turn_absolute(this->turn_pid, target_orientation.convert(okapi::degree));
}

void TankChassis::turn_relative(PID& turn_control, double degrees) {
  double orientation = get_orientation() + degrees;
  this->turn_absolute(turn_control, orientation);
}

void TankChassis::turn_relative(PID& turn_control, okapi::QAngle degrees) {
  turn_relative(turn_control, degrees.convert(okapi::degree));
}

void TankChassis::turn_relative(okapi::QAngle degrees) {
  turn_relative(this->turn_pid, degrees.convert(okapi::degree));
}

void TankChassis::turn_relative(double degrees) {
  turn_relative(this->turn_pid, degrees);
}

void TankChassis::swing_turn_absolute(PID& swing_control, lightning::swing_direction_e_t swing_direction, double target_orientation, const int opposite_speed_rpm) {
  target_orientation = reduce_angle_0_to_360(target_orientation);
  // swing_control.set_target(target_orientation);
  swing_control.set_integral_zone(target_orientation * .3);
  swing_control.initialization();

  float current_orientation = get_orientation();

  while (!swing_control.target_arrived()) {
    current_orientation = get_orientation();
    swing_control.update(reduce_angle_180_to_180(target_orientation - current_orientation));

    if (swing_direction == LEFT_SWING) {
      left_side.move_velocity(opposite_speed_rpm);
      right_side.move_velocity(-swing_control.get_output());
    }

    if (swing_direction == RIGHT_SWING) {
      left_side.move_velocity(swing_control.get_output());
      right_side.move_velocity(-opposite_speed_rpm);
    }

    pros::delay(swing_control.get_sample_time());
  }

  stop();
}

void TankChassis::swing_turn_absolute(PID& swing_control, lightning::swing_direction_e_t swing_direction, okapi::QAngle target_orientation, const int opposite_speed_rpm) {
  swing_turn_absolute(swing_control, swing_direction, target_orientation.convert(okapi::degree), opposite_speed_rpm);
}

void TankChassis::swing_turn_absolute(lightning::swing_direction_e_t swing_direction, double target_orientation, const int opposide_speed_rpm) {
  swing_turn_absolute(this->swing_pid, swing_direction, target_orientation, opposide_speed_rpm);
}

void TankChassis::swing_turn_absolute(lightning::swing_direction_e_t swing_direction, okapi::QAngle target_orientation, const int opposide_speed_rpm) {
  swing_turn_absolute(this->swing_pid, swing_direction, target_orientation.convert(okapi::degree), opposide_speed_rpm);
}

void TankChassis::swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, double degrees, const int opposide_speed_rpm) {
  double orientacion = this->get_orientation() + degrees;
  this->swing_turn_absolute(swing_control, swing_direction, orientacion, opposide_speed_rpm);
}

void TankChassis::swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, okapi::QAngle angle, const int opposide_speed_rpm) {
  swing_turn_relative(swing_control, swing_direction, angle.convert(okapi::degree), opposide_speed_rpm);
}

void TankChassis::swing_turn_relative(lightning::swing_direction_e_t swing_direction, double degrees, const int opposide_speed_rpm) {
  swing_turn_relative(this->swing_pid, swing_direction, degrees, opposide_speed_rpm);
}

void TankChassis::swing_turn_relative(lightning::swing_direction_e_t swing_direction, okapi::QAngle angle, const int opposide_speed_rpm) {
  swing_turn_relative(this->swing_pid, swing_direction, angle.convert(okapi::degree), opposide_speed_rpm);
}

void TankChassis::set_orientation(okapi::QAngle current_orientation) {
  gyro.set_heading(current_orientation.convert(okapi::degree));
  this->orientation = current_orientation.convert(okapi::degree);
}

void TankChassis::set_brake(const pros::motor_brake_mode_e_t mode) {
  this->actual_brake = mode;
  left_side.set_brake_mode_all(mode);
  right_side.set_brake_mode_all(mode);
}

void TankChassis::set_wheels_diameter(const float _wheels_diameter) {
  wheels_diameter = _wheels_diameter;
}

void TankChassis::set_center_distance(const float distance) {
  this->center_distance = distance;
}

void TankChassis::set_gearing(const pros::motor_gearset_e_t gearset) {
  this->cartridge = gearset;
  left_side.set_gearing(gearset);
  right_side.set_gearing(gearset);
}

void TankChassis::set_gear_ratio(const float _gear_ratio) {
  this->gear_ratio = _gear_ratio;
}

void TankChassis::set_max_rpm(const float _max_rpm) {
  this->max_rpm = _max_rpm;
}

void TankChassis::set_max_velocity(const float _max_vel) {
  this->max_vel = _max_vel;
}

void TankChassis::set_max_accel(const float _max_accel) {
  this->max_accel = _max_accel;
}

void TankChassis::auto_set_max_rpm(const int time_msec, const float scale) {
  left_side.tare_position();
  right_side.tare_position();
  pros::delay(10);
  int contador = 0;
  double max_rpm = 0;
  double current_rpm = 0;
  while (contador < time_msec) {
    left_side.move_voltage(12000 * scale);
    right_side.move_voltage(12000 * scale);

    current_rpm = get_actual_rpm();

    if (current_rpm > max_rpm) {
      max_rpm = current_rpm;
    }

    contador += 10;
    pros::delay(10);
  }

  stop();
  this->max_rpm = max_rpm;
}

void TankChassis::auto_set_max_velocity_with_position(const int time_msec,
                                                      const float scale) {
  left_side.tare_position();
  right_side.tare_position();
  pros::delay(10);
  int contador = 0;

  double initial_position = 0;
  double final_position = get_average_motors_position_deg() * (M_PI * wheels_diameter);

  while (contador < time_msec) {
    left_side.move_voltage(12000 * scale);
    right_side.move_voltage(12000 * scale);

    contador += 10;
    pros::delay(10);
  }

  stop();

  int ticks_cartridge;

  switch (this->integrated_encoders_unit) {
      // jala
    case pros::E_MOTOR_ENCODER_DEGREES:
      final_position = (get_average_motors_position_deg() / 360) * (M_PI * wheels_diameter);
      break;

      // JALA
    case pros::E_MOTOR_ENCODER_ROTATIONS:
      final_position = (get_average_motors_position_deg() * 360) * (M_PI * wheels_diameter);
      break;

      // PRUEBA
    case pros::E_MOTOR_ENCODER_COUNTS:
      // 1800 ticks/rev with 36:1 gears
      // 900 ticks/rev with 18:1 gears
      // 300 ticks/rev with 6:1 gears
      ticks_cartridge =
          this->cartridge == pros::motor_gearset_e::E_MOTOR_GEARSET_36   ? 1800
          : this->cartridge == pros::motor_gearset_e::E_MOTOR_GEARSET_18 ? 900
          : this->cartridge == pros::motor_gearset_e::E_MOTOR_GEARSET_06 ? 300
                                                                         : 0;

      final_position =
          (get_average_motors_position_deg() / ticks_cartridge) * (M_PI * wheels_diameter);
      break;

    default:
      final_position = 0;
      break;
  }

  float tiempo_total_sec = time_msec / 1000.0;

  this->max_vel = (final_position - initial_position) / (tiempo_total_sec);
}

void TankChassis::autoset_max_vel_accel(const int time_msec,
                                        const float scale) {
  left_side.tare_position();
  right_side.tare_position();

  int contador = 0;
  double current_vel, delta_vel, prev_vel, max_vel = 0;

  double accel, max_accel = 0;

  while (contador < time_msec) {
    move_voltage(12000 * scale);
    current_vel = rpm_to_linear(get_actual_rpm(), this->wheels_diameter);

    delta_vel = current_vel - prev_vel;
    prev_vel = current_vel;

    accel = delta_vel;

    if (current_vel > max_vel) {
      max_vel = current_vel;
    }

    if (accel > max_accel) {
      max_accel = accel;
    }

    std::cout << "\n Max Vel: " << max_vel;
    std::cout << "\t Max Accel: " << max_accel;

    contador += 10;
    pros::delay(10);
  }
  stop();
  this->max_vel = max_vel;
  this->max_accel = max_accel;
}

void TankChassis::stop() {
  this->left_side.brake();
  this->right_side.brake();
}

lightning::tank_odom_e_t TankChassis::get_odometry_configuration(){
  return this->odom_configuration; 
}

double TankChassis::get_odometry_rotation(){
  return this->odometry_rotation_deg; 
} 

std::vector<double> TankChassis::get_pose() {
  return this->pose;
  // return {{fixed_abs_global_x, fixed_abs_global_y, orientation}};
}

std::vector<double> TankChassis::get_position() {
  return this->position;
  // return {{fixed_abs_global_x, fixed_abs_global_y}};
}

double TankChassis::get_ForwardTracker_position() {
  if (this->odom_configuration == NO_ODOM) {
    this->ForwardTracker_position_inches = 0;
  }

  if (this->odom_configuration == ADI_ONE_ODOM || this->odom_configuration == ADI_TWO_ODOM || this->odom_configuration == ADI_TWO_ROTATED_ODOM) {
    this->ForwardTracker_position_inches = Encoder_Forward_tracker.get_value() * this->ForwardTracker_frequency;
  }

  if (this->odom_configuration == ROTATION_ONE_ODOM || this->odom_configuration == ROTATION_TWO_ODOM || this->odom_configuration == ROTATION_TWO_ROTATED_ODOM) {
    this->ForwardTracker_position_inches = Rotation_Forward_tracker.get_position() * this->ForwardTracker_frequency;
  }

  return this->ForwardTracker_position_inches;
}

double TankChassis::get_SideWays_position() {
  if (this->odom_configuration == NO_ODOM) {
    this->SideWaysTracker_position_inches = 0;
  }

  if (this->odom_configuration == ADI_ONE_ODOM || this->odom_configuration == ADI_TWO_ODOM || this->odom_configuration == ADI_TWO_ROTATED_ODOM) {
    this->SideWaysTracker_position_inches = Encoder_SideWays_tracker.get_value() * this->SideWaysTracker_frequency;
  }

  if (this->odom_configuration == ROTATION_ONE_ODOM || this->odom_configuration == ROTATION_TWO_ODOM || this->odom_configuration == ROTATION_TWO_ROTATED_ODOM) {
    this->SideWaysTracker_position_inches = Rotation_SideWays_tracker.get_position() * this->SideWaysTracker_frequency;
  }

  return this->SideWaysTracker_position_inches;
}

int TankChassis::get_current_index() {
  return this->current_index;
}

double TankChassis::get_orientation() const { return gyro.get_heading(); }

double TankChassis::get_x() const { return position[0]; }

double TankChassis::get_y() const { return position[1]; }

double TankChassis::get_motor_group_position(pros::MotorGroup& motor_group) {
  std::vector<double> motors_position = motor_group.get_position_all();

  int number_of_motors = motor_group.size() - 1;
  double sum = 0;

  for (auto i = 0; i < motor_group.size(); i++) {
    if (std::isnan(motors_position[i]) || std::isinf(motors_position[i])) {
      sum += 0;
      number_of_motors -= 1;
    }

    else {
      sum += motors_position[i];
    }
  }

  return sum / number_of_motors;
}

double TankChassis::get_average_motors_position_deg() {
  return (get_left_position_deg() + get_right_position_deg()) / 2;
}

double TankChassis::get_left_position_deg() {
  return get_motor_group_position(left_side);
}

double TankChassis::get_right_position_deg() {
  return get_motor_group_position(right_side);
}

double TankChassis::get_average_motors_position_inches() {
  return (get_left_position_inches() + get_right_position_inches()) / 2;
}

double TankChassis::get_left_position_inches() {
  return ((get_left_position_deg() / 360) * (M_PI * this->wheels_diameter));
}

double TankChassis::get_right_position_inches() {
  return ((get_right_position_deg() / 360) * (M_PI * this->wheels_diameter));
}

double TankChassis::get_actual_rpm() {
  std::vector<double> left_velocity = left_side.get_actual_velocity_all();
  std::vector<double> righ_velocity = right_side.get_actual_velocity_all();

  int num_motors = left_side.size();
  double average_velocity = 0;
  double sum_velocity = 0;

  for (auto i = 0; i <= left_velocity.size(); i++)  // 3
  {
    sum_velocity += (left_velocity[i] + righ_velocity[i]) / 2;  // 3

    // 4
  }

  average_velocity = sum_velocity / num_motors;

  return average_velocity / get_gear_ratio();
}

double TankChassis::get_actual_velocity() {
  return (rpm_to_linear(get_actual_rpm(), wheels_diameter)) / 60;
}

double TankChassis::get_max_rpm() { return max_rpm; }

double TankChassis::get_max_velocity() { return max_vel; }

double TankChassis::get_max_accel() { return this->max_accel; }

float TankChassis::get_wheels_diameter() const { return wheels_diameter; }

float TankChassis::get_center_distance() const { return center_distance; }

pros::motor_gearset_e TankChassis::get_gearing() const { return cartridge; }

pros::MotorUnits TankChassis::get_encoders_units() {
  return left_side.get_encoder_units(0);
}

float TankChassis::get_gear_ratio() const { return gear_ratio; }

void TankChassis::arcade(pros::Controller& control,
                         const lightning::tank_op_arcade_e_t arcade,
                         const float power_rate, const float turn_rate) {
  if (arcade == lightning::E_TANK_OP_ARCADE_LEFT) {
    power_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * power_rate;
    turn_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) * turn_rate;
  }

  if (arcade == lightning::E_TANK_OP_ARCADE_RIGHT) {
    power_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) * power_rate;
    turn_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * turn_rate;
  }

  if (arcade == lightning::E_TANK_OP_ARCADE_DOUBLE) {
    power_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * power_rate;
    turn_driver =
        control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * turn_rate;
  }

  left_side.move(power_driver + turn_driver);
  right_side.move(power_driver - turn_driver);
}

void TankChassis::arcade_exponential(pros::Controller& control,
                                     const lightning::tank_op_arcade_e_t arcade,
                                     int n_x,
                                     int n_y) {
  static int raw_joystick_x = 0;
  static int raw_joystick_y = 0;

  static float power = 0;
  static float turn = 0;

  n_x = abs(n_x);
  n_y = abs(n_y);

  if (arcade == lightning::E_TANK_OP_ARCADE_LEFT) {
    raw_joystick_x = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    raw_joystick_y = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  }

  if (arcade == lightning::E_TANK_OP_ARCADE_RIGHT) {
    raw_joystick_x = control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    raw_joystick_y = control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
  }

  if (arcade == lightning::E_TANK_OP_ARCADE_DOUBLE) {
    raw_joystick_x = control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    raw_joystick_y = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
  }

  power = util::smooth_Joystick_Output(raw_joystick_y, n_y);
  turn = util::smooth_Joystick_Output(raw_joystick_x, n_x);

  left_side.move(power + turn);
  right_side.move(power - turn);
}

void TankChassis::tank(pros::Controller& control) {
  left_side.move(control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
  right_side.move(control.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}

void TankChassis::reset_odometry() {
  this->Encoder_Forward_tracker.reset();
  this->Encoder_SideWays_tracker.reset();
  this->ForwardTracker_position_inches = 0;
  this->SideWaysTracker_position_inches = 0;
  orientation = 0;
  gyro.reset();
}

void TankChassis::reset_IMU() {
  this->gyro.reset();
}

void TankChassis::tare_motors_position() {
  this->left_side.tare_position();
  pros::delay(100);
  this->right_side.tare_position();
  pros::delay(100);
}

}  // namespace lightning
