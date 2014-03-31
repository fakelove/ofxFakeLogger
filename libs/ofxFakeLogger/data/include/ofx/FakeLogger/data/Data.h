#pragma once

#include "ofLog.h"
#include "ofFileUtils.h"

namespace ofx{
    namespace FakeLogger{
        
        class DataLogger {
        public:
            DataLogger();
            DataLogger(const string & path, bool append);
            virtual ~DataLogger();
            
            void setFile(const string & path,bool append=false);
            
            void close();

            
        private:
            ofFile file;
        };
    }
}