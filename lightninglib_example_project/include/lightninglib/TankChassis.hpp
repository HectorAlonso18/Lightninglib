/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

#include <cstdint>
#include <initializer_list>
#include <vector>

#include "lightninglib/Odom_tracker.hpp"
#include "lightninglib/PID.hpp"
#include "lightninglib/Path.hpp"
#include "lightninglib/TankChassis.h"
#include "lightninglib/Trapezoidal.hpp"
#include "okapi/api/units/QAngle.hpp"
#include "okapi/api/units/QLength.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.h"
#include "pros/rotation.hpp"

namespace lightning {
class TankChassis {
 private:
  pros::MotorGroup left_side;
  pros::MotorGroup right_side;
  pros::Imu gyro;

  pros::adi::Encoder Encoder_Forward_tracker;
  pros::adi::Encoder Encoder_SideWays_tracker;

  pros::Rotation Rotation_Forward_tracker;
  pros::Rotation Rotation_SideWays_tracker;

  lightning::OdomTracker odom;
  lightning::tank_odom_e_t odom_configuration;

  // lightning::PositionPID position_pid;
  lightning::PID drive_pid;
  lightning::PID turn_pid;
  lightning::PID swing_pid;

  float ForwardTracker_center_distance;
  float ForwardTracker_diameter;
  float ForwardTracker_frequency;
  float ForwardTracker_position_inches;

  float SideWays_center_distance;
  float SideWays_diameter;
  float SideWaysTracker_frequency;
  float SideWaysTracker_position_inches;

 private:
  float wheels_diameter;
  float gear_ratio;
  float center_distance;

  pros::motor_gearset_e cartridge;
  pros::motor_brake_mode_e_t actual_brake;
  pros::motor_encoder_units_e_t integrated_encoders_unit = pros::motor_encoder_units_e_t::E_MOTOR_ENCODER_DEGREES;

  float max_rpm;
  float max_vel;
  float max_accel;

 private:
  std::vector<double> pose;
  std::vector<double> position;
  double orientation;
  double abs_global_x;
  double abs_global_y;

  double odometry_rotation_deg; 

 private:
  float power_driver;
  float turn_driver;

  int current_index;

 public:
  /**
  @brief TankChassis constructor  without odometry.
  @param odom_config what odometry configuration the user want. (This constructor is designated for chassis without odometry system).
  @param left_side_ports a vector/list of the left motors ports of the drivetrain.
  @param right_side_ports a vector/list of the right motors ports of the drivetrain.
  @param gyro_port the IMU port.
  @param gearset what is the cartridge of you drivetrain (blue,green, red)?
  @param wheel_diameter what is the side of the drivetrain wheels ?
  @param gear_ratio what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
   */
  TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t>& right_side_ports,
              const char gyro_port, const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio);

  /**
  @brief TankChassis constructor with odometry using ADI encoders (The red ones).
  @param odom_config what odometry configuration the user want. (This constructor is designated for chassis with ADI encoder odometry).
  @param left_side_ports a vector/list of the left motors ports of the drivetrain.
  @param right_side_ports a vector/list of the right motors ports of the drivetrain.
  @param gyro_port the IMU port.
  @param gearset what is the cartridge of you drivetrain (blue,green, red)?
  @param wheel_diameter what is the side of the drivetrain wheels ? (must to be in inches).
  @param gear_ratio what is the gear ratio (Is the result of Driven/Driving, Drive:Driving).

  @param Encoder_Forward_Tracker_ports a vector with the ports of the forward tracker (example: {'A','B'}).
  @param Forward_Tracker_diameter the wheel diameter of your forward tracker (must to be in inches).
  @param Forward_Tracker_distance_to_center the distance that exist between the forward tracker  and the robot center point (must to be in inches).

  @param Encoder_SideWays_Tracker_ports a vector with the ports of the sideways tracker (example: {'B','C'}).
  @param SideWays_Tracker_diameter the wheel diameter of your sideways tracker (must to be in inches).
  @param SideWays_Tracker_distance_to_center the distance that exist between the sideways tracker  and the robot center point (must to be in inches).
   */
  TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t>& right_side_ports,
              const char gyro_port, const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio, const std::vector<int>& Encoder_Forward_Tracker_ports, const float Forward_Tracker_diameter, const float Forward_Tracker_distance_to_center,
              const std::vector<int>& Encoder_SideWays_Tracker_ports, const float SideWays_Tracker_wheel_diameter, const float SideWays_Tracker_distance_to_center);

  /**
  @brief TankChassis constructor with odometry using the V5 rotation sensors.
  @param odom_config what odometry configuration the user want. (This constructor is designated for chassis with ADI encoder odometry).
  @param left_side_ports a vector/list of the left motors ports of the drivetrain.
  @param right_side_ports a vector/list of the right motors ports of the drivetrain.
  @param gyro_port the IMU port.
  @param gearset what is the cartridge of you drivetrain (blue,green, red)?
  @param wheel_diameter what is the side of the drivetrain wheels ? (must to be in inches).
  @param gear_ratio what is the gear ratio (Is the result of Driven/Driving, Drive:Driving).

  @param Rotation_Forward_Tracker_ports The rotation forward tracker port.
  @param Forward_Tracker_diameter the wheel diameter of your forward tracker (must to be in inches).
  @param Forward_Tracker_distance_to_center the distance that exist between the forward tracker  and the robot center point (must to be in inches).

  @param Rotation_SideWays_Tracker_ports The rotation forward tracker port.
  @param SideWays_Tracker_diameter the wheel diameter of your sideways tracker (must to be in inches).
  @param SideWays_Tracker_distance_to_center the distance that exist between the sideways tracker  and the robot center point (must to be in inches).
   */
  TankChassis(tank_odom_e_t odom_config, const std::initializer_list<std::int8_t>& left_side_ports, const std::initializer_list<std::int8_t> right_side_ports, const char gyro_port,
              const pros::motor_gearset_e_t gearset, float wheel_diameter, float gear_ratio, const int Rotation_Forward_Tracker_port, const float Forward_Tracker_diameter, const float Forward_Tracker_distance_to_center, const int Rotation_SideWays_Tracker_port, const float SideWays_Tracker_wheel_diameter, const float SideWays_Tracker_distance_to_center);

  TankChassis(const TankChassis& other) = delete;

  /**
  @brief Destroys a TankChassis object.
   */
  ~TankChassis() = default;

 public:
  /**
   * @brief Tracks and Updates pose. The position and orientation vector (x,y,theta) using odometry.
   */
  void track_pose();

  /**
   * @brief Sets the coordinates for the odometry position system.
   * @param x the x coordinate in QLength unit.
   * @param y the y coordinate in QLength unit.
   * @param orientation_deg the orientation in QAngle unit.
   */
  void set_coordinates(const okapi::QLength x, const okapi::QLength y, const okapi::QAngle orientation_deg);
  
  /**
    *@brief Sets the odometry rotation for the odometry position system. 
    * The odometry rotation is needed for ROTATED configurations like: ADI_TWO_ROTATED_ODOM and ROTATION_TWO_ROTATED_ODOM
    *@param angle_of_rotation_deg The angle of rotation in degrees
    * @note For example if your tracking wheels are rotated to -45 degrees, you use set_odometry_rotation(-45); 
   */
  void set_odometry_rotation(const double angle_of_rotation_deg); 

  /**
   * @brief Sets the DrivePID constants for the Drive PID controller.
   * @param kp proportional constant.
   * @param ki integral constant.
   * @param kd derivative constant.
   * @param max PID max output.
   * @param scale PID scale.
   * @param integral_power_limit integral_power_limit.
   * @param derivative_tolerance how much the derivative would affect.
   */
  void set_drive_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance);

  /**
   * @brief Sets the DrivePID scale.
   * @param scale PID scale.
   */
  void set_drive_scale(const float scale);

  /**
   * @brief Sets the DrivePID exit conditions, conditions that would make that PID controller stops
   * @param error_tolerance The error tolerance for the controller.
   * @param jump_time_msec The jump time limit in milliseconds.
   * @param stop_time_msec The stop time limit in milliseconds. If more than this time elapses,
   *        the PID controller output will be forced to zero.
   */
  void set_drive_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec);

  /**
   * @brief Sets the TurnPID constants for the Drive PID controller.
   * @param kp proportional constant.
   * @param ki integral constant.
   * @param kd derivative constant.
   * @param max PID max output.
   * @param scale PID scale.
   * @param integral_power_limit integral_power_limit.
   * @param derivative_tolerance how much the derivative would affect.
   */
  void set_turn_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance);

  /**
   * @brief Sets the TurnPID scale.
   * @param scale PID scale.
   */
  void set_turn_scale(const float scale);

  /**
   * @brief Sets the TurnPID exit conditions, conditions that would make that PID controller stops
   * @param error_tolerance The error tolerance for the controller.
   * @param jump_time_msec The jump time limit in milliseconds.
   * @param stop_time_msec The stop time limit in milliseconds. If more than this time elapses,
   *        the PID controller output will be forced to zero.
   */
  void set_turn_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec);

  /**
   * @brief Sets the SwingPID constants for the Drive PID controller.
   * @param kp proportional constant.
   * @param ki integral constant.
   * @param kd derivative constant.
   * @param max PID max output.
   * @param scale PID scale.
   * @param integral_power_limit integral_power_limit.
   * @param derivative_tolerance how much the derivative would affect.
   */
  void set_swing_constants(float kp, float ki, float kd, float max, float scale, float integral_power_limit, float derivative_tolerance);

  /**
   * @brief Sets the SwingPID scale.
   * @param scale PID scale.
   */
  void set_swing_scale(const float scale);

  /**
   * @brief Sets the SwingPID exit conditions, conditions that would make that PID controller stops
   * @param error_tolerance The error tolerance for the controller.
   * @param jump_time_msec The jump time limit in milliseconds.
   * @param stop_time_msec The stop time limit in milliseconds. If more than this time elapses,
   *        the PID controller output will be forced to zero.
   */
  void set_swing_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec);

 public:
  /**
   * @brief Sets the velocity for the motors chassis.
   *
   * @note This velocity corresponds to different actual speeds depending on the gearset
   * used for the chassis. This results in a range of +-100 for E_MOTOR_GEARSET_36,
   * +-200 for E_MOTOR_GEARSET_18, and +-600 for E_MOTOR_GEARSET_6. The velocity
   * is held with PID to ensure consistent speed, as opposed to setting the
   * motor's voltage.
   *
   * \param RPM The new motors chassis velocity from +-100, +-200, or +-600 depending on the
   * motor's gearset
   */
  void move_velocity(const int rpm);
  
   /**
   * @brief Sets the velocity for the motors chassis (LEFTSIDE AND RIGHT SIDE).
   *
   * @note This velocity corresponds to different actual speeds depending on the gearset
   * used for the chassis. This results in a range of +-100 for E_MOTOR_GEARSET_36,
   * +-200 for E_MOTOR_GEARSET_18, and +-600 for E_MOTOR_GEARSET_6. The velocity
   * is held with PID to ensure consistent speed, as opposed to setting the
   * motor's voltage.
   *
   * @param left_rpm The left_side motors chassis velocity from +-100, +-200, or +-600 depending on the
   * motor's gearset
   * @param right_rpm the right_side motors chassis velocity from +-100, +-200, or +-600 depending on the
   * motor's gearset
   */
  void move_velocity(const int left_rpm, const int right_rpm); 

  /**
   * @brief Sets the output voltage for the motors chassis from -12000 to 12000 in millivolts
   *
   * This function uses the following values of errno when an error state is
   * reached:
   *
   * @param voltage_mv
   *        The new voltage value from -12000 to 12000 millivolts
   */
  void move_voltage(const int voltage_mv);
  
    /**
   * @brief Sets the output voltage for the motors chassis (LEFT SIDE AND RIGHT SIDE) from -12000 to 12000 in millivolts
   *
   * This function uses the following values of errno when an error state is
   * reached:
   *
   * @param left_voltage_mv
   *        The new voltage value from -12000 to 12000 millivolts for the left side
   * @param right_voltage_mv
   *        The new voltage value from -12000 to 12000 millivolts for the right side
   */

  void move_voltage(const int left_voltage_mv, const int right_voltage_mv); 

  /**
   * @brief Sets the voltage for the motors chassis from -127 to 127.
   *
   * This is designed to map easily to the input from the controller's analog
   * stick for simple opcontrol use.
   * @param voltage
   *        The new motors chassis voltage from -127 to 127
   */
  void move(const int voltage);
  
  /**
    * @brief Drives the robot from a starting pose to a target pose, using the boomerang controller.
    *@param drive_controller A PID controller designated for controlling the forward and backward movements of the robot.
    *@param turn_controller A PID controller designated for turns.
    *@param target_point  The target point {x,y} in inches.
    *@param orientation The orientation in degrees. 
    *@param lead is the gain that controls how far the carrot point is away from the end point. Can be a value between 0 and 1.
    *@note The boomerang controller just make the math to calculate the target coordinates in each cycle, the power calculatios are made
    * Using two PID controllers
   */
  void drive_to_pose(PID& drive_controller, PID& turn_controller, std::vector<double> target_point, double orientation, float lead); 
  
  /**
    * @brief Drives the robot from a starting pose to a target pose, using the boomerang controller.
    *@param drive_controller A PID controller designated for controlling the forward and backward movements of the robot.
    *@param turn_controller A PID controller designated for turns.
    *@param target_point  The target point {x,y} in okapi units.
    *@param orientation The orientation in okapi units. 
    *@param lead is the gain that controls how far the carrot point is away from the end point. in okapi units.
    *@note The boomerang controller just make the math to calculate the target coordinates in each cycle, the power calculatios are made
    * Using two PID controllers
   */
  void drive_to_pose(PID& drive_controller, PID& turn_controller, std::vector<okapi::QLength> target_point, okapi::QAngle orientation, okapi::QLength lead); 
  
  /**
    * @brief Drives the robot from a starting pose to a target pose, using the boomerang controller.
    *@param target_point  The target point {x,y} in inches.
    *@param orientation The orientation in degrees. 
    *@param lead is the gain that controls how far the carrot point is away from the end point. Can be a value between 0 and 1.
    *@note The boomerang controller just make the math to calculate the target coordinates in each cycle, the power calculatios are made
    * Using two PID controllers
   */
  void drive_to_pose(std::vector<double> target_point, double orientation, float lead); 

   /**
    * @brief Drives the robot from a starting pose to a target pose, using the boomerang controller.
    *@param target_point  The target point {x,y} in okapi units.
    *@param orientation The orientation in okapi units. 
    *@param lead is the gain that controls how far the carrot point is away from the end point. in okapi units.
    *@note The boomerang controller just make the math to calculate the target coordinates in each cycle, the power calculatios are made
    * Using two PID controllers
   */
  void drive_to_pose(std::vector<okapi::QLength> target_point, okapi::QAngle orientation, okapi::QLength lead); 

  /**
   * @brief Sets the voltage for the motors chassis (LEFT AND RIGHT SIDE) from -127 to 127.
   *
   * This is designed to map easily to the input from the controller's analog
   * stick for simple opcontrol use.
   * @param left_voltage
   *        The new left side motors chassis voltage from -127 to 127
   * @param right_voltage
   *        The new right side motors chassis voltage from -127 to 127
   */
  void move(const int left_voltage, const int right_voltage); 

  /**
   *@brief Drives the robot from a starting point to a target point using custom PID controller (Created for the user).
   *@param drive_controller a PID controller designated for controlling the forward and backward movements of the robot.
   *@param turn_controller a PID controller designated for turns.
   *@param target the target point {x,y} in inches.
   *@param reverse true if you want to go backwards.
   *@note The robot MUST to be facing the target point.
   */
  void drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<double> target, bool reverse);

  /**
   *@brief Drives the robot from a starting point to a target point using custom PID controller (Created for the user) using okapi units.
   *@param drive_controller a PID controller designated for controlling the forward and backward movements of the robot.
   *@param turn_controller a PID controller designated for turns.
   *@param target the target point {x,y} in okapi units, for example could be in inches, centimeters, meters, etc.
   *@param reverse true if you want to go backwards.
   *@note The robot MUST to be facing the target point.
   */
  void drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<okapi::QLength> target, bool reverse);

  /**
   *@brief Drives the robot from a starting point to a target point using the Drive and Turn PID .
   *@param target the target point {x,y}
   *@param reverse true if you want to go backwards.
   *@note The robot MUST to be facing the target point.
   */
  void drive_to_point(std::vector<double> target, bool reverse);

  /**
   *@brief Drives the robot from a starting point to a target point using the Drive and Turn PID .
   *@param target the target point {x,y} in okapi units, for example could be in inches, centimeters, meters, etc.
   *@param reverse true if you want to go backwards.
   *@note The robot MUST to be facing the target point.
   */
  void drive_to_point(std::vector<okapi::QLength> target, bool reverse);

  /**
   *@brief Drives the robot to follow a pre-computaded path using PID controllers created for the user.
   *@param path a desired path created by the Path class.
   *@param drive_controller a PID controller designated for controlling the forward and backward movements of the robot.
   *@param turn_controller a PID controller designated for turns.
   *@param look_ahead_distance The look ahead distance. It its important for the pure pursuit calculations see more information in:
   https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html
   */
  void follow_path(Path& path, PID& drive_controller, PID& turn_controller, float look_ahead_distance);

  /**
   *@brief Drives the robot to follow a pre-computaded path using the Drive and Turn PIDS from tank chassis class.
   *@param path a desired path created by the Path class.
   *@param look_ahead_distance The look ahead distance. It its important for the pure pursuit calculations see more information in:
   https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html
   */
  void follow_path(Path& path, float look_ahead_distance);
  
  void run_MotionLight_profile(const char* motion_light_file, PID& turn_control ,double target_orientation); 
  
  void run_MotionLight_profile(const char* motion_light_file,PID& turn_control, const okapi::QAngle target_orientation); 

  void run_MotionLight_profile(const char* motion_light_file, double target_orientation); 
  void run_MotionLight_profile(const char* motion_light_file, const okapi::QAngle target_orientation); 

  /**
   *@brief Drives the robot using a trapezoidal profile
   *@param profile the trapezoidal profile.
   */
  void move_with_motion_profile(TrapezoidalProfile& profile);

  /**
   *@brief Drives the robot to a certain distance and velocity in RPM, using the PROS move_absolute function.
   *@param distance how many inches do you want that the robot moves?
   *@param vel_rpm what would be the drive base motors velocity in RPM?
   *@note The user needs to set how many inches the robot would move.
   */
  void raw_drive_distance(double distance, const int vel_rpm);

  /**
   *@brief Drives the robot to a certain distance and velocity in RPM, using the PROS move_absolute function.
   *@param distance how much distance the robot would move?, Using okapi units.
   *@param vel_rpm what would be the drive base motors velocity in RPM?
   *@note The user needs to set how many inches the robot would move.
   */
  void raw_drive_distance(const okapi::QLength distance, const int vel_rpm);

  /**
   * @brief Drives the robot to a specified distance using PID controllers.
   *
   * This function controls the robot to move a certain distance using a user-defined PID controller for
   * forward and backward movements, while also maintaining alignment using a separate PID controller for turns.
   *
   * @param drive_control A PID controller designated for controlling the forward and backward movements of the robot.
   * @param turn_control A PID controller designated for controlling the turns of the robot.
   * @param distance The distance in inches that you want the robot to move.
   * @param target_orientation The target orientation in which you want the robot to stay in degrees.
   */
  void drive_distance(PID& drive_control, PID& turn_control, double distance, double target_orientation);

  /**
   * @brief Drives the robot to a specified distance using PID controllers.
   *
   * This function controls the robot to move a certain distance using a user-defined PID controller for
   * forward and backward movements, while also maintaining alignment using a separate PID controller for turns.
   *
   * @param drive_control A PID controller designated for controlling the forward and backward movements of the robot.
   * @param turn_control A PID controller designated for controlling the turns of the robot.
   * @param distance how much distance the robot would move?, Using okapi units.
   * @param target_orientation The target orientation in which you want the robot to stay, Using okapi units.
   */

  void drive_distance(PID& distance_control, PID& turn_controller, const okapi::QLength distance, const okapi::QAngle target_orientation);

  /**
   * @brief Drives the robot to a specified distance using PID controllers.
   *
   * This function controls the robot to move a certain distance using the DrivePID
   * ,while also maintaining alignment using a TurnPID controller for turns.
   *
   * @param distance The distance in inches that you want the robot to move.
   * @param target_orientation The target orientation in which you want the robot to stay, (In degrees).
   */
  void drive_distance(const double distance, const double target_orientation);

  /**
   * @brief Drives the robot to a specified distance using PID controllers.
   *
   * This function controls the robot to move a certain distance using the DrivePID
   * ,while also maintaining alignment using a TurnPID controller for turns.
   *
   * @param distance how much distance the robot would move?, Using okapi units.
   * @param target_orientation The target orientation in which you want the robot to stay, Using okapi units.
   */
  void drive_distance(const okapi::QLength distance, const okapi::QAngle target_orientation);
   
  
  /**
   *@brief Makes the robot turn to a certain orientation using a user-defined PID controller.
   *@param turn_control the user PID controller.
   *@param target_orientation the target orientation in degrees.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_absolute(PID& turn_control, double target_orientation);

  /**
   *@brief Makes the robot turn to a certain orientation using a user-defined PID controller.
   *@param turn_control the user PID controller.
   *@param target_orientation the target orientation in okapi units.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_absolute(PID& turn_control, okapi::QAngle target_orientation);

  /**
   *@brief Makes the robot turn to a certain orientation using the TurnPID.
   *@param target_orientation the target orientation in okapi units.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_absolute(okapi::QAngle target_orientation);

  /**
   *@brief Makes the robot turn to a certain absolute orientation using the TurnPID.
   *@param target_orientation the target orientation in degrees.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_absolute(double target_orientation);

  /**
   *@brief Turns the robot certain number of degrees, positive if the robot needs to turn right or negative if the robot needs to turn left.
   *@param turn_control  the user PID controller.
   *@param degrees how many degrees would turn?
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_relative(PID& turn_control, double degrees);

  /**
   *@brief Turns the robot certain number of degrees or radians, positive if the robot needs to turn right or negative if the robot needs to turn left.
   *@param turn_control  the user PID controller.
   *@param degrees how many radians/degrees would turn?
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_relative(PID& turn_control, okapi::QAngle degrees);

  /**
   *@brief Turns the robot certain number of degrees or radians, positive if the robot needs to turn right or negative if the robot needs to turn left.
           Using the turnPID controller.
   *@param degrees how many radians/degrees would turn?
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_relative(okapi::QAngle degrees);

  /**
   *@brief Turns the robot certain number of degrees, positive if the robot needs to turn right or negative if the robot needs to turn left.
   *        Using the turnPID controller.
   *@param turn_control  the user PID controller.
   *@param degrees how many degrees would turn?
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_relative(double degrees);

  /**
   *@brief Makes the robot turn to a target point given by the user. 
   *@param turn_control the user PID controller.
   *@param point  The target point in inches.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_to_point(PID& turn_control, std::vector<double> point); 

   /**
   *@brief Makes the robot turn to a target point given by the user. 
   *@param point  The target point in inches.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_to_point(std::vector<double> point); 

  /**
   *@brief Makes the robot turn to a target point given by the user. 
   *@param turn_control the user PID controller.
   *@param point  The target point in okapi units.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_to_point(PID& turn_control, std::vector<okapi::QLength> point); 

   /**
   *@brief Makes the robot turn to a target point given by the user. 
   *@param point  The target point in okapi units.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void turn_to_point(std::vector<okapi::QLength> point); 

  /**
   *@brief Makes the robot turn to a certain orientation using a user-defined PID controller, blocking one side of the drive train, making a 'swing'.
   *@param swing_control the user PID controller.
   *@param swing_direction what side do you want to block?
   *@param target_orientation the target orientation in degrees.
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_absolute(PID& swing_control, lightning::swing_direction_e_t swing_direction, double target_orientation, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain orientation using a user-defined PID controller, blocking one side of the drive train, making a 'swing'.
   *@param swing_control the user PID controller.
   *@param swing_direction what side do you want to block?
   *@param target_orientation the target orientation in okapi units.
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_absolute(PID& swing_control, lightning::swing_direction_e_t swing_direction, okapi::QAngle target_orientation, const int opposite_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain orientation using the SwingPID controller, blocking one side of the drive train, making a 'swing'.
   *@param swing_direction what side do you want to block?
   *@param target_orientation the target orientation in degrees.
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_absolute(lightning::swing_direction_e_t swing_direction, double target_orientation, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain orientation using the SwingPID controller, blocking one side of the drive train, making a 'swing'.
   *@param swing_direction what side do you want to block?
   *@param target_orientation the target orientation in okapi units.
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_absolute(lightning::swing_direction_e_t swing_direction, const okapi::QAngle target_orientation, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain amount of degrees using a user-defined PID controller, blocking one side of the drive train, making a 'swing'.
   * if the robot needs to turn right or negative if the robot needs to turn left.
   *@param swing_control the user PID controller.
   *@param swing_direction what side do you want to block?
   *@param degrees how many degrees would turn?
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, double degrees, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain amount of degrees using a user-defined PID controller, blocking one side of the drive train, making a 'swing'.
   * if the robot needs to turn right or negative if the robot needs to turn left.
   *@param swing_control the user PID controller.
   *@param swing_direction what side do you want to block?
   *@param angle how many degrees/radians would turn?
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, okapi::QAngle angle, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain amount of degrees using the SwingPID controller, blocking one side of the drive train, making a 'swing'.
   * if the robot needs to turn right or negative if the robot needs to turn left.
   *@param swing_direction what side do you want to block?
   *@param degrees how many degrees would turn?
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_relative(lightning::swing_direction_e_t swing_direction, double degrees, const int opposide_speed_rpm = 0);

  /**
   *@brief Makes the robot turn to a certain amount of degrees using the SwingPID controller, blocking one side of the drive train, making a 'swing'.
   * if the robot needs to turn right or negative if the robot needs to turn left.
   *@param swing_direction what side do you want to block?
   *@param angle how many degrees/radians would turn?
   *@param opposide_speed_rpm you could add power to the blocked side, however is zero by default.
   *@note the turning direction is determinated depending of which direction means less travel.
   */
  void swing_turn_relative(lightning::swing_direction_e_t swing_direction, okapi::QAngle angle, const int opposide_speed_rpm = 0);

  /**
   *@brief Sets the robot´s absolute orientation.
   *@param current_orientation the current orientation in okapi units.
   */
  void set_orientation(okapi::QAngle current_orientation);
  
  /**
   *@brief Sets the voltage limit for a motor in the motor group in millivolts.
   *@param left_side_voltage_limit left side voltage limit 
   *@param right_side_voltage_limit right side voltage limit
   */
  void set_voltage_limit(const std::int32_t left_side_voltage_limit, const std::int32_t right_side_voltage_limit); 
  
  /**
   *@brief Sets the voltage limit for a motor in the motor group in millivolts.
   *@param left_side_current_limit left side current limit 
   *@param right_side_current_limit right side current limit
   *@note default 2500 ma
   */
  void set_current_limit(const std::int32_t left_side_current_limit, const std::int32_t right_side_current_limit); 

  /**
   * @brief Sets the chassis motors brake mode.
   * @param mode The motor_brake_mode_e_t to set for the motors
   *
   */
  void set_brake(const pros::motor_brake_mode_e_t mode);

  /**
   * @brief Sets the chassis wheels diameter.
   * @param wheels_diameter The wheels´s diameter.
   */
  void set_wheels_diameter(const float _wheels_diameter);

  /**
   * @brief Sets the distance between lateral wheels to the center of rotation
   *
   *
   * @param distance
   */
  void set_center_distance(const float distance);

  /**
   * @brief Sets the drivetrain cartridge.
   *
   * @param gearset
   *        The gearset.  (E_MOTOR_GEARSET_36 = 0,  // 36:1, 100 RPM, Red gear set
   *                       E_MOTOR_GEAR_RED = E_MOTOR_GEARSET_36, // 36:1, 100 RPM, Red gear set
   *                       E_MOTOR_GEAR_100 = E_MOTOR_GEARSET_36, // 36:1, 100 RPM, Red gear set
   *                       E_MOTOR_GEARSET_18 = 1,  // 18:1, 200 RPM, Green gear set
   *                       E_MOTOR_GEAR_GREEN = E_MOTOR_GEARSET_18, // 18:1, 200 RPM, Green gear set
   *                       E_MOTOR_GEAR_200 = E_MOTOR_GEARSET_18, // 18:1, 200 RPM, Green gear set
   *                       E_MOTOR_GEARSET_06 = 2,  // 6:1, 600 RPM, Blue gear set
   *                       E_MOTOR_GEAR_BLUE  = E_MOTOR_GEARSET_06, // 6:1, 600 RPM, Blue gear set
   *                       E_MOTOR_GEAR_600 = E_MOTOR_GEARSET_06, // 6:1, 600 RPM, Blue gear set)
   *
   */
  void set_gearing(const pros::motor_gearset_e_t gearset);

  /**
   * @brief Sets the chassis´s gear ratio
   * @param _gear_ratio Is the result of Driven/Driving, Drive:Driving
   * @note speed is equal to = rpm/ gear ratio.  And torque is equal to = torque* gear_ratio
   */
  void set_gear_ratio(const float _gear_ratio);

  /**
   * @brief  Sets the maximum chassis velocity (RPM)
   * @param _max_rpm The maximum chassis RPM
   * @note May you want to test "auto_set_max_actual_vel" function to know this value and then
   * set the max actual velocity with this function.
   */
  void set_max_rpm(const float _max_rpm = 0);

  /**
   * @brief  Sets the maximum chassis lineal velocity distance/seconds
   * @param _max_vel The maximum robot velocity
   * @note May you want to test "auto_set_max_actual_vel" function to know this value and then
   * set the max velocity with this function.
   */
  void set_max_velocity(const float _max_vel = 0);

  /**
   * @brief Sets the maximum chassis acceleration distance/seconds^2
   * @param _max_accel The maximun robot acceleration
   * @note May you want to test "" function to know this value and the set the max acceleration with this function
   */
  void set_max_accel(const float _max_accel = 0);

  /**
   * @brief Runs a test (your bot would runs in a straight line) to set the maximun real robot lineal velocity
   * @param time_msec The time in miliseconds that robot would run  at maximum velocity to make the math.
   * @param scale The scale of velocity (.8,.9) would be nice.
   * @note The function is useful when you want to know the real maximun velocity of your robot-
   * Be careful using this function, if the time is to much your robot may crash with the field.
   *
   */
  void auto_set_max_velocity_with_position(const int time_msec, const float scale);

  void autoset_max_vel_accel(const int time_msec, const float scale);

  /**
   * @brief Runs a test (your bot would runs in a straight line) to set the maximun real robot lineal velocity
   * @param time_msec The time in miliseconds that robot would run  at maximum velocity to make the math.
   * @param scale The scale of velocity (.8,.9) would be nice.
   * @note The function is useful when you want to know the real maximun velocity of your robot-
   * Be careful using this function, if the time is to much your robot may crash with the field.
   *
   */
  void auto_set_max_rpm(const int time_msec, const float scale);

  /**
   *@brief Stops the chassis
   */
  void stop();

  /**
   * @brief Drives the chassis in arcade configuration
   * @param control The control
   * @param arcade The tank_op_arcade_e_t to set for the chassis
   * @param power_rate The rate for the forward and backwards movements
   * @param turn_rate The rate for the right and left turns
   * @note arcade is a lightning::tank_op_arcade_e_t
   */
  void arcade(pros::Controller& control, const lightning::tank_op_arcade_e_t arcade = lightning::E_TANK_OP_ARCADE_LEFT,
              const float power_rate = 1, const float turn_rate = 1);

  void arcade_exponential(pros::Controller& control, const lightning::tank_op_arcade_e_t arcade, int n_x, int n_y);

  /**
   * @brief Drives the chassis in tank configuration
   * @param control The control
   */
  void tank(pros::Controller& control);

 public:
  
  lightning::tank_odom_e_t get_odometry_configuration() const ; 
  
  /**
    *@brief Gets the odometry rotation in degrees.  
    * The odometry rotation is needed for ROTATED configurations like: ADI_TWO_ROTATED_ODOM and ROTATION_TWO_ROTATED_ODOM
   */
  double get_odometry_rotation() const ; 

  /**
   * @brief Gets the current pose (the position and orientation vector)
   * @return The pose vector
   */
  std::vector<double> get_pose() const ;

  /**
   *@brief get the current index of a path when the robot its following it.
   *@return the path index.
   */
  int get_current_index() const ;

  /**
   * @brief Gets the current position (x,y)
   * @return The position vector.
   */
  std::vector<double> get_position() const ;

  /**
   *@brief Gets the forwardtracker position value.
   *@return the forwardtracker position.
   */
  double get_ForwardTracker_position() ;

  /**
   *@brief Gets the Sidewaystracker position value.
   *@return the sidewaystracker position.
   */
  double get_SideWays_position() ;

  /**
   * @brief Gets the current orientation (theta)
   * @return The orientation in degrees.
   */
  double get_orientation() const;

  /**
   * @brief Gets the current x coordinate
   * @return The x coordinate in inches.
   */
  double get_x() const;

  /**
   * @brief Gets the current y coordinate
   * @return The y coordinate in inches.
   */
  double get_y() const;

 private:
  /**
   *@brief Gets the average position from a motor group.
   *@return the average motor position.
   */
  double get_motor_group_position(pros::MotorGroup& motor_group) ;

 public:
  /**
   *@brief Gets the current drawn by the left side motors in mA.
   *@param get_all_motors If you want to get the average current draw, set to true. However,
   if you want to get the current draw of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return return the current drawn by the left side in mA.
   */
  double get_left_side_current_draw(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the current drawn by the right side's motors in mA.
   *@param get_all_motors If you want to get the average current draw, set to true. However,
   if you want to get the current draw of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return return the current drawn by the right side in mA.
   */
  double get_right_side_current_draw(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the efficiency of left side's motors in percent.
   *@param get_all_motors If you want to get the average efficiency, set to true. However,
   if you want to get the efficiency of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return return the efficiency of left side´s motors in percent.
   */
  double get_left_side_efficiency(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the efficiency of right side's motors in percent.
   *@param get_all_motors If you want to get the average efficiency, set to true. However,
   if you want to get the efficiency of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return return the efficiency of right side´s motors in percent.
   */
  double get_right_side_efficiency(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the power of left side's motors in Watts.
   *@param get_all_motors If you want to get the average power, set to true. However,
   if you want to get the power of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return return the power of left side´s motors in Watts.
   */
  double get_left_side_power(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
 *@brief Gets the power of right side's motors in Watts.
 *@param get_all_motors If you want to get the average power, set to true. However,
 if you want to get the power of a specific motor, set to false.
 *@param index Optional parameter. The zero indexed index of the motor in the right side.
 *@return return the power of right side´s motors in Watts.
 */
  double get_right_side_power(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the temperature of left side's motors in degrees Celsius.
   *@param get_all_motors If you want to get the average temperature, set to true. However,
   if you want to get the temperature of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return return the temperature of left side´s motors in degrees Celsius.
   */
  double get_left_side_temperature(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
  *@brief Gets the temperature of right side's motors in degrees Celsius.
  *@param get_all_motors If you want to get the average temperature, set to true. However,
  if you want to get the temperature of a specific motor, set to false.
  *@param index Optional parameter. The zero indexed index of the motor in the right side.
  *@return return the temperature of right side´s motors in degrees Celsius.
  */
  double get_right_side_temperature(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
  *@brief Gets the torque of left side's motors in Newton Meters (Nm).
  *@param get_all_motors If you want to get the average torque, set to true. However,
  if you want to get the torque of a specific motor, set to false.
  *@param index Optional parameter. The zero indexed index of the motor in the left side.
  *@return return the torque of left side´s motors in Newton Meters (Nm).
  */
  double get_left_side_torque(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the torque of right side's motors in Newton Meters (Nm).
   *@param get_all_motors If you want to get the average torque, set to true. However,
   if you want to get the torque of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return return the torque of right side´s motors in Newton Meters (Nm).
   */
  double get_right_side_torque(const bool get_all_motors, const std::uint8_t index = 0) const;
  
   /**
   *@brief Gets the voltage of left side's motors in millivolts.
   *@param get_all_motors If you want to get the average voltage, set to true. However,
   if you want to get the voltage of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return return the voltage of left side´s motors in millivolts.
   */
  std::int32_t get_left_side_voltage(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the voltage of right side's motors in millivolts.
   *@param get_all_motors If you want to get the average voltage, set to true. However,
   if you want to get the voltage of a specific motor, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return return the voltage of right side´s motors in millivolts.
  */
  std::int32_t get_right_side_voltage(const bool get_all_motors, const std::uint8_t index = 0) const;
  
  /**
   *@brief Checks if left side is drawing over its current limit.
   *@param get_all_motors Set to true if you want to check if the entire left side is over current. However,
   if you want to check if a specific motor is over current, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return 1 if the motor's current limit is being exceeded and 0 if the current limit is not exceeded
  */
  std::int32_t left_side_is_over_current(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Checks if right side is drawing over its current limit.
   *@param get_all_motors Set to true if you want to check if the entire right side is over current. However,
   if you want to check if a specific motor is over current, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return 1 if the motor's current limit is being exceeded and 0 if the current limit is not exceeded
  */
  std::int32_t right_side_is_over_current(const bool get_all_motors, const std::uint8_t index = 0) const;
  
  /**
   *@brief Gets the temperature limit flag for the left side.
   *@param get_all_motors Set to true if you want to check if the entire left side is over temperature. However,
   if you want to check if a specific motor is over temperature, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the left side.
   *@return 1 if the temperature limit is exceeded and 0 if the temperature is below the limit
  */
  std::int32_t left_side_is_over_temp(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the temperature limit flag for the right side.
   *@param get_all_motors Set to true if you want to check if the entire right side is over temperature. However,
   if you want to check if a specific motor is over temperature, set to false.
   *@param index Optional parameter. The zero indexed index of the motor in the right side.
   *@return 1 if the temperature limit is exceeded and 0 if the temperature is below the limit
  */
  std::int32_t right_side_is_over_temp(const bool get_all_motors, const std::uint8_t index = 0) const;

  /**
   *@brief Gets the drive-train average mposition in degrees.
   *@return return the average motor position in degrees.
   */
  double get_average_motors_position_deg();

  /**
   *@brief Gets the left side of the drive-train average position in degrees.
   *@return return the average motor position in degrees.
   */
  double get_left_position_deg();

  /**
   *@brief Gets the right side of the drive-train average position in degrees.
   *@return return the average motor position in degrees.
   */
  double get_right_position_deg();

  /**
   *@brief Gets the drive train average position in inches.
   *@return return the average motor position in inches.
   */
  double get_average_motors_position_inches() ;

  /**
   *@brief Gets the left side  of the drive train average position in inches.
   *@return return the average motor position in inches.
   */
  double get_left_position_inches();

  /**
   *@brief Gets the right side  of the drive train average position in inches.
   *@return return the average motor position in inches.
   */
  double get_right_position_inches();

  /**
   * @brief Gets the current average chassis output velocity (RPM) between the left and right sides.
   *
   * This function calculates and returns the average rotational speed in RPM of the base motors.
   *
   * @return double The average velocity in RPM.
   *
   * @note This velocity is the average of the base motors' output.
   */
  double get_actual_rpm() const ;

  /**
   * @brief Gets the current chassis lineal velocity
   * @return The maximum Drive train lineal velocity.
   */
  double get_actual_velocity() const ;

  /**
   * @brief Gets maximum robot RPM.
   * @return The maximum Drive train RPM.
   */
  double get_max_rpm() const ;

  /**
   * @brief Gets the maximum robot lineal velocity.
   * @return The maximum robot lineal velocity.
   */
  double get_max_velocity() const ;

  /**
   * @brief Gets the maximum robot lineal acceleration.
   * @return The maximum robot lineal acceleration.
   */
  double get_max_accel() const ;

  /**
   * @brief Gets the robot wheels diameter.
   * @return The robot wheels diameter.
   * */
  float get_wheels_diameter() const;

  /**
   * @brief Gets the center distance
   * @return The robot center distance
   */
  float get_center_distance() const;

  /**
   * @brief Gets the robot motors gearing
   * @return The current internal gear ratio of the motors.
   * @note
   * [0] ->36:1, 100 RPM, Red gear set
   * [1] ->18:1, 200 RPM, Green gear set
   * [2] -> 6:1, 600 RPM, Blue gear set
   */
  pros::motor_gearset_e get_gearing() const;

  /**
   * @brief Gets the units for recording position by the chassis motors
   * @return Motors encoder units
   */
  pros::MotorUnits get_encoders_units() const ;

  /**
   * @brief Gets the current brake mode
   * @return Motors brake
   */
  pros::MotorBrake get_actual_brake() const ;

  /**
   * @addtogroup Gets the chassis gear ratio
   * @return the result of the division of Driven/Driving
   */
  float get_gear_ratio() const;

  /**
   * @brief Resets the position, orientation, tracking wheels value of the robot
   */
  void reset_odometry();

  /**
   *@brief Reset the IMU.
   */
  void reset_IMU();

  /**
   *@brief tares the integrated encoders from the drive train motors.
   */
  void tare_motors_position();
};
}  // namespace lightning
