//
//  Player.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef Player_hpp
#define Player_hpp

#include "Board.hpp"
#include "Position.hpp"

#include <string>

enum class PlayerType {
    Human,
    Computer
};

class Player {
public:
    // constructs a player with a player type and name
    Player(PlayerType, std::string);
    
    // returns the type of the player (human or computer)
    PlayerType getType() const;
    // returns the name of the player
    std::string getName() const;
    
    // returns the position of the next move for this player (given the current board and the symbol(Field) of the current player)
    virtual Position getNextMove(Board const&, Field) = 0;
    
private:
    // type of the player
    PlayerType const type_;
    // name of the player
    std::string const name_;
};

#endif /* Player_hpp */
