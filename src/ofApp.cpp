#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetFrameRate(30);
    ofSetBackgroundColor(0);
    //ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetLineWidth(2);
    
    
    //--------ptcset---------
    for(int i=0; i<PTC_NUM; i++){
        ptc[i].setP(ofVec2f(ofRandom(0, W), ofRandom(0, H)));
    }
   
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //--------vFset---------
    
    //xnoise = ofRandom(20);
    xnoise = 0;
    for(int i=0; i<w; i++){
        ynoise = 0;
        for(int j=0; j<h; j++){
            vF[i*h+j].setP(ofVec2f(i*d,j*d));
            
            noise = ofNoise(xnoise, ynoise, time);
            theta = ofMap(noise,0,1,0,TWO_PI);
            vF[i*h+j].setV(ofVec2f(cos(theta), sin(theta))*3*theta);
            //vF[i*h+j].setV(ofVec2f(cos(theta), sin(theta))*5*sin(time*(i+j))); で、なびくカーテンの表現が生まれる！！

            ynoise += step;
        }
        xnoise += step;
        
    }
    time += 0.01;
    
    //-----particleとvFの関係------
    for(int k=0; k<PTC_NUM; k++){
        int trueX, trueY;
        //最近傍のグリッドX値をサーチ
        for(int i=0; i<w; i++){
            if(abs(ptc[k].p.x - vF[i*h+0].p.x) < d/2){
                trueX = i;
                break;
            }
        }
        //最近傍のグリッドY値をサーチ
        for(int j=0; j<h; j++){
            if(abs(ptc[k].p.y - vF[0*h+j].p.y) < d/2){
                trueY = j;
                break;
            }
        }
        
        //該当位置のX,Yグリッドから速度をセット
        ptc[k].update(vF[trueX * h + trueY].v);
    }
    
    //------particleの画面境界処理------
    for(int k=0; k<PTC_NUM; k++){
        //particle画面の境界
        if(ptc[k].p.x - d < 0){
            ptc[k].p.x = ofRandom(0, ofGetWidth());
        }else if(ptc[k].p.x + d > ofGetWidth()){
            ptc[k].p.x = ofRandom(0, ofGetWidth());
        }
        if(ptc[k].p.y - d < 0){
            ptc[k].p.y = ofRandom(0, ofGetHeight());
        }else if(ptc[k].p.y + d > ofGetHeight()){
            ptc[k].p.y = ofRandom(0, ofGetHeight());
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    //背景更新（モーションブラー）
    ofSetColor(255, 100);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    //vF
    if(vfView){
        for(int i=0; i<w; i++){
            for(int j=0; j<h; j++){
                vF[i*h+j].draw();
            }
        }
    }
    
    //ptc
    for(int k=0; k<PTC_NUM; k++){
        ptc[k].draw();
    }
    
    //refference
    ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case'x':
            scrShot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
            scrShot.save("VectorField3" + ofGetTimestampString() +".png");
            break;
        case'v'://vectorField view
            if(vfView == false)vfView = true;
            else{vfView = false;}
            break;
            
    }
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
