/************************************************************
■概要
	ofxArtnetが "comletely different" なモノとして更新されていたのでtest
		https://github.com/hiroyuki/ofxArtnet
	
■細かい設定
	subnet, universe Idは、ofxArtnetMessage::setUniverse() からsetできる
	その他、Addonのsource codeを読めば色々わかる : 難しくないので読んでみること.

■Ch設定
	soft		: 0-5	/ 6-11	/ 12-17
	HardOffset	: 1		/ 7		/ 13
	
■dependency
	ofxNetwork 

■メモ
	・	Firewallをoffにしなくても動作した(old versionはoffにする必要があった)
************************************************************/
#pragma once

#define ARTNET_THREADED

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxArtnet.h"
#include "ofxGui.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
		const double fps = 60.0;
		
		ofxArtnetSender artnet;
		
		enum{
			DMX_SIZE = 512,
		};
		unsigned char DmxData[DMX_SIZE];
		
		ofxPanel gui;
		ofxIntSlider Gui_LightId;
		ofxColorSlider GuiColor;
		
		void ClearDmxData();
		void SendDmx();

	public:
		~ofApp();
		
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
};
