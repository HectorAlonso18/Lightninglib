---
sidebar_label: Enumerated Values
sidebar_position: 11
---
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';

# Enumerated Values

## ``tank_odom_et``
Indicates the current chassis odometry configuration. 

```cpp
typedef enum {
  NO_ODOM =0,

  ADI_ONE_ODOM,
  ADI_TWO_ODOM,
  ADI_TWO_ROTATED_ODOM,

  ROTATION_ONE_ODOM,
  ROTATION_TWO_ODOM,
  ROTATION_TWO_ROTATED_ODOM
  
} tank_odom_e_t; 
```
| Parameters    |  |
| ------------- | ------------- |
| ``NO_ODOM``  | No odometry. |
| ``ADI_ONE_ODOM``  |  Odometry with **one** tracking wheel using **ADI encoder**. |
| ``ADI_TWO_ODOM``  |  Odometry with **two** tracking wheels using **ADI encoders**.|
| ``ADI_TWO_ROTATED_ODOM``  |   Odometry with **two** rotated tracking wheels using **ADI encoders**. |
| ``ROTATION_ONE_ODOM``  |  Odometry with **one** tracking wheel using **v5 Rotation sensor**. |
| ``ROTATION_TWO_ODOM``  |  Odometry with **two** tracking wheels using **v5 Rotation sensor**.|
| ``ROTATION_TWO_ROTATED_ODOM``  |   Odometry with **two** rotated tracking wheels using **v5 Rotation sensor**. |
---

## `swing_direction_e_t`
Indicates the swing turn type. 

```cpp
typedef enum{
  LEFT_SWING=0,
  RIGHT_SWING
} swing_direction_e_t; 
```
| Parameters    |  |
| ------------- | ------------- |
| ``LEFT_SWING``  | Block the chassis´s **left side** when turning. |
| ``RIGHT_SWING``  |  Block the chassis´s **right side** when turning.|

---

## `tank_op_arcade_e_t`
Indicates the arcade configuration during driver period. 

```cpp
typedef enum {
  E_TANK_OP_ARCADE_LEFT = 0,       // Left stick configuration
  E_TANK_OP_ARCADE_RIGHT,          // Right stick configuration
  E_TANK_OP_ARCADE_DOUBLE         // Double stick configuration
} tank_op_arcade_e_t;
```

| Parameters    |  |
| ------------- | ------------- |
| ``E_TANK_OP_ARCADE_LEFT``  |Left stick configuration.|
| ``E_TANK_OP_ARCADE_RIGHT``  |  Right stick configuration.|
| ``E_TANK_OP_ARCADE_DOUBLE``  |  Double stick configuration.|
---