#include "ofApp.h"

agentarray::agentarray() {

}

void agentarray::setup(int _width, int _height, float population_percentage) {

    width = _width;
    height = _height;
    p = population_percentage;

    length = (int)(width * height * p);

    // populate array
    for(int i = 0; i < length; i++) {
        array.push_back(new agent());
    }
}

void agentarray::setup(int _width, int _height, int agents) {

    width = _width;
    height = _height;
    length = agents;
    // populate array
    for(int i = 0; i < length; i++) {
        array.push_back(new agent());
    }
}

void agentarray::cycle(const trailmap trail_map) {
    // randomly cycle through the array to avoid any bias due to sequential ordering
    //std::random_shuffle(array.begin(), array.end());
    for(int i = 0; i < length; i++) {
        // make agent sense where it should turn and rotate accordingly
        int where = array[i]->sense(trail_map);
        array[i]->rotate(where);
        // make the agent move
        array[i]->move();
        // deposit chemoattractant on trailmap tile corriponding to the new agent position
        array[i]->deposit(trail_map);
    }
}

void agentarray::draw(bool debug = false) {
    for(int i = 0; i < length; i++) {
        int x = array[i]->get_x();
        int y = array[i]->get_y();
        ofSetColor(255,0,0);
        ofDrawRectangle(x,y,1,1 );
        if (debug) {
            ofSetColor(0,0,0);
            float x,y;
            // draw FL
            array[i]->get_FL(-1,x,y);
            ofDrawRectangle(x,y,2,2);
            // draw F
            array[i]->get_FL(0,x,y);
            ofDrawRectangle(x,y,2,2);
            // draw FR
            array[i]->get_FL(1,x,y);
            ofDrawRectangle(x,y,2,2);
        }
    }
}
