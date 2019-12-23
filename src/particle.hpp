//
//  particle.hpp
//  VectorField3
//
//  Created by 堀内隆仁 on 2018/04/27.
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "vectorField.hpp"

class Particle{
public:
    //---------property--------
    float radius = 1;
    ofVec2f p;
    ofVec2f v;
    int c1, c2;
    ofColor c;
    float hue = 330;
    float saturation = 255;
    float brightness = 255;
    
    ofVec2f point[2];
    
    //---------method--------
    //p setter
    void setP(ofVec2f _p);
    void setV(ofVec2f _v);
    void update(ofVec2f _v);
    void draw();
    
};

#endif /* particle_hpp */
