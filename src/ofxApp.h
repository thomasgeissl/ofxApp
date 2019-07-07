#pragma once

#include "ofMain.h"

class ofxApp : public ofBaseApp{
public:
    ofxApp(){
        ofSetEscapeQuitsApp(false);
		ofAddListener(ofEvents().update, this, &ofxApp::onUpdate, OF_EVENT_ORDER_BEFORE_APP);
    }
    void onUpdate(ofEventArgs &e){
        ofSetWindowTitle(_applicationName +"["+_applicationVersion+"] @"+ofToString((int)(ofGetFrameRate()))+"fps");
    }

    std::string getApplicationName(){
        return _applicationName;
    }
    std::string getApplicationVersion(){
        return _applicationVersion;
    }
    std::string getOrganizationName(){
        return _organizationName;
    }
    std::string getOrganizationDomain(){
        return _organizationDomain;
    }
    void setApplicationName(std::string applicationName){
        _applicationName = applicationName;
    }
    void setApplicationVersion(std::string applicationVersion){
        _applicationVersion = applicationVersion;
    }
    void setApplicationVersion(int major, int minor, int patch){
        setApplicationVersion(ofToString(major)+"."+ofToString(minor)+"."+ofToString(patch));
    }
    void setOrganizationName(std::string organizationName){
        _organizationName = organizationName;
    }
    void setOrganizationDomain(std::string organizationDomain){
        _organizationDomain = organizationDomain;
    }
    std::string _applicationName;
    std::string _applicationVersion;
    std::string _organizationName;
    std::string _organizationDomain;
};