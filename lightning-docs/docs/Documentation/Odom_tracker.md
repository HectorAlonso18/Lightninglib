---
sidebar_label: Odom Tracker
sidebar_position: 4
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Odom Tracker
## Constructor
###  OdomTracker()
Constructs a ``OdomTraker`` object.

<Tabs
  groupId="odom_tracker_constructor"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
  ]
}>

<TabItem value="proto">

```cpp
  OdomTracker();
```
</TabItem>

</Tabs>  

---
### Functions
Updates the odometry system giving the new position from the trackers and orientation. 
<Tabs
  groupId="odom_tracker_functions_update_position"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    
  ]
}>

<TabItem value="proto">

```cpp
  void update_position( float ForwardTracker_position, float SidewaysTracker_position, float orientation_degrees);  

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``ForwardTracker_position``  | The forward tracker position.|
| ``SidewaysTracker_position ``| The sideways tracker position.  |
| ``orientation_degrees `` |  The orientation in degrees. |

---

## Setters
### set_position()
Sets the initial position for the odometry system.
<Tabs
  groupId="odom_tracker_setters_position"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    
  ]
}>

<TabItem value="proto">

```cpp
    void set_position (float x_position, float y_position, float orientation_degrees ,float ForwardTracker_position, float SidewaysTracker_position); 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``x_position``  | The x coordinate.. |
| ``y_position  ``|  The y coordinate.|
| ``orientation_degrees `` | the orientation in degrees. |
| ``ForwardTracker_position``  | the forward tracker position. |
| ``SidewaysTracker_position``  | the sideways tracker position. |

---

### set_physical_distances()
Sets the physical distances that exist from each tracker to the center point. 

<Tabs
  groupId="odom_tracker_setters_physical_distances"
  defaultValue="proto"
  values={[
    { label: 'Prototype',  value: 'proto', },
    
  ]
}>

<TabItem value="proto">

```cpp
    void set_physical_distances(float ForwardTracker_center_distance, float SidewaysTracker_center_distance); 

```
</TabItem>

</Tabs>  

| Parameters    |  |
| ------------- | ------------- |
| ``ForwardTracker_center_distance``  |  The distance between the center point and the forward tracker. |
| ``SidewaysTracker_center_distance``|  The distance between the center point and the sideways tracker. |


---