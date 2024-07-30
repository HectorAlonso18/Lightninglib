---
sidebar_label: Start Programming 
sidebar_position: 3
---

# Start Programming
Once you have already ``Lightning`` installed, it is time to make some code. 

:::warning
It is necessary to have an IMU sensor in your chassis. If you don't have one, the code will not work.
:::

## Testing 🧪
The easiest way to test ``Lightning`` is to run the driver controlled period and see if everything is okay. 

1. Open the ``main.cpp`` file of your example project. 
2. Declare your chassis [without odometry](/docs/Tutorials/Declaring_your_chassis#without-odometry). 
You will notice that at the top of the program, there is a declaration of a chassis that already has odometry. For testing purposes, we will delete this declaration.

```cpp title="main.cpp"
//Chassis declaration, for Odometry with a one tracking wheel using ADI, ENCODER 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::ADI_ONE_ODOM,
//Declaration of drivetrain motors
{-11,-12,-13,-14}, //Left side ports (using a negative number will reverse it!)
{20,19,18,17},    //Right side ports (using a negative number will reverse it!)
5,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1.3333, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
2.507, //Forward tracking wheel  diameter in inches
1.783, //Distance that exist between the forward tracker and the robot rotation center in inches.
{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Sideways tracking wheel  diameter in inches
0); //Forward tracking wheel  diameter in inches
```

Under this declaration, you will find another declaration that is commented out. This is the declaration we will use for testing. It is a declaration of a chassis without odometry.
```cpp title="main.cpp"
/*DECLARATION OF A CHASSIS WITHOUT ODOMETRY
lightning::TankChassis chassis_without_odometry(
  lightning::tank_odom_e_t::NO_ODOM, //No odometry 
  {1,2,3}, //Left side ports (using a negative number will reverse it!)
  {4,5,6}, //Right side ports (using a negative number will reverse it!)
  7, //IMU port 
  pros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? 
  3.25, //Wheel Diameter in inches
  1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
); */
```

Uncomment this declaration. You can change the name if desired. 
```cpp title="main.cpp"
//DECLARATION OF A CHASSIS WITHOUT ODOMETRY
lightning::TankChassis my_chassis(
  lightning::tank_odom_e_t::NO_ODOM, //No odometry 
  {1,2,3}, //Left side ports (using a negative number will reverse it!)
  {4,5,6}, //Right side ports (using a negative number will reverse it!)
  7, //IMU port 
  pros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? 
  3.25, //Wheel Diameter in inches
  1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
); 
```

3. Introduce your chassis specifications. 
    For example, if your chasis have the following specifications: 
    
    **4 motors by side**.
    **Left side motors connection:** 
    *The left motors needs to be reversed, so, the port is negative!*
    * LeftMotor_1 -> ``-1`` 
    * LeftMotor_2 -> ``-2``
    * LeftMotor_3 -> ``-3``
    * LeftMotor_4 -> ``-4`` 

    **Right side motors connection:** 
    * RightMotor_1 -> ``5``
    * RightMotor_2 -> ``6`` 
    * RightMotor_3 -> ``7``
    * RightMotor_4 -> ``8`` 

    **IMU port:** 
    * IMU ->``9`` 

    **Cartride:** 
    * BLUE = 600 RPM 
    
    **Wheel diameter:** 
    * ``3.25`` inches

    **Gear ratio (Driven/Driving):** 
    * ``1.3333``

    With that information, is possible to declare the chassis. 
    ```cpp title="main.cpp"
    //DECLARATION OF A CHASSIS WITHOUT ODOMETRY
    lightning::TankChassis my_chassis(
    lightning::tank_odom_e_t::NO_ODOM, //No odometry 
    {-1,-2,-3,-4}, //Left side ports (using a negative number will reverse it!)
    {5,6,7,8}, //Right side ports (using a negative number will reverse it!)
    9, //IMU port 
    pros::E_MOTOR_GEAR_BLUE, //Which motor cartride are you using, blue,red,green? 
    3.25, //Wheel Diameter in inches
    1.3333 //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
    ); 
    ```

4. Run the driver period 🏎️

    When the driver period is running, you will control your chassis using an arcade configuration! If everything runs well, it means that the chassis declaration is correct.
   
   :::note
   You will control the forward and backward direction using the Y-axis of the left joystick, and control the turning using the X-axis of the left joystick.
   :::

## What is next 🤑? 
I would like to encourage everyone to see learning Lightning as a process. As you start using Lightning, following the tutorials, and gradually reading the documentation, you will become proficient and achieve great results.

It is recommended to start reading and implementing the [Lightning Tutorials](/docs/category/tutorials-) and start looking the [Documentation](/docs/category/documentation-) what it is needed. 

