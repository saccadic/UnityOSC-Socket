#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(LISTEN_PORT);
	sender.setup(HOST, REMOTE_PORT);

	ofLogToConsole();
}

//--------------------------------------------------------------
void ofApp::update(){
	while (receiver.hasWaitingMessages()) {

		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		string adress = m.getAddress();
		unsigned int index = 0;
		int value_0 = m.getArgAsInt(index++);
		int64_t value_1 = m.getArgAsInt64(index++);
		float value_2 = m.getArgAsFloat(index++);
		string value_3 = m.getArgAsString(index++);
		ofBuffer value_4 = m.getArgAsBlob(index++);

		char* binary = value_4.getData();
		string value_4_str = string(binary);
	
		ofLog() << "----------";
		ofLog() << "adress  : " << adress;
		ofLog() << "value_0 : " << value_0;
		ofLog() << "value_1 : " << value_1;
		ofLog() << "value_2 : " << value_2;
		ofLog() << "value_3 : " << value_3;
		ofLog() << "value_4 : " << value_4_str;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//Debug.Log(soket.Address);
//Debug.Log(msg.path);
//Debug.Log((int)msg.data[0]);
//Debug.Log((long)msg.data[1]);
//Debug.Log((float)msg.data[2]);
//Debug.Log((string)msg.data[3]);
//Debug.Log((byte[])msg.data[4]);

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofxOscMessage m;
	m.setAddress("/of");
	m.addIntArg(1);
	m.addInt64Arg(ofGetFrameNum());
	m.addFloatArg(9.9f);
	m.addStringArg(ofGetTimestampString());

	ofBuffer buf;
	buf.allocate(256);
	string str = "Hoge_hoge";
	str2char(buf.getData(), str);
	m.addBlobArg(buf);

	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
