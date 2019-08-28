/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::~ofApp(){
	ClearDmxData();
	SendDmx();
}

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("test:Artnet");
	
	ofSetWindowShape(500, 500);
	/*
	ofSetVerticalSync(false);
	ofSetFrameRate(0);
	/*/
	ofSetVerticalSync(true);
	ofSetFrameRate(fps);
	//*/
	
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	ofColor initColor = ofColor(0, 0, 0, 255);
	ofColor minColor = ofColor(0, 0, 0, 0);
	ofColor maxColor = ofColor(255, 255, 255, 255);
	
	/**/
	gui.setup();
	gui.add(Gui_LightId.setup("id", 0, 0, 10));
	gui.add(GuiColor.setup("color", initColor, minColor, maxColor));

	/********************
	********************/
	ClearDmxData();
	artnet.setup("10.7.206.7"); // Target IP.
	
#ifdef ARTNET_THREADED
	artnet.enableThread(fps);	// main windowと同じにしておくのが安全かな.
#endif
}

/******************************
******************************/
void ofApp::ClearDmxData(){
	for(int i = 0; i < DMX_SIZE; i++){
		DmxData[i] = 0;
	}
}

/******************************
******************************/
void ofApp::update(){
	ClearDmxData();
	
	enum{
		NUM_CHS_1LIGHT = 6,
	};
	ofColor color = GuiColor;
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 0] = 255;	// dimmer
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 1] = color.r;
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 2] = color.g;
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 3] = color.b;
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 4] = 0;		// white
	DmxData[NUM_CHS_1LIGHT * (int)Gui_LightId + 5] = 1;		// Strobe : open
	
	SendDmx();
}

/******************************
******************************/
void ofApp::SendDmx(){
	ofxArtnetMessage message;
	message.setData(DmxData, DMX_SIZE);
	artnet.sendArtnet(message);
}

/******************************
******************************/
void ofApp::draw(){
	ofBackground(20);
	gui.draw();
}

/******************************
******************************/
void ofApp::keyPressed(int key){

}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
