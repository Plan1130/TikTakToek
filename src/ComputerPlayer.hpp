//
//  ComputerPlayer.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef ComputerPlayer_hpp
#define ComputerPlayer_hpp

#include "Player.hpp"

// parent class for random player and min max player
class ComputerPlayer : public Player {
public:
    ComputerPlayer(std::string);
};

#endif /* ComputerPlayer_hpp */
