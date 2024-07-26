---
sidebar_label: How to create a PID
sidebar_position: 5
---

# PID tutorial 

## Introduction
The Proportional-Integral-Derivative (PID) control is the most common control algortihm used in VEX. 

In lighitning, you are able to create PID controllers by using the ``PID`` class. Check the [PID documentation](http://localhost:3000/docs/Documentation/PID) for more information. 

For more details about what a PID controller is, how it works, and how to tune it, refer to this  [article](https://wiki.purduesigbots.com/software/control-algorithms/pid-controller) written by [BLRS](https://purduesigbots.com/)(Purdue SIGBots). 

---

## Create a PID object
You can create a ``PID`` like this :

```cpp title="main.cpp"
lightning::PID pid_controller(
    5, //Kp: 5 
    1, // ki: 1
    1, // kd: 1
    10, /// sample time: 10 msec
    1 // scale: 1 
)
```
Where: 
| Parameters    |  |
| ------------- | ------------- |
| ``_kp``  | The proportional constant. |
| ``_ki  ``| The integral constant. |
| ``_kd `` | The integral constant. |
| ``_sample_time``  | The derivative constant. |
| ``_scale``  | A scaling factor that limits the output of the PID controller. For example, a value of 0.5 limits the output to 50% of its maximum value.|

## Configure your PID controller
Is neccesary to provide some information about the gains of your controller. You can do this using different functions. 
Let´s see how each function works. 
```cpp {12,15,18,24,30,35,42}title="main.cpp"
lightning::PID pid_controller(
    5, //Kp: 5 
    1, // ki: 1
    1, // kd: 1
    10, /// sample time: 10 msec
    1 // scale: 1 
)

void configuration(){
    //Sets the stop time limit for the PID controller.
    //This function allows the user to set the maximum time limit after which the PID controller output will be set to zero.
    pid_controller.set_stop_time(5000); // 5 secs
    
    //Sets error tolerance.For example: In a distance controller maybe the error tolerance would be .02 inches.
    pid_controller.set_error_tolerance(5); 

    //Sets derivative tolerance. 
    pid_controller.set_derivative_tolerance(100);//We are setting that The derivative part must to be less than 100.  
    
    //Sets the integral zone. 
    //The integral zone is the zone where the integral will no act
    //Normally, this value can be calculated making: abs(error) * constant. 
    //You can set the value of the constant, normally is a value between .35-.5.  
    pid_controller.set_integral_zone(12); 
    
    //Sets the integral_power_limit. 
    // The integral power limit would be the highest value of the integral
    //You can calculated the value making the next equation: 
    //integral_power_limit = the max value that you want for the integral/ki
    pid_controller.set_integral_power_limit(100); 

    //Sets the jump time limit for the PID controller.
    //When the PID controller is approaching the target, a timer starts. 
    //If the timer reaches the jump time limit, the PID controller operation is halted.
    pid_controller.set_jump_time(500); //500 msec

    // Sets the maximum output value for the PID controller.
    // It's a good practice to limit the output to a maximum value,
    // as you typically do not use the full 100% of the available power.
    // For example, you might set it to 80% or 90% of the maximum power.
    // In this case, we are setting the maximum output to 500 units.
    pid_controller.set_max(500);
}
```
---

## Example 
In this example, we will create a ``PID`` controller to control the position of an arm mechanism. 

We have decided to send the ``PID`` output as voltage in **millivolts** to our motors. This means that the units for all ``PID`` calculations will be in **millivolts*, within a range of *-12,000 to 12,000 mV*. 

Additionally, we will measure the position of our arms in degrees. This is because we will use the integrated motor encoder to track the position of the arms.

### 1. Declaring the controller
```cpp title="main.cpp"
lightning::PID arms_controller(
    5, //Kp: 5 
    1, // ki: 1
    1, // kd: 1
    10, /// sample time: 10 msec
    1 // scale: 1 
)
```
---

### 2. Configuring the PID
```cpp title="main.cpp"

void config_arms_controller(){
    //The error tolerance would be of 30 degrees. The controller would have an error of +- 30 deg. 
    arms_controller.set_error_tolerance(30); 

    //The derivative part would be less than the 25% of the maximum motors output (3000 mv).   
    arms_controller.set_derivative_tolerance(3000);
    
    //Calculating the integral power limit
    // (The maximum value that we want for the integral) / ki 
    float integral_power_limit = 1500/arms_controller.get_ki(); 
    arms_controller.set_integral_power_limit(integral_power_limit); 

    //IF the arms stay more than 500 milliseconds in the range of the error tolerance
    //The arms would stop. 
    arms_controller.set_jump_time(500); //500 msec

    // The maximum value is 12,000 mv. 
    //But we will just using the 90% of the power.
    arms_controller.set_max(10800);
}
```
---

### 3. Creating the motion function. 
Now it is time to program the arms motion function. 
```cpp title="main.cpp"

void move_arms(float target, int stop_time_msec, float scale){
    //Setting the integral zone. 
    //It depends on the target 
   arms_controller.set_integral_zone(target*.45);
   
   //Setting the stop time.
   arms_controller.set_stop_time(stop_time_msec); 
   
   //Setting the scale. 
   arms_controller.set_scale(scale); 

   //VERY IMPORTANT YOU MUST TO INCLUDE THIS FUNCTION.  
   arms_controller.initialization(); 
   
   //STORE THE CURRENT POSITION
   float current_position = get_arms_position();

   float error = current_position; 
   
   //WHILE the arms doen´t reach the target 
   while(!(arms_controller.target_arrived())){
    current_position = get_arms_position();
    error = target-current_position; 
    
    //Updating the PID controller, using the error. 
    arms_controller.update(error); 

    arm_motor_1.move_voltage(arms_controller.get_output()); 
    arm_motor_2.move_voltage(arms_controller.get_output());
   }

}
```
---

### 4. Using the function 
Now, we will use the motion function. It's important to note that you can change the configuration of your PID controller at any time.

```cpp title="main.cpp"
lightning::PID arms_controller(5, 1, 1, 10, 1)
void autonomous(){
    config_arms_controller();

    //Setting the arms position to 200 degrees
    //If the arms doesn´t reach the position in 3 seconds (3000 milliseconds)
    //The arms would stop 
    //Running the arms at normal velocity, using a scale of 1. 
    move_arms(200, 3000, 1); 

    //Setting the arms position to 0 degrees
    //If the arms doesn´t reach the position in 3 seconds (3000 milliseconds)
    //The arms would stop 
    //Running the arms at half of the velocity, using a scale of .5. 
    move_arms(0, 3000, .5); 
    
    //Maybe you note that in some movements you need a less agresive controller
    //so you change the kp constant
    arms_controller.set_kp(2.25); 
}
```
### 5. Start testing and finding the best gains
The performance of the ``PID`` controller is highly dependent on the controller gains. It is crucial to iterate through different gain values and thoroughly test each configuration to identify the optimal settings. By systematically experimenting and refining the gains, you can achieve the best performance for your application.

Would be nice if you already have a method to tune ``PID`` controllers. 

### Putting everything together
```cpp title="main.cpp"
lightning::PID arms_controller(
    5, //Kp: 5 
    1, // ki: 1
    1, // kd: 1
    10, /// sample time: 10 msec
    1 // scale: 1 
)

void config_arms_controller(){
    //The error tolerance would be of 30 degrees. The controller would have an error of +- 30 deg. 
    arms_controller.set_error_tolerance(30); 

    //The derivative part would be less than the 25% of the maximum motors output (3000 mv).   
    arms_controller.set_derivative_tolerance(3000);
    
    //Calculating the integral power limit
    // (The maximum value that we want for the integral) / ki 
    float integral_power_limit = 1500/arms_controller.get_ki(); 
    arms_controller.set_integral_power_limit(integral_power_limit); 

    //IF the arms stay more than 500 milliseconds in the range of the error tolerance
    //The arms would stop. 
    arms_controller.set_jump_time(500); //500 msec

    // The maximum value is 12,000 mv. 
    //But we will just using the 90% of the power.
    arms_controller.set_max(10800);
}


void move_arms(float target, int stop_time_msec, float scale){
    //Setting the integral zone. 
    //It depends on the target 
   arms_controller.set_integral_zone(target*.45);
   
   //Setting the stop time.
   arms_controller.set_stop_time(stop_time_msec); 
   
   //Setting the scale. 
   arms_controller.set_scale(scale); 

   //VERY IMPORTANT YOU MUST TO INCLUDE THIS FUNCTION.  
   arms_controller.initialization(); 
   
   //STORE THE CURRENT POSITION
   float current_position = get_arms_position();

   float error = current_position; 
   
   //WHILE the arms doen´t reach the target 
   while(!(arms_controller.target_arrived())){
    current_position = get_arms_position();
    error = target-current_position; 
    
    //Updating the PID controller, using the error. 
    arms_controller.update(error); 

    arm_motor_1.move_voltage(arms_controller.get_output()); 
    arm_motor_2.move_voltage(arms_controller.get_output());
   }

}

void autonomous(){
    config_arms_controller();

    //Setting the arms position to 200 degrees
    //If the arms doesn´t reach the position in 3 seconds (3000 milliseconds)
    //The arms would stop 
    //Running the arms at normal velocity, using a scale of 1. 
    move_arms(200, 3000, 1); 

    //Setting the arms position to 0 degrees
    //If the arms doesn´t reach the position in 3 seconds (3000 milliseconds)
    //The arms would stop 
    //Running the arms at half of the velocity, using a scale of .5. 
    move_arms(0, 3000, .5); 
    
    //Maybe you note that in some movements you need a less agresive controller
    //so you change the kp constant
    arms_controller.set_kp(2.25); 
}

```
:::note
Feel free to organize the code in the way you feel more comfortable.
:::

---

## What happend if i want P,PD,and PI controllers?
Depending in your system, you may want to use a different controller. 

* `P` controller: This controller includes only the proportional part of the ``PID`` controller.
* `PD` controller: This controller includes both the proportional and derivative parts of the ``PID`` controller.
* `PI` controller:  This controller includes both the proportional and integral parts of the ``PID`` controller.

If you prefer to use one of these controllers instead of a full PID controller, simply set the corresponding gains to zero.

### For P controller
| Parameters   | Example               |
| ------------- | ------------- |
| ``ki``  |   ``controller.set_ki(0)``|
| ``kd``  |   ``controller.set_kd(0)``|
| ``derivative_tolerance``  |   ``controller.set_derivative_tolerance(0)``|
| ``integral_power_limit``  |   ``controller.set_integral_power_limit(0); ``|
| ``integral_zone``  |   ``controller.set_integral_zone(0);``|

---

### For PD controller
| Parameters   | Example               |
| ------------- | ------------- |
| ``ki``  |   ``controller.set_ki(0)``|
| ``integral_power_limit``  |   ``controller.set_integral_power_limit(0); ``|
| ``integral_zone``  |   ``controller.set_integral_zone(0);``|

---

### For PI controller
| Parameters   | Example               |
| ------------- | ------------- |
| ``kd``  |   ``controller.set_kd(0)``|
| ``derivative_tolerance``  |   ``controller.set_derivative_tolerance(0)``|


---
## Congratulations! 🎉
You finished the PID tutorial, now you are able to create and configure `P`, `PD`, `PI`, and ``PID`` controllers. 

To see robots in action using PID controllers checks the following videos: 
* [PID in a X drive](https://www.youtube.com/watch?v=7R-rEglKxTQ)
* [PI in a flywheel](https://www.youtube.com/watch?v=_u5JN3hauW0)
* [PID for turning](https://www.youtube.com/shorts/onqzP2TqsVQ)
* [PID odometry](https://www.youtube.com/shorts/yXknGL4GcQs)
