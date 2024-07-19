
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