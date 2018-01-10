//
//  Board.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef Board_hpp
#define Board_hpp

#include "Field.hpp"
#include "Position.hpp"

#include <vector>

#define GRID_SIZE 3
#define N_FIELD_TYPES 2

class Board {
public:
    // constructs a board
    Board();
    // constructs a board from an existing board (copies the board)
    Board(const Board&) = default;
    
    // resets the board
    void reset();
    
    // sets a field at a given position
    void setField(int, int, Field);
    // gets the field at a given position
    Field getField(int, int) const;
    
    // returns all empty positions
    std::vector<Position> getEmptyPositions() const;
    
    // executes a move for a given symbol(Field, ie. X or O) at a given position
    void doMove(Position, Field);
    
    // returns true if the board is full
    bool isFull() const;
    // returns true if the given field has won
    bool isWinner(Field) const;
    
private:
    // returns a board position from a given index
    Position getPositionFromIndex(int) const;
    // return an board index from a give position
    int getIndexFromPosition(Position) const;
    // return an board index from a give position
    int getIndexFromPosition(int, int) const;
    
    Field grid_[GRID_SIZE * GRID_SIZE];
};

#endif /* Board_hpp */
