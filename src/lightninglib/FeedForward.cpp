/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/FeedForward.hpp"
#include "lightninglib/Math.h"


namespace lightning {
FeedForward::FeedForward(const double _kv, const double _ks, const double _ka) : kv(_kv), ks(_ks), ka(_ka), velocity(0), acceleration(0), prev_velocity(0), output(0)

{
  prev_velocity = velocity;
}

FeedForward::FeedForward(const FeedForward& other) : kv(other.kv), ks(other.ks), ka(other.ka), velocity(other.velocity), acceleration(other.velocity), prev_velocity(other.prev_velocity), output(other.output) {
  prev_velocity = other.velocity;
}

void FeedForward::update(const double input) {
  velocity = input;
  acceleration = velocity - prev_velocity;
  prev_velocity = velocity;

  output = ks * sign(velocity) + kv * velocity + ka * acceleration;
}

void FeedForward::set_kv(const double kv){
  this->kv = kv; 
}
  

void FeedForward::set_ks(const double ks){
  this->ks = ks; 
}


void FeedForward::set_ka(const double ka){
  this->ka=ka; 
}
  
double FeedForward::get_output() const {
  return output;
}

double FeedForward::get_kv() const {
  return kv;
}

double FeedForward::get_ks() const {
  return ks;
}

double FeedForward::get_ka() const {
  return ka;
}
}  // namespace lightning