#pragma once

#include"ofMain.h"

struct tile{
    float value;
    bool fixed;
};

class trailmap{
public:
    void setup(int _width, int _height, bool random);           // generate trail map
    void diffuse();                                             // diffuse trail map using a 3x3 gaussian kernel
    void decay();                                               // subtract a fixed value from each tile
    void draw();                                                // draw each tile with color intensity proportional to the tile value
    void set(const float x, const float y, const int value);    // set trail map value
    float get_trail(const float x, const float y);              // get trail map value given x and y coordinates

    // brush functions
    void delete_trail(float x, float y, float radius);          // set tile value to 0 within a fixed radius from the mouse cursor
    void add_nugget(float x, float y, float radius, float value);   // add undepletable "nugget" of chemoattractant
    trailmap();
private:
    tile** map;     // pointer to bidimensional array of size height x width
    int width;      // bidimensional matrix width
    int height;     // bidimensional matrix height
    float diff_k;   // diffusion kernel size
    float decay_t;  // chemoattractant diffusion decay factor
};
