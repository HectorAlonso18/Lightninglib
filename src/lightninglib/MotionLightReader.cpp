#include "MotionLightReader.hpp"

#include <fstream>
#include <iostream>
#include <string>


namespace lightning {
namespace MotionLightReader {

void Profile::ReadMotionLightFile(const char* motion_file_name) {
  std::ifstream motion_file(motion_file_name);
  if (!motion_file.is_open()) {
    std::cerr << "Error opening the file" << "\n";
    std::cerr << "Are you sure that the file is on your project?" << "\n";
  }

  std::string line;
  std::vector<float> file_velocities;
  std::vector<float> parameters;

  for (int i = 0; i < 6; i++) {
    std::getline(motion_file, line, ',');
    parameters.push_back(std::stod(line));
  }

  std::getline(motion_file, line);
  parameters.push_back(std::stod(line));

  while (std::getline(motion_file, line, '\n')) {
    file_velocities.push_back(std::stod(line));
  }

  profiler_type = static_cast<LinearProfiler>(parameters[0]);
  MaxVelocity = parameters[1];
  MaxAcceleration = parameters[2];
  MaxDesacceleration = parameters[3];
  MaxJerk = parameters[4];
  TargetDistance = parameters[5];
  SampleTimeSec = parameters[6];
  this->Velocities = file_velocities;
}

}  // namespace MotionLightReader
}  // namespace lightning