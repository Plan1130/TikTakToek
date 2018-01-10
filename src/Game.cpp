//
//  Game.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "Game.hpp"

#include <stdexcept>

Game::Game(Player *p1, Player *p2) : players_{p1, p2} {
    assert(p1 != p2);
}

void Game::reset() {
    // reset board
    board_.reset();
    
    // set starting symbol
    current_field_ = Field::X;
}

Board& Game::getBoard() {
    return board_;
}

std::vector<Player *> Game::getPlayers() const {
    return players_;
}

Player *Game::getCurrentPlayer() const {
    return getPlayerForField(current_field_);
}

void Game::doPossibleMoves() {
    // do moves until there are no moves available
    while(tryDoMove());
}

bool Game::tryDoMove() {
    // return if game already finished
    if(isFinished()) {
        return false;
    }
    
    // gets move for current player
    Position move = getCurrentPlayer()->getNextMove(board_, current_field_);
    
    // return if move is not valid
    if(!move.isValid()) {
        return false;
    }
    
    // execute move on board
    board_.doMove(move, current_field_);
    
    // move to next player
    current_field_ = ~current_field_;
    
    return true;
}

bool Game::isFinished() const {
    return board_.isWinner(Field::X) || board_.isWinner(Field::O) || board_.isFull();
}

bool Game::isWinner(Player *player) const {
    return board_.isWinner(getFieldForPlayer(player));
}

Player *Game::getPlayerForField(Field field) const {
    assert(field != Field::Empty);
    
    // return player belonging to a symbol
    return players_[(int)field];
}

Field Game::getFieldForPlayer(Player *player) const {
    // returns the symbol belonging to the player
    if(getPlayerForField(Field::X) == player) {
        return Field::X;
    } else if(getPlayerForField(Field::O) == player) {
        return Field::O;
    }
    
    // throw error since the given player is not participating in this game
    throw std::runtime_error("player does not participate in this game");
}
