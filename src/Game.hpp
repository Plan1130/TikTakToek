//
//  Game.hpp
//  TicTacToe
//
//  Created by David Stritzl on 29/11/15.
//
//

#ifndef Game_hpp
#define Game_hpp

#include "Player.hpp"
#include "Board.hpp"

#include <cassert>
#include <iostream>
#include <vector>

#define N_PLAYERS N_FIELD_TYPES

class Game {
public:
    // construct a game with two players
    Game(Player *, Player *);
    
    // resets the game
    void reset();
    
    // returns the board belonging to the game
    Board& getBoard();
    
    // returns the players in the game
    std::vector<Player *> getPlayers() const;
    // returns the current player
    Player *getCurrentPlayer() const;
    
    // does all possible moves
    void doPossibleMoves();
    // tries to do a move
    bool tryDoMove();
    
    // returns true if the game is finished
    bool isFinished() const;
    // returns true if the player is the winner
    bool isWinner(Player *) const;
    
private:
    // returns the player belonging to the symbol, ie. X -> player1
    Player *getPlayerForField(Field) const;
    // returns the symbol belonging to the player, ie. player1 -> X
    Field getFieldForPlayer(Player *) const;
    
    Board board_;
    // list of players in the game
    std::vector<Player *> players_;
    
    // symbol of the player having the turn
    Field current_field_ = Field::X;
};

#endif /* Game_hpp */
