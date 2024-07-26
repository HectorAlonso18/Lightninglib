---
sidebar_label: Path
sidebar_position: 5
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Path
:::warning
The coordinates must to be in **(inches)**, orientation in **(degrees)** and velocity units in **(inches/seconds)**. 

Otherwise, the code will **not work** as expected. 
:::

## Constructors

### Path()
Constructor that initializes a ``Path`` object with specified parameters.

:::note
For this constructor the ``B`` constant is setted to .75 and the tolerance ``a`` value of .001
:::

<Tabs
  groupId="Path_constructor_1"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
Path(const std::vector<double> &X, const std::vector<double> &Y,bool _reverse, int _spacing);

```
</TabItem>


<TabItem value="example">

```cpp

lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3); 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``X``  | A vector that includes the x coordinates of each point.|
| ``Y``  | A vector that includes the y coordinates of each point.|
| ``_reverse``  | A boolean flag indicating if the path should be reversed. True if reversed.|
| ``_spacing``  | The space that would exist between each point for the injection method.|

---
### Path()

Constructor that initializes a ``Path`` object with **FULL** parameters.

This constructor initializes a ``Path`` object using the provided ``coordinates``, ``reverse`` flag, and ``spacing`` value and with ``B`` and ``Tolerance`` constants.

<Tabs
  groupId="Path_constructor_2"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  Path(const std::vector<double> &X, const std::vector<double> &Y,bool _reverse, int _spacing, const double B, const double Tolerance);

```
</TabItem>


<TabItem value="example">

```cpp
//Creating a path
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3,1,.98,.002); 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``X``  | A vector that includes the x coordinates of each point.|
| ``Y``  | A vector that includes the y coordinates of each point.|
| ``_reverse``  | A boolean flag indicating if the path should be reversed. True if reversed.|
| ``_spacing``  | The space that would exist between each point for the injection method.|
| ``B``  | Weight_smooth constant, larger b means a smoother path, a value between .75 and .98 works well. |
| ``Tolerance``  | It is the tolerance, a value of .001 works pretty well.|

---

## Path tuning functions
### inject_points()
Injects point to the current ``Path`` (using ``_spacing`` as parameter).

<Tabs
  groupId="Path_tunning_inject_points"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void inject_points(void);

```
</TabItem>


<TabItem value="example">

```cpp {2}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3); //Creating the path
goal_path.inject_points();  //Injecting more points to goal_path
```
</TabItem>

</Tabs>

---

### smoother
Smooths the current ``Path``.

<Tabs
  groupId="Path_tunning_smoother"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void smoother(void);

```
</TabItem>


<TabItem value="example">

```cpp {3}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3); //Creating the path
goal_path.inject_points(); //Injecting more points to goal_path
goal_path.smoother();  //Smoothing goal_path

```
</TabItem>

</Tabs>

---

### upgrade()
Upgrades the path using the injecting and smoothing algorithm.

:::tip
Instead of using ``inject_points`` and then the ``smoother`` function you can simply use ``upgrade``!
:::

<Tabs
  groupId="Path_tunning_smoother"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    void upgrade(void);

```
</TabItem>


<TabItem value="example">

```cpp {2}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3); //Creating the path
goal_path.upgrade(); //In this function we are injecting points and then smoothing the goal_path. 

```
</TabItem>

</Tabs>

---

## Setters
### set_max_lineal_velocity()

:::warning
This function it is **essencial**. You must invoke before using the ``make_calcs`` function. 
:::

Sets the maximum velocity **(inches/second)** for the path.

<Tabs
  groupId="Path_setters_max_lineal_velocity"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
   void set_max_lineal_velocity(double velocity);

```
</TabItem>


<TabItem value="example">

```cpp {5}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},false,3); 
goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second). 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``velocity``  |  The max velocity in **inches/second**.|

---

### set_reverse()
Sets if the path is **reversed**.

<Tabs
  groupId="Path_setters_reverse"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void set_reverse(bool _is_reverse);

```
</TabItem>


<TabItem value="example">

```cpp {5}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 
goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_reverse(true); //Reversing goal_path

goal_path.set_max_lineal_velocity(10); //10 (inches/second). 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``_is_reverse``  | Your path it is reversed?|

---

## Calcs functions
### make_calcs()
Makes all the calculations that need to calculates the target velocities.

:::note
Is neccesary to set the max velocity first.
:::

<Tabs
  groupId="Path_calcs_make"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void make_calcs(const float k);

```
</TabItem>


<TabItem value="example">

```cpp {10}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(1.15);  
pros::delay(10); //giving some time to make the calculations. 

}

```
</TabItem>

</Tabs>  

|   Param |   | 
|  --  | --- | 
|  ``k``  | it is constant, how slow you want the robot to go around turns. (aroud 1-5) | 

---

### calc_orientation()
Calculates the orientation allong the path.

:::note 
The orientation is the angle between the points. 
:::

<Tabs
  groupId="Path_calcs_orientation"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void calc_orientation(const float offset);
```
</TabItem>


<TabItem value="example">

```cpp {8}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.calc_orientation(0);

}

```
</TabItem>

</Tabs> 

| Parameters    |  |
| ------------- | ------------- |
| ``offset``  | The offset, if you want to set an orientation offset|


---

### calc_target_angular_velocities()
Calculates the target angular velocities.

:::warning
The functions must to be invoke after using the ``make_calcs`` function. 
:::

<Tabs
  groupId="Path_calcs_angular_velocities"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
void calc_target_angular_velocities();
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

goal_path.calc_target_angular_velocities(); 

}

```
</TabItem>

</Tabs> 

---

## Getters
### get_curvature_vector()
Gets the curvature vector.

<Tabs
  groupId="Path_getters_curvature_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
    std::vector<double> get_curvature_vector() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>curvature_in_path= goal_path.get_curvature_vector();

}

```
</TabItem>

</Tabs>

**Returns:** A new vector with all the curvatures.

---

### get_distance_vector()
Gets the distance vector.

<Tabs
  groupId="Path_getters_distance_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_distance_vector() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>distance_in_path= goal_path.get_distance_vector();

}

```
</TabItem>

</Tabs>


**Returns:** A new vector with the distance between each point.

---

### get_maximum_lineal_velocities()
Gets the maximum lineal velocities vector.

<Tabs
  groupId="Path_getters_max_lin_vel_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_maximum_lineal_velocities() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>max_velocities_in_path= goal_path.get_maximum_lineal_velocities();

}

```
</TabItem>

</Tabs>


**Returns:**  A new vector with the maximum lineal velocities in each point.

---

###  get_target_lineal_velocities()
Gets the target lineal velocities vector. 

<Tabs
  groupId="Path_getters_target_lin_vel_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_target_lineal_velocities() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>target_velocities_in_path= goal_path.get_target_lineal_velocities();

}

```
</TabItem>

</Tabs>

**Returns:** A new vector with the target lineal velocity in each point.

---

### get_orientation_vector()
Gets the orientation vector.

<Tabs
  groupId="Path_getters_orientation_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_orientation_vector() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>orientation_vector= goal_path.get_orientation_vector();

}

```
</TabItem>

</Tabs>

**Returns:** A new vector filled with the orientation target.

---

### get_target_angular_velocities()
Gets the target angular velocities vector.

<Tabs
  groupId="Path_getters_angular_velocities_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
  std::vector<double> get_target_angular_velocities() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<float>angular_velocities_vector= goal_path.get_target_angular_velocities();

}

```
</TabItem>

</Tabs>

**Returns:** A new vector filled with the target angular velocities.  

---

### get_size()
Gets the path size.

<Tabs
  groupId="Path_getters_size"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
int16_t get_size() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

int size= goal_path.get_orientation_vector();

}

```
</TabItem>

</Tabs>

**Returns:** The ``Path`` size.

---

### get_point_at()
Retrieves a point given an index.

This method returns the coordinates of a point at the specified index in the ``Path``.

<Tabs
  groupId="Path_getters_point_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_point_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::vector<double> a_Point= goal_path.get_point_at(5); //Getting a point at index 5 of goal_path. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The index of the point to retrieve.|



**Returns:** A vector containing the x and y coordinates of the point.

---

### get_x_at()
Retrieves the x coordinate of a point given an index.

This method returns the x coordinate of the point at the specified index in the ``Path``.

<Tabs
  groupId="Path_getters_x_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_x_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double x_point= goal_path.get_x_at(5); //Getting a x at index 5 of goal_path. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The index of the point to retrieve the x coordinate from.|

**Returns:** The x coordinate of the point. 

---

### get_y_at()
Retrieves the y coordinate of a point given an index.

This method returns the y coordinate of the point at the specified index in the ``Path``.

<Tabs
  groupId="Path_getters_y_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_y_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {14}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double x_point= goal_path.get_x_at(5); //Getting a x at index 5 of goal_path. 
double y_point= goal_path.get_y_at(5); //Getting a y at index 5 of goal_path. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The index of the point to retrieve the y coordinate from.|

**Returns:** The y coordinate of the point. 

---

### get_target_lineal_velocity_at()
Retrieves the target linear velocity at a given index.

This method returns the target linear velocity at the specified index in the ``Path``.


<Tabs
  groupId="Path_getters_target_lin_velocity_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_target_lineal_velocity_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double target_velocity = goal_path.get_target_lineal_velocity_at(5) //getting target velocity at index 5. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The index of the point to retrieve the target linear velocity from.|

**Returns:** The target linear velocity at the specified index.

---

### get_maximum_lineal_velocity()
Gets the maximum lineal velocity of the ``Path``.

<Tabs
  groupId="Path_getters_maximum_lineal"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_maximum_lineal_velocity() const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double maximum_velocity = goal_path.get_maximum_lineal_velocity()//getting maximum of goal_path. 

}

```
</TabItem>

</Tabs>



**Returns:** The maximum velocity.

---

### get_theta_at()
Retrieves the orientation (theta) at a given index 

<Tabs
  groupId="Path_getters_theta_at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
 double get_theta_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double theta = goal_path.get_theta_at(5)//getting theta at index 5 of the path. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The Index the index of the point to retrieve the orientation(theta)|

**Returns:** The theta at the specified index. 

---

### get_target_angular_velocity_at()
Retrieves the target angular velocity at a given index. 

<Tabs
  groupId="Path_getters_target_angular_velocity at"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double get_target_angular_velocity_at(const int index) const;
```
</TabItem>


<TabItem value="example">

```cpp {13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

goal_path.inject_points(); 
goal_path.smoother(); 

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

double target_angular_velocity = goal_path.get_target_angular_velocity_at(5)//getting target angular velocity at index 5. 

}

```
</TabItem>

</Tabs>

| Parameters    |  |
| ------------- | ------------- |
| ``index``  | The index of the point to retrieve the target angular velocity.|

**Returns:** The theta at the specified index.

---

## Checkers
Checks if the ``Path`` is raw.
:::note
When the ``Path`` is not injected or smoothed, is it considered **raw**. 
:::

<Tabs
  groupId="Path_checkers_raw"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
bool is_raw() const;
```
</TabItem>


<TabItem value="example">

```cpp {5,9}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

std::cout<<goal_path.is_raw(); /*Output: True. */

goal_path.inject_points(); 

std::cout<<goal_path.is_raw(); /*Output: False. */

}

```
</TabItem>

</Tabs>

---

### is_inject()
Checks if the path was injected.

<Tabs
  groupId="Path_checkers_inject"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
bool is_inject() const;
```
</TabItem>


<TabItem value="example">

```cpp {5,9}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

std::cout<<goal_path.is_inject(); /*Output: False. */

goal_path.inject_points(); 

std::cout<<goal_path.is_raw(); /*Output: True. */

}

```
</TabItem>

</Tabs>

---

### is_smooth()
Checks if the path it is smooth. 

<Tabs
  groupId="Path_checkers_smooth"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
bool is_smooth() const;
```
</TabItem>


<TabItem value="example">

```cpp {5,9,13}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

std::cout<<goal_path.is_smooth(); /*Output: False. */

goal_path.inject_points(); 

std::cout<<goal_path.is_smooth(); /*Output: False. */

goal_path.smoother(); 

std::cout<<goal_path.is_smooth(); /*Output: True. */

}

```
</TabItem>

</Tabs>

---

### is_ready()
Checks if the path it is ready.

:::note
When the ``Path`` is injected, smoothed, with the maximum velocity set, and the velocities calculated, it is considered **ready**.
:::

<Tabs
  groupId="Path_checkers_ready"
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

```cpp {5,9,13,20}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

std::cout<<goal_path.is_ready(); /*Output: False. */

goal_path.inject_points(); 

std::cout<<goal_path.is_ready(); /*Output: False. */

goal_path.smoother(); 

std::cout<<goal_path.is_ready(); /*Output: False. */

goal_path.set_max_lineal_velocity(10); //10 (inches/second).

goal_path.make_cals(); 
pros::delay(10); //giving some time to make the calculations. 

std::cout<<goal_path.is_ready(); /*Output: True. */

}

```
</TabItem>

</Tabs>

---

### is_reverse()
Checks if the path it is reversed. 

<Tabs
  groupId="Path_checkers_ready"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
bool is_reverse() const;
```
</TabItem>


<TabItem value="example">

```cpp {5}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){

std::cout<<goal_path.is_reverse(); /*Output: False. */

}

```
</TabItem>

</Tabs>
---

## Operators
### `std::ostream &operator<<`
Prints the ``Path`` coordinates in the integrated terminal. 


<Tabs
  groupId="Path_checkers_ready"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::ostream &operator<<(std::ostream &os, const Path &path);
```
</TabItem>


<TabItem value="example">

```cpp {7}
lightning::Path goal_path ({0,0,24,48},{0,24,48,64},true,3); 

void autonomous(){
goal_path.inject_points(); 
goal_path.smoother(); 

std::cout<<goal_path; //PRINTING THE PATH COORDINATES 

}

```
</TabItem>

</Tabs>

---
