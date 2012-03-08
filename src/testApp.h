#pragma once

#include "ofMain.h"
#include "ofxUI.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void draw();
    void exit(); 
    void guiEvent(ofxUIEventArgs &e);
    
    void prepareShape();
    void prepareGUI();
    
    ofVbo vbo;
    ofEasyCam camera;
    float degrees;
    float x,y,z;
    float xDeg, yDeg, zDeg;
    ofxUICanvas *gui;
};