//
//  particle.cpp
//  VectorField3
//
//  Created by 堀内隆仁 on 2018/04/27.
//

#include "particle.hpp"

void Particle::setP(ofVec2f _p){
    p.set(_p);
}


void Particle::update(ofVec2f _v){
    
    //ofApp内でaをsetしたのち、以下
    //point[0] = p;
    
    //a -= v * 0.03;//friction
    //v = v + a;
    v = _v;
    p = p + v;
    
    //point[1] = p;
    
}

void Particle::draw(){
    //ofSetLineWidth(3);
    //ofColor c;
    //float hue = ofMap(v.length(), 0, 3*PI, 0, 360);
    //c.setHueAngle(330);
    
    c1 = ofMap(v.x, 0, 3*PI, 100, 255);
    c2 = ofMap(v.y, 0, 3*PI, 100, 255);
    ofSetColor(125, c1, c2, 50);
    //c.setHsb(hue, 255, 255);
    //ofSetColor(c);
    ofDrawCircle(p, radius);
    //ofDrawLine(point[0], point[1]);
}
