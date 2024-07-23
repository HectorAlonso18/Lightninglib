---
sidebar_label: Math
sidebar_position: 10
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Math 
:::note
Math functions are built with templates. This means that you can use different types of parameters with these functions, such as `int`, `float`, `double`, etc.
Templates allow these functions to operate with various data types, providing flexibility and reusability in your code. 
:::
## Math functions
### sign()
Sign function.

<Tabs
  groupId="math_sign"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T sign(const T &num);

```
</TabItem>


<TabItem value="example">

```cpp
bool sign_number; 
sign_number = sign(-5); 
//sign_number equals to -1 

```
</TabItem>

</Tabs>  


| Parameters    |  |
| ------------- | ------------- |
| ``num``  | A number. |

**Returns:** -1 if its negative or 1 if its positive.

---

## Trigonometry
### to_rad()
Translates degrees to radians.
<Tabs
  groupId="math_to_rad"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T to_rad(const T &num)

```
</TabItem>


<TabItem value="example">

```cpp
int degrees = 90; 
int radians = to_rad(degrees);

std::cout<<degrees<<" Degrees is equal to: "<<radians<<"radians"; 

//OUTPUT: 90 Degrees is equal to π/2 radians 
```
</TabItem>

</Tabs>  


| Parameters    |  |
| ------------- | ------------- |
| ``num``  | An angle in degrees. |

**Returns:**  Angle in radians.

---

### to_degrees()
Translates radians to degrees.

<Tabs
  groupId="math_to_degrees"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T to_degrees(const T &num)

```
</TabItem>


<TabItem value="example">

```cpp

int radians = 3.141516; 
int degrees = to_rad(radians);

std::cout<<radians<<" Radians is equal to: "<<degrees<<"degrees"; 

//OUTPUT: 3.141516 Degrees is equal to 180 degrees
```
</TabItem>

</Tabs>  


| Parameters    |  |
| ------------- | ------------- |
| ``num``  | An angle in radians. |

**Returns:**  Angle in degrees. 

---

### reduce_angle_0_to_360()
Puts angle in a 0-360 degrees range.

<Tabs
  groupId="math_to_reduce_0_360"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T reduce_angle_0_to_360(T degrees); 

```
</TabItem>


<TabItem value="example">

```cpp
int angle_out_of_range = 720; 
int angle_in_range= reduce_angle_0_to_360(angle_out_of_range);

//angle_in_range is now equal to 360. 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``degrees``  | An angle in degrees. |

**Returns:** The angle in degrees in range of 0-360 degrees. 

---

###  reduce_angle_180_to_180()
Put angle in a -180 -180 degrees range.

<Tabs
  groupId="math_to_reduce_-180-180"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T> T reduce_angle_180_to_180()
```
</TabItem>


<TabItem value="example">

```cpp
int angle_out_of_range = 360; 
int angle_in_range= reduce_angle_180_to_180(angle_out_of_range);

//angle_in_range is now equal to 180. 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``degrees``  | An angle in degrees. |

**Returns:** The angle in degrees in range of -180-180 degrees. 

---

### get_angle_btw_points()
Gets the angle in degrees between two points.

<Tabs
  groupId="math_angle_btw_points"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
auto get_angle_btw_points(const std::vector<T1> &current,
                          const std::vector<T2> &target); 

```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Point_1 = {0,0}; //current point (x1,y1), x1= 0, y1= 0
std::vector<int> Point_2 = {2,2}; //target point (x2,y2), x2=2, y2=2

int angle_btw_points = get_angle_btw_points(Point_1,Point_2); 

//angle_btw_points is equal to: 45 degrees

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``current``  | Current point. |
| ``target``  | Target point. |


**Returns:** The angle in degrees that exist between current and target points. 

---

### distance_btw_points()
Gets the distance between two points using Pythagoras.

<Tabs
  groupId="math_to_dis_btw_points"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
auto distance_btw_points(const std::vector<T1> &p1, const std::vector<T2> &p2);
```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Point_1 = {0,0}; //current point (x1,y1), x1= 0, y1= 0
std::vector<int> Point_2 = {24,24}; //target point (x2,y2), x2=24, y2=24

float distance = distace_btw_points(Point_1,Point_2); 


//distance is equal to: 33.94

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``p1``  | Current point. |
| ``p2``  | Target point. |


**Returns:**  Distance between current and target points. 

---

## Velocity
:::note 
The linear velocity is always in **distance/seconds units**. 
:::
### rpm_to_linear()
Convert a **RPM** velocity to a linear velocity **(distance/seconds)**.

<Tabs
  groupId="math_rpm_to_linear"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
    { label: 'Example 2',  value: 'example_2', },
  ]
}>

<TabItem value="proto">

```cpp
auto rpm_to_linear(const T1 &rpm, const T2 &wheel_diameter);
```
</TabItem>


<TabItem value="example">

```cpp
//Converting RPM to inches/second 
int RPM= 450; //RPM
float wheel_diameter_inches = 3.25; //The wheel size

float velocity_inches_second = rpm_to_linear(RPM,wheel_diameter_inches); //equivalent linear velocity  (inches/s)

```
</TabItem>

<TabItem value="example_2">

```cpp
//Converting RPM to meters/second 
int RPM= 450; //RPM
float wheel_diameter_meters = 0.08255; //The wheel size

float velocity_inches_second = rpm_to_linear(RPM,wheel_diameter_meters); //equivalent linear velocity  (m/s)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``rpm``  | RPM velocity.|
| ``wheel_diameter``  | The wheel size. |


**Returns:** Velocity converted. 

---

### linear_to_rpm()
Convert a lineal velocity **(distance/seconds)** to a **RPM**.
:::warning
The distance units in the velocity and wheel diameter **must to be the same**.  
:::
<Tabs
  groupId="math_linear_rpm"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
    { label: 'Example 2',  value: 'example_2', },
  ]
}>

<TabItem value="proto">

```cpp
auto linear_to_rpm(const T1 &lineal_velocity, const T2 &wheel_diameter);
```
</TabItem>


<TabItem value="example">

```cpp
//Converting inches/second to RPM 
int velocity_inches_second = 5; 
float wheel_diameter_inches = 3.25; //The wheel size

float RPM = linear_to_rpm(velocity_inches_second, wheel_diameter_inches); //equivalent  RPM velocity. 

```
</TabItem>

<TabItem value="example_2">

```cpp
//Converting meters/second to RPM 
float velocity_meters_second = .25; 
float wheel_diameter_meters = 0.08255; //The wheel size

float RPM = linear_to_rpm(velocity_meters_second, wheel_diameter_meters); //equivalent  RPM velocity.

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``lineal_velocity``  | lineal velocity (distance/seconds).|
| ``wheel_diameter``  | The wheel size . |


**Returns:** Velocity converted. 

---

## Vector operations
### swap_vector()
Swaps the first two elements of a vector.

<Tabs
  groupId="math_swap_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
template <typename T1> std::vector<T1> swap_vector(const std::vector<T1> &a);
```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Vector_1 = {0,24} // Vector_1 elements are: x1:0 , y1:24

Vector_1 = swap_vector(Vector_1); 

//Now Vector_1 elements are: x1:24 , y1:0

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``a``  |The input vector. |


**Returns:**  A vector with the first two elements swapped.

---

### vector_add()
Adds two vectors element-wise.

<Tabs
  groupId="math_add_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<T1> vector_add(const std::vector<T1> &a, const std::vector<T1> &b);
```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Vector_a = {5,24}; 
std::vector<int> Vector_b = {10,6}; 

std::vector<int> Vector_c; 

//Vector_c is the result of: Vector_a + Vector_b
Vector_c = vector_add(Vector_a, Vector_b); 

//Vector_c elements are: (x:5+10 , y:24+6)
//Vector_c elements are: (x:15   , y:30)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``a``  |The first input vector. |
| ``b``  |The second input vector. |

**Returns:** A vector with each element being the sum of the corresponding elements of a and b.

---

### vector_sub()
Subtracts the second vector from the first vector element-wise.

<Tabs
  groupId="math_sub_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<T1> vector_sub(const std::vector<T1> &a, const std::vector<T1> &b);
```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Vector_a = {5,24}; 
std::vector<int> Vector_b = {10,6}; 

std::vector<int> Vector_c; 

//Vector_c is the result of: Vector_a - Vector_b
Vector_c = vector_sub(Vector_a, Vector_b); 

//Vector_c elements are: (x:5-10 , y:24-6)
//Vector_c elements are: (x:-5   , y:18)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``a``  |The first input vector. |
| ``b``  |The second input vector. |

**Returns:**  A vector with each element being the difference of the corresponding elements of a and b.

---

### vector_dot()
Computes the dot product of two vectors.
<Tabs
  groupId="math_dot_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
auto vector_dot(const std::vector<T1> &a, const std::vector<T1> &b);
```
</TabItem>


<TabItem value="example">

```cpp
std::vector<int> Vector_a = {5,24}; 
std::vector<int> Vector_b = {10,6}; 

//Making the dot product of Vector_a and Vector_b 
float dot_product = vector_dot (Vector_a,Vector_b); 
```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``a``  |The first input vector. |
| ``b``  |The second input vector. |

**Returns:**  The dot product of the vectors.

---

### vector_mult()
Multiplies each element of a vector by a scalar.
<Tabs
  groupId="math_mult_vector"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<T1> vector_mult(const std::vector<T1> &a, const T2 b);
```
</TabItem>


<TabItem value="example">

```cpp
//we will multiply vector_a to 2. 
std::vector<int> Vector_a = {5,24}; 
int multiply_by = 2; 


//Vector_c is the result of: Vector_a * 2

std::vector<int> Vector_c = vector_mult(Vector_a, multiply_by); 
//Vector_c elements are: (x:5*2 , y:24*2)
//Vector_c elements are: (x:10   , y:48)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``a``  |The input vector. |
| ``b``  |The scalar value. |

**Returns:**  A vector with each element multiplied by the scalar.

---
