#pragma once

#include "ofLog.h"
#include "ofFileUtils.h"

namespace ofx{
    namespace FakeLogger{
        
        class HttpLogger {
        public:
            HttpLogger();
            HttpLogger(const string & path, bool append);
            virtual ~HttpLogger();
            
            void setFile(const string & path,bool append=false);
            
            void logResponse(string url, int status);
            
            void close();
            
            void log();
            
        private:
            ofFile file;
        };
    }
}