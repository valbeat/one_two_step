#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC0_ALPHA, GL_ONE);
    
    //カメラの設定
    camWidth = 1920;
    camHeight = 1080;
    camera.setVerbose(true);
    camera.setDeviceID(0);
    camera.initGrabber(camWidth, camHeight);
    //OpenCVで解析する画像の領域を確保
    colorImg.allocate(camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::update(){
    bool newFrameFlag = false;
    camera.update();
    newFrameFlag = camera.isFrameNew();
    if (newFrameFlag) {
        colorImg.setFromPixels(camera.getPixels(), camWidth, camHeight);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0xffffff);
    camera.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
