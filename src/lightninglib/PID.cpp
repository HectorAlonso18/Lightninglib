#include "lightninglib/PID.hpp"
#include "lightninglib/Math.h"
#include <cmath>

namespace lightning {


PID::PID(const float _kp, const float _ki, const float _kd,
         unsigned int _sample_time,const float _scale)
    : kp(_kp), ki(_ki), kd(_kd), target(0), first(true), arrived(false),
      jump_time(0), sample_time(_sample_time), current_error(0), prev_error(0),
      delta_error(0), error_tolerance(0), derivative_tolerance(0),
      integral_raw(0), integral_zone(0), integral_power_limit(0),
      proportional(0), integral(0), derivative(0), max(0), output(0),
      contador(0), stop_time_msec(0), scale(_scale) {}

PID::PID(const PID &other)
    : kp(other.kp), ki(other.ki), kd(other.kd), target(0), first(true),
      arrived(false), jump_time(other.jump_time),
      sample_time(other.sample_time), current_error(0), prev_error(0),
      delta_error(0), error_tolerance(other.error_tolerance),
      derivative_tolerance(other.derivative_tolerance), integral_raw(0),
      integral_zone(0), integral_power_limit(other.integral_power_limit), proportional(0), integral(0),
      derivative(0), max(other.max), output(0), contador(0), stop_time_msec(0) ,scale(other.scale) {}

void PID::update(const float error) {
 
  this->current_error = error; 
  
  proportional = kp * current_error;

  if (first) {
    prev_error = current_error;
    integral_raw = 0;
    contador = 0;
    first = false;
  }

  delta_error = current_error - prev_error;
  prev_error = current_error;

  derivative = kd * delta_error;

  if (fabs(current_error) > fabs(integral_zone)) {
    integral_raw = 0;

  }

  else {
    integral_raw += current_error;
    integral_raw = integral_raw > integral_power_limit ? integral_power_limit
                   : integral_raw < -integral_power_limit
                       ? -integral_power_limit
                       : integral_raw;
  }

  if (sign(integral_raw) != sign(current_error) ||
      (fabs(current_error) <= error_tolerance)) {
    integral_raw = 0;
  }

  integral = ki * integral_raw;

  // Histerisis implementation

  if (fabs(current_error) <= error_tolerance &&
      fabs(derivative) <= derivative_tolerance) {

    if (contador >= jump_time) { 
      arrived = true;
       contador = 0;
    }

    else {
      arrived = false;
    }
    contador = contador + sample_time;
  }
  
 
  if (contador_stop_time>= this->stop_time_msec) { 
    contador_stop_time=0; 
    arrived=true;
  }

  contador_stop_time += sample_time; 

  output = (proportional + integral + derivative);
  output = output > max ? max : output < -max ? -max : output;
  output*=this->scale; 

  // std::cout<<"\nTiempo: "<<contador;
}

void PID::set_stop_time(const float _stop_time_msec) { this->stop_time_msec = _stop_time_msec; }

void PID::set_error_tolerance(const float _error_tolerance) {
  error_tolerance = _error_tolerance;
}

void PID::set_derivative_tolerance(const float _derivative_tolerance) {
  derivative_tolerance = _derivative_tolerance;
}

void PID::set_integral_zone(const float _integral_zone) {
  integral_zone = _integral_zone;
}

void PID::set_integral_power_limit(const float _integral_power_limit) {
  if (std::isnan(_integral_power_limit)) {
    integral_power_limit = 0;
  }

  else {
    integral_power_limit = _integral_power_limit;
  }
}

void PID::set_jump_time(const float _jump_time) { jump_time = _jump_time; }

void PID::set_max(const float _max) { max = _max; }

void PID::set_min(const float _min) {min = _min;}

void PID::set_scale(const float _scale){this->scale = _scale;}

void PID::set_kp(const float _kp) { this->kp = _kp; }

void PID::set_ki(const float _ki) { this->ki = _ki; }

void PID::set_kd(const float _kd) { this->kd = _kd; }

void PID::set_sample_time(const  unsigned int time_msec){
  this->sample_time = time_msec; 
} 

float PID::get_error() const { return current_error; }

float PID::get_kp() const { return kp; }

float PID::get_ki() const { return ki; }

float PID::get_kd() const { return kd; }

double PID::get_proportion() const { return proportional; }

double PID::get_integral() const { return integral; }

double PID::get_derivative() const { return derivative; }

unsigned int PID::get_sample_time() const { return sample_time; }

double PID::get_output() const { return output; }

float PID::get_target() const { return this->target; }

float PID::get_error_tolerance() const { return this->error_tolerance; }

float PID::get_derivative_tolerance() const {
  return this->derivative_tolerance;
}

float PID::get_integral_zone() const { return this->integral_zone; }

float PID::get_integral_power_limit() const {
  return this->integral_power_limit;
}

float PID::get_jump_time() const { return this->jump_time; }

float PID::get_max() const { return this->max; }

float PID::get_min() const {return this->min; }

bool PID::target_arrived() const { return arrived; }

void PID::initialization() {
  arrived = false;
  first = true;
  current_error = 0;
  prev_error = 0;
  delta_error = 0;

  integral_raw = 0;

  proportional = 0;
  integral = 0;
  derivative = 0;
  contador = 0;
  contador_stop_time=0; 

  output = 0;
}


} // namespace lightning