#pragma once

#include"ofMain.h"

class trailmap{
public:
    void setup(int _width, int _height, bool random);
    void diffuse();
    void decay();
    void draw();
    void set(const float x, const float y, const int value);
    float get_trail(const float x, const float y);    // get trail map value given x and y coordinates
    void delete_trail(float x, float y, float radius);
    trailmap();
private:
    float** map;      // pointer to bidimensional array of size height x width
    int width;
    int height;
    float diff_k;   // diffusion kernel size
    float decay_t;  // chemoattractant diffusion decay factor
};
