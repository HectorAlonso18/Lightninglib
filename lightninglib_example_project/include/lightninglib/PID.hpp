/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

namespace lightning {
class PID {
 protected:
  float kp;
  float ki;
  float kd;

 private:
  float target;

 protected:
  bool first;
  bool arrived;

  float jump_time;
  unsigned int sample_time;

  double current_error;
  double prev_error;
  double delta_error;

  float error_tolerance;
  float derivative_tolerance;

  double integral_raw;
  float integral_zone;
  float integral_power_limit;

  double proportional;
  double integral;
  double derivative;

  float max;

  float scale;

  double output;

  int contador;
  int contador_stop_time;

  float stop_time_msec;

 public:
  /**
   * @brief Build PID object given constants and the sample_time.
   *
   * @param kp
   *        the proportional constant.
   * @param ki
   *        the integral constant.
   * @param kd
   *        the derivative constant.
   *
   * @param sample_time
   *        the sample time of the controller in msec.
   *
   * @param _scale A scaling factor that limits the output of the PID controller.
   *        For example, a value of 0.5 limits the output to 50% of its maximum value.
   */
  PID(const float _kp, const float _ki, const float _kd,
      unsigned int _sample_time, const float _scale);

  /**
   * @brief Copy constructor
   *
   * @param other
   */
  PID(const PID &other);

  /**
   * @brief Destroyer
   *
   */
  ~PID() = default;

 public:
  /**
   * @brief Updates the PID controller
   *
   * @note You should put this function inside of while loop
   * to update the input to the current reading.
   *
   * With that function you will update the proportional, integral, derivative
   * and output value.
   *
   * @param error
   *        the current error (target-input)
   *
   */
  virtual void update(const float error);

 public:
  /**
   * @brief Sets the stop time limit for the PID controller.
   *
   * This function allows the user to set the maximum time limit after which the PID controller output will be set to zero.
   *
   * @param _stop_time_msec The stop time limit in milliseconds. If more than this time elapses,
   *        the PID controller output will be forced to zero.
   */
  void set_stop_time(const float _stop_time_msec);

  /**
   * @brief Sets error tolerance.
   *
   * @note For example: In a distance controller maybe the error tolerance would
   * be .02 inches.
   *
   * @param error_tolerance
   *        The error tolerance for the controller.
   *
   */
  void set_error_tolerance(const float _error_tolerance);

  /**
   * @brief Sets derivative tolerance.
   * @param derivative_tolerance
   *        The derivative tolerance.
   */
  void set_derivative_tolerance(const float _derivative_tolerance);

  /**
   * @brief Sets integral zone.
   * @note  The integral zone is the zone where the intregal will not act.
   * @param _integral_zone
   *        The integral_zone
   */
  void set_integral_zone(const float _integral_zone);

  /**
   * @brief Sets integral power limit.
   * @note The integral power limit would be the highest value of the integral.
   * @param integral_power_limit
   *        The integral power limit.
   */
  void set_integral_power_limit(const float _integral_power_limit);

  /**
   * @brief Sets the jump time limit for the PID controller.
   *
   * @param jump_time The jump time limit in milliseconds.
   *
   * @note When the PID controller is approaching the target, a timer starts. If the timer reaches
   *       the jump time limit, the PID controller operation is halted.
   */
  void set_jump_time(const float _jump_time);

  /**
   * @brief Sets the maximum output for the PID output.
   * @param max
   *        The max value of the output.
   */
  void set_max(const float _max);

  /**
   *@brief Set the scale for the PID controller.
   *@param _scale scaling factor that limits the output of the PID controller.
   *        For example, a value of 0.5 limits the output to 50% of its maximum value.
   */
  void set_scale(const float _scale);

  /**
   * @brief Sets the proportional constant (kp) of the PID controller.
   *
   * @param _kp The new value for the proportional constant.
   */
  void set_kp(const float _kp);

  /**
   * @brief Sets the integral constant (ki) of the PID controller.
   *
   * @param _ki The new value for the integral constant.
   */
  void set_ki(const float _ki);

  /**
   * @brief Sets the derivative constant (kd) of the PID controller.
   *
   * @param _kd The new value for the derivative constant.
   */
  void set_kd(const float _kd);

  /**
   * @brief Sets the sample time of the PID controller.
   *
   * @param time_msec The new sample time in milliseconds.
   */
  void set_sample_time(const unsigned int time_msec);

 public:
  /**
   * @brief Gets the current error.
   * @return The current error.
   */
  float get_error() const;

  /**
   * @brief Gets proportional constant [Kp].
   * @return the kp constant.
   */
  float get_kp() const;

  /**
   * @brief Gets integral constant [Ki].
   * @return the ki constant.
   */
  float get_ki() const;

  /**
   * @brief Gets the derivative constant [Kd].
   * @return the kd constant.
   */
  float get_kd() const;

  /**
   * @brief Gets the proportion part of the output.
   * @return the proportion value.
   */
  double get_proportion() const;

  /**
   * @brief Gets the integral part of the output.
   * @return the integral value.
   */
  double get_integral() const;

  /**
   * @brief Gets the derivative part of the output.
   * @return the derivative part.
   */
  double get_derivative() const;

  /**
   * @brief Gets the sample time.
   * @return the sample time.
   */
  unsigned int get_sample_time() const;

  /**
   * @brief Gets the current output from controller.
   * @return the current output from controller.
   */
  double get_output() const;

  /**
   * @brief Retrieves the error tolerance of the PID controller.
   *
   * @return the current error tolerance value.
   */
  float get_error_tolerance() const;

  /**
   * @brief Retrieves the derivative tolerance of the PID controller.
   *
   * @return the current derivative tolerance value.
   */
  float get_derivative_tolerance() const;

  /**
   * @brief Retrieves the integral zone of the PID controller.
   *
   * @return the current integral zone value.
   */
  float get_integral_zone() const;

  /**
   * @brief Retrieves the integral power limit of the PID controller.
   *
   * @return the current integral power limit value.
   */
  float get_integral_power_limit() const;

  /**
   * @brief Retrieves the jump time limit of the PID controller.
   *
   * @return the current jump time limit value.
   */
  float get_jump_time() const;

  /**
   * @brief Retrieves the maximum value allowed for the PID controller output.
   *
   * @return the maximum value allowed.
   */
  float get_max() const;

  /**
   * @brief Checks if the target was reached.
   * @return True if the target was reached, False if the target wasnt reached.
   */
  bool target_arrived() const;

  /**
   * @brief Initialize the controller.
   * \note This function is neccesary to start in any procces or function
   * where the controller is involve.
   *
   */
  void initialization();
};

}  // namespace lightning