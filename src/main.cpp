#include "main.h"
#include "liblvgl/llemu.hpp"
#include "lightninglib/TasksCreator.hpp"
#include "lightninglib/util.hpp"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"


//Chassis declaration
//Chassis declaration, for Odometry with a one tracking wheel using ADI, ENCODER 
lightning::TankChassis my_chassis( 
 //Odometry configuration
lightning::tank_odom_e_t::NO_ODOM,
//Declaration of drivetrain motors
{20}, //Left side ports (using a negative number will reverse it!)
{-10},    //Right side ports (using a negative number will reverse it!)
6,   //IMU port 
pros::E_MOTOR_GEAR_600, //Which motor cartride are you using, blue,red,green? 
3.25, //Wheel Diameter in inches
1, //what is the gear ratio (Is the result of Driven/Driving, Drive:Driving)
{-1,-1}, //Forward ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Forward tracking wheel  diameter in inches
0, //Distance that exist between the forward tracker and the robot rotation center in inches.
{-1,-1},//SIDEWAYS ADI ENCODER PORTS (using a negative number will reverse it!), setting -1,-1 would cancel the tracker!
0, //Sideways tracking wheel  diameter in inches
0); //Forward tracking wheel  diameter in inches

/*Odometry function 
This function is dedicated to make the math for your odometry system. 
WARNING: If you have and want odometry, dont delete the function. 
NOTE: if your odometry configuration is "NO_ODOM" you can erase the function. 
*/
void init_track(void*) {
 while (1) {
    static char buffer_x[32];
    static char buffer_y[32];
    static char buffer_theta[32];

    if (my_chassis.get_odometry_configuration() != lightning::NO_ODOM) {

      snprintf(buffer_x, 32, "X: %.4f", my_chassis.get_x());
      snprintf(buffer_y, 32, "Y: %.4f", my_chassis.get_y());
      snprintf(buffer_theta, 32, "Theta: %.4f", my_chassis.get_orientation());

      pros::lcd::set_text(2, buffer_x);
      pros::lcd::set_text(3, buffer_y);
      pros::lcd::set_text(4, buffer_theta);
      my_chassis.track_pose();
      pros::delay(10);
    }

    else {
      snprintf(buffer_theta, 32, "Theta: %.4f", my_chassis.get_orientation());
      pros::lcd::set_text(2, buffer_theta);

      pros::delay(10);
    }
  }
}


void initialize() {
  pros::lcd::initialize(); 
  pros::lcd::set_text(1, "Lightning");

  //If the user has odometry...
  if(!(my_chassis.get_odometry_configuration()==lightning::NO_ODOM)){
    /*
    Restarting the encoders and IMU,
    It s recommended to use a 3000 milliseconds delay. 
    */
    my_chassis.reset_odometry(); 
    pros::delay(3000); 
    //Setting the initial pose of your robot
    my_chassis.set_coordinates(0_in, 0_in, 0_deg);  
  }
  
  //If the user has not odometry...
  else{
     /*
    Restarting the IMU,
    It s recommended to use a 3000 milliseconds delay. 
    */
    my_chassis.reset_IMU(); 
    pros::delay(3000);
    my_chassis.tare_motors_position(); 
    pros::delay(100); 
    //Setting the initial orientation
    my_chassis.set_orientation(0_deg);
  }

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
  //This task would run your odometry system and printing the coordinates and orientation.
  //However, if you dont have an odometry system, the task will print the current orientation.  
  AUTON_TASKS.start_task("TRACK_AND_PRINT", init_track);


  float limit_integral = 150 / .00350;
  my_chassis.set_swing_constants(1.75, 0.00350, 3.15, 500, 1, limit_integral,
                                 175);
  my_chassis.set_swing_exit_conditions(1, 500, 2500);

  my_chassis.set_drive_constants(3, 0, 0, 500, 1, 0, 0);
  my_chassis.set_drive_exit_conditions(.15, 500, 2500);

  my_chassis.set_turn_constants(30, 0, 0, 450, 1, limit_integral, 0);
  my_chassis.set_turn_exit_conditions(1, 100, 5000);
  
  my_chassis.run_MotionLight_profile("motion.light.txt",0_deg); 
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
  std::cout<<lightning::util::SD_CARD_ACTIVE; 
  while (true) {
   my_chassis.arcade(master,lightning::E_TANK_OP_ARCADE_RIGHT);  //DRIVING ROBOT IN ARCADE MODE 

   pros::delay(lightning::util::DELAY_TIME); 
  }
}