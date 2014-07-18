#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofEnableSmoothing();
    //画面の混色の設定を加算合成にする
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC0_ALPHA, GL_ONE);
    
    //カメラの設定
<<<<<<< HEAD
    camWidth = 1920 / 4;
    camHeight = 1080 / 4;
=======
    camWidth = 1920;
    camHeight = 1080;
>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
    camera.setVerbose(true);
    camera.setDeviceID(0);
    camera.initGrabber(camWidth, camHeight);
    //OpenCVで解析する画像の領域を確保
    colorImg.allocate(camWidth, camHeight);
<<<<<<< HEAD
    grayImg.allocate(camWidth, camHeight);
    grayBg.allocate(camWidth, camHeight);
    grayDiff.allocate(camWidth, camHeight);
    bgFlag = true;
    threshold = 100;
=======
>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
}

//--------------------------------------------------------------
void ofApp::update(){
    bool newFrameFlag = false;
    camera.update();
    newFrameFlag = camera.isFrameNew();
    if (newFrameFlag) {
        colorImg.setFromPixels(camera.getPixels(), camWidth, camHeight);
<<<<<<< HEAD
        grayImg = colorImg;
        
        if (bgFlag) {
            grayBg = grayImg;
            bgFlag = false;
        }
        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);
        contourFinder.findContours(grayDiff, 20, (camWidth*camHeight)/3, 10, true);
=======
>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
<<<<<<< HEAD
    ofNoFill();
    ofSetColor(0xffffff);
    colorImg.draw(0,0);
    grayImg.draw(camWidth + 10, 0);
    grayBg.draw(0, camHeight + 10);
    grayDiff.draw(camWidth + 10, camHeight + 10);
    for (int i = 0; i < contourFinder.nBlobs; i++) {
        contourFinder.blobs[i].draw(camWidth,camHeight);
    }
=======
    ofSetColor(0xffffff);
    camera.draw(0,0);
>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
<<<<<<< HEAD
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
=======

>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
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
