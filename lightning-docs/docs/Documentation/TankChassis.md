---
sidebar_label: Tank Chassis
sidebar_position: 8
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Tank Chassis

## Constructors

### No Odometry
TankChassis constructor  without odometry. 

<Tabs
  groupId="TankChassis_contructor_no_odometry"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 TankChassis(tank_odom_e_t odom_config,
 const std::initializer_list<std::int8_t>& left_side_ports, 
 const std::initializer_list<std::int8_t>&right_side_ports, 
 const char gyro_port, const pros::motor_gearset_e_t gearset, 
 float wheel_diameter, float gear_ratio);
```
</TabItem>


<TabItem value="example">

```cpp {1,4}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``odom_config``  | What odometry configuration the user want. (This constructor is designated for chassis without odometry system).|
| ``left_side_ports``  | A vector/list of the left motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``right_side_ports``  | A vector/list of the right motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``gyro_port``  | The IMU port.|
| ``gearset``  |  What is the cartridge of you drivetrain (blue,green, red)?|
| ``wheel_diameter``  |  What is the side of the drivetrain wheels ?|
| ``gear_ratio``  |  What is the gear ratio (Is the result of Driven/Driving, Drive:Driving)?|

---

### ADI odometry
TankChassis constructor with odometry using ADI encoders (The red ones).

<Tabs
  groupId="TankChassis_contructor_ADI_odometry"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example 1',  value: 'example', },
    { label: 'Example 2', value: 'example_2',},
    { label: 'Example 3', value: 'example_3',},
  ]
}>

<TabItem value="proto">

```cpp
 TankChassis(tank_odom_e_t odom_config, 
 const std::initializer_list<std::int8_t>& left_side_ports, 
 const std::initializer_list<std::int8_t>&right_side_ports, 
 const char gyro_port, const pros::motor_gearset_e_t gearset, 
 float wheel_diameter, 
 float gear_ratio,
 const std::vector<int>& Encoder_Forward_Tracker_ports, 
 const float  Forward_Tracker_diameter, 
 const float  Forward_Tracker_distance_to_center,
 const std::vector<int>&Encoder_SideWays_Tracker_ports,
 const float SideWays_Tracker_wheel_diameter, 
 const float SideWays_Tracker_distance_to_center);
```
</TabItem>


<TabItem value="example">

```cpp {1,4}
//Chassis declaration using just ONE tracking wheel!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ADI_ONE_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!)
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.
{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Sideways tracking wheel  diameter
0); //Forward tracking wheel  diameter


```
</TabItem>

<TabItem value="example_2">

```cpp {1,4}
//Chassis declaration using TWO tracking wheels!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ADI_TWO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!)
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.
{-3,-4},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Forward tracking wheel  diameter


```
</TabItem>

<TabItem value="example_3">

```cpp {1,4}
//Chassis declaration using TWO ROTATED tracking wheels!!!!!! 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ADI_TWO_ROTATED_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!)
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.
{-3,-4},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Forward tracking wheel  diameter


```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``odom_config``  |what odometry configuration the user want. (This constructor is designated for chassis with **ADI encoder odometry**).|
| ``left_side_ports``  | A vector/list of the left motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``right_side_ports``  | A vector/list of the right motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``gyro_port``  | The IMU port.|
| ``gearset``  |  What is the cartridge of you drivetrain (blue,green, red)?|
| ``wheel_diameter``  |  What is the side of the drivetrain wheels ?|
| ``gear_ratio``  |  What is the gear ratio (Is the result of Driven/Driving, Drive:Driving)?|
| ``Encoder_Forward_Tracker_ports``  | Forward ADI ENCODER PORTS **(using a negative number will reverse it!)**!|
| ``Forward_Tracker_diameter``  |  The wheel diameter of your forward tracker **(must to be in inches)**.|
| ``Forward_Tracker_distance_to_center``  |  the distance that exist between the forward tracker  and the robot center point **(must to be in inches)**.|
| ``Encoder_SideWays_Tracker_ports``  |//SIDEWAYS ADI ENCODER PORTS **(using a negative number will reverse it!)**, setting -1,-1 would cancel the tracker!|
| ``Sideways_Tracker_diameter``  |  The wheel diameter of your sideways tracker **(must to be in inches)**.|
| ``Sidways_Tracker_distance_to_center``  |  the distance that exist between the sideways tracker  and the robot center point **(must to be in inches)**.|

---

### V5 Rotation Sensor Odometry
TankChassis constructor with odometry using the V5 rotation sensors. 


<Tabs
  groupId="TankChassis_contructor_v5_odometry"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example 1',  value: 'example', },
    { label: 'Example 2', value: 'example_2',},
    { label: 'Example 3', value: 'example_3',},
  ]
}>

<TabItem value="proto">

```cpp
 TankChassis(tank_odom_e_t odom_config, 
 const std::initializer_list<std::int8_t>& left_side_ports, 
 const std::initializer_list<std::int8_t>&right_side_ports, 
 const char gyro_port, const pros::motor_gearset_e_t gearset, 
 float wheel_diameter, 
 float gear_ratio,
 const int Rotation_Forward_Tracker_ports, 
 const float  Forward_Tracker_diameter, 
 const float  Forward_Tracker_distance_to_center,
 const int Rotation_SideWays_Tracker_ports,
 const float SideWays_Tracker_wheel_diameter, 
 const float SideWays_Tracker_distance_to_center);
```
</TabItem>


<TabItem value="example">

```cpp {1,4}
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
0,//Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
0, //Sideways tracking wheel  diameter
0); //Forward tracking wheel  diameter


```
</TabItem>

<TabItem value="example_2">

```cpp {1,4}
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
2,//Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Forward tracking wheel  diameter

```
</TabItem>

<TabItem value="example_3">

```cpp {1,4}
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
2,//Forward V5 ROTATION SENSOR PORT (using a negative number will reverse it!), setting 0 would cancel the tracker!
2.507, //Sideways tracking wheel  diameter
1.783); //Forward tracking wheel  diameter


```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``odom_config``  |what odometry configuration the user want. (This constructor is designated for chassis with **ADI encoder odometry**).|
| ``left_side_ports``  | A vector/list of the left motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``right_side_ports``  | A vector/list of the right motors ports of the drivetrain **(using a negative number will reverse it!)**.|
| ``gyro_port``  | The IMU port.|
| ``gearset``  |  What is the cartridge of you drivetrain (blue,green, red)?|
| ``wheel_diameter``  |  What is the side of the drivetrain wheels ?|
| ``gear_ratio``  |  What is the gear ratio (Is the result of Driven/Driving, Drive:Driving)?|
| ``Rotation_Forward_Tracker_ports``  | Forward V5 ROTATION SENSOR PORT **(using a negative number will reverse it!)**!|
| ``Forward_Tracker_diameter``  |  The wheel diameter of your forward tracker **(must to be in inches)**.|
| ``Forward_Tracker_distance_to_center``  |  the distance that exist between the forward tracker  and the robot center point **(must to be in inches)**.|
| ``Rotation_SideWays_Tracker_ports``  |Sideways V5 ROTATION SENSOR PORT **(using a negative number will reverse it!)**!|
| ``Sideways_Tracker_diameter``  |  The wheel diameter of your sideways tracker **(must to be in inches)**.|
| ``Sidways_Tracker_distance_to_center``  |  the distance that exist between the sideways tracker  and the robot center point **(must to be in inches)**.|

---

## PID Functions

### set_drive_constants()
Sets the ``drive_pid`` constants for the Drive ``PID`` controller. 

<Tabs
  groupId="TankChassis_pid_functions_drive_constants"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_drive_constants(float kp , float ki , float kd, float max, float scale, float integral_power_limit,float derivative_tolerance); 
```
</TabItem>


<TabItem value="example">

```cpp {14}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``kp``  | Proportional constant.|
| ``ki``  | Integral constant. |
| ``kd``  | Derivative constant.  |
| ``max``  | PID max output. |
| ``scale``  | PID scale.|
| ``integral_power_limit``  | The Integral_power_limit. |
| ``derivative_tolerance``  | How much the derivative would affect?. |

---

### set_drive_exit_conditions()
Sets the ``drive_pid`` exit conditions, conditions that would make that Drive ``PID`` controller stops

<Tabs
  groupId="TankChassis_pid_functions_drive_exit"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_drive_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec); 
```
</TabItem>


<TabItem value="example">

```cpp {15}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

### set_drive_scale()
Sets the ``drive_pid`` scale. 

<Tabs
  groupId="TankChassis_pid_functions_drive_scale"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_drive_scale(const float scale); 
```
</TabItem>


<TabItem value="example">

```cpp {19}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 
    /*
    Doing something...
    */
    my_chassis.set_drive_scale(.5); //Reducing the PID output. Using just 50% of the power. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

### set_turn_constants()
Sets the ``turn_pid`` constants for the Turn ``PID`` controller. 

<Tabs
  groupId="TankChassis_pid_functions_turn_constants"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_turn_constants(float kp , float ki , float kd, float max, float scale, float integral_power_limit,float derivative_tolerance); 
```
</TabItem>


<TabItem value="example">

```cpp {14}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``kp``  | Proportional constant.|
| ``ki``  | Integral constant. |
| ``kd``  | Derivative constant.  |
| ``max``  | PID max output. |
| ``scale``  | PID scale.|
| ``integral_power_limit``  | The Integral_power_limit. |
| ``derivative_tolerance``  | How much the derivative would affect?. |

---

### set_turn_exit_conditions()
Sets the ``turn_pid`` exit conditions, conditions that would make that Turn ``PID`` controller stops

<Tabs
  groupId="TankChassis_pid_functions_turn_exit"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_turn_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec); 
```
</TabItem>


<TabItem value="example">

```cpp {15}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

### set_turn_scale()
Sets the ``turn_pid`` scale. 

<Tabs
  groupId="TankChassis_pid_functions_turn_scale"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_turn_scale(const float scale); 
```
</TabItem>


<TabItem value="example">

```cpp {19}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    /*
    Doing something...
    */
    my_chassis.set_turn_scale(.5); //Reducing the PID output. Using just 50% of the power. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

### set_swing_constants()
Sets the ``swing_pid`` constants for the Swing ``PID`` controller. 

<Tabs
  groupId="TankChassis_pid_functions_swing_constants"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_swing_constants(float kp , float ki , float kd, float max, float scale, float integral_power_limit,float derivative_tolerance); 
```
</TabItem>


<TabItem value="example">

```cpp {14}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``kp``  | Proportional constant.|
| ``ki``  | Integral constant. |
| ``kd``  | Derivative constant.  |
| ``max``  | PID max output. |
| ``scale``  | PID scale.|
| ``integral_power_limit``  | The Integral_power_limit. |
| ``derivative_tolerance``  | How much the derivative would affect?. |

---

### set_swing_exit_conditions()
Sets the ``swing_pid`` exit conditions, conditions that would make that Swing ``PID`` controller stops

<Tabs
  groupId="TankChassis_pid_functions_swing_exit"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_swing_exit_conditions(float error_tolerance, float jump_time_msec, float stop_time_msec); 
```
</TabItem>


<TabItem value="example">

```cpp {15}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

### set_swing_scale()
Sets the ``swing_pid`` scale. 

<Tabs
  groupId="TankChassis_pid_functions_swing_scale"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_swing_scale(const float scale); 
```
</TabItem>


<TabItem value="example">

```cpp {19}
//Chassis declaration
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter
1.3333); //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)

void autonomous(){
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 
    /*
    Doing something...
    */
    my_chassis.set_swing_scale(.5); //Reducing the PID output. Using just 50% of the power. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``error_tolerance``  | The error tolerance for the controller.|
| ``jump_time_msec``  | The jump time limit in milliseconds. |
| ``stop_time_msec``  | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero. |

---

## Motion Functions 
Some motion functions uses **okapi units** to give more variety. 

To learn more about okapi units, check [here](https://okapilib.github.io/OkapiLib/md_docs_api_units.html).
### move_velocity()
Sets the velocity for the motors chassis.

:::note
This velocity corresponds to different actual speeds depending on the gearset
used for the chassis. This results in a range of +-100 for E_MOTOR_GEARSET_36,
+-200 for E_MOTOR_GEARSET_18, and +-600 for E_MOTOR_GEARSET_6. The velocity
is held with PID to ensure consistent speed, as opposed to setting the
motor's voltage.
:::

<Tabs
  groupId="TankChassis_motion_functions_move_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void move_velocity(const int rpm); 
```
</TabItem>


<TabItem value="example">

```cpp {14}

void autonomous(){
    my_chassis.move_velocity(500); //Running the Robot at 500 RPM. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``rpm``  | The new motors chassis velocity from +-100, +-200, or +-600 depending on the motor's gearset|

---

### move_voltage()
Sets the output voltage for the motors chassis from -12000 to 12000 in millivolts. 

This function uses the following values of errno when an error state is reached:

<Tabs
  groupId="TankChassis_motion_functions_move_voltage"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void move_voltage(const int voltage_mv);
```
</TabItem>


<TabItem value="example">

```cpp {14}


void autonomous(){
    my_chassis.move_voltage(8000); //
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``voltage_mv``  |  The new voltage value from -12000 to 12000 millivolts.|

---

### move()
Sets the voltage for the motors chassis from -127 to 127.

This is designed to map easily to the input from the controller's analog stick for simple opcontrol use.

<Tabs
  groupId="TankChassis_motion_functions_move"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void move(const int voltage); 
```
</TabItem>


<TabItem value="example">

```cpp {14}

void autonomous(){
    my_chassis.move(-127);
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``voltage``  |  The new motors chassis voltage from -127 to 127.|

---

### drive_to_point() 
Drives the robot from a starting point to a target point. **Different versions of this function are available below.** 

:::note
The robot **MUST** to be facing the target point. 
:::

#### Using custom PID controllers and inches units. 
Drives the robot from a starting point to a target point using custom ``PID`` controller (Created for the user) and in **inches units**.

<Tabs
  groupId="TankChassis_motion_drive_to_point_custom_pid_inches"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<double> target, bool reverse); 
```
</TabItem>


<TabItem value="example">

```cpp {24}

void autonomous(){

    lightning::PID drive_controller (5,.001,2,10,1); 
    drive_controller.set_stop_time(2000);
    drive_controller.set_error_tolerance(1); 
    drive_controller.set_derivative_tolerance(50); 
    drive_controller.set_integral_power_limit(100); 
    drive_controller.set_jump_time(500);
    drive_controller.set_max(600); 
    drive_controller.set_min(0); 


    lightning::PID turn_controller (2.5,.001,1,10,1); 

    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.drive_to_point(drive_controller,turn_controller, {0,24}, false); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``drive_controller``  |  A ``PID`` controller designated for controlling the forward and backward movements of the robot.|
| ``turn_controller``  |   A ``PID`` controller designated for turns. |
| ``target``  |  The target point ``{x,y}`` in **inches**. |
| ``reverse``  | The direction. ``true`` if you want to go backwards, `false` if you want to go forward. |

---

#### Using custom PID controllers and okapi units. 

Drives the robot from a starting point to a target point using custom PID controller (Created for the user) using okapi units.

<Tabs
  groupId="TankChassis_motion_drive_to_point_custom_pid_okapi_units"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_to_point(PID& drive_controller, PID& turn_controller, std::vector<okapi::QLength> target, bool reverse); 
```
</TabItem>


<TabItem value="example">

```cpp {24}

void autonomous(){

    lightning::PID drive_controller (5,.001,2,10,1); 
    drive_controller.set_stop_time(2000);
    drive_controller.set_error_tolerance(1); 
    drive_controller.set_derivative_tolerance(50); 
    drive_controller.set_integral_power_limit(100); 
    drive_controller.set_jump_time(500);
    drive_controller.set_max(600); 
    drive_controller.set_min(0); 


    lightning::PID turn_controller (2.5,.001,1,10,1); 

    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.drive_to_point(drive_controller,turn_controller, {0_in,24_in}, false); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``drive_controller``  |  A ``PID`` controller designated for controlling the forward and backward movements of the robot.|
| ``turn_controller``  |   A ``PID`` controller designated for turns. |
| ``target``  |  The target point ``{x,y}`` in **okapi units**,for example could be in inches, centimeters, meters, etc. |
| ``reverse``  | The direction. ``true`` if you want to go backwards, `false` if you want to go forward. |

---

#### Using ``drive_pid`` , ``turn_pid`` and inches units.  
Drives the robot from a starting point to a target point using the ``Drive`` and ``Turn`` ``PID`` .

<Tabs
  groupId="TankChassis_motion_drive_to_point_pid_inches"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_to_point(std::vector<double>target, bool reverse); 
```
</TabItem>


<TabItem value="example">

```cpp {9}

void autonomous(){
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 

    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    my_chassis.drive_to_point({0,24},false); //USING THE my_chassis drive and turn pid! 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``target``  |  The target point ``{x,y}`` in **inches** |
| ``reverse``  | The direction. ``true`` if you want to go backwards, `false` if you want to go forward. |

---

#### Using ``drive_pid`` , ``turn_pid`` and okapi units.  
Drives the robot from a starting point to a target point using the ``Drive`` and ``Turn`` ``PID`` using **okapi units**.

<Tabs
  groupId="TankChassis_motion_drive_to_point_pid_okapi_units"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">
```cpp
void drive_to_point(std::vector<okapi::QLength> target, bool reverse); 
```
</TabItem>


<TabItem value="example">

```cpp {9}

void autonomous(){
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 

    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    my_chassis.drive_to_point({0_in,24_in},false); //USING THE my_chassis drive and turn pid! 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``target``  |  The target point ``{x,y}`` in **okapi units**  for example could be in inches, centimeters, meters, etc.  |
| ``reverse``  | The direction. ``true`` if you want to go backwards, `false` if you want to go forward. |

---

### follow_path()
Drives the robot to follow a pre-computaded path using **pure pursuit**. 

**Different versions of this function are available below.**
:::tip
You can see more information about **pure pursuit**  [here](https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html)
:::

#### Using custom PID. 
Drives the robot to follow a pre-computaded path using PID controllers created for the user. 

<Tabs
  groupId="TankChassis_motion_follow_path_custom_pid"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void follow_path(Path &path, PID& drive_controller,PID&turn_controller, float look_ahead_distance); 

```
</TabItem>


<TabItem value="example">

```cpp {32}

lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3);  //PATH

void autonomous(){
    //Path stuff
    goal_path.upgrade()
    goal_path.set_max_lineal_velocity(10); //10 (inches/second).
    goal_path.make_cals(); 
    pros::delay(10); //giving some time to make the calculations. 
    //////////////////////////////////////////////

    //Tunning Custom PID controllers 
    lightning::PID drive_controller (5,.001,2,10,1); 
    drive_controller.set_stop_time(2000);
    drive_controller.set_error_tolerance(1); 
    drive_controller.set_derivative_tolerance(50); 
    drive_controller.set_integral_power_limit(100); 
    drive_controller.set_jump_time(500);
    drive_controller.set_max(600); 
    drive_controller.set_min(0); 

    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 
    ////////////////////////////////////////////////////////////////////
    
    my_chassis.follow_path(goal_path,drive_controller,turn_controller,12); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``path``  |   A desired path created by the Path class. |
| ``drive_controller``  | A PID controller designated for controlling the forward and backward movements of the robot.   |
| ``turn_controller``  | A PID controller designated for turns.  |
| ``look_ahead_distanc``  | The look ahead distance. It its important for the pure pursuit calculations see more information [here](https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html).  |
---

#### Using ``drive_pid`` and ``turn_pid``
Drives the robot to follow a pre-computaded path using the ``Drive`` and ``Turn`` PIDS from tank chassis class.  

<Tabs
  groupId="TankChassis_motion_follow_path_pid"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void follow_path(Path&path,float look_ahead_distance);

```
</TabItem>


<TabItem value="example">

```cpp {21}

lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3);  //PATH

void autonomous(){
    //Path stuff
    goal_path.upgrade()
    goal_path.set_max_lineal_velocity(10); //10 (inches/second).
    goal_path.make_cals(); 
    pros::delay(10); //giving some time to make the calculations. 
    //////////////////////////////////////////////

    //Tunning Drive and turn. 
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 

    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    //////////
    
    my_chassis.follow_path(goal_path,12); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``path``  |   A desired path created by the Path class. |
| ``look_ahead_distanc``  | The look ahead distance. It its important for the pure pursuit calculations see more information [here](https://la.mathworks.com/help/nav/ug/pure-pursuit-controller.html).  |
---

### move_with_motion_profile()
Drives the robot using a trapezoidal profile.

<Tabs
  groupId="TankChassis_motion_motion_profile"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void move_with_motion_profile(TrapezoidalProfile& profile); 

```
</TabItem>


<TabItem value="example">

```cpp {4}
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec
    my_chassis.move_with_motion_profile(test_profile); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``profile``  |   The trapezoidal profile.  |

---

### raw_drive_distance()
Drives the robot to a certain distance and velocity in RPM, using the PROS move_absolute function.

:::note 
A positive distance means that the robot needs to move forward, while a negative distance means that the robot needs to move backwards. 
:::

**Different versions of this function are available below.**

#### Using inches. 

:::note
The user needs to set how many inches the robot would move. 
:::

<Tabs
  groupId="TankChassis_motion_raw_drive_distance_inches"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void raw_drive_distance(double distance, const int vel_rpm);  

```
</TabItem>


<TabItem value="example">

```cpp {2,5}
void autonomous(){
    my_chassis.raw_drive_distance(24,300); //Moving the robot 24 inches forward at 300 RPM.
    pros::delay(1500); //Waiting
    my_chassis.stop(); //After 1.5 seconds that robot start moving Stops the chassis. 
    my_chassis.raw_drive_distance(-24,300); //Moving the robot 24 inches backwards at 300 RPM. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``distance``  |   How many inches do you want that the robot moves? (with a negative distance your robot would go in backwards) |
| ``vel_rpm``  |   What would be the drive base motors velocity in RPM?   |

---


#### Using okapi units. 

:::note
The user needs to set how many distance the robot would move. 
:::

<Tabs
  groupId="TankChassis_motion_raw_drive_distance_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void raw_drive_distance(const okapi::QLength distance, const int vel_rpm); 

```
</TabItem>


<TabItem value="example">

```cpp {2,5,8}
void autonomous(){
    my_chassis.raw_drive_distance(24_in,300); //Moving the robot 24 inches forward at 300 RPM.
    pros::delay(1500); //Waiting
    my_chassis.stop(); //After 1.5 seconds that robot start moving Stops the chassis. 
    my_chassis.raw_drive_distance(-24_in,300); //Moving the robot 24 inches backwards at 300 RPM. 
    pros::delay(1500); //Waiting
    my_chassis.stop(); //After 1.5 seconds that robot start moving Stops the chassis. 
    my_chassis.raw_drive_distance(1_ft,300); //Moving the robot 1 foot forward at 300 RPM. 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``distance``  |   How much distance the robot would move?, Using **okapi units** (with a negative distance your robot would go in backwards). |
| ``vel_rpm``  |   What would be the drive base motors velocity in RPM?   |

---

### drive_distance()
Drives the robot to a specified distance using PID controllers.
:::note 
The function will block the program execution until it completes. Once finished, the program will resume and continue running subsequent lines of code.
:::
**Different versions of this function are available below.**

#### Using custom PIDs and units of inches and degrees.
This function controls the robot to move a certain distance using a user-defined ``PID`` controller for **forward** and **backward** movements, while also maintaining alignment using a separate ``PID`` controller for **turns**.

<Tabs
  groupId="TankChassis_motion_drive_distance_custom_pid_inches_deg"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_distance(PID& drive_control, PID& turn_control, double distance, double target_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {22,23,25,26}
void autonomous(){
    //Tunning Custom PID controllers 
    lightning::PID drive_controller (5,.001,2,10,1); 
    drive_controller.set_stop_time(2000);
    drive_controller.set_error_tolerance(1); 
    drive_controller.set_derivative_tolerance(50); 
    drive_controller.set_integral_power_limit(100); 
    drive_controller.set_jump_time(500);
    drive_controller.set_max(600); 
    drive_controller.set_min(0); 

    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 
    ////////////////////////////////////////////////////////////////////

    //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(drive_controller,turn_controller,24,0); 

    //Running 48 inches in a straight line at a 0-degree orientation in backwards.
    my_chassis.drive_distance(drive_controller,turn_controller,-48,0); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``drive_control``  | A ``PID`` controller designated for controlling the forward and backward movements of the robot. |
| ``turn_control``  |  A ``PID`` controller designated for controlling the turns of the robot.   |
| ``distance``  |  The distance in **inches** that you want the robot to move (with a negative distance your robot would go in backwards).  |
| ``target_orientation``  |  The target orientation in which you want the robot to stay in **degrees**.  |

---

#### Using custom PIDs and okapi units.

This function controls the robot to move a certain distance using a user-defined ``PID`` controller for **forward** and **backward** movements, while also maintaining alignment using a separate ``PID`` controller for **turns**. ***This functions uses okapi units***. 

<Tabs
  groupId="TankChassis_motion_drive_distance_custom_pid_okapi_units"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_distance(PID& distance_control, PID& turn_controller, 
const okapi::QLength distance, const okapi::QAngle  target_orientation);  

```
</TabItem>


<TabItem value="example">

```cpp {22,23,25,26}
void autonomous(){
    //Tunning Custom PID controllers 
    lightning::PID drive_controller (5,.001,2,10,1); 
    drive_controller.set_stop_time(2000);
    drive_controller.set_error_tolerance(1); 
    drive_controller.set_derivative_tolerance(50); 
    drive_controller.set_integral_power_limit(100); 
    drive_controller.set_jump_time(500);
    drive_controller.set_max(600); 
    drive_controller.set_min(0); 

    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 
    ////////////////////////////////////////////////////////////////////

    //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(drive_controller,turn_controller,24_in,0_deg); 

    //Running 2 tile in a straight line at a 0-radians orientation in backwards.
    my_chassis.drive_distance(drive_controller,turn_controller,-2_tiles,0_rad); 
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``drive_control``  | A ``PID`` controller designated for controlling the forward and backward movements of the robot. |
| ``turn_control``  |  A ``PID`` controller designated for controlling the turns of the robot.   |
| ``distance``  |  The distance in **okapi units** (inches,centimeters,tiles,etc) that you want the robot to move (with a negative distance your robot would go in backwards).  |
| ``target_orientation``  |  The target orientation in which you want the robot to stay in **okapi units** (radians,degrees).  |

---

#### Using ``drive_pid`` , ``turn_pid`` and units of inches and degrees. 
This function controls the robot to move a certain distance using the ``drive_pid`` ,while also maintaining alignment using a ``turn_pid`` controller for turns. Using units of ***inches and degrees***. 

<Tabs
  groupId="TankChassis_motion_drive_distance_drive_pid,turn_pid,inches_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_distance(const double distance, const double target_orientation);  

```
</TabItem>


<TabItem value="example">

```cpp {10}
void autonomous(){
    //Tunning Drive and turn. 
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 

    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(24,0); 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``distance``  |  The distance in **inches** that you want the robot to move (with a negative distance your robot would go in backwards).  |
| ``target_orientation``  |  The target orientation in which you want the robot to stay in **degrees**  |

---

#### Using ``drive_pid`` , ``turn_pid`` and okapi units 
This function controls the robot to move a certain distance using the ``drive_pid`` ,while also maintaining alignment using a ``turn_pid`` controller for turns. Using ***okapi units***.

<Tabs
  groupId="TankChassis_motion_drive_distance_drive_pid,turn_pid,okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void drive_distance(const okapi::QLength distance, const okapi::QAngle target_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {10}
void autonomous(){
    //Tunning Drive and turn. 
    my_chassis.set_drive_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_drive_exit_conditions(1,350,2000); 

    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    //Running 24 inches in a straight line at a 0-degree orientation.  
    my_chassis.drive_distance(24_in,0_deg); 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``distance``  |  The distance in **okapi units** (inches,centimeters,tiles,etc) that you want the robot to move (with a negative distance your robot would go in backwards).  |
| ``target_orientation``  |  The target orientation in which you want the robot to stay in **okapi units** (radians,degrees).  |

---

### turn_absolute()
Makes the robot turn to a certain orientation using a ``PID`` controller. 
:::note
The turning direction is determinated depending of which direction means less travel.  
:::

#### Using custom ``PID`` and units of degrees. 

<Tabs
  groupId="TankChassis_motion_turn_absolute_custom_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_absolute(PID&turn_control,double target_orientation);

```
</TabItem>


<TabItem value="example">

```cpp {11-13}
void autonomous(){
    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.turn_absolute(turn_controller,180); //turning 180 degrees. 
    my_chassis.turn_absolute(turn_controller,270); //turning 270 degrees. 
    my_chassis.turn_absolute(turn_controller,360); //turning 360 degrees. 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``turn_control``  |  The user ``PID`` controller.|
| ``target_orientation``  |  The target orientation in **degrees**.  |

---

#### Using custom ``PID`` and okapi units.

<Tabs
  groupId="TankChassis_motion_turn_absolute_custom_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void turn_absolute(PID& turn_control,okapi::QAngle target_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {11-13}
void autonomous(){
    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.turn_absolute(turn_controller,180_deg); //turning 180 degrees. 
    my_chassis.turn_absolute(turn_controller,270_deg); //turning 270 degrees. 
    my_chassis.turn_absolute(turn_controller,3.1415_rad); //turning pi radians = turning 180 degrees.  
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``turn_control``  |  The user ``PID`` controller.|
| ``target_orientation``  |  The target orientation in **okapi units**.  |

---

#### Using ``turn_pid`` and units of degrees

<Tabs
  groupId="TankChassis_motion_turn_absolute_turn_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_absolute(double target_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 

    my_chassis.turn_absolute(180); //turning 180 degrees. 
    my_chassis.turn_absolute(270); //turning 270 degrees. 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``target_orientation``  |  The target orientation in **degrees**.  |

---

#### Using ``turn_pid`` and okapi units

<Tabs
  groupId="TankChassis_motion_turn_absolute_turn_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_absolute(okapi::QAngle target_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {6-8}
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 

    my_chassis.turn_absolute(180_deg); //turning 180 degrees. 
    my_chassis.turn_absolute(270_deg); //turning 270 degrees. 
    my_chassis.turn_absolute(3.1415_rad); //turning pi radians = turning 180 degrees.  
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``target_orientation``  |  The target orientation in **okapi units**.  |

---


### turn_relative()
Turns the robot certain number of degrees, positive if the robot needs to turn right or negative if the robot needs to turn left. 

:::note
The turning direction is determinated depending of which direction means less travel.  
:::

#### Using custom ``PID`` and units of degrees. 

<Tabs
  groupId="TankChassis_motion_turn_relative_custom_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_relative(PID&turn_control,double degrees);

```
</TabItem>


<TabItem value="example">

```cpp {11-13}
void autonomous(){
    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.turn_relative(turn_controller,180); //turning 180 degrees. 
    my_chassis.turn_relative(turn_controller,90); //turning 90 degrees, current heading 270. 
    my_chassis.turn_relative(turn_controller,-90); //turning -90 degrees, current heading 180. 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``turn_control``  |  The user ``PID`` controller.|
| ``degrees``  | How many **degrees** would turn?  |

---

#### Using custom ``PID`` and okapi units

<Tabs
  groupId="TankChassis_motion_turn_relative_custom_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void turn_relative(PID& turn_control,okapi::QAngle degrees); 

```
</TabItem>


<TabItem value="example">

```cpp {11-13}
void autonomous(){
    lightning::PID turn_controller (2.5,.001,1,10,1); 
    turn_controller.set_stop_time(1000);
    turn_controller.set_error_tolerance(.15); 
    turn_controller.set_derivative_tolerance(50); 
    turn_controller.set_integral_power_limit(100); 
    turn_controller.set_jump_time(250);
    turn_controller.set_max(450); 
    turn_controller.set_min(0); 

    my_chassis.turn_relative(turn_controller,180_deg); //turning 180 degrees. 
    my_chassis.turn_relative(turn_controller,90_deg); //turning 90 degrees, current heading 270. 
    my_chassis.turn_relative(turn_controller,-90_deg); //turning -90 degrees, current heading 180. 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``turn_control``  |  The user ``PID`` controller.|
| ``degrees``  |  How many **okapi units** would turn?  |

---

#### Using ``turn_pid`` and units of degrees

<Tabs
  groupId="TankChassis_motion_turn_relative_turn_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_relative(double degrees); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 

    my_chassis.turn_relative(180); //turning 180 degrees. 
    my_chassis.turn_relative(90); //turning 90 degrees, current heading 270. 
    my_chassis.turn_relative(-90); //turning -90 degrees, current heading 180. 
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``degrees``  | How many **degrees** would turn?   |

---

#### Using ``turn_pid`` and okapi units

<Tabs
  groupId="TankChassis_motion_turn_relative_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void turn_relative(okapi::QAngle degrees); 

```
</TabItem>


<TabItem value="example">

```cpp {6-8}
void autonomous(){
    //Tunning turn_pid
    my_chassis.set_turn_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_turn_exit_conditions(1,350,2000); 
    
    my_chassis.turn_relative(180_deg); //turning 180 degrees. 
    my_chassis.turn_relative(90_deg); //turning 90 degrees, current heading 270. 
    my_chassis.turn_relative(-90_deg); //turning -90 degrees, current heading 180. 
   
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``degrees``  |  How many **okapi units** would turn?   |

---

### swing_turn_absolute()
Makes the robot turn to a certain orientation using a user-defined PID controller, blocking one side of the drive train, making a *swing*. 

:::note
The turning direction is determinated depending of which direction means less travel.
:::

#### Using custom ``PID`` and units of degrees
<Tabs
  groupId="TankChassis_motion_swing_turn_custom_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void swing_turn_absolute(PID&swing_control, lightning::swing_direction_e_t swing_direction, 
double target_orientation, const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {12-13}
void autonomous(){
    //Tunning PID 
     lightning::PID swing_controller (2.5,.001,1,10,1); 
    swing_controller.set_stop_time(1000);
    swing_controller.set_error_tolerance(.15); 
    swing_controller.set_derivative_tolerance(50); 
    swing_controller.set_integral_power_limit(100); 
    swing_controller.set_jump_time(250);
    swing_controller.set_max(450); 
    swing_controller.set_min(0); 
    
    my_chassis.swing_turn_absolute (swing_controller, LEFT_SWING, 90);
    my_chassis. swing_turn_absolute (swing_controller, LEFT_SWING, 270);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_control``  |  The user ``PID`` controller.  |
| ``swing_direction``  | What side do you want to block?    |
| ``target_orientation``  | The target orientation in **degrees**.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

#### Using custom ``PID`` and okapi units
<Tabs
  groupId="TankChassis_motion_swing_turn_custom_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void swing_turn_absolute( PID& swing_control, lightning::swing_direction_e_t swing_direction, 
 okapi::QAngle target_orientation, const int opposite_speed_rpm=0);  

```
</TabItem>


<TabItem value="example">

```cpp {12-13}
void autonomous(){
    //Tunning PID 
     lightning::PID swing_controller (2.5,.001,1,10,1); 
    swing_controller.set_stop_time(1000);
    swing_controller.set_error_tolerance(.15); 
    swing_controller.set_derivative_tolerance(50); 
    swing_controller.set_integral_power_limit(100); 
    swing_controller.set_jump_time(250);
    swing_controller.set_max(450); 
    swing_controller.set_min(0); 
    
    my_chassis.swing_turn_absolute (swing_controller, LEFT_SWING, 90_deg);
    my_chassis.swing_turn_absolute (swing_controller, LEFT_SWING, 270_deg);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_control``  |  The user ``PID`` controller.  |
| ``swing_direction``  | What side do you want to block?    |
| ``target_orientation``  | The target orientation in **okapi units**.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

#### Using ``swing_pid`` and units of degrees
<Tabs
  groupId="TankChassis_motion_swing_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  void swing_turn_absolute(lightning::swing_direction_e_t swing_direction, double target_orientation, 
  const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning swing_pid
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 

    my_chassis.swing_turn_absolute (LEFT_SWING, 90);
    my_chassis. swing_turn_absolute (LEFT_SWING, 270);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_direction``  | What side do you want to block?    |
| ``target_orientation``  | The target orientation in **degrees**.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

####  Using ``swing_pid`` and okapi units
<Tabs
  groupId="TankChassis_motion_swing_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void swing_turn_absolute(lightning::swing_direction_e_t swing_direction, 
   const okapi::QAngle target_orientation, const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning swing_pid
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 

    my_chassis.swing_turn_absolute (LEFT_SWING, 90_deg);
    my_chassis.swing_turn_absolute (LEFT_SWING, 270_deg);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_direction``  | What side do you want to block?    |
| ``target_orientation``  | The target orientation in **okapi units**.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

### swing_turn_relative()
Makes the robot turn to a certain amount of degrees using a user-defined PID controller, blocking one side of the drive train, making a *swing*. if the robot needs to turn right or negative if the robot needs to turn left. 


#### Using custom ``PID`` and units of degrees
<Tabs
  groupId="TankChassis_motion_swing_turn_relative_custom_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, 
double degrees, const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {12-13}
void autonomous(){
    //Tunning PID 
     lightning::PID swing_controller (2.5,.001,1,10,1); 
    swing_controller.set_stop_time(1000);
    swing_controller.set_error_tolerance(.15); 
    swing_controller.set_derivative_tolerance(50); 
    swing_controller.set_integral_power_limit(100); 
    swing_controller.set_jump_time(250);
    swing_controller.set_max(450); 
    swing_controller.set_min(0); 
    
    my_chassis.swing_turn_relative (swing_controller, LEFT_SWING, 90);
    my_chassis.swing_turn_relative (swing_controller, LEFT_SWING, 270);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_control``  |  The user ``PID`` controller.  |
| ``swing_direction``  | What side do you want to block?    |
| ``degrees``  | how many **degrees** would turn?.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

#### Using custom ``PID`` and okapi units
<Tabs
  groupId="TankChassis_motion_swing_turn_relative_custom_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void swing_turn_relative(PID& swing_control, lightning::swing_direction_e_t swing_direction, 
okapi::QAngle angle, const int opposide_speed_rpm=0);

```
</TabItem>


<TabItem value="example">

```cpp {12-13}
void autonomous(){
    //Tunning PID 
     lightning::PID swing_controller (2.5,.001,1,10,1); 
    swing_controller.set_stop_time(1000);
    swing_controller.set_error_tolerance(.15); 
    swing_controller.set_derivative_tolerance(50); 
    swing_controller.set_integral_power_limit(100); 
    swing_controller.set_jump_time(250);
    swing_controller.set_max(450); 
    swing_controller.set_min(0); 
    
    my_chassis.swing_turn_relative (swing_controller, LEFT_SWING, 90_deg);
    my_chassis.swing_turn_relative (swing_controller, LEFT_SWING, 270_deg);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_control``  |  The user ``PID`` controller.  |
| ``swing_direction``  | What side do you want to block?    |
| ``degrees``  | how many **okapi units** would turn?.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

#### Using ``swing_pid`` and units of degrees
<Tabs
  groupId="TankChassis_motion_swing_relative_pid_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  void swing_turn_relative(lightning::swing_direction_e_t swing_direction, double degrees, const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning swing_pid
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 

    my_chassis.swing_turn_absolute (LEFT_SWING, 90);
    my_chassis.swing_turn_absolute (LEFT_SWING, 270);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_direction``  | What side do you want to block?    |
| ``degrees``  | how many **degrees** would turn?.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

####  Using ``swing_pid`` and okapi units
<Tabs
  groupId="TankChassis_motion_swing_relative_pid_okapi"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void swing_turn_relative(lightning::swing_direction_e_t swing_direction, 
    okapi::QAngle angle, const int opposide_speed_rpm=0); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    //Tunning swing_pid
    my_chassis.set_swing_constants(5 , .001 , 1, 450, 1, 25,50);  
    my_chassis.set_swing_exit_conditions(1,350,2000); 

    my_chassis.swing_turn_absolute (LEFT_SWING, 90_deg);
    my_chassis.swing_turn_absolute (LEFT_SWING, 270_deg);
   
}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``swing_direction``  | What side do you want to block?    |
| ``degrees``  | how many **okapi units** would turn?.  |
| ``opposide_speed_rpm``  | You could add power to the blocked side, however is zero by default.   |

---

### stop()
Stops the chassis.
<Tabs
  groupId="TankChassis_motion_stop"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void stop(); 

```
</TabItem>


<TabItem value="example">

```cpp {6,7}
void autonomous(){
    my_chassis.move_voltage(12000); //running at maximum velocity
    pros::delay(2000); //Wait 2 seconds.
    my_chassis.stop(); //Stops chassis
}

```
</TabItem>

</Tabs>  

---
## Driver functions  
For arcade types, you need to provide one of following configurations: 

| Arcade configurations    | Description |
| ------------- | ------------- |
| `` E_TANK_OP_ARCADE_LEFT``  | Left stick configuration. |
| ``E_TANK_OP_ARCADE_RIGHT``  | Right stick configuration.|
| `` E_TANK_OP_ARCADE_DOUBLE``  |  Double stick configuration. |




### arcade()
Drives the chassis in arcade configuration.

:::note
The default configuration is with the left joystick. 
:::

<Tabs
  groupId="TankChassis_driver_functions_arcade"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void arcade(pros::Controller& control, 
    const lightning::tank_op_arcade_e_t arcade = lightning::E_TANK_OP_ARCADE_LEFT ,
    const float power_rate=1, const float turn_rate=1); 

```
</TabItem>


<TabItem value="example">

```cpp 
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {
   my_chassis.arcade(master);  //DRIVING ROBOT IN ARCADE MODE 

   pros::delay(lightning::util::DELAY_TIME); 
  }
}


```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``control``  | The control. |
| ``arcade``  | The tank_op_arcade_e_t to set for the chassis.|
| ``power_rate``  |  The rate for the forward and backwards movements (Default is 1). |
| ``turn_rate``  | The rate for the right and left turns (Default is 1). |
---

### arcade_exponential()
Drives the chassis in an arcade configuration using a smoothing function for more accurate control.

<Tabs
  groupId="TankChassis_driver_functions_arcade_exponential"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void arcade_exponential(pros::Controller&control, const lightning::tank_op_arcade_e_t arcade, 
                        int n_x, int n_y); 

```
</TabItem>


<TabItem value="example">

```cpp 
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {
   my_chassis.arcade_expontential(master,  E_TANK_OP_ARCADE_LEFT,3,3);  

   pros::delay(lightning::util::DELAY_TIME); 
  }
}



```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``control``  | The control. |
| ``arcade``  | The tank_op_arcade_e_t to set for the chassis.|
| ``n_x``  |  The exponential for the joystick x axis. |
| ``n_y``  | The exponential for the joystick y axis. |

---

### tank()
Drives the chassis in tank configuration. 

<Tabs
  groupId="TankChassis_driver_functions_tank"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void tank(pros::Controller& control); 

```
</TabItem>


<TabItem value="example">

```cpp 
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {
   my_chassis.tank(master); 

   pros::delay(lightning::util::DELAY_TIME); 
  }
}


```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``control``  | The control. |

---
## Telemetry Functions
:::note
The position is recorded in **inches**.
:::
### track_pose()
Tracks and Updates pose. The position and orientation vector (x,y,theta) using odometry.
<Tabs
  groupId="TankChassis_telemetry_track_pose"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void track_pose(); 

```
</TabItem>


<TabItem value="example">

```cpp 
void init_odometry(void*){
    while (1) {
    my_chassis.track_pose();      
  }
}


```
</TabItem>

</Tabs>  

---

### set_coordinates
Sets the coordinates for the odometry position system. 
<Tabs
  groupId="TankChassis_telemetry_set_coordinates"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void set_coordinates(const okapi::QLength x, const okapi::QLength y, const okapi::QAngle orientation_deg);

```
</TabItem>


<TabItem value="example">

```cpp {6}
void initialize() {
 my_chassis.reset_odometry();  
 pros::delay(3000); 

 //Finally, a function to set the initial pose of your robot
 my_chassis.set_coordinates(0_in, 0_in, 0_deg);  

}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``x``  | The x coordinate in **okapi unit**.     |
| ``y``  | The y coordinate in **okapi unit**.  |
| ``orientation``  | The orientation in **okapi unit**. |

---

### set_orientation()
Sets the robot´s absolute orientation in **degrees**. 
<Tabs
  groupId="TankChassis_telemetry_set_orientation"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void set_orientation(okapi::QAngle current_orientation); 

```
</TabItem>


<TabItem value="example">

```cpp {6}
void initialize() {

 my_chassis.set_orientation(0_deg);  

}

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``orientation``  | The orientation in **okapi unit**. |

---

### get_pose()
Gets the current pose (the position and orientation vector).
<Tabs
  groupId="TankChassis_telemetry_get_pose"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   std::vector<double> get_pose(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 std::vector<double> pose; 
 pose = my_chassis.get_pose(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The pose vector.

---

### get_position()
Gets the current position (x,y)
<Tabs
  groupId="TankChassis_telemetry_get_position"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   std::vector<double> get_pose(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 std::vector<double> position; 
 position = my_chassis.get_position(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The position vector. 

---

### get_x()
Gets the current x coordinate in **inches**.
<Tabs
  groupId="TankChassis_telemetry_get_x"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    double get_x() const ; 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double x;  
 x = my_chassis.get_x(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The x coordinate in **inches**.

---

### get_y()
Gets the current **y** coordinate in **inches**.
<Tabs
  groupId="TankChassis_telemetry_get_y"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    double get_y() const ; 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double x;  
 y = my_chassis.get_y(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The y coordinate in **inches**.

---

### get_orientation()
Gets the current orientation (theta) in **degrees**.
<Tabs
  groupId="TankChassis_telemetry_get_orientation"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    double get_orientation() const ; 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double orientation_degrees;  
 orientation_degrees = my_chassis.get_orientation(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The orientation in **degrees**.

---

### get_ForwardTracker_position()
Gets the forwardtracker position value in **inches**. 
<Tabs
  groupId="TankChassis_telemetry_get_forward_tracker"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_ForwardTracker_position(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double forward_tracker_pos;  
 forward_tracker_pos = my_chassis.get_ForwardTracker_position(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The forwardtracker position in **inches**.

---

### get_SideWays_position()
Gets the Sidewaystracker position value in **inches**.

<Tabs
  groupId="TankChassis_telemetry_get_sideways_tracker"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_SideWays_position(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double sideways_tracker_pos;  
 sideways_tracker_pos = my_chassis.get_SideWays_position(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The sidewaystracker position in **inches**. 

---

### get_average_motors_position_deg()
Gets the drive-train average mposition in **degrees**.

<Tabs
  groupId="TankChassis_telemetry_get_avg_motors_pos_deg"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_average_motors_position_deg();

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double motors_chassis_pos;  
 motors_chassis_pos = my_chassis.get_average_motors_position_deg(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **degrees**. 

---

### get_left_position_deg()
Gets the left side of the drive-train average position in **degrees**. 

<Tabs
  groupId="TankChassis_telemetry_get_left_motors_pos_deg"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_left_position_deg(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double chassis_left_position_deg;  
 chassis_left_position_deg= my_chassis.get_left_position_deg(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **degrees**. 

---

### get_right_position_deg()
Gets the right side of the drive-train average position in **degrees**. 
<Tabs
  groupId="TankChassis_telemetry_get_right_motors_pos_deg"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_right_position_deg(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double chassis_right_position_deg;  
 chassis_right_position_deg = my_chassis.get_right_position_deg(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **degrees**. 

---

### get_average_motors_position_inches();
Gets the drive train average position in **inches**. 
<Tabs
  groupId="TankChassis_telemetry_get_average_motors_position_inche"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_average_motors_position_inches();

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double chassis_avg_pos_inches;  
 chassis_avg_pos_inches = my_chassis.get_average_motors_position_inches();
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **inches**.  

---

### get_left_position_inches(); 
Gets the left side  of the drive train average position in **inches**.  
<Tabs
  groupId="TankChassis_telemetry_get_left_position_inch"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_left_position_inches(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double left_position_inches;  
 left_position_inches = my_chassis.get_left_position_inches(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **inches**. 

---

### get_right_position_inches()
Gets the right side  of the drive train average position in **inches**.
<Tabs
  groupId="TankChassis_telemetry_get_right_position_inch"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_right_position_inches(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double right_position_inches;  
 right_position_inches = my_chassis.get_right_position_inches(); 
}

```
</TabItem>

</Tabs>  

**Returns:** The average motor position in **inches**. 

---

### get_actual_rpm()
Gets the current average chassis output velocity **(RPM)** between the left and right sides.

This function calculates and returns the average rotational speed in RPM of the base motors.

:::note
This velocity is the average of the base motors' output.
:::

<Tabs
  groupId="TankChassis_telemetry_get_actual_rpm"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_actual_rpm(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double actual_rpms;  
 actual_rpms = my_chassis.get_actual_rpm(); 
}
```
</TabItem>

</Tabs>  

**Returns:** The average velocity in RPM.

---

### get_actual_velocity()
Gets the current chassis lineal velocity in **distance/seconds**. 

<Tabs
  groupId="TankChassis_telemetry_get_actual_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_actual_velocity(); 

```
</TabItem>


<TabItem value="example">

```cpp {3}
void autonomous() {
 double actual_velocity;  
 actual_velocity = my_chassis.get_actual_velocity(); 
}
```
</TabItem>

</Tabs>  

**Returns:** The maximum Drive train lineal velocity.

---


### get_current_index()
Get the current index of a path when the robot its following it.
<Tabs
  groupId="TankChassis_telemetry_get_current_index"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   int get_current_index(); 

```
</TabItem>


<TabItem value="example">

```cpp {5,12}

 void actions(void*){
  while (1) {    
    //When the robot is at index 5 of a path:
    if(my_chassis.get_current_index()==5){
      /*
      Do some things. 
      */
    }
    
     //When the robot is at index 13 of a path:
    if(my_chassis.get_current_index()==13){
      /*
      Do another things.  
      */
    }
  }
}

```
</TabItem>

</Tabs>  

---

###  reset_odometry()
Resets the position, orientation, tracking wheels value of the robot.

<Tabs
  groupId="TankChassis_telemetry_reset_odometry"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void reset_odometry();

```
</TabItem>


<TabItem value="example">

```cpp {6}
void initialize() {
 /*
 Restarting the encoders and IMU,
 It s recommended to use a 3000 milliseconds delay. 
 */
 my_chassis.reset_odometry(); 
 pros::delay(3000); 
}
```
</TabItem>

</Tabs>  

---

###  reset_IMU()
Resets the IMU. 

<Tabs
  groupId="TankChassis_telemetry_reset_IMU"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void reset_IMU(); 

```
</TabItem>


<TabItem value="example">

```cpp {5}
void initialize() {
 /*
 It s recommended to use a 3000 milliseconds of delay. 
 */
 my_chassis.reset_IMU(); 
 pros::delay(3000); 
}
```
</TabItem>

</Tabs>  

---

### tare_motors_position()
Tares the integrated encoders from the drive train motors.

<Tabs
  groupId="TankChassis_telemetry_tare_motors_position"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void tare_motors_position();

```
</TabItem>


<TabItem value="example">

```cpp {3}
void initialize() {

 my_chassis.tare_motors_position(); 
 pros::delay(100); 
}
```
</TabItem>

</Tabs>

---

## Configuration Functions
### set_brake()
Sets the chassis motors brake mode. 
<Tabs
  groupId="TankChassis_configuration_set_brake"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_brake(const pros::motor_brake_mode_e_t mode); 

```
</TabItem>


<TabItem value="example">

```cpp {2-4}
void initialize() {
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_COAST); 
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_HOLD);
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_BRAKE); 
}
```
</TabItem>

</Tabs>

---

### set_wheels_diameter()
Sets the chassis wheels diameter in **inches**.

<Tabs
  groupId="TankChassis_configuration_set_wheels_diameter"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_wheels_diameter(const float _wheels_diameter); 

```
</TabItem>


<TabItem value="example">

```cpp
void initialize() {
  my_chassis.set_wheels_diameter(3.25);
}
```
</TabItem>

</Tabs>

---
### set_center_distance()
Sets the distance between lateral wheels to the center of rotation in **inches**. 

<Tabs
  groupId="TankChassis_configuration_set_center_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_center_distance(const float distance); 

```
</TabItem>


<TabItem value="example">

```cpp 
void initialize() {
  my_chassis.set_center_distance(6);

}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``distance``  | The center distance in **inches** |

---

### set_gearing()
Sets the drivetrain cartridge. 

<Tabs
  groupId="TankChassis_configuration_set_gearing"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_gearing(const pros::motor_gearset_e_t gearset);

```
</TabItem>


<TabItem value="example">

```cpp {2-4}
void initialize() {
  my_chassis.set_gearing(pros::E_MOTOR_GEAR_100);
  my_chassis.set_gearing(pros::E_MOTOR_GEAR_200);
  my_chassis.set_gearing(pros::E_MOTOR_GEAR_600);
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``gearset``  | The gearset |

---


### set_gear_ratio()
Sets the chassis´s gear ratio.
:::note
speed is equal to = rpm/ gear ratio.  And torque is equal to = torque* gear_ratio
:::

<Tabs
  groupId="TankChassis_configuration_set_gear_ratio"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_gear_ratio(const float _gear_ratio); 

```
</TabItem>


<TabItem value="example">

```cpp
void initialize() {
  my_chassis.set_gear_ratio(1.33333);
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``_gear_ratio``  | Is the result of Driven/Driving, Drive:Driving |

---




### set_max_rpm()
Sets the maximum chassis velocity **RPM**.
:::note
May you want to test ``auto_set_max_actual_vel`` function to know this value and then 
set the max actual velocity with this function. 
:::

<Tabs
  groupId="TankChassis_configuration_set_max_rpm"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_max_rpm(const float _max_rpm=0);

```
</TabItem>


<TabItem value="example">

```cpp
void initialize() {
  my_chassis.set_max_rpm(600);
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``_max_rpm``  | The maximum chassis RPM. |

---

### set_max_velocity()
Sets the maximum chassis lineal velocity **inches/seconds**.

:::note
May you want to test ``auto_set_max_actual_vel`` function to know this value and then 
set the max actual velocity with this function. 
:::

<Tabs
  groupId="TankChassis_configuration_set_max_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_max_velocity(const float _max_vel=0); 

```
</TabItem>


<TabItem value="example">

```cpp
void initialize() {
  my_chassis.set_max_velocity(10);
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``_max_vel``  | The maximum robot velocity. |

---

### set_max_accel()
Sets the maximum chassis acceleration **distance/seconds <sup>2 </sup>**.

<Tabs
  groupId="TankChassis_configuration_set_max_accel"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 void set_max_accel(const float _max_accel=0); 

```
</TabItem>


<TabItem value="example">

```cpp
void initialize() {
  my_chassis.set_max_accel(2);
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``_max_accel``  | The maximun robot acceleration |

---

### get_max_rpm()
Gets maximum robot RPM. 
<Tabs
  groupId="TankChassis_configuration_get_max_rpm"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 double get_max_rpm(); 

```
</TabItem>


<TabItem value="example">

```cpp
void autonomous() {
  double max_robot_rpm = my_chassis.get_max_rpm(); 
}
```
</TabItem>

</Tabs>

**Returns:** The maximum Drive train RPM.

---

### get_max_velocity()
Gets the maximum robot lineal velocity in **distance/seconds**. 

<Tabs
  groupId="TankChassis_configuration_get_max_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 double get_max_velocity(); 

```
</TabItem>


<TabItem value="example">

```cpp
void autonomous() {
  double max_robot_velocity = my_chassis.get_max_velocity(); 
}
```
</TabItem>

</Tabs>

**Returns:** The maximum robot lineal velocity.

---

### get_max_accel()
Gets the maximum robot lineal acceleration in **distance/seconds <sup>2 </sup>**.. 
<Tabs
  groupId="TankChassis_configuration_get_max_acceleration"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 double get_max_accel(); 

```
</TabItem>


<TabItem value="example">

```cpp
void autonomous() {
  double max_robot_accel = my_chassis.get_max_accel(); 
}
```
</TabItem>

</Tabs>

**Returns:** The maximum robot lineal acceleration.

---

### get_wheels_diameter()
Gets the robot wheels diameter in **inches**.
<Tabs
  groupId="TankChassis_configuration_get_wheels_diameter"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 float get_wheels_diameter() const ;  

```
</TabItem>


<TabItem value="example">

```cpp
void autonomous() {
  float wheels_diameter = my_chassis.get_wheels_diameter();
}
```
</TabItem>

</Tabs>

**Returns:** The robot wheels diameter in **inches**.

---

### get_center_distance()
Gets the center distance in **inches**.

<Tabs
  groupId="TankChassis_configuration_get_center_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  float get_center_distance() const;  

```
</TabItem>


<TabItem value="example">

```cpp
void autonomous() {
  float center_distance = my_chassis.get_center_distance(); 
}
```
</TabItem>

</Tabs>

**Returns:** The robot center distance in **inches**. 

---

### get_gearing()
Gets the robot motors gearing.
:::note
[0] ->36:1, 100 RPM, Red gear set.

[1] ->18:1, 200 RPM, Green gear set.

[2] -> 6:1, 600 RPM, Blue gear set.
:::

<Tabs
  groupId="TankChassis_configuration_get_gearing"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  pros::motor_gearset_e get_gearing() const ; 
```
</TabItem>


<TabItem value="example">

```cpp {3,7,11}
void autonomous() {
  float center_distance = my_chassis.get_center_distance(); 
  if (my_chassis.get_gearing() ==pros::E_MOTOR_GEAR_100 ){
    std::cout<<"The chassis have red motors"; 
  }

  if (my_chassis.get_gearing() ==pros::E_MOTOR_GEAR_200 ){
    std::cout<<"The chassis have blue motors"; 
  }

  if (my_chassis.get_gearing() ==pros::E_MOTOR_GEAR_600 ){
    std::cout<<"The chassis have blue motors"; 
  }


}
```
</TabItem>

</Tabs>

**Returns:** The current internal gear ratio of the motors. 

---

### get_encoders_units()
Gets the units for recording position by the chassis motors.

<Tabs
  groupId="TankChassis_configuration_get_encoders_units"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  pros::MotorUnits get_encoders_units(); 
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    pros::MotorUnits encoder_units = my_chassis.get_encoders_units();  
}
```
</TabItem>

</Tabs>

**Returns:** Motors encoder units.

---

### get_actual_brake()
Gets the current brake mode.

<Tabs
  groupId="TankChassis_configuration_get_actual_brake"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   pros::motor_brake_mode_e_t get_actual_brake(); 
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    pros::motor_brake_mote_e_t current_brake = my_chassis.get_actual_brake(); 
}
```
</TabItem>

</Tabs>

**Returns:** Motors brake.

---

### get_gear_ratio()
Gets the chassis gear ratio.

<Tabs
  groupId="TankChassis_configuration_get_gear_ratio"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  float get_gear_ratio() const ; 
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    float robot_gear_ratio = my_chassis.get_gear_ratio();  
}
```
</TabItem>

</Tabs>

**Returns:** The result of the division of Driven/Driving.

## Auto setters
### auto_set_max_velocity_with_position()
Runs a test (your bot would runs in a straight line) to set the maximun real robot lineal velocity. 

**The linear velocity is calculated using the change in position over time**

:::danger
The function is useful when you want to know the real maximun velocity of your robot-
**Be careful using this function**, if the time is to much your robot may crash with the field.
:::

<Tabs
  groupId="TankChassis_auto_setters_max_velocity_with_position"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void auto_set_max_velocity_with_position(const int time_msec, const float scale); 
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    my_chassis.auto_set_max_velocity_with_position(4,.8); 
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``time_msec``  | The time in miliseconds that robot would run  at maximum velocity to make the math. |
| ``scale``  |  The scale of velocity (.8,.9) would be nice. |

---

### autoset_max_vel_accel()
Runs a test (your bot would runs in a straight line) to set the maximun real robot lineal velocity.

**The linear velocity and acceleration are calculated using the motors RPMS**

:::danger
The function is useful when you want to know the real maximun velocity of your robot-
**Be careful using this function**, if the time is to much your robot may crash with the field.
:::

<Tabs
  groupId="TankChassis_auto_setters_max_vel_accel"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void autoset_max_vel_accel(const int time_msec, const float scale);  
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    my_chassis.auto_set_max_vel_accel(2000,.8)
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``time_msec``  | The time in miliseconds that robot would run  at maximum velocity to make the math. |
| ``scale``  |  The scale of velocity (.8,.9) would be nice. |

---


### auto_set_max_rpm()
Runs a test (your bot would runs in a straight line) to set the maximun real robot lineal velocity.

:::danger
The function is useful when you want to know the real maximun velocity of your robot-
**Be careful using this function**, if the time is to much your robot may crash with the field.
:::

<Tabs
  groupId="TankChassis_auto_setters_max_rpm"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example ',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void auto_set_max_rpm(const int time_msec, const float scale); 
```
</TabItem>


<TabItem value="example">

```cpp 
void autonomous() {
    my_chassis.auto_set_max_rpm(2000,.8); 
}
```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``time_msec``  | The time in miliseconds that robot would run  at maximum velocity to make the math. |
| ``scale``  |  The scale of velocity (.8,.9) would be nice. |

---
