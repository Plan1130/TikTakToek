//
//  MinMaxPlayer.cpp
//  TicTacToe
//
//  Created by Florian Fikkert & Sander Koning
//
//

#include "HeuristicPlayer.h"

#include <cassert>
#include <climits>
#include <cstdlib>
#include <vector>
#include <algorithm>

Position HeuristicPlayer::getNextMove(Board const& board, Field current_field) {
	//store moves in vector stack
	std::vector<Position> possible_moves = board.getEmptyPositions();

	//init best score and current move
	int moveScore = -1;
	Position move = Position::unknown_position;

	for (unsigned int i = 0; i < possible_moves.size(); i++) {
		// copy board and simulate move
		Board copy = Board(board);
		copy.doMove(possible_moves[i], current_field);

		// calculate score for possible move
		int currentMoveScore = -getMinMaxScore(copy, ~current_field);
		if (copy.isWinner(current_field)) { //check if move ends it
			move = possible_moves[i];
			break;
		}
		else if (currentMoveScore > moveScore) { //or if better than previous
			moveScore = currentMoveScore;
			move = possible_moves[i];
		}
	}

	return move;
}

int HeuristicPlayer::getMinMaxScore(Board const& board, Field current_field) {
	//store moves in vector stack
	std::vector<Position> possible_moves = board.getEmptyPositions();

	//determine score of the move
	if (board.isWinner(current_field)) {
		return 1;
	}
	else if (board.isWinner(~current_field)) {
		return -1;
	}
	else if (board.isFull()) {
		return 0;
	}

	//check all the other options by checking the new situation recursively in the loop
	int currentScore = -1; // lowest value
	for (unsigned int i = 0; i < possible_moves.size(); i++) {
		Board copy = Board(board);
		copy.doMove(possible_moves[i], current_field);
		currentScore = std::max(currentScore, -getMinMaxScore(copy, ~current_field));
	}

	return currentScore;
}