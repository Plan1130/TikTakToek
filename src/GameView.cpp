//
//  GameView.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "GameView.hpp"

#include "HumanPlayer.hpp"

#define DEFAULT_FONT "manteka.ttf"
#define DEFAULT_FONT_SIZE 64

#define LINE_WIDTH 10
#define HALF_LINE_WIDTH LINE_WIDTH / 2

#define BOARD_SIZE_FACTOR 0.8
#define STATUS_TEXT_FONT_SIZE_FACTOR 0.4
#define FIELD_CONTENT_SIZE_FACTOR 0.8

GameView::GameView(Game& game, int x, int y, int width, int height) : game_(game) {
    // load font
    font_.load(DEFAULT_FONT, DEFAULT_FONT_SIZE);
    
    // set initial dimensions
    resize(x, y, width, height);
}

void GameView::draw() {
    ofBackground(ofColor::white);
    
    // draw board
    drawBoard(x_ + border_width_, y_ + border_height_, width_ - 2 * border_width_, height_ - 2 * border_height_);
    
    // draw status text
    drawStatusText(x_ + border_width_, y_ + height_ - status_text_offset_, font_size_);
}

void GameView::resize(int x, int y, int width, int height) {
    // set new dimensions
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
    
    // calculate new dimensions of some compontents
    board_size_ = std::min(width_, height_) * BOARD_SIZE_FACTOR;
    
    border_width_ = (width_ - board_size_) / 2;
    border_height_ = (height_ - board_size_) / 2;
    
    field_size_ = board_size_ / GRID_SIZE;
    
    font_size_ = border_height_ * STATUS_TEXT_FONT_SIZE_FACTOR;
    status_text_offset_ = (border_height_ - font_size_) / 2;
}

void GameView::mouseReleased(int x, int y, int button) {
    // reset game if it is finished
    if(game_.isFinished()) {
        game_.reset();
        return;
    }
    
    // check if current player is human
    Player *current_player = game_.getCurrentPlayer();
    if(current_player->getType() == PlayerType::Human) {
        HumanPlayer *human_player = (HumanPlayer *)current_player;
        
        // calculate position on board from mouse position
        char const xi = (x - border_width_) / field_size_;
        char const yi = (y - border_height_) / field_size_;
        
        // check if calculated position is valid
        if(xi >= 0 && xi < GRID_SIZE && yi >= 0 && yi < GRID_SIZE
           && game_.getBoard().getField(xi, yi) == Field::Empty) {
            // give move to player
            human_player->setMove(Position(xi, yi));
        }
    }
}

void GameView::drawBoard(int x, int y, int width, int height) {
    ofSetColor(ofColor::black);
    
    // draw inner lines
    for(int xi = 0; xi < GRID_SIZE - 1; xi++) {
        int const line_x = x + (xi + 1) * field_size_;
        ofDrawLine(line_x, y, line_x, y + height);
    }
    for(int yi = 0; yi < GRID_SIZE - 1; yi++) {
        int const line_y = y + (yi + 1) * field_size_;
        ofDrawLine(x, line_y, x + width, line_y);
    }
    
    // draw border lines
    ofSetLineWidth(LINE_WIDTH);
    
    ofDrawLine(x - HALF_LINE_WIDTH, y, x + width + HALF_LINE_WIDTH, y);
    ofDrawLine(x, y - HALF_LINE_WIDTH, x, y + height + HALF_LINE_WIDTH);
    ofDrawLine(x - HALF_LINE_WIDTH, y + height, x + width + HALF_LINE_WIDTH, y + height);
    ofDrawLine(x + width, y - HALF_LINE_WIDTH, x + width, y + height + HALF_LINE_WIDTH);
    
    // draw field content
    int const field_content_size = (int)(field_size_ * FIELD_CONTENT_SIZE_FACTOR);
    
    for(int yi = 0; yi < GRID_SIZE; yi++) {
        for(int xi = 0; xi < GRID_SIZE; xi++) {
            int const field_content_x = x + xi * field_size_ + (field_size_ - field_content_size) / 2;
            int const field_content_y = y + yi * field_size_ + (field_size_ - field_content_size) / 2;
            drawFieldContent(game_.getBoard().getField(xi, yi), field_content_x, field_content_y, field_content_size, field_content_size);
        }
    }
}

void GameView::drawFieldContent(Field field, int x, int y, int width, int height) {
    ofSetColor(ofColor::black);
    
    switch(field) {
        case Field::X:
            // draw X
            ofSetLineWidth(LINE_WIDTH);
            ofDrawLine(x, y, x + width, y + height);
            ofDrawLine(x, y + height, x + width, y);
            break;
        case Field::O:
            // draw O
            ofSetCircleResolution(100);
            ofDrawEllipse(x + width / 2, y + height / 2, width, height);
            ofSetColor(255);
            ofDrawEllipse(x + width / 2, y + height / 2, width - 2 * LINE_WIDTH, height - 2 * LINE_WIDTH);
            break;
        case Field::Empty: default:
            // draw nothing
            break;
    }
}

void GameView::drawStatusText(int x, int y, int font_size) {
    ofSetColor(ofColor::black);
    
    std::string status_text;
    
    if(!game_.isFinished()) {
        // game is ongoing, so display the current players name
        status_text = "it's " + game_.getCurrentPlayer()->getName() + "'s turn.";
    } else {
        // game is finished, so check for a winner
        bool has_winner = false;
        for(Player *player : game_.getPlayers()) {
            if(game_.isWinner(player)) {
                // player has won, so display winning message
                status_text = "the winner is " + player->getName() + "!";
                has_winner = true;
                break;
            }
        }
        
        // no winners, so display message for a draw
        if(!has_winner) {
            status_text = "it's a draw!";
        }
    }
    
    // draw text
    drawText(status_text, x, y, font_size);
}

void GameView::drawText(std::string text, int x, int y, int font_size) {
    ofPushMatrix();
    {
        ofTranslate(x, y);
        
        // rescales the font to a given font_size
        double const scale = font_size / font_.stringHeight(text);
        ofScale(scale, scale, 1);
        
        font_.drawString(text, 0, 0);
    }
    ofPopMatrix();
}
