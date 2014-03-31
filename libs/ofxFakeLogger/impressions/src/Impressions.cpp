#include "ofx/FakeLogger/impressions/Impressions.h"

namespace ofx{
    namespace FakeLogger{
        
        ImpressionsLogger::ImpressionsLogger(){
            setFile(ofToDataPath(ofGetTimestampString()+"-impressions.log"), true);
            mNumClicks = 0;
            mKeysPressed = 0;
        }
        
        ImpressionsLogger::ImpressionsLogger(const string & path, bool append){
            setFile(path+"-impressions.log", true);
            mNumClicks = 0;
            mKeysPressed = 0;
        }
        ImpressionsLogger::~ImpressionsLogger(){
            
        }
        void ImpressionsLogger::setFile(const string & path,bool append){
            mPath = path;
            bAppend = append;
            mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            mFile.close();
        }
        void ImpressionsLogger::log(){
            
        }
        
        void ImpressionsLogger::mousePressed(ofMouseEventArgs& mouse){
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" mousePressed ";
            if(bOpen){
                mFile<<logString;
                mFile<<" @ x:y "<<mouse.x<<" : "<<mouse.y;
                mFile<<endl;
                mFile.close();
            }
        }
        void ImpressionsLogger::mouseMoved(ofMouseEventArgs& mouse){
//            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
//            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" mouseMoved";
//            if(bOpen){
//                mFile<<logString;
//                mFile<<endl;
//                mFile<<" moved x:y "<<mouse.x<<" : "<<mouse.y;
//                mFile<<endl;
//                mFile.close();
//            }
        }
        void ImpressionsLogger::mouseDragged(ofMouseEventArgs& mouse){
//            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
//            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" mouseDragged";
//            if(bOpen){
//                mFile<<logString;
//                mFile<<endl;
//                mFile<<" dragged x:y "<<mouse.x<<" : "<<mouse.y;
//                mFile<<endl;
//                mFile.close();
//            }
        }
        void ImpressionsLogger::mouseReleased(ofMouseEventArgs& mouse){
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" mouseReleased";
            mNumClicks++;
            logString.append(" total clicks "+ofToString(mNumClicks));
            if(bOpen){
                mFile<<logString;
                mFile<<" released x:y "<<mouse.x<<" : "<<mouse.y;
                mFile<<endl;
                mFile.close();
            }
        }
        void ImpressionsLogger::keyPressed(ofKeyEventArgs& key){
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" keyPressed";
            if(bOpen){
                mFile<<logString;
                mFile<<endl;
                mFile.close();
            }
        }
        void ImpressionsLogger::keyReleased(ofKeyEventArgs& key){
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" keyReleased";
            mKeysPressed++;
            logString.append(" total pressed "+ofToString(mKeysPressed));
            if(bOpen){
                mFile<<logString;
                mFile<<" key pressed == "<<key.key<<endl;
                mFile.close();
            }
        }
        
    }
}