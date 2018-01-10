//
//  Player.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "Player.hpp"

Player::Player(PlayerType type, std::string name) : type_(type), name_(name) {
}

PlayerType Player::getType() const {
    return type_;
}

std::string Player::getName() const {
    return name_;
}
