#include "ofMain.h"
#include "ofxApp.h"

class ofApp : public ofxApp
{
public:
    ofApp()
        // set window title automatically and dont quite on esc, these are the defaults
        : ofxApp(true, false)
    {
        setApplicationName("demo app");
        // set a custom getter for the window title
        setGetWindowTitle([this]() { return getApplicationName() + " v" + getApplicationVersion(); });
        setApplicationVersion(1, 0, 0);
        // setApplicationVersion("1.0.0");
    }
};

int main()
{
    ofSetupOpenGL(1024, 768, OF_WINDOW);
    ofRunApp(new ofApp());
}