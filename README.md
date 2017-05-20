
[image1]: ./imgs/simulator.png
[image2]: ./imgs/nosimulator.png
[image3]: ./imgs/sampling_rate.png
[image4]: ./imgs/pgainerr.png
[image5]: ./imgs/psteer.png
[image6]: ./imgs/pdgainerr.png
[image7]: ./imgs/pdsteer.png
[image8]: ./imgs/pidgainerr.png
[image9]: ./imgs/pidsteer.png

# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

# PID Control

Before describing what I have done, I first have to express my discontent with the simulator. It locks up a gargantuan amount of resources just to run the simulator (see figures below). That creates a huge amount of trouble for people like me who do not have very powerful computer nor GPU. The problems multiple:

1. When running the simulator I was unable to do any coding at all, even just the parameter tuning was very hard.
2. The sampling rate was too high. In my case, it was ~100ms. That makes creating high-performance control algorithms very hard. The only solution is to slow down the car. 
3. The sampling rate is highly inconsistent (see figure below). That makes the whole behavior of the control system unpredictable and erratic. 
4. The simulator does not work on the second track! That fix would help build better and more robust controllers.

I would prefer less fancy graphics, for higher and more consistent sampling rate. 

| Simulator Running | No simulator | Sampling rate  |
|-------------------|--------------|----------------|
|![][image1]        | ![][image2]  |  ![][image3]   |



## P gain

P gain seemed to guide the car towards the center of the road. The problem with it was that the car was oscillating around the middle of the road all the time. If the P gain was too large the oscillations were increasing, leading to the car leaving the road. When I was setting the P gain, I have selected the biggest possible so that car makes the first turn. Larger ones would cause a car to leave the road before or at the first corner. Both the error and the control are very oscillatory. Here are the output and control signal:


| CTE               | Steering angle  |
|-------------------|-----------------|
|![][image4]        | ![][image5]     |

Video showing the response can be found [here.](./imgs/pgain.mp4)

## D gain

D gain is added to remove the oscillations of the car. When the D gain was too high, the car produces erratic movements and control signal jumped violently. When the D gain was too low, the car was still oscillating. So, the D gain was selected as a tradeoff between those two, the value that removes oscillations of the car without causing violent jumps of the control signal. Here are the output and control signal:


| CTE               | Steering angle  |
|-------------------|-----------------|
|![][image6]        | ![][image7]     |

Video showing the response can be found [here.](./imgs/pdgain.mp4)


## I gain

With only PD the car was always slightly to the side of the road. Also, in some of the corners, the car was slow to react. For that reason the I gain was added, in order to maintain cars position at the center of the road. The only problem was the right turn after two left turns when the I component has aggregated big amount. Here are the output and control signal:

| CTE               | Steering angle  |
|-------------------|-----------------|
|![][image8]        | ![][image9]     |

Video showing the response can be found [here.](./imgs/pidgain.mp4)

## Conclusions
The PID controller produced decent results when the turning radius was high. For the tight turns, the car went near the edge of the road. The problem is that car takes the only current state into consideration. We, humans, can anticipate future steering angles based on the configuration of the road, so similar mechanism should be incorporated in control system. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


