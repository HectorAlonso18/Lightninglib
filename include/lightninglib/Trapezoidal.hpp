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
   *@param max_velocity what would be the maximum profile velocity?
   *@param max_acceleration what would be the maximum profile accleration? 
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
    *@param max_velocity what would be the maximum profile velocity?
    *@param max_acceleration what would be the maximum profile accleration? 
   */
  void set_parameters(const float max_velocity, const float max_acceleration); 
  
  /**
    *@brief sets the maximum profile velocity. 
    *@param max_velocity what would be the maximum profile velocity?
   */
  void set_max_velocity(const float max_velocity);

  /**
    *@brief sets the maximum profile acceleration. 
    *@param max_acceleration what would be the maximum profile acceleration?
  */
  void set_max_acceleration(const float max_acceleration);

  /**
    *@brief gets the desired velocity giving a point. 
    *@param index the profile index. 
    *@return the desired velocity. 
   */ 
  float get_velocity_at(int index) const;

  /**
    *@brief gets the maximum profile velocity. 
    *@return the maximum velocity. 
   */
  float get_max_velocity() const;

  /**
    *@brief gets the maximum profile acceleration.
    *@return the maximum acceleration.  
   */
  float get_max_acceleration() const;
  
  /**
    *@brief gets the acceleration time.
    *@return the acceleration time.   
   */
  float get_accel_time() const;
  
  /**
    *@brief gets the acceleration distance (acceleration phase).  
    *@return the acceleration time. 
   */
  float get_accel_distance() const;
  
  /**
    *@brief gets the desacceleration distance (desacceleration phase). 
    *@return gets the desacceleration time. 
   */
  float get_desaccel_distance() const;
  
  /**
    *@brief gets the constant velocity distance (constant acceleration phase). 
    *@return gets the constant velocity distance. 
   */
  float get_velocity_constant_distance() const;
  
  /**
    *@brief gets the time to arrive. 
    *@return the time to arrive. 
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

} // namespace lightning