# PID Control Project
Self-Driving Car Engineer Nanodegree Program

---
# Project description
The goal of the project is to design a PID controller that is able to drive safely on the provided simulator track. The implementation of the controller itself and tuning its hyperparameters are both part of the project.

# Implementation
I implemented the basic PID controller in C++. The controller itself calculates the error which then used to calculate the steering angle of the car. Using only the controller would result in a wobbly driving experience for the passengers (it is also a strain for the eyes of the viewer) so I implemented a filter which smoothen the controller output by calculating the weighted sum of the actual PID output and the previous steering angle. This gave a much stabler result.

# Parameter tuning
Technically there are two outputs that can be updated: one is the steering angle and one is the speed of the car (by throttle). I implemented both steering and throttling control.

The parameter tuning was carried out manually. First, I checked if there is any systematic bias in the steering. I found none so I set the "I" parameter to 0 as it is not required for a stable control. Later I updated this and set to 0.00001 because leaving it on 0 would not be realistic in a real-life environment (anything could happen from a flat tire to some minor or major damage in the steering system). This made no major difference in control but should help if something should happen as then the error would accumulate very fast. 

Normally, the "P" parameter should be able to utilise the whole controller interval [-1, 1]. In this case I found that the error on the edges of the road is around 4 which would suggest P in the range of 0.25. This would enable the controller to be able to steer the car with maximum steering back to the road. I found however that using the linear P in a nonlinear environment like this (the influence of the steering angle on the velocity direction of the car is nonlinear) is not stable as for a relatively low error it would change the steering angle too much. This made the car alternating from left to right very annoyingly (especially at higher speeds). So I ended up using only about half of this, 0.12.

The "D" parameter is responsible to smoothen the trajectory. The tuning of this was experimental. I checked the produced error components and found out that it should be somewhere in the 9-15 region. I ended up using 14.

The throttling is controlled by the calculated steering angle. The equation for setting this is 1 - (3 * abs(steering_angle))
This effectively limits the speed on hard turns but does not limit the speed on long straight parts.

# Results
At my final setup I can drive safely without leaving the track. The steering is not perfect but I believe it is already acceptable and it should be okay for real passengers, too.
I also recorded a video to demostrate this:
https://youtu.be/WNVHZTEvOgk

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)


