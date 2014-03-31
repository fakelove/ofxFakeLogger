#pragma once

#include "ofMain.h"
#include "ofx/FakeLogger/logger/EventWatcher.h"

namespace ofx{
    namespace FakeLogger{
        
        class ImpressionsLogger : public EventWatcher{
        public:
            ImpressionsLogger();
            ImpressionsLogger(const string & path, bool append);
            virtual ~ImpressionsLogger();
            void setFile(const string & path,bool append=false);
            void log();
            
            
            void mousePressed(ofMouseEventArgs& mouse);
            void mouseMoved(ofMouseEventArgs& mouse);
            void mouseDragged(ofMouseEventArgs& mouse);
            void mouseReleased(ofMouseEventArgs& mouse);
            void keyPressed(ofKeyEventArgs& key);
            void keyReleased(ofKeyEventArgs& key);
        private:
            ofFile mFile;
            string mPath;
            bool bAppend;
            bool bOpen;
            unsigned long long mNumClicks;
            unsigned long long mKeysPressed;
            
        };
    }
}