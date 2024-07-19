#include "main.h"

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
void init_odometry(void*){
    while (1) {
    my_chassis.track_pose();      
  }
}


void initialize() {
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
  turn_controller.set_min(0); 
  
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

   pros::delay(lightning::util::DELAY_TIME); 
  }
}