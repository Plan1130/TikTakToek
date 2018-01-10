//
//  Move.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "Position.hpp"

#include "Board.hpp"

#include <cassert>

Position const Position::unknown_position = Position();

Position::Position(int x, int y) : x_(x), y_(y) {
    assert(isValid());
}

bool Position::isValid() const {
    return x_ >= 0 && x_ < GRID_SIZE && y_ >= 0 && y_ < GRID_SIZE;
}

int Position::getX() const {
    assert(isValid());
    return x_;
}

int Position::getY() const {
    assert(isValid());
    return y_;
}

Position::Position() : x_(-1), y_(-1) {
}
