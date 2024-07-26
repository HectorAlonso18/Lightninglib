/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include <iostream>
#include <vector>

namespace lightning {
class TrapezoidalProfile {
 private:
  std::vector<float> velocities;
  float max_velocity;
  float max_acceleration;
  std::size_t size;

  float accel_time;
  float accel_distance;
  float desaccel_distance;
  float velocity_constant_distance;
  float total_time;

  float ready;

 public:
  /**
   *@brief Trapezoidal profile constructor. Create a new trapezoidal profile.
   *@param max_velocity what would be the maximum profile velocity in inches/second?
   *@param max_acceleration what would be the maximum profile accleration in inches/second^2?
   */
  TrapezoidalProfile(float max_velocity, float max_acceleration);
  ~TrapezoidalProfile() = default;

  friend std::ostream &operator<<(std::ostream &os,
                                  const TrapezoidalProfile &profile);

  /**
   *@brief resets the trapezoidal profile
   *@note the functions erases and clean all the profile.
   */
  void reset();

  /**
   *@brief updates the trapezoidal profile giving the target and the sample time.
   *@param target how many distance you would travel in inches.
   *@param sample_time_sec the update rate in secconds.
   */
  void update(const float target, float sample_time_sec);

  /**
   *@brief checks if the profile its ready to use.
   */
  bool is_ready() const;

  /**
   *@brief sets the main parameters for the profile.
   *@param max_velocity what would be the maximum profile velocity (inches/second)?
   *@param max_acceleration what would be the maximum profile accleration (inches/second^2)?
   */
  void set_parameters(const float max_velocity, const float max_acceleration);

  /**
   *@brief sets the maximum profile velocity.
   *@param max_velocity what would be the maximum profile velocity(inches/second)?
   */
  void set_max_velocity(const float max_velocity);

  /**
   *@brief sets the maximum profile acceleration.
   *@param max_acceleration what would be the maximum profile acceleration (inches/second^2)?
   */
  void set_max_acceleration(const float max_acceleration);

  /**
   *@brief gets the desired velocity giving a point.
   *@param index the profile index.
   *@return the desired velocity (inches/second).
   */
  float get_velocity_at(int index) const;

  /**
   *@brief gets the maximum profile velocity.
   *@return the maximum velocity (inches/second).
   */
  float get_max_velocity() const;

  /**
   *@brief gets the maximum profile acceleration.
   *@return the maximum acceleration (inches/second^2).
   */
  float get_max_acceleration() const;

  /**
   *@brief gets the acceleration time.
   *@return the acceleration time (seconds).
   */
  float get_accel_time() const;

  /**
   *@brief gets the acceleration distance (acceleration phase).
   *@return the acceleration distance (inches).
   */
  float get_accel_distance() const;

  /**
   *@brief gets the desacceleration distance (desacceleration phase).
   *@return gets the desacceleration distance (inches).
   */
  float get_desaccel_distance() const;

  /**
   *@brief gets the constant velocity distance (constant acceleration phase).
   *@return gets the constant velocity distance (inches).
   */
  float get_velocity_constant_distance() const;

  /**
   *@brief gets the time to arrive.
   *@return the time to arrive (second).
   */
  float get_time_to_arrived() const;

  /**
   *@brief returns the profile size.
   *@return the current profile size.
   */
  std::size_t get_size() const;

  /**
   *@brief return a vector with the desired velocities using the trapezoidal profile.
   *@return desired velocities vector.
   */
  std::vector<float> get_velocities() const;
};

}  // namespace lightning