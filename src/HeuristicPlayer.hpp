//
//  HeuristicPlayer.hpp
//  TicTacToe
//
//  Created by Sander Koning & Florian Fikkert on 10/1/18.
//
//

#ifndef HeuristicPlayer_hpp
#define HeuristicPlayer_hpp

#include "ComputerPlayer.hpp"

class HeuristicPlayer : public ComputerPlayer {
public:
	// use constructor of computer player
	using ComputerPlayer::ComputerPlayer;

	// returns the position of the next move for this player (given the current board and the symbol(Field) of the current player)
	Position getNextMove(Board const&, Field) override;


private:
	// depth for minmax heuristic
	const int DEPTH = 2;

	// depth added to normal minmax
	int getMinMaxScore(Board const & board, Field current_field, int depth);

	// heuristic score determination
	int getHeuristicScore(Board const & board, Field current_field);
};

#endif