#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"


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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofVideoGrabber camera; //ビデオ入力
    int camWidth;
    int camHeight;
    
<<<<<<< HEAD
    ofxCvColorImage colorImg; //OpenCVで扱うカラー画像
    ofxCvGrayscaleImage grayImg; //OpenCVで扱うグレースケール画像
    ofxCvGrayscaleImage grayBg; //背景のグレースケール画像
    ofxCvGrayscaleImage grayDiff; //背景との差分
    ofxCvContourFinder contourFinder; //輪郭抽出
    
    bool bgFlag;
    int threshold;
=======
    ofxCvColorImage colorImg; //OpenCVで扱う画像
>>>>>>> 16fab5e67ee6911a161c47298e7a70736ee883b7
};
