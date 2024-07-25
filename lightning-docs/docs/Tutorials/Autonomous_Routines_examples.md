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
Check the [TrapezoidalProfile Documentation](http://localhost:3000/docs/Documentation/Trapezoidal) for more information.

You can see the ``TrapezoidalProfile`` in action in this [video](https://www.youtube.com/watch?v=WZaXgi8o368). 

---

## Driving to a point
:::note
You need to have odometry to do this.
:::