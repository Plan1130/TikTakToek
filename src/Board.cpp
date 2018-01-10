//
//  Board.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "Board.hpp"

#include <cassert>

Board::Board() {
    reset();
}

void Board::reset() {
    // sets all fields to empty
    for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        grid_[i] = Field::Empty;
    }
}

void Board::setField(int x, int y, Field field) {
    assert(x >= 0 && x < GRID_SIZE);
    assert(y >= 0 && y < GRID_SIZE);
    grid_[getIndexFromPosition(x, y)] = field;
}

Field Board::getField(int x, int y) const {
    assert(x >= 0 && x < GRID_SIZE);
    assert(y >= 0 && y < GRID_SIZE);
    return grid_[getIndexFromPosition(x, y)];
}

std::vector<Position> Board::getEmptyPositions() const {
    std::vector<Position> empty_positions;
    
    // add all empty field to vector
    for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        if(grid_[i] == Field::Empty) {
            empty_positions.push_back(getPositionFromIndex(i));
        }
    }
    
    return empty_positions;
}

void Board::doMove(Position position, Field field) {
    assert(position.isValid());
    assert(getField(position.getX(), position.getY()) == Field::Empty);
    setField(position.getX(), position.getY(), field);
}

bool Board::isFull() const {
    // checks if an empty field exists
    for(int i = 0; i < GRID_SIZE * GRID_SIZE; i++) {
        if(grid_[i] == Field::Empty) {
            return false;
        }
    }
    
    return true;
}

bool Board::isWinner(Field field) const {
    // check vertical
    for(int y = 0; y < GRID_SIZE; y++) {
        if(getField(0, y) != Field::Empty && getField(0, y) == getField(1, y) && getField(1, y) == getField(2, y)) {
            return field == getField(0, y);
        }
    }
    
    // check horizontal
    for(int x = 0; x < GRID_SIZE; x++) {
        if(getField(x, 0) != Field::Empty && getField(x, 0) == getField(x, 1) && getField(x, 1) == getField(x, 2)) {
            return field == getField(x, 0);
        }
    }
    
    // check diagonal
    if(getField(0, 0) != Field::Empty && getField(0, 0) == getField(1, 1) && getField(1, 1) == getField(2, 2)) {
        return field == getField(0, 0);
    }
    if(getField(0, 2) != Field::Empty && getField(0, 2) == getField(1, 1) && getField(1, 1) == getField(2, 0)) {
        return field == getField(0, 2);
    }
    
    // no winner :(
    return false;
}

Position Board::getPositionFromIndex(int index) const {
    return Position(index % GRID_SIZE, (char)(index / GRID_SIZE));
}

int Board::getIndexFromPosition(Position position) const {
    return getIndexFromPosition(position.getX(), position.getY());
}

int Board::getIndexFromPosition(int x, int y) const {
    return x + y * GRID_SIZE;
}
