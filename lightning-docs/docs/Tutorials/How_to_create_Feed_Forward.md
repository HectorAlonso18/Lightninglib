---
sidebar_label: How to create a FeedForward
sidebar_position: 6
---

# Introduction 
>A feedforward control system improves system performance by taking preemptive action based on known or anticipated disturbances
rather than reacting to the system's output. It directly manipulates the system's input based on a model or prediction of how  disturbances will impact the output ( [Cadence PCB Resources](https://resources.pcb.cadence.com/blog/2023-feedforward-control-system) ).

The FeedForward implementation in lightning is based on **The Permanent-Magned DC Motor Feedforward Equation**, To se more information about the equation , refer to the article written by [WPILib](https://resources.pcb.cadence.com/blog/2023-feedforward-control-system). 

**The Permanent-Magned DC Motor Feedforward Equation is**: 

$$ Voltage = K_s * sgn(\dot{d}) + K_v * \dot{d} + K_a * \ddot{d} $$

---

During the [SPIN-UP](https://www.youtube.com/watch?v=wIZgvVDZc2Y&t=89s&pp=ygUZc3BpbiB1cCBzZWFzb24gZ2FtZSB2aWRlbw%3D%3D) season our team ``ITESM1`` used a PID combined with a FeedForward Controller to control the Flywheel Velocity. The results were amazing, providing incredible control over the flywheel velocity and increasing the shooting accurancy. To see this in action, check out this [Video](https://www.youtube.com/watch?v=_u5JN3hauW0).

---

# FeedForward Tutorial
## Creating a FeedForward controller
Creating a FeedForward controller is matter of using the constructor for the ``FeedForward`` class. 
Check the [FeedForward Documentation](http://localhost:3000/docs/Documentation/Feed_Forward) for more information about it. 

```cpp title="main.cpp"
lightning::FeedForward speed_controller (
    5, // The velocity constant.
    1000, // The Friction constant.
    350); //Acceleration constant.
```
---
## Creating the motion function 
In the next code we would create a function with the objetive of controlling the velocity on a flywheel using a feedforward controller. 
```cpp title= "main.cpp"
lightning::FeedForward speed_controller (
    5, // The velocity constant.
    1000, // The Friction constant.
    350); //Acceleration constant.

void move_flywheel(int RPM){
    float velocity=0; 
    while(1){
        velocity = get_flywheel_velocity(); 
        controller.update(velocity);
        flywheel.move_voltage(speed_controller.get_output()); 
    }
}
```
---

## FeedForward Tuning
Tuning the feedforward controller is necessary for accurate results. For a comprehensive guide on how to tune your feedforward controller, We recommend the following [guide](https://learnroadrunner.com/feedforward-tuning.html#tuning).

---

## Congratulations! 🥳
You finished the ``FeedForward`` tutorial, now you are able to create and use a ``FeedForward`` controller for your routines. 

:::tip
You can combined the ``FeedForward`` controller with a ``PID`` controller, having a **FeedForward FeedBack controller**, feel free to experiment 🧪. 
:::



