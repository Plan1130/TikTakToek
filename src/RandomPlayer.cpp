//
//  RandomPlayer.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "RandomPlayer.hpp"

#include <cassert>
#include <cstdlib>
#include <vector>

Position RandomPlayer::getNextMove(Board const& board, Field current_field) {
    // get all possible moves
    std::vector<Position> possible_moves = board.getEmptyPositions();
    
    assert(!possible_moves.empty());
    
    // get random move from possible moves
    Position random_move = possible_moves[std::rand() % possible_moves.size()];
    
    return random_move;
}
