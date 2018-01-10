//
//  MinMaxPlayer.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef MinMaxPlayer_hpp
#define MinMaxPlayer_hpp

#include "ComputerPlayer.hpp"

class MinMaxPlayer : public ComputerPlayer {
public:
    // use constructor of computer player
    using ComputerPlayer::ComputerPlayer;
    
    // returns the position of the next move for this player (given the current board and the symbol(Field) of the current player)
    Position getNextMove(Board const&, Field) override;
    
private:
    // return the maximum possible score given a board and the symbol(Field) of a player
    // note: it is suggested to this method for your own algorithm, but other implementations are possible as well
    int getMinMaxScore(Board const&, Field);
};

#endif /* MinMaxPlayer_hpp */
