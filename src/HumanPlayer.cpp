//
//  HumanPlayer.cpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#include "HumanPlayer.hpp"

HumanPlayer::HumanPlayer(std::string name) : Player(PlayerType::Human, name) {
}

Position HumanPlayer::getNextMove(Board const& board, Field current_field) {
    // only return given move if is valid for current turn
    if(is_move_valid_for_current_turn_) {
        is_move_valid_for_current_turn_ = false;
        return next_move_;
    }
    
    // otherwise return "unknown_position" -> no move is executed
    return Position::unknown_position;
}

void HumanPlayer::setMove(Position next_move) {
    next_move_ = next_move;
    is_move_valid_for_current_turn_ = true;
}
