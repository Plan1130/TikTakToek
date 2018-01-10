//
//  MinMaxPlayer.cpp
//  TicTacToe
//
//  Created by Florian Fikkert & Sander Koning
//
//

#include "HeuristicPlayer.hpp"

#include <cassert>
#include <climits>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

Position HeuristicPlayer::getNextMove(Board const& board, Field current_field) {
	//store moves in vector stack
	std::vector<Position> possible_moves = board.getEmptyPositions();

	//init best score and current move
	int moveScore = -1;

	if(possible_moves.size() == 0)
		return Position::unknown_position;
		
	Position move = possible_moves[0];

	for (unsigned int i = 0; i < possible_moves.size(); i++) {
		// copy board and simulate move
		Board copy = Board(board);
		copy.doMove(possible_moves[i], current_field);

		// calculate score for possible move
		int currentMoveScore = -getMinMaxScore(copy, ~current_field, DEPTH);

		std::cout << std::to_string(moveScore) + "\n";

		if (copy.isWinner(current_field)) { //check if move ends it
			move = possible_moves[i];
			break;
		}
		else if (currentMoveScore > moveScore) { //or if better than previous
			moveScore = currentMoveScore;
			move = possible_moves[i];
		}
	}
	std::cout << "======================\n";
	return move;
}

int HeuristicPlayer::getMinMaxScore(Board const& board, Field current_field, int depth) {
	//store moves in vector stack
	std::vector<Position> possible_moves = board.getEmptyPositions();

	//determine score of the move
	if (board.isWinner(current_field)) {
		return 10;
	}
	else if (board.isWinner(~current_field)) {
		return -10;
	}
	else if (board.isFull()) {
		return 0;
	}

	if (depth == 0) {
		return getHeuristicScore(board, current_field);
	}

	//check all the other options by checking the new situation recursively in the loop
	int currentScore = -1; // lowest value
	for (unsigned int i = 0; i < possible_moves.size(); i++) {
		Board copy = Board(board);
		copy.doMove(possible_moves[i], current_field);
		currentScore = std::max(currentScore, -getMinMaxScore(copy, ~current_field, depth-1));
	}

	return currentScore;
}

int HeuristicPlayer::getHeuristicScore(Board const& board, Field current_field) {
	int score = 0;

	// High score positions
	if (board.getField(0, 0) == current_field)
		score += 3;
	else if (board.getField(0, 0) == ~current_field)
		score -= 3;

	if (board.getField(0, 2) == current_field)
		score += 3;
	else if (board.getField(0, 2) == ~current_field)
		score -= 3;

	if (board.getField(2, 0) == current_field)
		score += 3;
	else if (board.getField(2, 0) == ~current_field)
		score -= 3;

	if (board.getField(2, 2) == current_field)
		score += 3;
	else if (board.getField(2, 2) == ~current_field)
		score -= 3;
	
	// Mid score position
	if (board.getField(1, 1) == current_field)
		score += 2;
	else if (board.getField(1, 1) == ~current_field)
		score -= 2;

	// Low score position
	if (board.getField(1, 2) == current_field)
		score += 1;
	else if (board.getField(1, 2) == ~current_field)
		score -= 1;

	if (board.getField(0, 1) == current_field)
		score += 1;
	else if (board.getField(0, 1) == ~current_field)
		score -= 1;

	if (board.getField(1, 0) == current_field)
		score += 1;
	else if (board.getField(1, 0) == ~current_field)
		score -= 1;

	if (board.getField(2, 1) == current_field)
		score += 1;
	else if (board.getField(2, 1) == ~current_field)
		score -= 1;

	return score;
}