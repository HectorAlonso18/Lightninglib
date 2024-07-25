---
sidebar_label: How to create tasks
sidebar_position: 3
---
# What are tasks?

>``Tasks`` are a great tool to do multiple things at once, but they can be difficult to use properly. The most important thing to remember when using ``tasks`` is that ``tasks`` aren’t truly running in the background - they are run one at a time and swapped out by the PROS scheduler. If your task performs some repeated action (e.g. a while loop), you should include a ``delay()`` or ``task_delay_until()``. Without a ``delay()`` statement, your task could starve the processor of resources and prevent the kernel from running properly.

-**Pros Documentation.**

---
# How to create tasks using **lighting**
In lightning, you can create and manage task using the ``TaskManager`` class. 


## Creating a ``TaskManager`` object. 
To create a TaskManager object, simply do the following:

```cpp title="main.cpp"
lightning::TaskManager task_manager_name; 

``` 
---

## Creating and Running ``tasks``
### Creating the ``task`` 
The first thing to be aware of is that you need to create the function you want to run in the background.

Commonly, this function is in a ``while`` loop. 

:::note 
Remember to set a delay time. Not using a delay time will cause problems with the V5 Brain and lead to unexpected behavior.
:::

**The second thing is very important**, your function must to be of type ``void name_function (void*)``. 

#### Example
In the next example, we will crate a function. The objetive of this function is to sense something. 

```cpp title="main.cpp"
void sensing_something(void*){
    while (1) {
    sense_sensors(); 
    pros::delay(util::DELAY_TIME); //10 milliseconds of delay.   
  }
}

``` 
Note that our function meets the following: 

- [x] It is of type ``void (void*)``. 
- [x] It is inside of a ``loop``.
- [x] Has delay time.  

---

### Running the `task`
Now that we have our function, it is time to run it as a task using the ``start_task()`` function.

#### How to use it? 
We need to understand parameters of this function: 

| Parameters    |  |
| ------------- | ------------- |
| ``task_name``  | The name key that you want for your task. |
| ``function``  | The void function that will pass. |

First, we need to provide a name for this task. **The name is important** because it is useful for referencing and managing that particular task. 

Then we need to provide the designated function. 

**As a result**, we have the following: 

```cpp  title="main.cpp"
task_manager_name.start_task("key_name", function); 
```
---

#### Example, running a task. 
In the next example, we will running the **previous example function** in the ``autonomous`` function. 

```cpp {11} title="main.cpp"
void sensing_something(void*){
    while (1) {
    sense_sensors(); 
    pros::delay(util::DELAY_TIME); //10 milliseconds of delay.   
  }
}

lightning::TaskManager autonomous_task_manager; //Our task manager 

void autonomous(){
    autonomous_task_manager.start_task("SENSING", sensing_something); 
    //WE WOULD RUNNING THE sensing_something function in the autonomous routine as a task. 
}

``` 
---
#### Example, running multiple tasks.
You can create **more than just one task**.
```cpp {28-30} title="main.cpp"

/////////////////////////////////Our functions:
void sensing_something(void*){
    while (1) {
    sense_sensors(); 
    pros::delay(util::DELAY_TIME); //10 milliseconds of delay.   
  }
}

void printing_stuff(void*){
    while(1){
        some_printing_function(); 
        pros::delay(util::DELAY_TIME); //10 milliseconds of delay.
    }
}

void timer(void*){
    while(1){
        some_clock_function();
        pros::delay(util::DELAY_TIME); //10 milliseconds of delay.
    }
}
//////////////////////////////////////////////////////////////////

lightning::TaskManager autonomous_task_manager; //Our task manager 

void autonomous(){
    autonomous_task_manager.start_task("SENSING", sensing_something); //FIRST TASK 
    autonomous_task_manager.start_task("PRINTING", printing_stuff);  //SECOND TASK
    autonomous_task_manager.start_task("CLOCK",timer); //THIRD TASK
}

``` 
---

#### Considerations
* You can create more than just one task. 
* You can create different task manager (example: One task manager for the **driver period** and another for the **autonomous period**). 

---

## Deleting ``tasks``
To delete ``tasks`` use the ``kill_task()`` method.

For this function you just need to provide the ``task name`` that you want delete. 

```cpp title="main.cpp"
task_manager.kill_task("TASK NAME"); 
```
### Example
Let´s suppose that after using a ``task`` we want to delete it. 
```cpp {16} title="main.cpp"
void sensing_something(void*){
    while (1) {
    sense_sensors(); 
    pros::delay(util::DELAY_TIME); //10 milliseconds of delay.   
  }
}

lightning::TaskManager autonomous_task_manager; //Our task manager 

void autonomous(){
    autonomous_task_manager.start_task("SENSING", sensing_something); 
    //AFTER USING THE TASK SOME AMOUNT OF TIME 
    ///
    ///
    ///
    autonomous_task_manager.kill_task("SENSING"); //KILLING THE TASK. 
}

```
---

Delete the ``task`` when it is no longer required.

### Considerations
**One important thing to keep in mind**. The tasks belong to the ``TaskManager`` object. This means that if the ``task manager`` is deleted, all the task will be deleted as well. 

---
## Printing current tasks
You can print the current tasks that are running in the integrated PROS terminal . To do this you can use two different ways: 
1. Using the ``print_current_tasks()``.

```cpp {7} title="main.cpp"
lightning::TaskManager autonomous_task_manager; //Our task manager 
void autonomous(){
   autonomous_task_manager.start_task("SENSING", sensing_something); //FIRST TASK 
   autonomous_task_manager.start_task("PRINTING", printing_stuff);  //SECOND TASK
   autonomous_task_manager.start_task("CLOCK",timer); //THIRD TASK

   autonomous_task_manager.print_current_tasks(); 
   /* OUTPUT
    SENSING
    PRINTING
    CLOCK
   */ 
}
```
2. Or using ``std::cout``.
```cpp {7} title="main.cpp"
lightning::TaskManager autonomous_task_manager; //Our task manager 
void autonomous(){
   autonomous_task_manager.start_task("SENSING", sensing_something); //FIRST TASK 
   autonomous_task_manager.start_task("PRINTING", printing_stuff);  //SECOND TASK
   autonomous_task_manager.start_task("CLOCK",timer); //THIRD TASK

   std::cout<<autonomous_task_manager; 
   /* OUTPUT
    SENSING
    PRINTING
    CLOCK
   */ 
}
```
---

For more information check the [TaskManager Documentation.](http://localhost:3000/docs/Documentation/TaskManager)

