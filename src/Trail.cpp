#include "ofApp.h"

trailmap::trailmap() {
}

void trailmap::setup(int _width, int _height, bool random) {

    diff_k = 3;
    decay_t = 0.1;
    width = _width;
    height = _height;

    // dynamically allocate the trail map
    map = new float*[height];
    for(int i = 0; i < height; i++) {
        map[i] = new float[width];
    }

    // set random trail
    if (random) {
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                float r = ofRandom(1);
                if (r > 1-0.01) map[i][j] = 5;
            }
        }
    }

}

void trailmap::decay() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
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
    map[i][j] += value;
}

void trailmap::draw() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(map[i][j] > 0) {
                ofSetColor(0,0,255);
                ofDrawRectangle(i,j,1,1);
            }
        }
    }
}

void trailmap::delete_trail(float x, float y, float radius) {
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            if (((x-i)*(x-i) + (y-j)*(y-j)) < radius*radius) {
                map[i][j] = 0;
            }
        }
    }
}
