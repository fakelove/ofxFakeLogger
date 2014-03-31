#pragma once

#include "ofMain.h"
#include "ofxFakeLogger.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofPtr<ofx::FakeLogger::Logger> logger;
    
    // Variables for logging
    int startTime;
    int elapsedTime;
    int triggerOne;
    int triggerTwo;
    
    bool verboseLevel;
    bool logToFile;
    bool currentVerboseLevel;
    bool currentLogToFile;
    
};
