#pragma once

#include "ofLog.h"
#include "ofFileUtils.h"

namespace ofx{
    namespace FakeLogger{
        
        class Logger : public ofBaseLoggerChannel {
            
            Logger();
            Logger(const string & path, bool append);
            virtual ~Logger();
            
            void setFile(const string & path,bool append=false);
            
            void log(ofLogLevel level, const string & module, const string & message);
            void log(ofLogLevel level, const string & module, const char* format, ...);
            void log(ofLogLevel level, const string & module, const char* format, va_list args);
            
            void close();
            
            void log();
            
        private:
            ofFile file;
        };
    }
}