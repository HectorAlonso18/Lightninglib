/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

#include <cmath>
#include <vector>

#define M_PI 3.14159265358979323846

/**
 * @brief Sign function.
 * @tparam T
 * @param num
 * @return Sign, -1 if its negative or 1 if its positive.
 */
template <typename T>
T sign(const T &num) { return (num >= 0) ? 1 : -1; }

/**
 * @brief Translate degrees to radians.
 * @tparam T
 * @param num
 * @return Angle in radians.
 */
template <typename T>
T to_rad(const T &num) { return num * M_PI / 180; }

/**
 * @brief Translate radians to degrees.
 * @tparam T
 * @param num
 * @return Angle in degrees.
 */
template <typename T>
T to_degrees(const T &num) { return (num * 180) / M_PI; }

/**
 * @brief Put angle in a 0-360 degrees range.
 * @tparam T
 * @param degrees
 * @return The angle in range.
 */
template <typename T>
T reduce_angle_0_to_360(T degrees) {
  while (!(degrees >= 0 && degrees <= 360)) {
    degrees = degrees < 0     ? degrees += 360
              : degrees > 360 ? degrees -= 360
                              : degrees;
  }

  return (degrees);
}

/**
 * @brief Put angle in a -180 -180 degrees range.
 * @tparam T
 * @param degrees
 * @return the angle in range.
 */
template <typename T>
T reduce_angle_180_to_180(T degrees) {
  while (!(degrees >= -180 && degrees <= 180)) {
    degrees = degrees < -180  ? degrees += 360
              : degrees > 180 ? degrees -= 360
                              : degrees;
  }

  return (degrees);
}

/**
 * @brief Gets the angle in degrees between two points.
 * @tparam T1
 * @tparam T2
 * @param current
 * @param target
 * @return the angle in degrees.
 */
template <typename T1, typename T2>
auto get_angle_btw_points(const std::vector<T1> &current,
                          const std::vector<T2> &target) {
  // Calculamos un diferencial de Y y X
  // dy = Y2 - Y1
  double dy = target[1] - current[1];
  // dx= X2 -X1
  double dx = target[0] - current[0];

  // Calculamos el angulo, utilizando arco tangente, pero con el plano desfasado
  // para que concuerda con el del robot

  double Angle = to_degrees(atan2(dx, dy));

  // El resultado lo ponemos en un rango de 0-360
  Angle = reduce_angle_0_to_360(Angle);

  return Angle;
}

/**
 * @brief Gets the distance between two points using Pythagoras.
 * @tparam T1
 * @tparam T2
 * @param p1 Current
 * @param p2 Target
 * @return Distance.
 */
template <typename T1, typename T2>
auto distance_btw_points(const std::vector<T1> &p1, const std::vector<T2> &p2) {
  return std::hypot(p2[0] - p1[0], p2[1] - p1[1]);
}

/**
 * @brief Convert a rpm velocity to a linear velocity (distance/seconds).
 * @tparam T1
 * @tparam T2
 * @param rpm
 * @param wheel_diameter
 * @return velocity converted.
 */
template <typename T1, typename T2>
auto rpm_to_linear(const T1 &rpm, const T2 &wheel_diameter) {
  return rpm * ((M_PI * wheel_diameter) / 60);
}

/**
 * @brief Convert a lineal velocity (distance/seconds) to a rpm.
 * @tparam T1
 * @tparam T2
 * @param lineal_velocity distance/seconds
 * @param wheel_diameter
 * @return velocity converted.
 */
template <typename T1, typename T2>
auto linear_to_rpm(const T1 &lineal_velocity, const T2 &wheel_diameter) {
  return lineal_velocity * (60 / (M_PI * wheel_diameter));
}

/**
 * @brief Swaps the first two elements of a vector.
 *
 * @tparam T1 Type of the elements in the vector.
 * @param a The input vector.
 * @return std::vector<T1> A vector with the first two elements swapped.
 */
template <typename T1>
std::vector<T1> swap_vector(const std::vector<T1> &a) {
  return {a[1], a[0]};
}

/**
 * @brief Adds two vectors element-wise.
 *
 * @tparam T1 Type of the elements in the vectors.
 * @param a The first input vector.
 * @param b The second input vector.
 * @return std::vector<T1> A vector with each element being the sum of the corresponding elements of a and b.
 */
template <typename T1>
std::vector<T1> vector_add(const std::vector<T1> &a, const std::vector<T1> &b) {
  return {a[0] + b[0], a[1] + b[1]};
}

/**
 * @brief Subtracts the second vector from the first vector element-wise.
 *
 * @tparam T1 Type of the elements in the vectors.
 * @param a The first input vector.
 * @param b The second input vector.
 * @return std::vector<T1> A vector with each element being the difference of the corresponding elements of a and b.
 */
template <typename T1>
std::vector<T1> vector_sub(const std::vector<T1> &a, const std::vector<T1> &b) {
  return {a[0] - b[0], a[1] - b[1]};
}

/**
 * @brief Computes the dot product of two vectors.
 *
 * @tparam T1 Type of the elements in the vectors.
 * @param a The first input vector.
 * @param b The second input vector.
 * @return auto The dot product of the vectors.
 */
template <typename T1>
auto vector_dot(const std::vector<T1> &a, const std::vector<T1> &b) {
  return a[0] * b[0] + a[1] * b[1];
}

/**
 * @brief Multiplies each element of a vector by a scalar.
 *
 * @tparam T1 Type of the elements in the vector.
 * @tparam T2 Type of the scalar.
 * @param a The input vector.
 * @param b The scalar value.
 * @return std::vector<T1> A vector with each element multiplied by the scalar.
 */
template <typename T1, typename T2>
std::vector<T1> vector_mult(const std::vector<T1> &a, const T2 b) {
  return {a[0] * b, a[1] * b};
}
