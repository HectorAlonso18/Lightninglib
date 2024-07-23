/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/PurePursuit.hpp"
#include "lightninglib/Math.h"
#include <iostream>

double distance(std::vector<double> p1, std::vector<double> p2) {
  return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
}


std::vector<double> get_intersection(std::vector<double> start,
                                     std::vector<double> end,
                                     std::vector<double> cur, double radius) {
  std::vector<double> d = vector_sub(end, start);
  std::vector<double> f = vector_sub(start, cur);

  std::vector<double> intersectVector;
  std::vector<double> vector_segment;
  std::vector<double> point;

  double a = vector_dot(d, d);
  double b = 2 * vector_dot(f, d);
  double c = vector_dot(f, f) - pow(radius, 2);
  double discriminant = pow(b, 2) - (4 * a * c);

  if (discriminant < 0) {
    std::cout << "\nCeroooo";
    return {std::numeric_limits<double>::quiet_NaN(),
            std::numeric_limits<double>::quiet_NaN()};
  }

  else {
    discriminant = sqrt(std::abs(discriminant));
    double t1 = (-b - discriminant) / (2 * a);
    double t2 = (-b + discriminant) / (2 * a);

    if (t1 >= 0 && t1 <= 1) {
      std::cout << "\nT1 es la solucion correcta";
      intersectVector = vector_sub(end, start);
      vector_segment = vector_mult(intersectVector, t1);
      point = vector_add(start, vector_segment);
      std::cout << "\t Point[0]: " << point[0] << " Point[1]: " << point[1];
      return point;
    }

    if (t2 >= 0 && t2 <= 1) {
      std::cout << "\nT2 es la solucion correcta";
      intersectVector = vector_sub(end, start);
      vector_segment = vector_mult(intersectVector, t2);
      point = vector_add(start, vector_segment);

      std::cout << "\t Point[0]: " << point[0] << " Point[1]: " << point[1];
      return point;
    }
  }

  return {std::numeric_limits<double>::quiet_NaN(),
          std::numeric_limits<double>::quiet_NaN()};

  /*
  std::vector<double> p1 {start[1] - cur[1], start[0] - cur[0]};
  std::vector<double> p2 {end[1] - cur[1], end[0] - cur[0]};

  double dx = p2[1] - p1[1];
  double dy = p2[0] - p1[0];
  float d = sqrt(pow(dx,2) + pow(dy,2));
  float D = p1[1] * p2[0] - p2[1] * p1[0];
  float discriminant = abs(pow(radius,2) * pow(d,2) - pow(D,2));

  float x1 = (D * dy + sign(dy) * dx * sqrt(discriminant)) / pow(d,2);
  float y1 = (-D * dx + abs(dy) * sqrt(discriminant)) / pow(d,2);
  float x2 = (D * dy - sign(dy) * dx * sqrt(discriminant)) / pow(d,2);
  float y2 = (-D * dx - abs(dy) * sqrt(discriminant)) / pow(d,2);
  // Above calculations can be explained and proven here:
  https://mathworld.wolfram.com/Circle-LineIntersection.html

  std::vector<double> intersection1 {x1, y1};
  std::vector<double> intersection2 {x2, y2};

  float distance1 = distance(p2, intersection1);
  float distance2 = distance(p2, intersection2);

  std::vector<double> calc1 {(x1 + cur[1]), (y1 + cur[0])};
  std::vector<double> calc2 {(x2 + cur[1]), (y2 + cur[0]) };

  if (distance1 < distance2) return calc1;
  if (distance1 > distance2) return calc2;*/

  /* There are always two intersections between a circle and a line- if they do
  not appear visually, they are imaginary. We select the intersection that is
  closer to the end of the waypoint path so we are always moving forwards*/
}