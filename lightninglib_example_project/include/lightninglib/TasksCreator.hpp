/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#pragma once

#include <list>
#include <map>
#include <memory>
#include <string>

#include "pros/rtos.hpp"

namespace lightning {
class TaskManager {
 private:
  std::map<std::string, std::unique_ptr<pros::Task>> manager;
  std::list<std::string> name_tasks_list;

 private:
  /**
   * @brief Checks if the task already exist.
   *
   * @param task_name
   * The name key of the task that you want to check if exists.
   *
   * @return True if the task exist or False if the task doesn´t exist.
   */
  bool task_exists(const std::string &task_name);

 public:
  /**
   * @brief Construct a new TaskManager object (A way no manage and create task).
   *
   */
  TaskManager();
  TaskManager(const TaskManager &other) = delete;
  ~TaskManager();
  friend std::ostream &operator<<(std::ostream &os,
                                  const TaskManager &task_manager);

 public:
  /**
   * Start a task passing a void function.
   *
   * @param task_name
   * The name key that you want for your task.
   *
   * @param function
   * The void function that will pass.
   */
  void start_task(const std::string &task_name, void (*func)(void *));

  /**
   * @brief Erases a the task.
   *
   * @param task_name.
   * The name key of the task that you want to erase.
   *
   */
  void kill_task(const std::string &task_name);

  /**
   * @brief Prints the current task thar are currently running.
   *
   */
  void print_current_tasks();
};
}  // namespace lightning
