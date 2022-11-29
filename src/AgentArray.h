#pragma once

#include "Agent.h"
#include "Trail.h"
#include"ofMain.h"

class agentarray{
public:
    void setup(int _width, int _height, float population_percentage);
    void setup(int _width, int _height, int agents);
    void encircle(float r_min, float r_max, float angle);                    // encircle agents
    void cycle(const trailmap trail_map);                                    // cycle scene, takes as input the trail map
    void draw(bool debug);                                                   // draw agents on screen, if debug = true draw sensors too

    agentarray();

private:
    std::vector<agent*> array;
    int width;
    int height;
    int length;
    float p;

    bool move(agent* a, int& new_i, int& new_j);                             // move if possible, return true if moved, else false
    void populate(float p);                                                  // populate p% of the map
    bool insert_agent(agent* a);                                             // insert agent in map based on x and y coordinates, returns true if successful
};

