#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    logger = ofPtr<ofx::FakeLogger::Logger>(new ofx::FakeLogger::Logger());
    logger->logImpressions(true);
    ofSetLoggerChannel(logger);

    
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    
	startTime = ofGetElapsedTimeMillis();
	elapsedTime = 0;
	triggerOne = 0;
	triggerTwo = 0;
    
	verboseLevel = true;
    
	// Bools for tracking changed conditions
	currentVerboseLevel = false;
	currentLogToFile = false;
    
	// Default log level is OF_NOTICE, so this doesn't have to be set
	// all log messages of level Notice and above will be shown.
    
	// We can set specific log levels for "modules", independent of the
	// global log level, like so:
	ofSetLogLevel("loggingChannelStuff", OF_LOG_VERBOSE);
    
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    elapsedTime = ofGetElapsedTimeMillis() - startTime;
    
	if(elapsedTime >= triggerOne){
		ofLogVerbose() << "Run time is " << (elapsedTime / 1000) << " seconds"; //One way of composing log messages
		triggerOne += 1000; // triggerOne fires every second
	}
    
	if(elapsedTime >= triggerTwo){
		ofLog(OF_LOG_NOTICE, "5s timer: Run time is %i seconds", elapsedTime / 1000); //Another way of composing log messages
		triggerTwo += 5000; // triggerTwo fires every 5 seconds
        logger->logScreen();
	}
    
    logger->logStatus();
    
	if(verboseLevel != currentVerboseLevel){ // if the verbosity level has just changed
		currentVerboseLevel = verboseLevel;
		if(verboseLevel){ // set log level according to button state
			ofSetLogLevel(OF_LOG_VERBOSE);
		}
		else{
			ofSetLogLevel(OF_LOG_NOTICE);
		}
		ofLog(OF_LOG_FATAL_ERROR, "New log level is " + ofGetLogLevelName(ofGetLogLevel())); // The third way of composing log messages
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    string verboseStr = "[ ]";
	if( verboseLevel ) verboseStr = "[x]";

	ofDrawBitmapString("Key Controls:\nv: Set verbose log "+verboseStr, 20, 30);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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