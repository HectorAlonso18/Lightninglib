---
sidebar_label: Trapezoidal Profile
sidebar_position: 3
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# TrapezoidalProfile
:::warning
The velocity units must be in **(inches/seconds)** and the acceleration units in **(inches/seconds<sup>2</sup>)** Otherwise, the code will not work as expected. 
:::

## Constructor

### TrapezoidalProfile()
Trapezoidal profile constructor. Create a new trapezoidal profile.

<Tabs
  groupId="trapezoidal_constructor"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    TrapezoidalProfile(float max_velocity, float max_acceleration);
```
</TabItem>


<TabItem value="example">

```cpp
void autonomous(){
    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``max_velocity``  | What would be the maximum profile velocity?. |
| ``max_acceleration``  | What would be the maximum profile accleration? . |
---

## Functions

### update()
Updates the trapezoidal profile giving the target and the sample time. 
<Tabs
  groupId="trapezoidal_functions_update"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void update(const float target, float sample_time_sec);
```
</TabItem>


<TabItem value="example">

```cpp {5}
lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 
void autonomous(){
    //target= 48 inches.
    //sample_time_sec = .01 seconds.
    profile.update(48,.01); 
}
```
</TabItem>
</Tabs>  


| Parameters    |  |
| ------------- | ------------- |
| ``target``  | How many distance you would travel in inches. |
| ``sample_time_sec``  | The update rate in secconds. . |

---

### reset()
Resets the trapezoidal profile.

:::note
The function erases and clean all the profile. 
:::

<Tabs
  groupId="trapezoidal_functions_reset"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void reset();
```
</TabItem>


<TabItem value="example">

```cpp {10}
void autonomous(){
    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 
    profile.update(48,.01);  // 48 inches , .01 sec

    /*
    USING THE PROFILE during autonomous 
    */

    //When we finish using the profile
    profile.reset();
}

```
</TabItem>

</Tabs>  

---

### is_ready()
Checks if the profile its ready to use. 

<Tabs
  groupId="trapezoidal_functions_is_ready"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    bool is_ready() const;
```
</TabItem>


<TabItem value="example">

```cpp {5}
void autonomous(){
    lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2
    profile.update(48,.01); // 48 inches , .01 sec
    
    if(profile.is_ready()){
    /*
    MAKE THINGS 
    */
    } 
}
```
</TabItem>

</Tabs>  

---

## Setters
### set_parameters()
Sets the main parameters for the profile. 

<Tabs
  groupId="trapezoidal_setters_parameters"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_parameters(const float max_velocity, const float max_acceleration); 
```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 
void autonomous(){
    profile.set_parameters(10,2); //10 inches/second, 2 inches/second^2
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``max_velocity``  | What would be the maximum profile velocity?. |
| ``max_acceleration``  | What would be the maximum profile accleration? . |
---

### set_max_velocity()
Sets the maximum profile velocity. 

<Tabs
  groupId="trapezoidal_setters_max_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_max_velocity(const float max_velocity);
```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); //5 inches/second, 1 inches/second^2 
void autonomous(){
    profile.set_max_velocity(10); //5 inches/second 
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``max_velocity``  | What would be the maximum profile velocity?. |

---

### set_max_acceleration()
Sets the maximum profile acceleration. 

<Tabs
  groupId="trapezoidal_setters_max_acceleration"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void set_max_acceleration(const float max_acceleration);

```
</TabItem>


<TabItem value="example">

```cpp {4}
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.set_max_velocity(10); //10 inches/second
    profile.set_max_acceleration(2); //2 inches/second^2
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``max_acceleration``  | What would be the maximum profile accleration? .  |

---

## Getters
### get_velocity_at()
Gets the desired velocity giving a point. 

<Tabs
  groupId="trapezoidal_getters_velocity_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_velocity_at(int index) const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float velocity = profile.get_velocity_at(5) //getting the velocity at index 5. 
}
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | Index the profile index.  |

**Returns:** The desired velocity.  

---

### get_max_velocity()
Gets the maximum profile velocity. 

<Tabs
  groupId="trapezoidal_getters_max_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_max_velocity() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float max_velocity = profile.get_max_velocity(); 
}
```
</TabItem>

</Tabs>  

**Returns:** The maximum velocity.

---

### get_max_acceleration()
Gets the maximum profile acceleration.

<Tabs
  groupId="trapezoidal_getters_max_acceleration"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_max_acceleration() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float max_acceleration = profile.get_max_acceleration(); 
}
```
</TabItem>

</Tabs>  

**Returns:** The maximum acceleration.  

---

### get_accel_time()
Gets the acceleration time.

<Tabs
  groupId="trapezoidal_getters_accel_time"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_accel_time() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float accel_time = profile.get_accel_time(); 
}
```
</TabItem>

</Tabs>  

**Returns:** The acceleration time. 

---

### get_accel_distance()
Gets the acceleration distance (acceleration phase).  

<Tabs
  groupId="trapezoidal_getters_accel_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_accel_distance() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float accel_distance = profile.get_accel_distance(); 
}
```
</TabItem>

</Tabs>  

**Returns:**  The acceleration time. 

---

### get_desaccel_distance()
Gets the desacceleration distance (desacceleration phase).

<Tabs
  groupId="trapezoidal_getters_desaccel_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_desaccel_distance() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float desaccel_distance = profile.get_desaccel_distance();
}
```
</TabItem>

</Tabs> 

**Returns:** Gets the desacceleration time. 

---

### get_velocity_constant_distance()
Gets the constant velocity distance (constant acceleration phase). 

<Tabs
  groupId="trapezoidal_getters_velocity_constant_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_velocity_constant_distance() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float velocity_constant_distance = profile.get_velocity_constant_distance();
}
```
</TabItem>

</Tabs> 

**Returns:** Gets the constant velocity distance. 

---

### get_time_to_arrived()
Gets the time to arrive. 

<Tabs
  groupId="trapezoidal_getters_time_to_arrived"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    float get_time_to_arrived() const; 

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    float time_to_arrived = profile.get_time_to_arrived();  // in seconds
}
```
</TabItem>

</Tabs> 

**Returns:** The time to arrive in seconds. 

---

### get_size()
Returns the profile size. 

<Tabs
  groupId="trapezoidal_getters_size"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    std::size_t get_size() const; 

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec

    int profile_size = profile.get_size();
}
```
</TabItem>

</Tabs> 

**Returns:** The current profile size. 

---

### get_velocities()
Return a vector with the desired velocities using the trapezoidal profile. 

<Tabs
  groupId="trapezoidal_getters_velocities"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    std::vector<float> get_velocities() const;

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec
    
    //Saving the profile velocities to a new vector.
    std::vector<float> profile_velocities = profile.get_velocities(); 
}
```
</TabItem>

</Tabs> 

**Returns:** Desired velocities vector. 

---


## Operators
### ``std::ostream &operator <<``
Prints the  desired velocities of a ```TrapezoidalProfile``` object in Integrated Terminal. 

<Tabs
  groupId="trapezoidal_operator_<<"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    std::ostream &operator<<(std::ostream &os,const TrapezoidalProfile &profile);

```
</TabItem>


<TabItem value="example">

```cpp 
lightning::TrapezoidalProfile profile (5,1); 
void autonomous(){
    profile.update(48,.01); // 48 inches , .01 sec
    
    //Printing velocities
    std::cout<<profile; 
}
```
</TabItem>

</Tabs> 

---
