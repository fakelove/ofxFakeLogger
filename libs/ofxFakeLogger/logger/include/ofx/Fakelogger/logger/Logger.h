#pragma once
#include "ofMain.h"
#include "ofx/FakeLogger/status/status.h"
#include "ofx/FakeLogger/logger/EventWatcher.h"
#include "ofx/FakeLogger/impressions/Impressions.h"
namespace ofx{
    namespace FakeLogger{
        
        class Logger : public ofBaseLoggerChannel{
            
        public:
            Logger();
            Logger(const string & path, bool append);
            virtual ~Logger();
            
            void setFile(const string & path,bool append=false);
            
            void log(ofLogLevel level, const string & module, const string & message);
            void log(ofLogLevel level, const string & module, const char* format, ...);
            void log(ofLogLevel level, const string & module, const char* format, va_list args);
            void close();
            void log();
            void logScreen();
            void logStatus();
            void logImpressions(bool touch);
        private:
            ofFile mFile;
            string mPath;
            bool bAppend;
            bool bVerbos;
            bool bError;
            bool bWarning;
            bool bNotice;
            bool bOpen;
            ofPtr<StatusLogger> mStatus;
            ofPtr<ImpressionsLogger> mImpressions;
        };
    }
}