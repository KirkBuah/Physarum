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
    map = new float*[height+1];
       for(int i = 0; i < height+1; i++) {
           map[i] = new float[width+1];
       }

    // set random trail
    for(int i = 0; i < height+1; i++) {
        for(int j = 0; j < width+1; j++) {
            if(i == 0 || j == 0 || i == height || j == width) { // pad edges
                map[i][j] = 0;
                continue;
            }
            float r = ofRandom(1);
            if (r > 1-0.1) map[i][j] = 5;
        }
    }

}

void trailmap::decay() {
    for(int i = 1; i < height; i++) {
        for(int j = 1; j < width; j++) {
            if(map[i][j] > decay_t) map[i][j] -= decay_t;
            else map[i][j] = 0;
        }
    }
}

float trailmap::get_trail(const float x, const float y) {
    // if out of bound return 0
    if(x <= 0 || x >= width || y <= 0 || y >= height) return 0;
    int i = std::floor(x);
    int j = std::floor(y);
    return map[i][j];
}

void trailmap::set(const float x, const float y, const int value) {
    int i = std::floor(x);
    int j = std::floor(y);
    // guard to make sure the passing isn't changed
    if(i == 0 || j == 0 || i == height || j == width) return;
    map[i][j] += value;
}

void trailmap::draw() {
    for(int i = 1; i < height; i++) {
        for(int j = 1; j < width; j++) {
            if(map[i][j] > 0) {
                int b = std::floor(510/PI * std::atan(0.01*map[i][j]));
                ofSetColor(b,b,b);
                ofDrawRectangle(i,j,1,1);
            }
        }
    }
}

void trailmap::delete_trail(float x, float y, float radius) {
    for(int i = 1; i < width; i++) {
        for(int j = 1; j < height; j++) {
            if (((x-i)*(x-i) + (y-j)*(y-j)) < radius*radius) {
                map[i][j] = 0;
            }
        }
    }
}

void trailmap::diffuse() {
    for(int i = 1; i < width; i++) {
        for(int j = 1; j < width; j++) {
            // set the pixel in position i,j as the mean of the values in the 3x3 matrix
            float tl = map[i-1][j-1];
            float t = map[i][j-1];
            float tr = map[i+1][j-1];
            float ml = map[i-1][j];
            float m = map[i][j];
            float mr = map[i+1][j];
            float bl = map[i-1][j+1];
            float b = map[i][j+1];
            float br = map[i+1][j+1];

            // gaussian constants
            map[i][j] = tl/16 + t/8 + tr/16 + ml/8 + m/4 + mr/8 + bl/16 + b/8 + br/16;

        }
    }
}
