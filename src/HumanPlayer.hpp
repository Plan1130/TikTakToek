//
//  HumanPlayer.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "Player.hpp"

class HumanPlayer : public Player {
public:
    // constructs a human player
    HumanPlayer(std::string);
    
    // returns the position of the next move for this player (given the current board and the symbol(Field) of the current player)
    Position getNextMove(Board const&, Field) override;
    // sets the next move for the player (to be used in GUI code)
    void setMove(Position);
    
private:
    // the next move that is returned for getNextMove
    Position next_move_ = Position::unknown_position;
    // flag for move is valid for this turn
    bool is_move_valid_for_current_turn_ = false;
};

#endif /* HumanPlayer_hpp */
