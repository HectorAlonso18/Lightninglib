---
sidebar_label: Declaring your chassis
sidebar_position: 1
---

# How to declare your chassis? 
In lightning declaring your chassis is possibly with the ``TankChassis`` class.

:::warning
At this moment, lightning just supports tank-drive chassis. Support for x-drives comming soon.
:::

If you are not sure what type of drive train your robot has, check this [video](https://youtu.be/Py14YTHCth0).

---
## Choose your odometry configuration
When declaring your chassis, it is important to provide your odometry configuration.

Odometry is an algorithm that allows you to determine the absolute position and orientation of your robot. With odometry, you can program more sophisticated autonomous routines, as the robot will always know its location.

lightning will ideally apply odometry to your robot based on your configuration.

:::note
lighting supports odometry with **tracking wheels**, using the [ADI Encoders](https://kb.vex.com/hc/en-us/articles/360039512851-Using-the-V5-3-Wire-Optical-Shaft-Encoder) or the [v5 Rotation Sensors](https://kb.vex.com/hc/en-us/articles/360051368331-Using-the-V5-Rotation-Sensor). 
:::

For more information about odometry, how it works, and how to program it, check [this.](https://wiki.purduesigbots.com/software/odometry).

### Without odometry
If you don´t have tracking wheels in your robot, don´t worry!. This configuration is for you. 

You can declare your chassis without any problems, and still use different autonomous function that will help you to program your autonomous routine in a precise way. 

It is important to be aware that some functions would not work in your robot, because that particullar functions need that your robot 
have odometry. 

**The motion functions are the following:** 
* ``move_to_point()``
* ``follow_path()``

**The telemetry functions are the following:**
* ``set_coordinates()``
* ``track_pose()``
* ``get_pose()``
* ``get_current_index()``
* ``get_position()``
* ``get_ForwardTracker_position()``
* ``get_SideWays_position()``
* ``get_orientation()`` 
* ``get_x()`` 
* ``get_y()``  

---

### With one tracking wheel
If you have just one tracking wheel you can use the following configurations: 

| Odometry configuration    |  |
| ------------- | ------------- |
| ``ADI_ONE_ODOM``  | Use this configuration if you are using the  [ADI Encoder](https://kb.vex.com/hc/en-us/articles/360039512851-Using-the-V5-3-Wire-Optical-Shaft-Encoder).|
| `` ROTATION_ONE_ODOM``  | Use this configuration if you are using the [v5 Rotation Sensor](https://kb.vex.com/hc/en-us/articles/360051368331-Using-the-V5-Rotation-Sensor).  |


---

### With two tracking wheels
If you have just two tracking wheels you can use the following configurations: 

| Odometry configuration    |  |
| ------------- | ------------- |
| ``ADI_TWO_ODOM``  | Use this configuration if you are using the  [ADI Encoders](https://kb.vex.com/hc/en-us/articles/360039512851-Using-the-V5-3-Wire-Optical-Shaft-Encoder).|
| `` ROTATION_TWO_ODOM``  | Use this configuration if you are using the [v5 Rotation Sensors](https://kb.vex.com/hc/en-us/articles/360051368331-Using-the-V5-Rotation-Sensor).  |

---

### With two rotated tracking wheels
If you have two tracking wheels, you can rotate both of them. This way, you can make better use of the space on your robot.

With lightning, you can use this configuration. The tracking wheels need to be rotated -45 degrees.

The available configurations are the following: 

| Odometry configuration    |  |
| ------------- | ------------- |
| ``ADI_TWO_ROTATED_ODOM``  | Use this configuration if you are using the  [ADI Encoders](https://kb.vex.com/hc/en-us/articles/360039512851-Using-the-V5-3-Wire-Optical-Shaft-Encoder).|
| `` ROTATION_TWO_ROTATED_ODOM``  | Use this configuration if you are using the [v5 Rotation Sensors](https://kb.vex.com/hc/en-us/articles/360051368331-Using-the-V5-Rotation-Sensor).  |

---

## Check your chassis information
To declare your chassis is neccesary to provide important information about your chassis. 

 Parameters    |  |
| ------------- | ------------- |
| ``left_side_ports``  | A vector/list of the left motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``right_side_ports``  | A vector/list of the right motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``gyro_port``  | The IMU port.|
| ``gearset``  |  What is the cartridge of you drivetrain (blue,green, red)?|
| ``wheel_diameter``  |  What is the side of the drivetrain wheels in **inches**?|
| ``gear_ratio``  |  What is the gear ratio (Is the result of Driven/Driving, Drive:Driving)?|

:::info
You can create a chassis with ``n`` number of motors by side. Just provide the ports of the motors. 
:::

---

## Check your odometry information. 
To declare your chassis is neccesary to provide important information about your odometry configuration.

|Parameters    |  | 
| ------------- | ------------- |
| ``odom_config``  |What odometry configuration you would like to use?.| 
| ``Forward_Tracker_diameter``  |  The wheel diameter of your forward tracker **(must to be in inches)**.|
| ``Forward_Tracker_distance_to_center``  |  The distance that exist between the forward tracker  and the robot center point **(must to be in inches)**.|
| ``Sideways_Tracker_diameter``  |  The wheel diameter of your sideways tracker **(must to be in inches)**.|
| ``Sidways_Tracker_distance_to_center``  |  The distance that exist between the sideways tracker  and the robot center point **(must to be in inches)**.|

### If you are using ADI Encoders
:::warning
The ADI encoder ports need to be connected together. For example, if the top wire is connected to the 'A' port, the bottom wire needs to be connected to the 'B' port.

In lightning, you indicate the ADI ports using numbers, as follows:

* 1 -> 'A' port
* 2 -> 'B' port 
* 3 -> 'C' port
* 4 -> 'D' port 
* 5 -> 'E' port
* 6 -> 'F' port 
* 7 -> 'G' port 
* 8 -> 'H' port 

Please keep this in mind! Introducing letters to the constructor will not work; use numbers instead.
:::

| Parameters    |  |
| ------------- | ------------- |
| ``Encoder_Forward_Tracker_ports``  | Forward ADI ENCODER PORTS **(using a negative number will reverse it!)**!|
| ``Encoder_SideWays_Tracker_ports``  |Sideways ADI ENCODER PORTS **(using a negative number will reverse it!)**, setting -1,-1 would cancel the tracker!|

### If you are using v5 Rotation Sensors
| Parameters    |  |
| ------------- | ------------- |
| ``Rotation_Forward_Tracker_port``  | Forward V5 ROTATION SENSOR PORT **(using a negative number will reverse it!)**!|
| ``Rotation_SideWays_Tracker_port``  | Sideways V5 ROTATION SENSOR PORT **(using a negative number will reverse it!)**!, setting 0, would cancel the tracker|

---

## Declaring NO_ODOM 

```cpp title="main.cpp"
//Chassis declaration, name of my_chassis
lightning::TankChassis my_chassis( 
 //Odometry configuration/ chassis without odometry 
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
```
---
## Declaring ADI_ONE_ODOM
In this configuration is vital to cancel the ``sideways tracker``, because you are using only one tracking wheel.
For this reason, we cancel the ``sideways tracker`` by setting the ports in this way ``{-1,-1}``. 

```cpp title="main.cpp"
//Chassis declaration using just ONE tracking wheel!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration, with ADI tracking wheel
lightning::tank_odom_e_t::ADI_ONE_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), top wire is connected to A and the bottom wire is connected to B.

2.507, //Forward tracking wheel  diameter in inches
1.783, //Distance that exist between the forward tracker and the robot rotation center.

{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Sideways tracking wheel  diameter
0); //Distance that exist between the Sideways tracker and the robot rotation center.
```
---
## Declaring ADI_TWO_ODOM
```cpp title="main.cpp"
//Chassis declaration using just ONE tracking wheel!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration, with ADI tracking wheel
lightning::tank_odom_e_t::ADI_TWO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), top wire is connected to A and the bottom wire is connected to B.

2.507, //Forward tracking wheel  diameter in inches
1.783, //Distance that exist between the forward tracker and the robot rotation center.

{-3,-4},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!,
//top wire is connected to C and the bottom wire is connected to D.

2.507, //Sideways tracking wheel  diameter
1.783); //Distance that exist between the Sideways tracker and the robot rotation center.
```
---
## Declaring ADI_TWO_ROTATED_ODOM
```cpp title="main.cpp"
//Chassis declaration using just ONE tracking wheel!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration, with ADI tracking wheel
lightning::tank_odom_e_t::ADI_TWO_ROTATED_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), top wire is connected to A and the bottom wire is connected to B.

2.507, //Forward tracking wheel  diameter in inches
1.783, //Distance that exist between the forward tracker and the robot rotation center.

{-3,-4},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!,
//top wire is connected to C and the bottom wire is connected to D.

2.507, //Sideways tracking wheel  diameter
1.783); //Distance that exist between the Sideways tracker and the robot rotation center.
```
---
## Declaring ROTATION_ONE_ODOM
In this configuration is vital to cancel the ``sideways tracker``, because you are using only one tracking wheel.
For this reason, we cancel the ``sideways tracker`` by setting the port in ``0``. 
```cpp title="main.cpp"
//Chassis declaration using just ONE tracking wheel!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ROTATION_ONE_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

1, //Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!), 
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.

0,//Sideways V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
0, //Sideways tracking wheel  diameter
0 //Distance that exist between the Sideways tracker and the robot rotation center.
); 
```
---
## Declaring ROTATION_TWO_ODOM
```cpp title="main.cpp"
//Chassis declaration using TWO tracking wheels!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ROTATION_TWO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
1, //Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!)
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.

2,//Sideways V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Distance that exist between the Sideways tracker and the robot rotation center.
```
---

## Declaring ROTATION_TWO_ROTATED_ODOM
```cpp title="main.cpp"
//Chassis declaration using TWO ROTATED tracking wheels!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ROTATION_TWO_ROTATED_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

1, //Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!)
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.

2,//Sidways V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Distance that exist between the Sideways tracker and the robot rotation center.
```
## Program autonomous routines 🤖 and driver period 🎮
Now, you can start programming!
:::tip
Check the tutorials to know how program an autonomous routines and the driver period. 
:::

Check how to program the autonomous routines and the [driver period](http://localhost:3000/docs/Tutorials/Driver_period_examples). 

