/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once
#include <vector>

/**
 *@brief Gets the distance betweens between the two points.
 *@param p1 A vector of length two in the format {Y,X} that contains Robot::y and Robot::x.
 *@param p2 A vector of length two in the format {Y, X} that contains the Y and X coordinate of the target point.
 *@return Provides the distance between the two points using the standard distance formula.
 */
double distance(std::vector<double> p1, std::vector<double> p2);

/**
 *@brief 	First point of waypoint path.
 *@param start 	Second point of a two-point segment of the waypoint path.
 *@param end A vector of length two in the format {Y, X} that contains the Y and X coordinate of the target point.
 *@param cur A vector that contains Robot::y and Robot::x position.
 *@param radius A scalar representing how far our lookahead distance should be- in other words, how early we should start turning in anticipation of a change in direction.
 *@return The intersection between a circle centered on our Robot's current position with radius and the line formed between start and end.
 */
std::vector<double> get_intersection(std::vector<double> start,
                                     std::vector<double> end,
                                     std::vector<double> cur, double radius);