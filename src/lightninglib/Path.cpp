#include "lightninglib\Path.hpp"
#include "lightninglib\Math.h"
#include "pros\rtos.hpp"
#include <cmath>

namespace lightning {

Path::Path(const std::vector<double> &X, const std::vector<double> &Y,
           bool _reverse, int _spacing) {
  std::vector<std::vector<double>> path;
  path.reserve(X.size());

  Path::a = 1 - .75;
  Path::b = .75;
  Path::tolerance = .001;

  for (int i = 0; i < X.size(); i++) {
    std::vector<double> vector_aux;

    for (int j = 0; j < 1; j++) {
      vector_aux.emplace_back(X[i]);
      vector_aux.emplace_back(Y[i]);
    }

    path.emplace_back(vector_aux);
  }

  raw = true;
  injected = false;
  smoothed = false;
  ready = false;
  this->reverse = _reverse;

  this->spacing = _spacing;
  Path::path = path;

  size = int64_t(path.size());
}

Path::Path(const std::vector<double> &X, const std::vector<double> &Y,
           bool _reverse, int _spacing, const double B,
           const double Tolerance) {
  std::vector<std::vector<double>> n_path;
  n_path.reserve(X.size());
  Path::a = 1 - B;
  Path::b = B;
  Path::tolerance = Tolerance;

  for (int i = 0; i < X.size(); i++) {
    std::vector<double> vector_aux;

    for (int j = 0; j < 1; j++) {
      vector_aux.emplace_back(X[i]);
      vector_aux.emplace_back(Y[i]);
    }

    n_path.emplace_back(vector_aux);
  }

  path = n_path;
  size = int64_t(path.size());

  raw = true;
  injected = false;
  smoothed = false;

  ready = false;
  
  //aqui era  =  reverse
  this->reverse = _reverse;

  this->spacing = _spacing;
}

std::ostream &operator<<(std::ostream &os, const Path &path) {
  for (int i = 0; i < path.size; i++) {
    os << "\n [" << i << "] X: " << path.path[i][0]
       << ", Y: " << path.path[i][1];
    pros::delay(10);
  }
  return os;
}

double Path::curvature(const std::vector<double> &Q,
                       const std::vector<double> &P,
                       const std::vector<double> &R) {
  double x1 = P[0] + .001;
  double y1 = P[1];

  double x2 = Q[0];
  double y2 = Q[1];

  double x3 = R[0];
  double y3 = R[1];

  double k1 =
      .5 * (pow(x1, 2) + pow(y1, 2) - pow(x2, 2) - pow(y2, 2)) / (x1 - x2);
  double k2 = (y1 - y2) / (x1 - x2);
  double b = .5 *
             (pow(x2, 2) - 2 * x2 * k1 + pow(y2, 2) - pow(x3, 2) + 2 * x3 * k1 -
              pow(y3, 2)) /
             (x3 * k2 - y3 + y2 - x2 * k2);
  double a = k1 - k2 * b;
  double r = hypot(x1 - a, y1 - b);

  double curvature = 1 / r;

  curvature = std::isnan(curvature) ? 0 : curvature;

  return curvature;
}

double Path::distance_btw_two_pts(const int index) {
  return hypot(Path::path[index + 1][0] - Path::path[index][0],
               Path::path[index + 1][1] - Path::path[index][1]);
}

void Path::set_max_lineal_velocity(double velocity) {
  max_lineal_velocity = velocity;
}

void Path::set_reverse(bool _is_reverse) { this->reverse = _is_reverse; }

void Path::inject_points() {
  std::vector<std::vector<double>> new_points;
  new_points.reserve(this->size);

  for (int i = 0; i < path.size() - 1; i++) {

    double vectorX = path[i + 1][0] - path[i][0];
    double vectorY = path[i + 1][1] - path[i][1];

    double magnitude = sqrt(pow(vectorX, 2) + pow(vectorY, 2));

    int num_points_that_fit = ceil(magnitude / this->spacing);

    double normalized_x = (vectorX) / (magnitude);
    double normalized_y = (vectorY) / (magnitude);

    vectorX = normalized_x * this->spacing;
    vectorY = normalized_y * this->spacing;

    for (int j = 0; j < num_points_that_fit; j++) {
      std::vector<double> vector_aux;
      vector_aux.reserve(num_points_that_fit);
      for (int k = 0; k < 1; k++) {
        vector_aux.emplace_back((path[i][0]) + vectorX * j);
        vector_aux.emplace_back((path[i][1]) + vectorY * j);
      }

      new_points.emplace_back(vector_aux);
    }
  }

  std::vector<double> vector_final;
  vector_final.reserve(2);

  vector_final.emplace_back(path[path.size() - 1][0]);
  vector_final.emplace_back(path[path.size() - 1][1]);

  new_points.emplace_back(vector_final);

  raw = false;
  injected = true;

  Path::path = new_points;
  size = path.size();
}

void Path::smoother() {
  std::vector<std::vector<double>> newPath = path;
  double change = Path::tolerance;
  while (change >= Path::tolerance) {
    change = 0;
    for (int i = 1; i < Path::path.size() - 1; i++) {

      for (int j = 0; j < Path::path[i].size(); j++) {
        double aux = newPath[i][j];
        newPath[i][j] +=
            a * (Path::path[i][j] - newPath[i][j]) +
            b * (newPath[i - 1][j] + newPath[i + 1][j] - (2 * newPath[i][j]));
        change += std::abs(aux - newPath[i][j]);
      }
    }
  }

  raw = false;
  smoothed = true;

  Path::path = newPath;
  size = path.size();
}

void Path::calc_curvature_vector() {

  std::vector<double> aux;
  aux.reserve(this->size);

  for (int i = 0; i < this->size; i++) {
    aux.emplace_back(0.0); // Llenar el vector con ceros
  }

  aux[0] = 0;
  aux[Path::path.size() - 1] = 0;

  for (auto i = 1; i < Path::path.size() - 1; i++) {
    std::vector<double> Q = Path::path[i - 1];
    std::vector<double> P = Path::path[i];
    std::vector<double> R = Path::path[i + 1];

    aux[i] = curvature(Q, P, R);
  }

  curvature_vector = aux;
}

void Path::calc_distance_vector() {
  std::vector<double> distance_at_point;
  distance_at_point.reserve(this->size);

  for (int i = 0; i < this->size; i++) {
    distance_at_point.emplace_back(0.0); // Llenar el vector con ceros
  }

  distance_at_point[0] = 0;

  for (auto i = 1; i < Path::path.size() - 1; i++) {
    distance_at_point[i] =
        Path::distance_btw_two_pts(i) + distance_at_point[i - 1];
  }

  distance_at_point[path.size() - 1] = distance_at_point[path.size() - 2];

  Path::distance_vector = distance_at_point;
}

void Path::calc_maximum_lineal_velocities(const float k) {
  std::vector<double> aux;
  aux.reserve(this->size);

  for (int i = 0; i < this->size; i++) {
    aux.emplace_back(0.0); // Llenar el vector con ceros
  }

  for (auto i = 0; i < aux.size(); i++) {
    aux[i] = std::min(Path::max_lineal_velocity, k / Path::curvature_vector[i]);
  }

  Path::max_lineal_velocities_vector = aux;
}

void Path::calc_target_lineal_velocities() {
  std::vector<double> velocities;
  velocities.reserve(this->size);

  for (int i = 0; i < this->size; i++) {
    velocities.emplace_back(0.0); // Llenar el vector con ceros
  }

  velocities[Path::path.size() - 1] = 0;

  std::vector<double> distances_between_points;
  distances_between_points.reserve(this->size);
  distances_between_points = get_distance_vector();

  for (auto i = path.size() - 2; i > 0; i--) {
    double distance = Path::distance_btw_two_pts(i);
    velocities[i] = std::min(
        Path::max_lineal_velocities_vector[i],
        (sqrt(pow(velocities[i + 1], 2) + 2 * max_lineal_velocities_vector[i] *
                                              distances_between_points[i])));
  }

  // Revisar
  velocities[0] = 5;

  Path::target_lineal_velocities = velocities;
}

void Path::make_calcs(const float k) {
  calc_curvature_vector();
  calc_distance_vector();
  calc_maximum_lineal_velocities(k);
  calc_target_lineal_velocities();
  ready = true;
}

// Podemos agregar un parametro que registre la orientacion
void Path::calc_orientation(const float offset) {
  std::vector<double> orientation(Path::path.size());
  orientation[Path::path.size() - 1] = 0;

  double angle = 0;
  for (int i = 0; i < get_size() - 1; i++) {
    std::vector<double> current = get_point_at(i);
    std::vector<double> target = get_point_at(i + 1);

    angle = get_angle_btw_points(current, target) + offset;

    orientation[i] = angle;
  }

  orientation[get_size() - 1] = angle;

  Path::orientation_vector = orientation;
}

void Path::calc_target_angular_velocities() {
  std::vector<double> angular_velocity(get_size());
  for (auto i = 0; i < get_size() - 1; i++) {
    // 1/curvature_vector es el radio de la curvatura
    angular_velocity[i] =
        (target_lineal_velocities[i] / (1 / curvature_vector[i]));
  }

  angular_velocity[get_size() - 1] = 0;

  target_angular_velocities = angular_velocity;
}

std::vector<double> Path::get_curvature_vector() const {
  return curvature_vector;
}

std::vector<double> Path::get_distance_vector() const {
  return distance_vector;
}

std::vector<double> Path::get_maximum_lineal_velocities() const {
  return max_lineal_velocities_vector;
}

std::vector<double> Path::get_target_lineal_velocities() const {
  return target_lineal_velocities;
}

std::vector<double> Path::get_orientation_vector() const {
  return orientation_vector;
}

std::vector<double> Path::get_target_angular_velocities() const {
  return target_angular_velocities;
}

int16_t Path::get_size() const { return Path::size; }

std::vector<double> Path::get_point_at(const int index) const {
  return {Path::path[index][0], Path::path[index][1]};
}

double Path::get_x_at(const int index) const { return Path::path[index][0]; }

double Path::get_y_at(const int index) const { return Path::path[index][1]; }

double Path::get_target_lineal_velocity_at(const int index) const {
  return this->target_lineal_velocities[index];
}

double Path::get_maximum_lineal_velocity() const { return max_lineal_velocity; }

double Path::get_theta_at(const int index) const {
  return this->orientation_vector[index];
}

double Path::get_target_angular_velocity_at(const int index) const {
  return this->curvature_vector[index];
}

void Path::upgrade() {
  inject_points();
  smoother();
}

bool Path::is_raw() const { return raw; }

bool Path::is_inject() const { return injected; }

bool Path::is_smooth() const { return smoothed; }

bool Path::is_ready() const { return ready; }

bool Path::is_reverse() const { return this->reverse; }

} // namespace lightning
