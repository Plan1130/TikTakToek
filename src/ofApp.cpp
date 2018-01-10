#include "ofApp.h"

#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "MinMaxPlayer.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    // init random generator
    std::srand((unsigned int)std::time(0));
    
    // init players
    Player *p1 = new HumanPlayer("Alice");
    Player *p2 = new MinMaxPlayer("Bob");
    
    // init game
    game_ = new Game(p1, p2);
    
    // init game view
    game_view_ = new GameView(*game_, 0, 0, ofGetWidth(), ofGetHeight());
    
    // try to do all possible moves
    game_->doPossibleMoves();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw game view
    game_view_->draw();
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
    // trigger game view mouse actions
    game_view_->mouseReleased(x, y, button);
    
    // try to do all possible moves
    game_->doPossibleMoves();
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    // resize game view
    game_view_->resize(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
