---
sidebar_label: Driver period examples 
sidebar_position: 1
---
# Programming the Driver period

>In Head-to-Head Matches, two (2) Alliances—one (1) “red” and one (1) “blue”—composed of two (2)
>Teams each, compete in Matches consisting of a fifteen (15) second Autonomous Period followed by a
>one minute and forty-five second (1:45) **Driver Controlled Period**.

The **Driver Controlled Period** is one of the most important aspects in VEX. For that reason, Lightning provides the ability to easily program the driver period for your drivetrain using various configurations that can help you.

In this tutorial, you will learn how to program the driver period using Lightning.

# Ensure you have declared your **drive train**
Your chassis declaration needs to be **global**. This means that each function can interact with your chassis. The easiest way to do this is to make your chassis declaration at the top of the ```main.cpp``` file.

You need more information about **Global Variables**? check [this](https://www.geeksforgeeks.org/cpp-global-variables/) 
for more details.

```cpp title="main.cpp"
#include "main.h"
//Here is your drive-train 
//Declaring a simple drive train
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
); //Forward tracking wheel  diameter

```
---
Once our chassis is declared it is time to program the driver period. 

# Program in the ```opcontrol``` function
Inside ```main.cpp```,you need to locate the ```opcontrol``` function. This function is designated for **Driver Controlled Period**. 

```cpp title: main.cpp {13-18}
#include "main.h"

void initialize() {
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
}

void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {

  }
}

```
The code that we will program in the ```opcontrol``` function will act in the **Driver Controlled Period**.

# Chose your driver configuration

## Tank

## Arcade

## Arcade with exponential

## Double