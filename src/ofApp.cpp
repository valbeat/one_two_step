#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC0_ALPHA, GL_ONE);
    
    //カメラの設定
    camWidth = 1920 / 4;
    camHeight = 1080 / 4;
    camera.setVerbose(true);
    camera.setDeviceID(0);
    camera.initGrabber(camWidth, camHeight);
    //OpenCVで解析する画像の領域を確保
    colorImg.allocate(camWidth, camHeight);
    grayImg.allocate(camWidth, camHeight);
    grayBg.allocate(camWidth, camHeight);
    grayDiff.allocate(camWidth, camHeight);
    bgFlag = true;
    threshold = 100;
}

//--------------------------------------------------------------
void ofApp::update(){
    bool newFrameFlag = false;
    camera.update();
    newFrameFlag = camera.isFrameNew();
    if (newFrameFlag) {
        colorImg.setFromPixels(camera.getPixels(), camWidth, camHeight);
        grayImg = colorImg;
        
        if (bgFlag) {
            grayBg = grayImg;
            bgFlag = false;
        }
        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);
        contourFinder.findContours(grayDiff, 20, (camWidth*camHeight)/3, 10, true);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(0xffffff);
    colorImg.draw(0,0);
    grayImg.draw(camWidth + 10, 0);
    grayBg.draw(0, camHeight + 10);
    grayDiff.draw(camWidth + 10, camHeight + 10);
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(camWidth,camHeight);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case ' ':
            bgFlag = true;
            break;
        case '+':
            threshold ++;
            if (threshold > 255) threshold = 255;
            break;
        case '-':
            threshold --;
            if (threshold < 0) threshold = 0;
            break;
        case 'f':
            ofToggleFullscreen();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
