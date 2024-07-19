---
sidebar_label: Util
sidebar_position: 7
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Util 
## Functions
### is_reversed()
Checks whether a smart port is reversed.

<Tabs
  groupId="util_functions"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Prototype_2', value: 'proto_2'} ,
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  bool is_reversed(double input); 
```
</TabItem>

<TabItem value="proto_2">

```cpp
  bool is_reversed(int input); 
```
</TabItem>

<TabItem value="example">

```cpp
   #define INTAKER_PORT
   
   bool port_is_reversed = is_reversed(INTAKER_PORT);     
   
   if(port_is_reversed){

   }
```
</TabItem>

</Tabs>  
| Parameters    |  |
| ------------- | ------------- |
| ``input``  | A number. |


**Returns:** ``true`` if the port it is reversed. Or ``false` if the port it not reversed. 

---

### smooth_Joystick_Output()
Applies a smoothing function to joystick input values.

This function smooths the joystick input based on a specified exponent and maximum value. The smoothing function adjusts the joystick value to create a more gradual response. 


<Tabs
  groupId="util_functions"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  float smooth_Joystick_Output(int joystick_value, int exponent, int max_value); 
```
</TabItem>


<TabItem value="example">

```cpp
void opcontrol(){
    while(1){
    raw_joystick_x = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X); //raw joystick value
    raw_joystick_y = control.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  //raw joystick value
    
    power = util::smooth_Joystick_Output(raw_joystick_y,n_y); //smooth joystick value
    turn= util::smooth_Joystick_Output(raw_joystick_x, n_x);  //smooth joystick value
    
    left_side.move(power+turn);
    right_side.move(powe-turn); 

    pros::delay(10);
    }
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``joystick_value``  | Analog joystick value. |
| ``exponent``  | The exponent value; a higher exponent provides more smoothing. |
| ``max_value``  | The maximum value of the joystick. Default value is 127. |