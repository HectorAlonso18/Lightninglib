/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

namespace lightning {

// Inspired by JAR TEMPLATE
class OdomTracker {
 private:
  /**
   * @brief Struct for the constants of each tracker.
   */
  struct Tracker {
    float center_distance;
    float position;
  } forward, sideways;

 public:
  float x_position;
  float y_position;
  float orientation_degrees;

  float prev_x_position;
  float prev_y_position;

 public:
  /**
   * @brief Constructor.
   */
  OdomTracker();

  OdomTracker(const OdomTracker &other) = delete;

  /**
   *@brief destroys the OdomTracker object
   */
  ~OdomTracker() = default;

  /**
   *@brief sets the initial position for the odometry system.
   *@param x_position the x coordinate.
   *@param y_position the y coordinate.
   *@param orientation_degrees the orientation in degrees.
   *@param ForwardTracker_position the forward tracker position.
   *@param SidewaysTracker_position  the sideways tracker position.
   */
  void set_position(float x_position, float y_position, float orientation_degrees, float ForwardTracker_position, float SidewaysTracker_position);

  /**
   *@brief updates the odometry system giving the new position from the trackers and orientation
   *@param ForwardTracker_position the forward tracker position.
   *@param SidewaysTracker_position the sideways tracker position.
   *@param orientation_degrees the orientation in degrees.
   */
  void update_position(float ForwardTracker_position, float SidewaysTracker_position, float orientation_degrees);

  /**
   *@brief Sets the physical distances that exist from each tracker to the center point
   *@param ForwardTracker_center_distance the distance between the center point and the forward tracker.
   *@param SidewaysTracker_center_distance the distance between the center point and the sideways tracker.
   */
  void set_physical_distances(float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
};
}  // namespace lightning