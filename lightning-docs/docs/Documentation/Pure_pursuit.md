---
sidebar_label: Pure pursuit
sidebar_position: 6
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Pure Pursuit
## Functions

### distance()
Gets the distance betweens between the two points. 

<Tabs
  groupId="Pure_pursuit_function_distance"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    { label: 'Example',  value: 'example', },
  ]
}>

<TabItem value="proto">

```cpp
double distance(std::vector<double> p1, std::vector<double> p2);

```
</TabItem>


<TabItem value="example">

```cpp

std::vector<int> Point_1 = {0,0}; //current point (x1,y1), x1= 0, y1= 0
std::vector<int> Point_2 = {24,24}; //target point (x2,y2), x2=24, y2=24

float distance = distance(Point_1,Point_2);  
```
</TabItem>

</Tabs>  


| Parameters    |  |
| ------------- | ------------- |
| ``p1``  | A vector of length two in the format ``{Y,X}`` that contains Robot::y and Robot::x.|
| ``p2``  | A vector of length two in the format ``{Y, X}`` that contains the Y and X coordinate of the target point. |


**Returns:** Provides the distance between the two points using the standard distance formula

---


### get_intersection()
 Calculates the next step of our pure pursuit mvoement given a segment
 of the waypoint path and our current position

 
<Tabs
  groupId="Pure_pursuit_function_get_intersection"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
  ]
}>

<TabItem value="proto">

```cpp
std::vector<double> get_intersection(std::vector<double> start,
                                     std::vector<double> end,
                                     std::vector<double> cur, double radius)

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``start``   | First point of waypoint path. |
| ``end``  | Second point of a two-point segment of the waypoint path. |
| ``cur``  | A vector that contains Robot::y and Robot::x position. |
| ``radius``  | A scalar representing how far our lookahead distance should be- in other words, how early we should start turning in anticipation of a change in direction |

 **Returns:** The intersection between a circle centered on our Robot's current
 position with ``radius`` and the line formed between ``start`` and
 ``end``

 ---
 