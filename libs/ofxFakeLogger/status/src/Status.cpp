#include "ofx/FakeLogger/status/Status.h"
namespace ofx{
    namespace FakeLogger{
        
        StatusLogger::StatusLogger(){
            mStartTime = ofGetSystemTime();
            setFile(ofToDataPath(ofGetTimestampString()+"-status.log"), false);
        }
        
        StatusLogger::StatusLogger(const string & path, bool append){
            setFile(ofToDataPath(path+"-status.log"), append);
        }
        
        StatusLogger::~StatusLogger(){
            
        }
        
        void StatusLogger::setFile(const string &path, bool append){
            mPath = path;
            bAppend = append;
            if(!bAppend){
                if(ofFile::doesFileExist(path)){
                    ofFile::moveFromTo(path, path+ofGetTimestampString());
                }
            }
        }
        void StatusLogger::close(){
            if(bOpen){
                mFile.close();
            }
            
        }
        void StatusLogger::log(){
            bOpen = mFile.open(mPath, ofFile::WriteOnly, false);
            if(bOpen){
                mFrameRate+=ofGetFrameRate();
                mFrameRate = mFrameRate/2;
                string logString;
                logString.append(ofGetTimestampString("%M-%D-%Y-%H-%M-%S-%i"));
                logString.append(" avg frame rate: ");
                logString.append(ofToString(mFrameRate));
                logString.append(" current frame rate ");
                logString.append(ofToString(ofGetFrameRate()));
                logString.append(" uptime (s): "+ofToString(ofGetElapsedTimeMillis()/1000));
                logString.append("\n");
                mFile<<logString;
                mFile<<endl;
                mFile.close();
            }
        }
    }
}