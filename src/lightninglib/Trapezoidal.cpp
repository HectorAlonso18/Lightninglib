/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/Trapezoidal.hpp"
#include "pros/rtos.hpp"

namespace lightning {
TrapezoidalProfile::TrapezoidalProfile(float max_velocity,
                                       float max_acceleration)
    : max_velocity(max_velocity), max_acceleration(max_acceleration),
      velocities(0), size(0), accel_time(0), accel_distance(0),
      desaccel_distance(0), velocity_constant_distance(0), total_time(0),
      ready(false) {}

std::ostream &operator<<(std::ostream &os, const TrapezoidalProfile &profile) {
  for (int i = 0; i < profile.size; i++) {
    os << "\n Velocity at [" << i << "] " << profile.velocities[i];
    pros::delay(10);
  }

  return os;
}

void TrapezoidalProfile::update(float target, float sample_time_sec) {

  accel_time = max_velocity / max_acceleration;
  accel_distance = 0.5 * max_acceleration * accel_time * accel_time;
  desaccel_distance = accel_distance;
  velocity_constant_distance =
      std::abs(target) - accel_distance - desaccel_distance;
  total_time = 2 * accel_time + (velocity_constant_distance / max_velocity);

  const int total_steps = static_cast<int>(total_time / sample_time_sec);

  this->velocities = std::vector<float>(); // Asigna un nuevo vector vacío
  this->size = 0;

  float current_time = 0;

  for (int step = 0; step < total_steps; step++) {
    float current_velocity;

    if (current_time < accel_time) {
      current_velocity = max_acceleration * current_time;
    } else if (current_time <
               accel_time + velocity_constant_distance / max_velocity) {
      current_velocity = max_velocity;
    } else if (current_time <
               2 * accel_time + velocity_constant_distance / max_velocity) {
      float desaccel_time =
          current_time - accel_time - velocity_constant_distance / max_velocity;
      current_velocity = max_velocity - max_acceleration * desaccel_time;
    } else {
      current_velocity = 0;
    }

    if (target < 0) {
      current_velocity *= -1;
    }

    this->velocities.emplace_back(current_velocity);
    current_time += sample_time_sec;
  }

  ready = true;
  this->size = this->velocities.size();
}

bool TrapezoidalProfile::is_ready() const { return this->ready; }

void TrapezoidalProfile::reset() {

  this->velocities = std::vector<float>(); // Asigna un nuevo vector vacío
  this->size = 0;

  ready = false;
}

void TrapezoidalProfile::set_parameters(const float max_velocity,
                                        const float max_acceleration) {
  this->max_velocity = max_velocity;
  this->max_acceleration = max_acceleration;
}

void TrapezoidalProfile::set_max_velocity(const float max_velocity) {
  this->max_velocity = max_velocity;
}

void TrapezoidalProfile::set_max_acceleration(const float max_acceleration) {
  this->max_acceleration = max_acceleration;
}

float TrapezoidalProfile::get_velocity_at(int index) const {
  if (index > this->size - 1) {
    index = this->size - 1;
  }
  return velocities[index];
}

float TrapezoidalProfile::get_max_velocity() const {
  return this->max_velocity;
}

float TrapezoidalProfile::get_max_acceleration() const {
  return this->max_acceleration;
}

float TrapezoidalProfile::get_accel_time() const { return this->accel_time; }

float TrapezoidalProfile::get_accel_distance() const {
  return this->accel_distance;
}

float TrapezoidalProfile::get_desaccel_distance() const {
  return this->desaccel_distance;
}

float TrapezoidalProfile::get_velocity_constant_distance() const {
  return this->velocity_constant_distance;
}

float TrapezoidalProfile::get_time_to_arrived() const {
  return this->total_time;
}

std::vector<float> TrapezoidalProfile::get_velocities() const {
  return this->velocities;
}

std::size_t TrapezoidalProfile::get_size() const { return this->size; }
} // namespace lightning