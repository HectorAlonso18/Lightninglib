#include "main.h"
#include "liblvgl/llemu.hpp"
#include "lightninglib/TankChassis.h"
#include "lightninglib/TankChassis.hpp"
#include "pros/motors.h"

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


/*Odometry function 
This function is dedicated to make the math for your odometry system and print the odometry information. 
WARNING: If you have and want odometry, don´t delete the function. 
*/
void init_track(void*) {
  while (1) {
    if(!(my_chassis.get_odometry_configuration()== lightning::NO_ODOM)){
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

    else {
    static char buffer_theta[32];
    snprintf(buffer_theta, 32, "Theta: %.4f", my_chassis.get_orientation());
    pros::lcd::set_text(2, buffer_theta);
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


  //CONFIGURING PID CONSTANTS

  /*
  In the next lines we would configuring our PID controllers: 
  SWING_PID -> Is the PID controller that acts when we want to make swing turns. swing turns are turn but just using one side of our chassis

  TURN_PID -> Is the PID controller that acts when we want to make turns. 

  DRIVE_PID -> Is the PID controller that acts when we want to travel a distance. 

  NOTE we could create our own pid object and use it in the same functions
  */
  float limit_integral = 150 / .00350;
  my_chassis.set_swing_constants(1.75, 0.00350, 3.15, 500, 1, limit_integral,
                                 175);
  my_chassis.set_swing_exit_conditions(1, 500, 2500);

  my_chassis.set_drive_constants(9, 0, 1.75, 250, 1, 0, 100);
  my_chassis.set_drive_exit_conditions(.15, 250, 500);

  my_chassis.set_turn_constants(1.75, 0, 0, 300, 1, 0, 0);
  my_chassis.set_turn_exit_conditions(1, 100, 5000);

  //creating our own pid objects 
  lightning::PID turn_controller (1.75, 0, 0,10,1); 
  //configuring our pid object. 
  turn_controller.set_integral_power_limit(limit_integral); 
  turn_controller.set_derivative_tolerance(0); 
  turn_controller.set_error_tolerance(1); 
  turn_controller.set_jump_time(100); 
  turn_controller.set_max(300);

  //using the pid object. 
  my_chassis.turn_absolute(turn_controller,180_deg); 
  


  //MAKING SOME TURNS 
  my_chassis.turn_absolute(90_deg); //WITH OKAPI UNITS 
  my_chassis.turn_absolute(90);  //NORMAL UNITS (DEGREES)

  //MAKING SWING TURNS
  //In the next function we are indicating that we want to block the LEFTSIDE of our chassis. 
  my_chassis.swing_turn_absolute(lightning::swing_direction_e_t::LEFT_SWING,180_deg); 
  my_chassis.swing_turn_absolute(lightning::swing_direction_e_t::RIGHT_SWING,90); 
  
  //Driving in a straigh line (FORWARD)
  //USES THE DRIVE PID to travel some amout of distane in this case: 24 inches 
  //USES THE TURN PID to block the orientation of the bot
  my_chassis.drive_distance(24_in,0_deg);  //okapi units
  my_chassis.drive_distance(1_ft, 0_deg); 

  my_chassis.drive_distance(24,0); //Using default units (inches,degrees); 

  //DRIVING (BACKWARDS)
  //WE JUST NEED TO SET THE DISTANCE TO NEGATIVE 
  my_chassis.drive_distance(-24_in,0_deg); 

  /*
  DRIVING FORWARD OR BACKWARDS WITHOUT USING CUSTOM PID CONTROLLER, JUST USING THE INTEGRATED MOTORS PID
  */
  my_chassis.raw_drive_distance(24,300); 
  my_chassis.raw_drive_distance(24_in,200); 
  
  
  
 /*
 SETTING THE BRAKE MODE FOR OUR CHASSIS
 */
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_COAST); 
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_HOLD);
  my_chassis.set_brake(pros::E_MOTOR_BRAKE_BRAKE); 

  //STOPPING THE ROBOT
  my_chassis.stop(); 
  

  //FOLLOW A PATH USING PURE PURSUIT!
  //Its recommended that the first point of the path be equal that your robot position. 
  lightning::Path regresar(
	{my_chassis.get_x(), 0}, //The x coordinates (inches)
	 {my_chassis.get_y(), 0}, //The y coordinates (inches)
    false,  //going backwards ? 
	1 //the space that would exist between each point for the injection method.
	);

  regresar.upgrade(); //UPGRADING THE PATH
  regresar.set_max_lineal_velocity(2); //Setting the maximun lineal velocity for this path (inches/sec)
  regresar.make_calcs(1.75);  //k constant
  pros::delay(20); //give some time to make the calculations 

  my_chassis.follow_path(regresar, 12); //the robot would start following the path using pure pursuit. 
  
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
   
   /**
   If you want tank configuration use: my_chassis.tank(master); 
   */
   pros::delay(lightning::util::DELAY_TIME); 
  }
}