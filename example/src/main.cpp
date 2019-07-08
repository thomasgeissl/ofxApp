#include "ofMain.h"
#include "ofxApp.h"

class ofApp : public ofxApp{
    public:
    ofApp(){
        setApplicationName("demo app");
        setApplicationVersion(1, 0, 0);
        // setApplicationVersion("1.0.0");
    }

};

int main(){
	ofSetupOpenGL(1024, 768, OF_WINDOW);
	ofRunApp(new ofApp());
}