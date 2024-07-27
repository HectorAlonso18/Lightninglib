---
sidebar_label: Programming the autonomous routine
sidebar_position: 3
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Programming the autonomous routine
In this tutorial, you will learn how to use different motion functions to program a competitive autonomous routine.

You can increase your knowledge by reading the Lightning documentation. However, it can be quite difficult to read the entire documentation without any hands-on programming. For this reason, it is recommended to follow the tutorials and gradually read the documentation as needed.

## Things to keep in mind
lightning uses ``okapi`` to provide more adaptability to the functions.

Thanks to Okapi, you can specify units of length and angles in different motion functions.

For example, for Length you can use some of these units: 
| Unit   |  Literal|
| :---: | :---:|
| Meter   | `_m`|
| Centimeter   |`_cm` |
| Millimeter   | `_mm`|
| Inch   | `_in`|
| Foot  | `_ft`|
| tile   | `_tile`|

And for Angles you can use: 
| Unit   |  Literal|
| :---: | :---:|
| Radian   | `_rad`|
| Degree   |`_deg` |

Check the [okapi Units API](https://okapilib.github.io/OkapiLib/md_docs_api_units.html) for more information. 

## Driving straight without PID
If you want to drive your robot to certain distance and velocity you can use the ``raw_drive_distance()`` function.

You just need to indicate the distance that you want to travel in ``inches`` and indicating the velocity of your motors in ``RPM``. 

:::note
This function simply sets the target for the motor, it does not block program execution until the movement finishes. That means, while the robot it is moving can do more functions. 
:::

<Tabs
  groupId="Tutorial_autonomous_routine_raw_distance"
  defaultValue="_drive_forward"
  values={[
    { label: 'Drive forward',  value: '_drive_forward', },
    { label: 'Drive backward',  value: '_drive_backward', },
  ]
}>

<TabItem value="_drive_forward">

```cpp title="main.cpp"
void autonomous(){
    my_chassis.raw_drive_distance(24,300); //Moving the robot 24 inches forward at 300 RPM.
    pros::delay(3000); //When the robot reachead the target

    my_chassis.raw_drive_distance(24_in,300); //Moving the robot 24 inches at the same velocity. 
    pros::delay(3000);

    my_chassis.raw_drive_distance(1_tile,300); //Moving 1 tile (48 inches aprox) at the same velocity. 
    pros::delay(3000);
}
```
</TabItem>


<TabItem value="_drive_backward">

```cpp title="main.cpp"
void autonomous(){
    my_chassis.raw_drive_distance(-24,300); //Moving the robot 24 inches backward at 300 RPM.
    pros::delay(3000);

    my_chassis.raw_drive_distance(-24_in,300); //Moving the robot 24 inches at the same velocity. 
    pros::delay(3000);

    my_chassis.raw_drive_distance(-1_tile,300); //Moving 1 tile (48 inches aprox) at the same velocity.
    pros::delay(3000); 
}
```
</TabItem>

</Tabs>  

:::warning
It is important to consider that the function is not entirely precise, but it is useful when you want to drive a certain distance without worrying too much about precision. Additionally, there is nothing that guarantees the robot will drive completely straight, so achieving straight movement depends on your robot's construction.
:::

---

## Driving straight using PID
Using ``drive_distance()`` you can drive the robot to a specified distance using PID controller and additionally control the heading of your robot using another dedicated ``PID`` controller.

**This motion function it is more accurate than ``raw_drive_distance()``**. 

:::note 
The function will block the program execution until it completes. Once finished, the program will resume and continue running subsequent lines of code.
:::

### Using the ``drive_pid`` and ``turn_pid``
The perfomance of the functions depends in the tunning of the ``drive_pid`` and ``turn_pid``.

* The ``drive_pid`` controls the robot´s velocity to travel the specified distance. 
* The ``turn_pid`` controls the robot´s orientation to keep your robot straight. 

<Tabs
  groupId="Tutorial_autonomous_routine_drive_distance"
  defaultValue="_drive_forward"
  values={[
    { label: 'Drive forward',  value: '_drive_forward', },
    { label: 'Drive backward',  value: '_drive_backward', },
  ]
}>

<TabItem value="_drive_forward">

```cpp title="main.cpp" {10-13}
void autonomous(){
    //Setting the drive_pid
    my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
    my_chassis.set_drive_exit_conditions(.15, 250, 500);
    
    //Setting the turn_pid
    my_chassis.set_turn_constants(1.75, 0, 0, 300, 1, 0, 0);
    my_chassis.set_turn_exit_conditions(1, 100, 5000);
    
    //Driving forward
    my_chassis.drive_distance(24,0); //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(24_in,0); //Running 24 inches in a straight line at a 0-degree orientation.
    my_chassis.drive_distance(1_tile,0);  //Running 1 tile in a straight line at a 0-degree orientation.  
}
```
</TabItem>


<TabItem value="_drive_backward">

```cpp title="main.cpp" {10-13}
void autonomous(){
    //Setting the drive_pid
    my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
    my_chassis.set_drive_exit_conditions(.15, 250, 500);
    
    //Setting the turn_pid
    my_chassis.set_turn_constants(1.75, 0, 0, 300, 1, 0, 0);
    my_chassis.set_turn_exit_conditions(1, 100, 5000);
    
    //Driving backwards
    my_chassis.drive_distance(-24,0); //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(-24_in,0); //Running 24 inches in a straight line at a 0-degree orientation.
    my_chassis.drive_distance(-1_tile,0);  //Running 1 tile in a straight line at a 0-degree orientation.  
}
```
</TabItem>

</Tabs>  

---

## Turning
The ``turn_absolute()`` Makes the robot turn to a certain absolute orientation. 

```cpp {6-9} title="main.cpp"
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
   
    my_chassis.turn_absolute(90_deg);
    my_chassis.turn_absolute(180_deg); 
    my_chassis.turn_absolute(270); //turning 270 degrees.   
    my_chassis.turn_absolute(1_rad); //turning to 1 radian (for some reason?). 
}
```
On the other hand, you can use `turn_relative` to make your robot turn a certain number of degrees. Use a positive value if the robot needs to turn right, or a negative value if the robot needs to turn left.

```cpp {6-9} title="main.cpp"
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
   
    my_chassis.turn_relative(turn_controller,180_deg); //turning 180 degrees. 
    my_chassis.turn_relative(turn_controller,90_deg); //turning 90 degrees, current heading 270. 
    my_chassis.turn_relative(turn_controller,-90_deg); //turning -90 degrees, current heading 180.
}
```
:::note
The turning direction is determinated depending of which direction means less travel.
:::

---

## Driving and turning example
You can combine the driving and turning functions.

```cpp {11-21} title="main.cpp"
void autonomous(){
    //Setting the drive_pid
    my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
    my_chassis.set_drive_exit_conditions(.15, 250, 500);

    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    //Making a square  of 24 in x 24 in []
    my_chassis.drive_distance(24_in,0_deg); //DRIVING 24 inches ↑
    my_chassis.turn_absolute(90_deg); //Turning at 90 degrees orientation →

    my_chassis.drive_distance(24_in,90_deg); //Driving 24 inches →
    my_chassis.turn_absolute(180_deg); //Turning at 180 degrees orientation  ↓

    my_chassis.drive_distance(24_in,180_deg);  //Driving 24 inches ↓
    my_chassis.turn_absolute(270_deg); //Turning at 270 degrees orientation  ←

    my_chassis.drive_distance(24_in,270_deg); //Driving 24 inches ←
    my_chassis.turn_absolute(360_deg); //Turning at 360 degrees orientation ↑ 
}
```
---

## Swing turns
A *swing* turn is when the robot turns to a certain orientation but blocking one side of the drive train, making a *swing*. 
:::note
The turning direction is determinated depending of which direction means less travel.
:::

```cpp title="main.cpp"
void autonomous(){
    //Tunning swing_pid
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 

    //Making a turn blocking the right side of the chassis.
    //to 90 degrees orientation. 
    my_chassis.swing_turn_absolute (RIGHT_SWING, 90_deg); 
    
    //Making a turn blocking the left side of the chassis. 
    //to 0 degrees orientation. 
    my_chassis. swing_turn_absolute (LEFT_SWING, 0_deg);
   
    //Making a turn blocking the right side of the chassis.
    //turn 90 degrees to the right.  
    my_chassis.swing_turn_relative (RIGHT_SWING, 90_deg); 
    
    //Making a turn blocking the right side of the chassis. 
    //turn 90 degrees to the right
    my_chassis. swing_turn_relative (RIGHT_SWING, 90_deg); 

}
```
---
## Using Trapezoidal profile
A trapezoidal profile is a type of motion control trajectory. This method is commonly used in robotics and automation to ensure smooth and controlled movements, minimizing sudden jerks and mechanical stress on the system.

[Click here to get more information about trapezoidal profile.](https://www.pmdcorp.com/resources/type/articles/get/mathematics-of-motion-control-profiles-article)

With ``lightning`` you are able to create trapezoidal profilers, which provide good performance when traveling distances.

```cpp title="main.cpp"
lightning::TrapezoidalProfile profile (5,1);  // Max velocity: 5 inches/seconds, Max accel: 1 inches/seconds^2 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    //The robot would travel 48 inches using the trapezoidal profile. 
    my_chassis.move_with_motion_profile(test_profile);
}
```
Check the [TrapezoidalProfile Documentation](/docs/Documentation/Trapezoidal) for more information.

You can see the ``TrapezoidalProfile`` in action in this [video](https://www.youtube.com/watch?v=WZaXgi8o368). 

---

## Driving to a point
:::note
You need to have odometry, using a odometry configuration that lightning supports, check the **[Declaring your chassis tutorial](/docs/Tutorials/Declaring_your_chassis)** to get more information .
:::

Drives the robot from a starting point to a target point. The robot **MUST** to be facing the target point with the front or back side of the chassis.
<Tabs
  groupId="Tutorial_autonomous_routine_drive_point"
  defaultValue="_drive_forward"
  values={[
    { label: 'Drive forward',  value: '_drive_forward', },
    { label: 'Drive backward',  value: '_drive_backward', },
  ]
}>

<TabItem value="_drive_forward">

```cpp {13} title="main.cpp"
void autonomous(){
    //Setting the drive_pid
    my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
    my_chassis.set_drive_exit_conditions(.15, 250, 500);

    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    //The robot is in (0_in,0_in) and we want to go to (0_in,24_in)
    //The robot is facing the target point, so we can use the function. 
    //we set false, because the robot would run forward. 
    my_chassis.drive_to_point({0_in,24_in},false); //USING THE my_chassis drive and turn pid! 
}
```
</TabItem>


<TabItem value="_drive_backward">

```cpp {13} title="main.cpp"
void autonomous(){
    //Setting the drive_pid
    my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
    my_chassis.set_drive_exit_conditions(.15, 250, 500);

    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
     //The robot is in (0_in,0_in) and we want to go to (0_in,-24_in)
    //The robot is facing the target point with the back side of the robot, so we can use the function. 
    //we set true, because the robot would run backward to reach the point. 
    my_chassis.drive_to_point({0_in,-24_in},true); //USING THE my_chassis drive and turn pid! 
}
```
</TabItem>

</Tabs>  
---

## Following a path
:::note
You need to have odometry, using a odometry configuration that lightning supports,check the **[Declaring your chassis tutorial](/docs/Tutorials/Declaring_your_chassis)** to get more information .
:::

You can create a pre-computated path and make that you robot follow it using ``follow_path()``. 

This works using pure pursuit, path planning and motion profiling. During the 2023-2024 Vex U season, our team used the same function and achieved great results. 

Videos of our robot in action can be found [here](https://youtu.be/wV4qQ4udcdQ). 

<Tabs
  groupId="Tutorial_autonomous_follow_path"
  defaultValue="_example_1"
  values={[
    { label: 'Example 1',  value: '_example_1', },
    { label: 'Example 2',  value: '_example_2', },
  ]
}>

<TabItem value="_example_1">

```cpp {24} title="main.cpp"
void autonomous(){
 //Creating the path
  lightning::Path corredor_path(
  
  // X coordinates
  {my_chassis.get_x(), 12, 11.55, 11.55, 12.15,5.25, .61, -8.34, 15.23, -19.57},
  
  // Y coordinates 
  {my_chassis.get_y(), 16.91, 20, 40, 80, 109.21,111.16, 116.25, 115.25, 115.25},
  
  ////going backwards ? True if you robot needs to go backward and False if you robot need to go forward. 
  true,
  
  6 //The space that would exist between each point for the injection method. 

  );
  
  //You must to use this functions
  corredor_path.upgrade(); //Upgrading the path
  corredor_path.set_max_lineal_velocity(10); //Setting the maximum velocity in inches/second
  corredor_path.make_calcs(1.75); //how slow you want the robot to go around turns  (aroud 1-5). 

  pros::delay(20); //a delay to make all calculations
  my_chassis.follow_path(corredor_path, 18); //The path that we want to follow (corredor_path), 
  //and setting a look ahead distance of 18. 
}
```
</TabItem>


<TabItem value = "_example_2">

```cpp {35} title="main.cpp"
void autonomous(){
lightning::Path pick_triball(                     //-27.80

// X coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_x(), -19.34, -19.89, -25, -26.72},

// Y coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_y(), 108.03,99.11,85.13,69.5}, 

////going backwards ? True if you robot needs to go backward and False if you robot need to go forward. 
false, 

//The space that would exist between each point for the injection method. 
3

);

 //You must to use this functions
pick_triball.upgrade();    //Upgrading the path                                    
pick_triball.set_max_lineal_velocity(14); //Setting the maximum velocity in inches/second
pick_triball.make_calcs(1.5); //how slow you want the robot to go around turns  (aroud 1-5). 

pros::delay(20);

//Tunning pid controller
float limit_integral = 200 / .001250;
my_chassis.set_turn_constants(1.15, 0, 0, 550, 1, 0, 0);
my_chassis.set_turn_exit_conditions(1, 500, 8000);

my_chassis.set_drive_constants(6, 0.00155, 10, 500, 1, 100, 300);
my_chassis.set_drive_exit_conditions(.15, 250, 1000);

intaker.move_voltage(12000); //making some another functions 

my_chassis.follow_path(pick_triball,25); //Following the path (pick_triball), 
//setting a look ahead distance of 25.  
}
```

</TabItem>

</Tabs>  

To see more information about, please check: 

1. **Path Documentation** 
    * [lightning Path Documentation](/docs/Documentation/Path). 

2. **Pure Pursuit**
    * [Pure pursuit and LookAheadDistance](https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html).
    * [Basic Pure Pursuit](https://wiki.purduesigbots.com/software/control-algorithms/basic-pure-pursuit).

---

### Multitasking
You may want your robot to perform different actions while following a path. For example, you might want to activated a pneumatic actuator at the same time that your robot is following a ``path``. This can make your routine more compact and efficient.

#### Simple functions 
Suppose you want to activate the intake mechanism from the beginning until the end of the path travel. Although it may seem straightforward to simply activate the intake, the task involves ensuring the intake mechanism is activated before executing the ``follow_path()`` function.

The code would look some like this: 

```cpp {35} title="main.cpp"
void autonomous(){
lightning::Path pick_triball(                     //-27.80

// X coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_x(), -19.34, -19.89, -25, -26.72},

// Y coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_y(), 108.03,99.11,85.13,69.5}, 

////going backwards ? True if you robot needs to go backward and False if you robot need to go forward. 
false, 

//The space that would exist between each point for the injection method. 
3

);

 //You must to use this functions
pick_triball.upgrade();    //Upgrading the path                                    
pick_triball.set_max_lineal_velocity(14); //Setting the maximum velocity in inches/second
pick_triball.make_calcs(1.5); //how slow you want the robot to go around turns  (aroud 1-5). 

pros::delay(20);

intaker.move_voltage(12000); //activating my intaker

my_chassis.follow_path(pick_triball,25); //Following the path (pick_triball), 
//setting a look ahead distance of 25.  

intaker.stop();  //stopping the intaker. 
}
```
In this aproach the intake activation would run during all the execution of the ``path``. 

However, if you want to create a more complex function, it is necessary to make some adjustments to the code.

#### More complex functions
For example, during the ``Over Under`` season, our team programmed the robot to follow a path while simultaneously activating and deactivating different pneumatic actuators at specific points along the path. This made our autonomous routine more efficient and competitive.

You can found a video of our autonomous routine in action [here.](https://youtu.be/LpFiJdZ04_4)

##### Well, and how i can do the same 🤔?
Well that is a easy job!

The first thing to considered is that a ``Path`` contains **points**. Each point correspond an **path index**.

For example if our path is composed of the following points: 
```cpp
//This is not a code, is just a visual representation: 
example_path=
    first point ( x: 0, y: 24 )
    second point ( x: 48, y: 24 )
    third point ( x: 48, y: 0 )
    fourth point ( x: 0, y: 0 )

```
Each point correspond an specific **index**.

```cpp
//This is not a code, is just a visual representation: 
example_path.index[0] = first point ( x: 0, y: 24 )
example_path.index[1] = second point ( x: 48, y: 24 )
example_path.index[2] = third point ( x: 48, y: 0 )
example_path.index[3] = fourth point ( x: 0, y: 0 )
```
After considered that, it is more easy to start programming the logic. 

We can use the ``get_current_index()`` function. This functions allows you to get the current path index that our robot is travelling in real time. 

The aproach is creating a task that would check the current path index that the robot is navigating. This task will command different
actions or functions depending on the index. 

1. **Create the function**.
```cpp
void path_actions(void*){
  while (1) {        
    //When the robot is in the index 5 = point 6. 
    if(my_chassis.get_current_index()==5){
        //Do the following 
        activate_pneumatics(); 
    }
    
    //When the robot is in the index 11 = point 12. 
    if(my_chassis.get_current_index()==11){
      //Do the following
      activate_intaker();
    }
    
    //When the robot is in the index 13 = point 14. 
    if(my_chassis.get_current_index()==13){
      //Do the following
      close_pneumatics(); 
    }
    
    //MAYBE CHECK THE INDEX AND OTHER THINGS
     //When the robot is in the index 13 = point 14. 
    if(my_chassis.get_current_index()==16 && we_have_time()){
      //Do other thing
    }

    else{
        my_chassis.stop(); 
    }

    // AND SO ON ......
    
  }
}
```
2. **Have a ``TaskManager`` declared**. 
```cpp title="main.cpp"
lightning::TaskManager autonomous_task_manager; //Our task manager 

void autonomous(){
}
```
3. **Create and run the task**.
``` cpp title="main.cpp"
lightning::Path pick_triball(                    
// X coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_x(), -19.34, -19.89, -25, -26.72},

// Y coordinates. (Its recommended that the first point be your current position)
{my_chassis.get_y(), 108.03,99.11,85.13,69.5}, 

////going backwards ? True if you robot needs to go backward and False if you robot need to go forward. 
false, 

//The space that would exist between each point for the injection method. 
3

);

 //You must to use this functions
pick_triball.upgrade();    //Upgrading the path                                    
pick_triball.set_max_lineal_velocity(14); //Setting the maximum velocity in inches/second
pick_triball.make_calcs(1.5); //how slow you want the robot to go around turns  (aroud 1-5). 

pros::delay(20);

//WHILE THE ROBOT IS FOLLOWING THE PATH, THE ROBOT WOULD EXECUTE THE path_actions FUNCTION. 
autonomous_task_manager.start_task("MULTITASK_ACTIONS_PATH",path_actions)
my_chassis.follow_path(pick_triball,25); //Following the path (pick_triball), 
//setting a look ahead distance of 25.  
```

4. **Kill the task**
After, the robot finished the ``path``, the ``task`` is not longer needed. 
``` cpp title="main.cpp"

autonomous_task_manager.start_task("MULTITASK_ACTIONS_PATH",path_actions)
my_chassis.follow_path(pick_triball,25);
pros::delay(10); 
autonomous_task_manager.kill_task("MULTITASK_ACTIONS_PATH");
```
If you have doubts please check the [How to create tasks tutorial.](/docs/Tutorials/Using_TaskManager_Class)

---

## Congratulations! 🎉
With this simple tutorial you are able to program an effective autonomous routine. 