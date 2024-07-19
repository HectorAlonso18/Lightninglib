#include "lightninglib/Odom_tracker.hpp"
#include "lightninglib/Math.h"



namespace lightning {
OdomTracker::OdomTracker() {}

void OdomTracker::set_physical_distances(
    float ForwardTracker_center_distance,
    float SidewaysTracker_center_distance) {
  this->forward.center_distance = ForwardTracker_center_distance;
  this->sideways.center_distance = SidewaysTracker_center_distance;
}

void OdomTracker::set_position(float x_position, float y_position,
                               float orientation_degrees,
                               float forward_position,
                               float sideways_position) {

  this->x_position = x_position;                               
  this->y_position = y_position;
  this->orientation_degrees = orientation_degrees;

  this->forward.position = forward_position;
  this->sideways.position = sideways_position;
}

void OdomTracker::update_position(float ForwardTracker_position,
                                  float SidewaysTracker_position,
                                  float orientation_degrees) {


  float forward_delta_position =
      ForwardTracker_position - this->forward.position;
  float sideways_delta_position =
      SidewaysTracker_position - this->sideways.position;
  

  this->forward.position = ForwardTracker_position; 
  this->sideways.position = SidewaysTracker_position; 


  float orientation_rad = to_rad(orientation_degrees);
  float prev_orientation_rad = to_rad(this->orientation_degrees);
  float orientation_delta_rad = orientation_rad - prev_orientation_rad;
  this->orientation_degrees = orientation_degrees;

  float local_X_position;
  float local_Y_position;

  // All of the following lines are pretty well documented in 5225A's Into to
  // Position Tracking Document at
  // http://thepilons.ca/wp-content/uploads/2018/10/Tracking.pdf

  if (orientation_delta_rad == 0) {
    local_X_position = sideways_delta_position;
    local_Y_position = forward_delta_position;
  } else {
    local_X_position = (2 * sin(orientation_delta_rad / 2)) *
                       ((sideways_delta_position / orientation_delta_rad) +
                        sideways.center_distance);

    local_Y_position = (2 * sin(orientation_delta_rad / 2)) *
                       ((forward_delta_position / orientation_delta_rad) +
                        forward.center_distance);
  }

  float local_polar_angle;
  float local_polar_length;

  if (local_X_position == 0 && local_Y_position == 0) {
    local_polar_angle = 0;
    local_polar_length = 0;
  } else {
    local_polar_angle = atan2(local_Y_position, local_X_position);
    local_polar_length =
        sqrt(pow(local_X_position, 2) + pow(local_Y_position, 2));
  }

  float global_polar_angle =
      local_polar_angle - prev_orientation_rad - (orientation_delta_rad / 2);

  float X_position_delta = local_polar_length * cos(global_polar_angle);
  float Y_position_delta = local_polar_length * sin(global_polar_angle);
 
  this->x_position += X_position_delta;
  this->y_position += Y_position_delta;
  
}

} // namespace lightning