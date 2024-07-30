#include "main.h"
#include "liblvgl/llemu.hpp"
#include "lightninglib/TasksCreator.hpp"
#include "lightninglib/util.hpp"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"


//Chassis declaration
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
{-1,-2}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
2.507, //Forward tracking wheel  diameter
1.783, //Distance that exist between the forward tracker and the robot rotation center.
{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Sideways tracking wheel  diameter
0); //Forward tracking wheel  diameter

/*Odometry function 
This function is dedicated to make the math for your odometry system. 
WARNING: If you have and want odometry, dont delete the function. 
NOTE: if your odometry configuration is "NO_ODOM" you can erase the function. 
*/
void init_odometry(void*) {
  while (1) {
    static char buffer_x[32];
    static char buffer_y[32];
    static char buffer_theta[32];

    snprintf(buffer_x, 32, "X: %.4f", my_chassis.get_x());
    snprintf(buffer_y, 32, "Y: %.4f", my_chassis.get_y());
    snprintf(buffer_theta, 32, "Theta: %.4f", my_chassis.get_orientation());

    pros::lcd::set_text(2, buffer_x);
    pros::lcd::set_text(3, buffer_y);
    pros::lcd::set_text(4, buffer_theta);
    my_chassis.track_pose();
  }
}

void initialize() {
  pros::lcd::initialize(); 
  pros::lcd::set_text(1, "Lightning");
 
 /*
 Restarting the encoders and IMU,
 It s recommended to use a 3000 milliseconds delay. 
 */
 my_chassis.reset_odometry(); //IF you don´t have odometry, you must delete the function. 
 pros::delay(3000); 

 /*
 However, you should use the function "reset_IMU", that function allows you to reset the IMU sensor
 (Is recommended to use a 3000 milliseconds delay). 
 */
 //my_chassis.reset_IMU(); 

 
 
 //Finally, a function to set the initial pose of your robot
 //You could erase this function if you dont have odometry but still using set_orientation to set the initial robot orientation.
 my_chassis.set_coordinates(0_in, 0_in, 0_deg);  
 
 //my_chassis.set_orientation(0_deg);

}


void disabled() {}


void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

lightning::TaskManager AUTON_TASKS; //YOU CAN USE THIS MANAGER TO CREATE AND MANAGE TASK DURING THE AUTONOMOUS PERIOD
void autonomous() {
  AUTON_TASKS.start_task("ODOMETRY", init_odometry); //WE WOULD RUNNING THE ODOMETRY FUNCTION DURING THE AUTONOMOUS PERIOD
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  pros::Controller master(pros::E_CONTROLLER_MASTER);
  while (true) {
   my_chassis.arcade(master);  //DRIVING ROBOT IN ARCADE MODE 

   pros::delay(lightning::util::DELAY_TIME); 
  }
}