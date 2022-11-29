#pragma once

#include "ofMain.h"
#include "Trail.h"
class agent{
public:
    int sense(trailmap trail_map);                          // sense chemoattractant, input from trail_map and return -1,0,1 for rotate left,straight,right
    void rotate(const int where);                           // rotate according to output from sense()
    void rotate(const float angle);                         // rotate according to angle within range [0,2*PI)
    void next_position(float &x, float &y);                 // writes on variables x and y the next position of the agent
    void move();                                            // move agent to next position
    void deposit(trailmap trail_map);                       // deposit chemoattractant after moving
    void encircle(float r_min, float r_max, float angle);   // places the agent on a random position on a circle centered in the center of the scene,
                                                            // with radius r_min and thickness r_max - r_min. Angle is the radial direction of the agent
                                                            // with 0 degrees pointing directly outwards
    // getters
    float get_x();                                      // return x coordinate
    float get_y();                                      // return y coordinate
    float get_step_size();                              // return the agent step size
    float get_direction();                              // return the direction the agent is pointing towards (0,2PI)
    void get_FL(const int which, float &x, float&y);    // get sensor coordinates, which takes -1 for FL, 0 for F, 1 for FR

    // setters
    void set_x(const float _x);                         // set x coordinate to a float in range (0, width)
    void set_y(const float _y);                         // set y coordinate to a float in range (0,height)
    void new_direction();                               // assign a random new direction to the agent

    agent();
private:
    // agent variables
    float x;                          // agent x coordinate
    float y;                          // agent y coordinate
    float i;                          // corresponding agent i index
    float j;                          // corresponding agent j index
    float direction;                  // current agent direction, from 0 to 2pi
    const float arm_angle;            // sensor arm angle
    const float rotation_angle;       // agent rotation angle
    const float sensor_offset;        // sensor arm length
    const float sensor_width;         // sensor size
    const float step_size;            // how far the agent moves per step
    const float dep_t;                // chemoattractant deposition per step
    const float p_random_direction;   // probability of random change in direction
    const float s_min;                // sensitivity to chemoattractant threshold
};
