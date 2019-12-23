#pragma once

#include "ofMain.h"
#include "vectorField.hpp"
#include "particle.hpp"


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
    
    
    //マクロ的な定義．
    static const int W = 2800;//Width of window
    static const int H = 1800;//Height of window
    static const int d = 40;//unit of grids
    //dを80とかにすると、particleの振る舞いがカーテンになる。
    static const int w = W/d;//grid num x
    static const int h = H/d;//grid num y
    //各スイッチ
    bool vfView = false;

    //------------vectorField-------------
    //instance
    vectorField vF[w*h];
    //noise
    float xnoise;
    float ynoise;
    float time = ofRandom(10);
    float noise;
    float theta;
    float step = 0.02;
    
    //------------particle----------------
    ofVboMesh mesh;
    static const int PTC_NUM = 80000;
    Particle ptc[PTC_NUM];
    
    //scholor field
    float scholor;
    
    //screen shot
    ofImage scrShot;
    
    
    
    
};
