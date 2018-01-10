//
//  GameView.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef GameView_hpp
#define GameView_hpp

#include "Game.hpp"
#include "ofMain.h"

class GameView {
public:
    // constructs a game
    GameView(Game& game, int x, int y, int width, int height);
    
    // draws the game (board and status text)
    void draw();
    
    // resizes the dimensions of the view
    void resize(int, int, int, int);
    // triggers game actions based on mouse click
    void mouseReleased(int, int, int);
    
private:
    // draws the board
    void drawBoard(int x, int y, int width, int height);
    // draws the contents of a field
    void drawFieldContent(Field, int x, int y, int width, int height);
    // draws the status text below the field (note: text will render outside of view if resized inresponsibly)
    void drawStatusText(int x, int y, int font_size);
    // draws text
    void drawText(std::string text, int x, int y, int font_size);
    
    // the game corrensponding to this game view
    Game& game_;
    
    // font used to render text in the game view
    ofTrueTypeFont font_;
    
    // dimensions of the game view
    int x_ = 0, y_ = 0;
    int width_ = 1, height_ = 1;
    
    // some variables to store current dimensions of some components
    int border_width_, border_height_;
    int board_size_, field_size_;
    int font_size_;
    int status_text_offset_;
};

#endif /* GameView_hpp */
