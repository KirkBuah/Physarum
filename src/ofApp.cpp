#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    trail_map.setup(ofGetWidth(), ofGetHeight(), true);
    data_map.setup(ofGetWidth(), ofGetHeight(), (float)0.15);
}

//--------------------------------------------------------------
void ofApp::update(){
    data_map.cycle(trail_map);
    trail_map.diffuse();
    trail_map.decay();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(0, 0, 0);
    //trail_map.draw();
    data_map.draw(false);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    trail_map.add_nugget((float)x, (float)y, 10, 200);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
