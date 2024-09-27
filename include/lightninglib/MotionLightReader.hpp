#pragma once
#include <vector>

namespace lightning {
namespace MotionLightReader {
enum LinearProfiler {
  TRAPEZOIDAL,
  SCURVE
};

struct Profile {
  LinearProfiler profiler_type = TRAPEZOIDAL;
  float MaxVelocity = 0;
  float MaxAcceleration = 0;
  float MaxDesacceleration = 0;
  float MaxJerk = 0;
  float TargetDistance = 0;
  float SampleTimeSec = 0;
  std::vector<float> Velocities;

  void ReadMotionLightFile(const char* motion_file_name);

};

}  // namespace MotionLightReader

}  // namespace lightning