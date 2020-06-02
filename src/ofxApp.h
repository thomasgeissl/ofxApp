#pragma once

#include "ofMain.h"

class ofxApp : public ofBaseApp
{
public:
    ofxApp(bool registerUpdateEvent = true, bool quitOnEscape = false)
    {
        ofSetEscapeQuitsApp(quitOnEscape);
        if (registerUpdateEvent)
        {
            ofAddListener(ofEvents().update, this, &ofxApp::onUpdate, OF_EVENT_ORDER_BEFORE_APP);
        }
        _getWindowTitle = [this]() { return _applicationName + "[" + _applicationVersion + "] @" + ofToString((int)(ofGetFrameRate())) + "fps"; };
    }
    void onUpdate(ofEventArgs &e)
    {
        ofSetWindowTitle(_getWindowTitle());
    }

    std::string getApplicationName()
    {
        return _applicationName;
    }
    std::string getApplicationVersion()
    {
        return _applicationVersion;
    }
    std::string getOrganizationName()
    {
        return _organizationName;
    }
    std::string getOrganizationDomain()
    {
        return _organizationDomain;
    }
    void setApplicationName(std::string applicationName)
    {
        _applicationName = applicationName;
    }
    void setApplicationVersion(std::string applicationVersion)
    {
        _applicationVersion = applicationVersion;
    }
    void setApplicationVersion(int major, int minor, int patch)
    {
        setApplicationVersion(ofToString(major) + "." + ofToString(minor) + "." + ofToString(patch));
    }
    void setOrganizationName(std::string organizationName)
    {
        _organizationName = organizationName;
    }
    void setOrganizationDomain(std::string organizationDomain)
    {
        _organizationDomain = organizationDomain;
    }
    void setGetWindowTitle(std::function<std::string()> fun)
    {
        _getWindowTitle = fun;
    }
    std::string _applicationName;
    std::string _applicationVersion;
    std::string _organizationName;
    std::string _organizationDomain;

    std::function<std::string()> _getWindowTitle;
};