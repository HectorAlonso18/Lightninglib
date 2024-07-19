/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include <vector>

double distance(std::vector<double> p1, std::vector<double> p2);
double get_degrees(std::vector<double> p1, std::vector<double> p2);
std::vector<double> get_deviation(std::vector<double> headings, int numb);
std::vector<double> get_intersection(std::vector<double> start,
                                     std::vector<double> end,
                                     std::vector<double> cur, double radius);