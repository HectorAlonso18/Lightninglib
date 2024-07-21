---
sidebar_label: Task Manager
sidebar_position: 9
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# TaskManager
## Constructor
### TaskManager()
Construct a new ``TaskManager`` object.

<Tabs
  groupId="taskmanager"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
TaskManager();

```
</TabItem>


<TabItem value="example">

```cpp

lightning::TaskManager Auton_tasks; 
void autonomous(){

}
```
</TabItem>

</Tabs>  

## Functions
### start_task()
Start a task passing a void function.
<Tabs
  groupId="taskmanager_functions_start_task"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void start_task(const std::string &task_name, void (*func)(void *));
```
</TabItem>


<TabItem value="example">

```cpp

//Some function that we want to put into the task manager
void print_stats(void*){
    while(1){
        //Do some printing stuff

        pros::delay(10); //Important to prevent bugs.
    }
}

lightning::TaskManager Auton_tasks; 
void autonomous(){
Auton_tasks.start_task("PRINTING", print_stats); 
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``task_name``  | The name key that you want for your task. |
| ``function``  | The void function that will pass. |

---

### kill_task()
Erases a selected task.
<Tabs
  groupId="taskmanager_functions_kill_task"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  void kill_task(const std::string &task_name);

```
</TabItem>


<TabItem value="example">

```cpp

//Some function that we want to put into the task manager
void print_stats(void*){
    while(1){
        //Do some printing stuff

        pros::delay(10); //Important to prevent bugs.
    }
}

lightning::TaskManager Auton_tasks; 
void autonomous(){
Auton_tasks.start_task("PRINTING", print_stats); 
/*
Doing some stuff during autonomous period
---
--
-
---
--
*/

//We can delete the "PRINTING" task

Auton_tasks.kill_task("PRINTING"); //Deleting the task. 

}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``task_name``  | The name key that you want for your task. |

---

### print_current_task()
Prints the current task thar are currently running in Integrated Terminal.

<Tabs
  groupId="taskmanager_functions_print_current"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void print_current_tasks();

```
</TabItem>


<TabItem value="example">

```cpp {30-35}

//Our functions
void print_stats(void*){
    while(1){
        //Do some printing stuff

        pros::delay(10); //Important to prevent bugs.
    }
}

void sensing_something(void*){
    while(1){
        //Do some sensing stuff
        pros::delay(10); //Important to prevent bugs.
    }
}

lightning::TaskManager Auton_tasks; 
void autonomous(){
Auton_tasks.start_task("PRINTING", print_stats); 
Auton_tasks.start_task("SENSING",sensing_something); 

/*
Doing some stuff during autonomous period
---
--

*/

Auton_tasks.print_current_tasks(); 

/*OUTPUT Of print_current_tasks
 PRINTING
 SENSING
*/

}
```
</TabItem>

</Tabs> 

---

## Operators
### ``std::ostream &operator <<``
Prints the current tasks in Integrated Terminal. 
<Tabs
  groupId="taskmanager_operator_<<"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   std::ostream &operator<<(std::ostream &os, const TaskManager &task_manager); 

```
</TabItem>


<TabItem value="example">

```cpp {30-37}

//Our functions
void print_stats(void*){
    while(1){
        //Do some printing stuff

        pros::delay(10); //Important to prevent bugs.
    }
}

void sensing_something(void*){
    while(1){
        //Do some sensing stuff
        pros::delay(10); //Important to prevent bugs.
    }
}

lightning::TaskManager Auton_tasks; 
void autonomous(){
Auton_tasks.start_task("PRINTING", print_stats); 
Auton_tasks.start_task("SENSING",sensing_something); 

/*
Doing some stuff during autonomous period
---
--

*/

std::cout<<Auton_tasks; 

/*OUTPUT Of print_current_tasks
 PRINTING
 SENSING
*/

}
```
</TabItem>

</Tabs> 

---
