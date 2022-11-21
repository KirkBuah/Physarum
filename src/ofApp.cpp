#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    trail_map.setup(ofGetWidth(), ofGetHeight(), true);
    data_map.setup(ofGetWidth(), ofGetHeight(), (float)0.15);
}

//--------------------------------------------------------------
void ofApp::update(){
    data_map.cycle(trail_map);
    trail_map.decay();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(255, 255, 255);
    trail_map.draw(); // drawn blue
    data_map.draw(false); // drawn red
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
    trail_map.delete_trail((float)x, (float)y, 30);
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
