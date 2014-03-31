#pragma once

#include "ofMain.h"

namespace ofx{
    namespace FakeLogger{
        
        class StatusLogger{
           public:
            StatusLogger();
            StatusLogger(const string & path, bool append);
            virtual ~StatusLogger();
            
            void setFile(const string & path,bool append=false);
            
            void close();
            
            void log();

        private:
            ofFile mFile;
            string mPath;
            bool bAppend;
            bool bOpen;
            unsigned long long mStartTime;
            unsigned long long mCurrentTime;
            double mFrameRate;
        };
    }
}