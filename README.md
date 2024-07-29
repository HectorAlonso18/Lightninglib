[![License: MPL 2.0](https://img.shields.io/badge/License-MPL%202.0-brightgreen.svg)](https://opensource.org/licenses/MPL-2.0)

# Python utilities 🐍
Lightning has different python utilities to **maximize** the user experience. 

---

## LightningPlanner

With ``LightningPlanner``, you can plan your autonomous routine directly from your computer, eliminating the need for field measurements.

---

### Path Planning 
Plan your autonomous routes without the necessity of physical measurements.
**Features:**

* **Easy to Use:** Intuitive interface for generating waypoints and trajectories.
* **Flexible:** Save and reset coordinates with simple commands.
* **Export Capabilities:** Save your route plans to a file for easy integration with your autonomous system.

--- 

### Available for 
``LightningPlanner`` can be setted for: 
* VRC
    * VRC Matches (Blue and Red alliance)
    * VRC Skills

* VEXU
    * VEXU Matches (Blue and Red alliance)
    * VEXU Skills

---

### How it works
1. **Generate Waypoints:** Click to set waypoints for your robot's path.

![Planner](LPlanner_teaser_field.png)

2. **Print Coordinates:** Right-click to view all the coordinates you’ve generated.
```console
Origin: x: 0 (inches)  y:  0 (inches)
x: 2.59 (inches)  y: 28.18 (inches)
x: -42.40 (inches)  y: 49.90 (inches)
x: -91.78 (inches)  y: 51.19 (inches)
X:  [185.0, 11.0, -180.0]
Y:  [-88.0, -4.0, 1.0]
```

3. **Save Coordinates:** Press 's' to save the waypoints to a text file in the Field_waypoints directory.
```txt
X: {185.0, 11.0, -180.0}
Y: {-88.0, -4.0, 1.0}
```
You can paste this new coordinates to your `Lightning project` and construct a new Path using the `Path` class. 

```cpp
lightning::Path my_path({185.0, 11.0, -180.0},{-88.0, -4.0, 1.0},false,3)
```

4. **Reset:** Press 'r' to reset the coordinates and start planning from scratch.

5. **Exit:** Press 'q' to exit the program

---

## License
This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with this file, you can obtain one at http://mozilla.org/MPL/2.0/.