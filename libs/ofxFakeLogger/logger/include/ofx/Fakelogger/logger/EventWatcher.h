#pragma once
class EventWatcher {
public:
	virtual void mousePressed(ofMouseEventArgs& mouse) {}
	virtual void mouseMoved(ofMouseEventArgs& mouse) {}
	virtual void mouseDragged(ofMouseEventArgs& mouse) {}
	virtual void mouseReleased(ofMouseEventArgs& mouse) {}
	virtual void keyPressed(ofKeyEventArgs& key) {}
	virtual void keyReleased(ofKeyEventArgs& key) {}
    bool eventsEnabled = false;
	void enableImpressionsLogging() {
        eventsEnabled = true;
		ofAddListener(ofEvents().keyPressed, this, &EventWatcher::keyPressed);
		ofAddListener(ofEvents().keyReleased, this, &EventWatcher::keyReleased);
		ofAddListener(ofEvents().mousePressed, this, &EventWatcher::mousePressed);
		ofAddListener(ofEvents().mouseReleased, this, &EventWatcher::mouseReleased);
		ofAddListener(ofEvents().mouseMoved, this, &EventWatcher::mouseMoved);
		ofAddListener(ofEvents().mouseDragged, this, &EventWatcher::mouseDragged);
	}
	void disableImpressionsLogging() {
        if(eventsEnabled){
            eventsEnabled = false;
            ofRemoveListener(ofEvents().keyPressed, this, &EventWatcher::keyPressed);
            ofRemoveListener(ofEvents().keyReleased, this, &EventWatcher::keyReleased);
            ofRemoveListener(ofEvents().mousePressed, this, &EventWatcher::mousePressed);
            ofRemoveListener(ofEvents().mouseReleased, this, &EventWatcher::mouseReleased);
            ofRemoveListener(ofEvents().mouseMoved, this, &EventWatcher::mouseMoved);
            ofRemoveListener(ofEvents().mouseDragged, this, &EventWatcher::mouseDragged);
        }
	}
};