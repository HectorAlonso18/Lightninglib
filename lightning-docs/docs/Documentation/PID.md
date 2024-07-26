---
sidebar_label: PID
sidebar_position: 1
---

import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# PID 

## Constructors
### PID()
Build ``PID`` object given constants and the sample_time.

<Tabs
  groupId="pid_constructor_1"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  PID(const float _kp, const float _ki, const float _kd,unsigned int _sample_time, const float _scale);
```
</TabItem>

<TabItem value="example">
```cpp
lightning::PID position_controller (2,1,1,10,1); 
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``_kp``  | The proportional constant. |
| ``_ki  ``| The integral constant. |
| ``_kd `` | The integral constant. |
| ``_sample_time``  | The derivative constant. |
| ``_scale``  | A scaling factor that limits the output of the PID controller. For example, a value of 0.5 limits the output to 50% of its maximum value.|

---
**PID Copy constructor**
<Tabs
  groupId="pid_constructor_2"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  PID(const PID& other);
```
</TabItem>

<TabItem value="example">

```cpp

lightning::PID controller (2,1,1,10,1);

 //Using copy constructor
lightning:: PID other_controller(controller); 

```
</TabItem>

</Tabs>  

| Parameters    |                |
| ------------- | ------------- |
| ``other``     | other PID object. |
---
## Functions

### update()
Updates the PID controller.

:::note
You should put this function inside of while loop to update the PID input.
:::
  
With this function you will update the proportional, integral, derivative and output value.

<Tabs
  groupId="pid_functions_1"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   virtual void update(const float error);
```
</TabItem>



<TabItem value="example">

```cpp {15}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){
  
  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 

  while (!arm_controller.target_arrived()) {
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    left_arm.move_velocity(arm_controller.output());
    right_arm.move_velocity(arm_controller.output());
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }

```
</TabItem>
</Tabs>  

| Parameters    |                |
| ------------- | ------------- |
| ``error``     | The error of PID controller (target - actual reading). |
---

### target_arrived()
Checks if the target was reached.

<Tabs
  groupId="pid_functions_target_arrived"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   bool target_arrived() const;
```
</TabItem>



<TabItem value="example">

```cpp {11}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    left_arm.move_velocity(arm_controller.output());
    right_arm.move_velocity(arm_controller.output());
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }

```

</TabItem>
</Tabs> 

**Returns:** True if the target was reached, False if the target wasn´t reached.

---

### initialization()
Initialize the controller.
:::note
This function is neccesary to start in any procces or function where the controller is involve.
:::

<Tabs
  groupId="pid_functions_initialization"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void initialization();
```
</TabItem>


<TabItem value="example">

```cpp {5}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    left_arm.move_velocity(arm_controller.output());
    right_arm.move_velocity(arm_controller.output());
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```

</TabItem>
</Tabs>
---

## Setters

### set_stop_time()
Sets the stop time limit for the PID controller.

This function allows the user to set the maximum time limit after which the PID controller output will be set to zero.

<Tabs
  groupId="pid_setters_stop_time"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void set_stop_time(const float _stop_time_msec);  
```
</TabItem>

<TabItem value="example">

```cpp
lightning::PID arm_controller (2,1,1,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
}

```

</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_stop_time_msec``     | The stop time limit in milliseconds. If more than this time elapses,the PID controller output will be forced to zero |

---

### set_error_tolerance()
Sets the error tolerance.
:::note
For example: In a distance controller maybe the error tolerance would be .02 inches
:::

<Tabs
  groupId="pid_setters_error_tolerance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_error_tolerance(const float _error_tolerance);  
```
</TabItem>

<TabItem value="example">

```cpp {4}
lightning::PID arm_controller (2,1,1,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
}
```

</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_error_tolerance``     | The error tolerance for the controller. |

---

### set_derivative_tolerance()
Sets derivative tolerance.
<Tabs
  groupId="pid_setters_derivative_tolerance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
     void set_derivative_tolerance(const float _derivative_tolerance);
```
</TabItem>

<TabItem value="example">

```cpp {5}
lightning::PID arm_controller (2,1,1,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
arm_controller.set_derivative_tolerance(50);
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_derivative_tolerance``     | The derivative tolerance. |

---

### set_integral_zone()
Sets integral zone.
:::note
 The integral zone is the zone where the intregal will not act.
:::

<Tabs
  groupId="pid_setters_integral_zone"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_integral_zone(const float _integral_zone);
```
</TabItem>

<TabItem value="example">

```cpp {4}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    left_arm.move_velocity(arm_controller.output());
    right_arm.move_velocity(arm_controller.output());
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```

</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_integral_zone``     | The integral zone. |

---

### set_integral_power_limit
Sets integral power limit.
:::note
The integral power limit would be the highest value of the integral.
:::

<Tabs
  groupId="pid_setters_integral_power_limit"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_integral_power_limit(const float _integral_power_limit);

```
</TabItem>

<TabItem value="example">

```cpp {6}
lightning::PID arm_controller (2,1,.135,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
arm_controller.set_derivative_tolerance(50);
arm_controller.set_integral_power_limit(100/arm_controller.get_ki());
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_integral_power_limit``     | The integral power limit. |

---

### set_jump_time()
Sets the jump time limit for the PID controller.

:::note
When the PID controller is approaching the target, a timer starts. If the timer reaches the jump time limit, the PID controller operation is halted.
:::

<Tabs
  groupId="pid_setters_jump_time"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_jump_time(const float _jump_time);

```
</TabItem>

<TabItem value="example">

```cpp {7}
lightning::PID arm_controller (2,1,.135,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
arm_controller.set_derivative_tolerance(50);
arm_controller.set_integral_power_limit(100/arm_controller.get_ki());
arm_controller.set_jump_time(500); 
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_jump_time``     | The jump time limit in milliseconds. |

---
### set_max()
Sets the maximum output for the PID output.

<Tabs
  groupId="pid_setters_max"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_max(const float _max);
```
</TabItem>

<TabItem value="example">

```cpp {8}
lightning::PID arm_controller (2,1,.135,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
arm_controller.set_derivative_tolerance(50);
arm_controller.set_integral_power_limit(100/arm_controller.get_ki());
arm_controller.set_jump_time(500); 
arm_controller.set_max(300); 
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_max``     | The max value of the PID output. |

---

### set_scale()
Set the scale for the PID controller.

<Tabs
  groupId="pid_setters_scale"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_scale(const float _scale);
```
</TabItem>

<TabItem value="example">

```cpp {10}
lightning::PID arm_controller (2,1,.135,10,1); 
void autonomous(){
arm_controller.set_stop_time(3000); 
arm_controller.set_error_tolerance(10); 
arm_controller.set_derivative_tolerance(50);
arm_controller.set_integral_power_limit(100/arm_controller.get_ki());
arm_controller.set_jump_time(500); 
arm_controller.set_max(300); 
arm_controller.set_min(0);
arm_controller.set_scale(1); //Default
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_scale``    | scaling factor that limits the output of the PID controller.For example, a value of 0.5 limits the output to 50% of its maximum value.  |

---

### set_kp()
Sets the proportional constant (kp) of the PID controller.

<Tabs
  groupId="pid_setters_kp"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_kp(const float _kp);

```
</TabItem>

<TabItem value="example">

```cpp
void autonomous(){
controller.set_kp (5); 
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_kp``     | The new value for the proportional constant.  |

---

### set_ki()
Sets the integral constant (ki) of the PID controller.

<Tabs
  groupId="pid_setters_ki"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_ki(const float _ki);

```
</TabItem>

<TabItem value="example">

```cpp {3}
void autonomous(){
controller.set_kp(5);
controller.set_ki(.012);  
}
```
</TabItem>
</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``_ki``     | The new value for the integral constant.  |

---

### set_kd
Sets the derivative constant (kd) of the PID controller.

<Tabs
  groupId="pid_setters_kd"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_kd(const float _kd);

```
</TabItem>

<TabItem value="example">

```cpp {4}
void autonomous(){
controller.set_kp(5);
controller.set_ki(.012);  
controller.set_kd(1);
}
```
</TabItem>

</Tabs>
| Parameters    |                |
| ------------- | ------------- |
| ``_kd``     | The new value for the derivative constant.  |

---

### set_sample_time
Sets the sample time of the PID controller.
<Tabs
  groupId="pid_setters_kd"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_sample_time(const  unsigned int time_msec); 

```
</TabItem>

<TabItem value="example">

```cpp {5}
void autonomous(){
controller.set_kp(5);
controller.set_ki(.012);  
controller.set_kd(1);
controller.set_sample_time(10); 
}
```
</TabItem>

</Tabs>

| Parameters    |                |
| ------------- | ------------- |
| ``time_msec``     |  The new sample time in milliseconds.  |

---

## Getters
### get_error()
Gets the current error.
<Tabs
  groupId="pid_getters_error"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_error() const;

```
</TabItem>

<TabItem value="example">

```cpp
float current_error = controller.get_error(); 
```
</TabItem>

</Tabs>

**Returns:** The current error.

---

### get_kp()
Gets proportional constant [Kp].
<Tabs
  groupId="pid_getters_kp"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_kp() const;

```
</TabItem>

<TabItem value="example">

```cpp
float kp_constant = controller.get_kp(); 
```
</TabItem>

</Tabs>

**Returns:** The kp constant.

---

### get_ki()
Gets proportional constant [Ki].
<Tabs
  groupId="pid_getters_ki"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_ki() const;
```
</TabItem>

<TabItem value="example">

```cpp
float ki_constant = controller.get_ki(); 
```
</TabItem>

</Tabs>

**Returns:** The ki constant.

---

### get_kd()
Gets proportional constant [Kd].
<Tabs
  groupId="pid_getters_kd"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_kd() const;
```
</TabItem>

<TabItem value="example">

```cpp
float kd_constant = controller.get_kd(); 
```
</TabItem>

</Tabs>

**Returns:** The kd constant.

---

### get_proportion()
Gets the proportion part of the output.
<Tabs
  groupId="pid_getters_proportional"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_proportion() const;

```
</TabItem>

<TabItem value="example">

```cpp {17}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    float proportion = arm.controller.get_proportion(); //Proportion part

    left_arm.move_velocity(proportion); //P controller 
    right_arm.move_velocity(proportion); // P controller 
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```
</TabItem>

</Tabs>

**Returns:** The proportion value. 

---


### get_integral()
Gets the proportion part of the output.
<Tabs
  groupId="pid_getters_integral"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_integral() const;
```
</TabItem>

<TabItem value="example">

```cpp {18}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    float proportion = arm.controller.get_proportion(); //Proportion part
    float integral = arm.controller.get_integral(); // Integral part

    left_arm.move_velocity(proportion+integral); //PI controller 
    right_arm.move_velocity(proportion+integral); // PI controller 
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```
</TabItem>

</Tabs>

**Returns:** The integral value. 

---


### get_derivative()
Gets the proportion part of the output.
<Tabs
  groupId="pid_getters_derivative"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_derivative() const;
```
</TabItem>

<TabItem value="example">

```cpp {19}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.

    float proportion = arm.controller.get_proportion(); //Proportion part
    float integral = arm.controller.get_integral(); // Integral part
    float derivative = arm.controller.get_derivative(); //Derivative part

    left_arm.move_velocity(proportion+integral+derivative); //PID controller 
    right_arm.move_velocity(proportion+integral+derivative); // PID controller 
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```
</TabItem>

</Tabs>

**Returns:** The derivative value. 

---

### get_sample_time()
Gets the sample time.

<Tabs
  groupId="pid_getters_sample_time"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
unsigned int get_sample_time() const;

```
</TabItem>

<TabItem value="example">

```cpp
int controller_sample_time = controller.get_sample_time(); 
```
</TabItem>

</Tabs>

**Returns:** The sample time. 

### get_output()
Gets the current output from controller.
<Tabs
  groupId="pid_getters_output"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_output() const;
```
</TabItem>

<TabItem value="example">

```cpp {17}
//A Function to control the arms position using a PID. 
void move_arm(PID& arm_controller, float target){

  arm_controller.set_integral_zone(target * .3);
  arm_controller.initialization();
                            
                            //some function to get current data. 
  float current_position  = get_current_arm_position(); 
  float error = target - current_position; 
  
  while (!arm_controller.target_arrived()) { //Have the arms arrived?. 
    current_position= get_current_arm_position();
    error = target - current_position; 

    arm_controller.update(error); //Updating pid controller.
    
    float output = arm_controller.get_output(); 

    left_arm.move_velocity(output);  
    right_arm.move_velocity(output); 
    
    pros::delay(turn_control.get_sample_time());
  }

  stop_arms();
 }
```
</TabItem>

</Tabs>

**Returns:** The current output from controller. 

### get_error_tolerance()
Retrieves the error tolerance of the PID controller.

<Tabs
  groupId="pid_getters_error_tolerance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_error_tolerance() const;

```
</TabItem>

<TabItem value="example">

```cpp
float error_tolerance = controller.get_error_tolerance(); 
```
</TabItem>

</Tabs>

**Returns:** The current error tolerance value. 

### get_derivative_tolerance() 
<Tabs
  groupId="pid_getters_derivative_tolerance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_derivative_tolerance() const;
```
</TabItem>

<TabItem value="example">

```cpp
float derivative_tolerance = controller.get_derivative_tolerance(); 
```
</TabItem>

</Tabs>

**Returns:** The current derivative tolerance value. 

### get_integral_zone()
Retrieves the integral zone of the PID controller.

<Tabs
  groupId="pid_getters_integral_zone"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_integral_zone() const;
```
</TabItem>

<TabItem value="example">

```cpp
float integral_zone = controller.get_integral_zone(); 
```
</TabItem>

</Tabs>

**Returns:** The current integral zone value.

---

### get_integral_power_limit()
Retrieves the integral power limit of the PID controller.
<Tabs
  groupId="pid_getters_integral_power_limit"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_integral_power_limit() const;

```
</TabItem>

<TabItem value="example">

```cpp
float integral_power_limit = controller.get_integral_power_limit(); 
```
</TabItem>

</Tabs>

**Returns:** The current integral power limit value.

### get_max()
Retrieves the maximum value allowed for the PID controller output.

<Tabs
  groupId="pid_getters_max"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
float get_max() const;
```
</TabItem>

<TabItem value="example">

```cpp
float max_value = controller.get_max();
```
</TabItem>

</Tabs>

**Returns:** The maximum values allowed. 

---
