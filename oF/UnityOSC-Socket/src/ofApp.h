#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// IP Adress
#define HOST "127.0.0.1"

// listening port
#define LISTEN_PORT 8080

// Remote port
#define REMOTE_PORT 8081

// Utility
#define ARRAYSIZE(_ARR) ((int)(sizeof(_ARR)/sizeof(*_ARR)))  

inline void str2char(char* dst, const std::string& src) {
	int size = src.length();
	strncpy(dst, src.c_str(), size);
	*(dst + size) = '\0';
}

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		//For send message
		ofxOscSender sender;

		//For recive message
		ofxOscReceiver receiver;
};
