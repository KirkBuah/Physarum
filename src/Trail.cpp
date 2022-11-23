#include "ofApp.h"

trailmap::trailmap() {
}

void trailmap::setup(int _width, int _height, bool random) {

    diff_k = 3;
    decay_t = 0.01;
    width = _width;
    height = _height;

    // dynamically allocate the trail map
    // pad the map with 0s to allow diffuse() to work
    map = new tile*[height+1];
       for(int i = 0; i < height+1; i++) {
           map[i] = new tile[width+1];
       }

    // set random trail
    for(int i = 0; i < height+1; i++) {
        for(int j = 0; j < width+1; j++) {
            // pad edges
            if(i == 0 || j == 0 || i == height || j == width) {
                map[i][j].value = 0;
                map[i][j].fixed = true;
                continue;
            }
            // insert random value
            float r = ofRandom(1);
            if (r > 1-0.1) map[i][j].value = 5;
            else map[i][j].value = 0;
            map[i][j].fixed = false;
        }
    }

}

void trailmap::decay() {
    for(int i = 1; i < height; i++) {
        for(int j = 1; j < width; j++) {
            if(map[i][j].value > decay_t && !map[i][j].fixed) map[i][j].value -= decay_t;
            else if (map[i][j].value <= decay_t && !map[i][j].fixed) map[i][j].value = 0;
        }
    }
}

float trailmap::get_trail(const float x, const float y) {
    // if out of bound return 0
    if(x <= 0 || x >= width || y <= 0 || y >= height) return 0;
    int i = std::floor(x);
    int j = std::floor(y);
    return map[i][j].value;
}

void trailmap::set(const float x, const float y, const int value) {
    int i = std::floor(x);
    int j = std::floor(y);
    // guard to make sure there won't be unwanted changes on fixed tiles
    if(map[i][j].fixed) return;
    map[i][j].value += value;
}

void trailmap::draw() {
    for(int i = 1; i < height; i++) {
        for(int j = 1; j < width; j++) {
            if(map[i][j].value > 0) {
                int b = std::floor(510/PI * std::atan(0.01*map[i][j].value));
                ofSetColor(b,b,b);
                ofDrawRectangle(i,j,1,1);
            }
        }
    }
}

void trailmap::delete_trail(float x, float y, float radius) {
    for(int i = 1; i < width; i++) {
        for(int j = 1; j < height; j++) {
            if (((x-i)*(x-i) + (y-j)*(y-j)) < radius*radius && !map[i][j].fixed) {
                map[i][j].value = 0;
            }
        }
    }
}

void trailmap::diffuse() {
    for(int i = 1; i < width; i++) {
        for(int j = 1; j < width; j++) {
            // skip fixed tiles
            if (map[i][j].fixed) continue;
            // set the pixel in position i,j as the mean of the values in the 3x3 matrix
            float tl = map[i-1][j-1].value;
            float t = map[i][j-1].value;
            float tr = map[i+1][j-1].value;
            float ml = map[i-1][j].value;
            float m = map[i][j].value;
            float mr = map[i+1][j].value;
            float bl = map[i-1][j+1].value;
            float b = map[i][j+1].value;
            float br = map[i+1][j+1].value;

            // gaussian constants
            map[i][j].value = tl/16 + t/8 + tr/16 + ml/8 + m/4 + mr/8 + bl/16 + b/8 + br/16;

        }
    }
}

void trailmap::add_nugget(float x, float y, float radius, float value) {
    for(int i = 1; i < width; i++) {
        for(int j = 1; j < height; j++) {
            if (((x-i)*(x-i) + (y-j)*(y-j)) < radius*radius) {
                map[i][j].value = value;
                map[i][j].fixed = true;
            }
        }
    }
}
