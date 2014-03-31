#include "ofx/FakeLogger/logger/Logger.h"
namespace ofx{
    namespace FakeLogger{
        
        Logger::Logger(){
            setFile(ofToDataPath(ofGetTimestampString()+".log"), true);
        }
        
        Logger::Logger(const string & path, bool append){
            setFile(path+".log", append);
        }
        
        Logger::~Logger(){
            
        }
        
        void Logger::setFile(const string &path, bool append){
            mPath = path;
            bAppend = append;
            mStatus = ofPtr<StatusLogger>(new StatusLogger(path, true));
            mImpressions = ofPtr<ImpressionsLogger>(new ImpressionsLogger(path, true));
            
            
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            mFile.close();
        }
        
        void Logger::log(ofLogLevel level, const string & module, const string & message){
            string logString = ofGetTimestampString("%H:%M:%S:%i %m-%d-%Y")+" ";
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            if(bOpen){
                switch (level) {
                    case OF_LOG_VERBOSE:
                        if(bVerbos){
                            logString.append(module);
                            logString.append(" ");
                            logString.append(message);
                            mFile<<logString;
                            mFile<<endl;
                        }
                        break;
                    case OF_LOG_NOTICE:
                        if(bNotice){
                            logString.append(module);
                            logString.append(" ");
                            logString.append(message);
                            mFile<<logString;
                            mFile<<endl;
                        }
                        break;
                    case OF_LOG_WARNING:
                        if(bWarning){
                            logString.append(module);
                            logString.append(" ");
                            logString.append(message);
                            mFile<<logString;
                            mFile<<endl;
                        }
                        break;
                    case OF_LOG_ERROR:
                        if(bError){
                            logString.append(module);
                            logString.append(" ");
                            logString.append(message);
                            mFile<<logString;
                            mFile<<endl;
                        }
                        break;
                    case OF_LOG_FATAL_ERROR:
                        if(bError){
                            logString.append(module);
                            logString.append(" ");
                            logString.append(message);
                            mFile<<logString;
                            mFile<<endl;
                        }
                        break;
                    default:
                        logString.append(module);
                        logString.append(" ");
                        logString.append(message);
                        mFile<<logString;
                        mFile<<endl;
                        break;
                }
                mFile.close();
            }
            
        }
        
        void Logger::log(ofLogLevel level, const string & module, const char* format, ...){
            va_list args;
            va_start( args, format );
            log(level,module,format,args);
            va_end( args );
        }
        
        void Logger::log(ofLogLevel level, const string & module, const char* format, va_list args){
            bOpen = mFile.open(mPath, bAppend?ofFile::Append:ofFile::WriteOnly, false);
            if(bOpen){
                mFile<<ofGetTimestampString("%H:%M:%S:%i %M-%d-%Y")<<" "<< "[" << ofGetLogLevelName(level, true) << "] ";
                if(module != ""){
                    mFile << module << ": ";
                }
                mFile << ofVAArgsToString(format,args) << endl;
                mFile.close();
            }
        }
        
        void Logger::close(){
            if(bOpen){
                mFile.close();
            }
        }
        void Logger::logImpressions(bool touch){
            if(touch){
                mImpressions->enableImpressionsLogging();
            }else{
                mImpressions->disableImpressionsLogging();
            }
        }
        void Logger::logScreen(){
            ofSaveScreen(ofGetTimestampString()+".png");
        }
        
        void Logger::logStatus(){
            mStatus->log();
        }
    }
}