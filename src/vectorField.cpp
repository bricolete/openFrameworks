//
//  vectorField.cpp
//  VectorField3
//
//  Created by 堀内隆仁 on 2018/04/20.
//

#include "vectorField.hpp"
//-----------------------コンストラクタ--------------------------------------------------
//＊超重要：引数ありのコンストラクタを定義した場合は、引数なしのデフォルトコンストラクタも定義しなくてはならない！！！　自動的に継承する親クラスのデフォルトコンストラクタも同時に呼ばれることに注意。
/*
vectorField::vectorField(ofVec2f _p){
    //p.set(p);
    //#//pのみコンストラクタで指定．pは不変だからこそコンストラクタでok.．
    
}
 */
//-----------------------更新----------------------------------------------------------
void vectorField::update(){
    
     //------attraction
    /*
     mouseP.set(ofGetMouseX(), ofGetMouseY());//mouse position
     dist = p.distance(mouseP);
     if(dist < 1000){
         attraction.set((mouseP - p)* 1/pow(dist, 2));
     }else{
         attraction.set(ofVec2f(0,0));
     }
    
     //------vはattractionが足される
    v+=attraction;
    */
}
//-----------------------描画----------------------------------------------------------
void vectorField::draw(){
    
    ofSetColor(80,80,80,100);
    ofDrawLine(p - v, p + v);
    //ofDrawCircle(p + 10*a, 3);
    //ofDrawLine(p - 100, p + 100);
}

//-----------------------セッター-----------------------
void vectorField::setP(ofVec2f _p){
    p.set(_p);
}
void vectorField::setV(ofVec2f _v){
    v.set(_v);
}

//-----------------------デストラクタ-----------------------
//vectorField::~vectorField(){
    
//}
