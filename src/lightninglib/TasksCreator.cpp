/*
This Source Code Form is subject to the terms of the Mozilla Public
License, v. 2.0. If a copy of the MPL was not distributed with this
file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "lightninglib/TasksCreator.hpp"
#include <iostream>

namespace lightning {
TaskManager::TaskManager() {
  manager.clear();
  name_tasks_list.clear();
}

TaskManager::~TaskManager() {
  for (auto const &i : name_tasks_list) {
    kill_task(i);
  }
}

bool TaskManager::task_exists(const std::string &task_name) {
  return TaskManager::manager.find(task_name) != manager.end();
}

void TaskManager::start_task(const std::string &task_name,
                             void (*func)(void *)) {
  if (!task_exists(task_name)) {

    manager.insert(std::pair<std::string, std::unique_ptr<pros::Task>>(
        task_name, std::move(std::make_unique<pros::Task>(
                       func, (void *)"PROS", TASK_PRIORITY_DEFAULT,
                       TASK_STACK_DEPTH_DEFAULT, ""))));

    name_tasks_list.push_back(
        task_name); // lista para poder ver las tasks activas
  }
}

void TaskManager::kill_task(const std::string &task_name) {

  if (task_exists(task_name) == true) {
    manager[task_name]->remove();
    manager[task_name].release();
    manager.erase(task_name);
    name_tasks_list.remove(task_name);
  }
}

void TaskManager::print_current_tasks() {
  for (auto const &i : name_tasks_list) {
    std::cout << i << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const TaskManager &task_manager) {
  for (auto const &i : task_manager.name_tasks_list) {
    std::cout << i << std::endl;
  }

  return os;
}

} // namespace lightning