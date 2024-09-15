---
slug: Lightning v1.1.0
title: v1.1.0 is here!💪  
authors: [halonso]
tags: [lightning,release]
---

I am thrilled to announce that the first content version of lightning is out. 

The ``v1.1.0`` adds new functions for chassis motion and a new brand arcade configuration.

---

# What is new? 

* **Added new arcade configuration 🕹️ (```E_TANK_OP_ARCADE_DOUBLE_ALTERNATIVE```)**
 With this configuration now you can control de forward/backward movements using the right stick and control the turns using the left stick

* **New overloads for motion functions 🏎️**
  * ``move_velocity(const int left_rpm, const int right_rpm)``
  *  ``move_voltage(const int left_voltage_mv, const int right_voltage_mv)``
  *  ``move(const int left_voltage, const int right_voltage)``
  
  Now it is possible to control each side of the drive train. In previous versions you were just able to control the entire drive train.

---
# Sounds great, how can i start coding? 😳
Great! just dowloand the example project [here](https://github.com/HectorAlonso18/Lightninglib/releases/tag/v1.1.0). 

---

# How can i upgrade my lightning project ? 
Easy, just follow these steps: 
1. Download the zip file ``lightninglib@1.1.0.zip``
2. Go to the PROS terminal in your project
3. Execute this command: ``pros conduct fetch lightninglib@1.1.0.zip``
4. Then execute: ``pros conduct apply lightninglib``
5. There you go! Start coding 😀