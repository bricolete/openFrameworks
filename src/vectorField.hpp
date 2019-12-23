//
//  vectorField.hpp
//  VectorField3
//
//  Created by 堀内隆仁 on 2018/04/20.
//

#ifndef vectorField_hpp
#define vectorField_hpp

#include <stdio.h>
#include "ofMain.h"

class vectorField : public ofBaseApp{
public:
    //--------property---------
    //property of each grid
    ofVec2f p;//pos
    ofVec2f flow;//position power
    ofVec2f attraction;//mouse power
    ofVec2f v;//flow + mouse
    float dist;//mouse-p
    
    ofVec2f mouseP;
    ofVec2f centerP = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    
    
    //---------method----------
    //vectorField(ofVec2f _p);//constractor
    //virtual ~vectorField();
    //vectorField();//constractor
    void update();
    void draw();
    
    void setP(ofVec2f _p);//setter of p
    void setV(ofVec2f _v);//setter of v
   
    
};


#endif /* vectorField_hpp */
