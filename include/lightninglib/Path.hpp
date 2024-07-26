/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include <iostream>
#include <vector>

namespace lightning {
class Path {
 private:
  double max_lineal_velocity;

  std::vector<std::vector<double>> path;

  int16_t size;

  std::vector<double> curvature_vector;
  std::vector<double> distance_vector;

  std::vector<double> max_lineal_velocities_vector;
  std::vector<double> target_lineal_velocities;

  std::vector<double> target_angular_velocities;

  std::vector<double> orientation_vector;

  int spacing;

  double a;
  double b;
  double tolerance;

  bool reverse;

 private:  // States of the path construction.
  bool raw = false;
  bool injected = false;
  bool smoothed = false;
  bool ready = false;

 private:
  /**
   * @brief Formula to get the curvature given three points (Q,P,R).
   * @param Q firt point.
   * @param P second point.
   * @param R third point.
   * @return the curvate in radians.
   */
  double curvature(const std::vector<double> &Q, const std::vector<double> &P,
                   const std::vector<double> &R);

  /**
   * @brief Formula to get the distance btw two points using the index of the
   * path.
   * @param index the index of the path.
   * @return the distance that exist (inches).
   */
  double distance_btw_two_pts(const int index);

  /**
   * @brief Calculates the curvature vector.
   * @note curvature vector is the curvature that exist in each point in the path.
   */
  void calc_curvature_vector();

  /**
   * @brief Calculates the distance vector.
   */
  void calc_distance_vector();

  /**
   * @brief Calculates the maximum velocities in each point.
   */
  void calc_maximum_lineal_velocities(const float k = 3.5);

  /**
   * @brief Calculates the targets velocities of the path in each point.
   */
  void calc_target_lineal_velocities();

 public:
  /**
   * @brief Constructor that initializes a Path object with specified parameters.
   *
   * This constructor initializes a Path object using the provided coordinates,
   * reverse flag, and spacing value.
   *
   * @param X a vector that includes the x coordinates (inches) of each point.
   * @param Y a vector that includes the y coordinates (inches) of each point.
   * @param _reverse a boolean flag indicating if the path should be reversed. True if reversed.
   * @param _spacing the space that would exist between each point for the injection method.
   * @note For this constructor the B constant is setted to .75 and the tolerance a value of .001
   */
  Path(const std::vector<double> &X, const std::vector<double> &Y,
       bool _reverse, int _spacing);

  /**
   * @brief Constructor that initializes a Path object with FULL parameters.
   *
   * This constructor initializes a Path object using the provided coordinates,
   * reverse flag, and spacing value and with B and Tolerance constants.
   *
   * @param X a vector that includes the x coordinates (inches) of each point.
   * @param Y a vector that includes the y coordinates (inches) of each point.
   * @param _reverse a boolean flag indicating if the path should be reversed. True if reversed.
   * @param _spacing the space that would exist between each point for the injection method.
   * @param B weight_smooth constant, larger b means a smoother path, a value between .75 and .98 works well.
   * @param Tolerance it is the tolerance, a value of .001 works pretty well
   */
  Path(const std::vector<double> &X, const std::vector<double> &Y,
       bool _reverse, int _spacing, const double B, const double Tolerance);

  Path(const Path &other) = delete;

  /**
   *@brief Destroys the Path object
   */
  ~Path() = default;

 public:
  /**
   * @brief Overload of the << operator for the Path class.
   *
   * This friend function allows the Path object to be output to an output stream.
   *
   * @param os the output stream to which the Path object is written.
   * @param path the Path object to be written to the output stream.
   * @return std::ostream& The output stream after the Path object has been written.
   */
  friend std::ostream &operator<<(std::ostream &os, const Path &path);

 public:
  /**
   * @brief Sets the maximum velocity (inches/second) for the path .
   * @param velocity the max velocity (inches/second).
   */
  void set_max_lineal_velocity(double velocity);

  /**
   * @brief Sets if the path is reverse.
   *
   *
   * @param _is_reverse your path it is reverse?
   */
  void set_reverse(bool _is_reverse);

  /**
   * @brief Injects point to the current path.
   */
  void inject_points(void);

  /**
   * @brief Smooths the current path.
   */
  void smoother(void);

  /**
   * @brief makes all the calculations that need to calculates
   * the target velocities.
   * @note is neccesary to set the max velocity first.
   * @param K it is constant, how slow you want the robot to go around turns.
   */
  void make_calcs(const float k);

  /**
   * @brief Calculates the orientation allong the path.
   * @param offset the offset, if you want to set an offset.
   * @note The orientation is the angle between the points.
   */
  void calc_orientation(const float offset);

  /**
   * \brief Calculates the target angular velocities.
   */
  void calc_target_angular_velocities();

  /**
   * @brief Upgrades the path using the injecting and smoothing algorithm.
   *
   */
  void upgrade();

  /**
   * @brief Gets the curvature vector.
   *
   * @return a new vector with all the curvatures.
   */
  std::vector<double> get_curvature_vector() const;

  /**
   * @brief Gets the distance vector.
   * @return a new vector with the distance between each point.
   */
  std::vector<double> get_distance_vector() const;

  /**
   * @brief Gets the distance vector.
   * @return a new vector with the maximum lineal velocities in each point.
   */
  std::vector<double> get_maximum_lineal_velocities() const;

  /**
   * @brief Gets the target lineal velocities vector.
   * @return a new vector with the target lineal velocity in each point.
   */
  std::vector<double> get_target_lineal_velocities() const;

  /**
   * @brief Gets the orientation vector.
   * @return a new vector filled with the orientation target.
   */
  std::vector<double> get_orientation_vector() const;

  /**
   *@brief Gets the target angular velocities vector.
   *@return a new vector filled with the target angular velocities.
   */
  std::vector<double> get_target_angular_velocities() const;

  /**
   *@brief Gets the path size.
   *@return path size.
   */
  int16_t get_size() const;

  /**
   * @brief Retrieves a point given an index.
   *
   * This method returns the coordinates of a point at the specified index in the path.
   *
   * @param index the index of the point to retrieve.
   * @return std::vector<double> A vector containing the x and y coordinates of the point.
   */
  std::vector<double> get_point_at(const int index) const;

  /**
   * @brief Retrieves the x coordinate of a point given an index.
   *
   * This method returns the x coordinate of the point at the specified index in the path.
   *
   * @param index The index of the point to retrieve the x coordinate from.
   * @return the x coordinate of the point.
   */
  double get_x_at(const int index) const;

  /**
   * @brief Retrieves the y coordinate of a point given an index.
   *
   * This method returns the y coordinate of the point at the specified index in the path.
   *
   * @param index The index of the point to retrieve the y coordinate from.
   * @return the y coordinate of the point.
   */
  double get_y_at(const int index) const;

  /**
   * @brief Retrieves the target linear velocity at a given index.
   *
   * This method returns the target linear velocity at the specified index in the path.
   *
   * @param index The index of the point to retrieve the target linear velocity from.
   * @return the target linear velocity at the specified index.
   */
  double get_target_lineal_velocity_at(const int index) const;

  /**
   *@brief Gets the maximum lineal velocity of the path.
   *@return the maximum velocity.
   */
  double get_maximum_lineal_velocity() const;

  /**
   *@brief Retrieves the orientation (theta) at a given index
   *@param index the index of the point to retrieve the orientation(theta)
   *@return the theta at the specified index.
   */
  double get_theta_at(const int index) const;

  /**
   *@brief Retrieves the target angular velocity at a given index.
   *@param index the index of the point to retrieve the target angular velocity.
   *@return the theta at the specified index.
   */
  double get_target_angular_velocity_at(const int index) const;

  /**
   * @brief Checks if the path is raw.
   * @return 1 if its raw, 0 if it is not.
   */
  bool is_raw() const;

  /**
   *@brief Checks if the path was injected.
   *@return 1 if was injected, 0 if was not.
   */
  bool is_inject() const;

  /**
   *@brief Checks if the path it is smooth.
   *@return 1 if it is smooth, 0 if it is not.
   */
  bool is_smooth() const;

  /**
   *@brief Checks if the path it is ready.
   *@return 1 if it is ready, 0 if it is not.
   */
  bool is_ready() const;

  /**
   *@brief Checks if the path it is reversed.
   *@return 1 if it is reversed, 0 if it is not.
   */
  bool is_reverse() const;
};

}  // namespace lightning