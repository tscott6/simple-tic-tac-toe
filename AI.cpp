#include "AI.h"
#include <iostream>

void AI::setComputerMove(std::pair<int, int> newMove) {
	computerMove = newMove;
}

std::pair<int, int> AI::getComputerMove() {
	return computerMove;
}

/**
* Main AI function, loops through all board spaces and calls minimax for each blank space.
* Sets computerMove to the board space returning the highest score.
*/
void AI::bestMove(Board& game) {
	int bestScore = -100;
	std::pair<int, int> move(0, 0);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game.getGameBoard()[i][j] == -1) {
				game.addCounter(1, i, j);
				int score = minimax(game, 0, 0, -100, 100);
				game.resetCounter(i, j);

				//std::cout << "score: " << score << std::endl;
				//std::cout << "bestScore: " << bestScore << std::endl;

				if (score > bestScore) {
					bestScore = score;
					move.first = i;
					move.second = j;
				}
			}
		}
	}

	setComputerMove(move);
}

/**
* Minimax recursive algorithm with alpha-beta pruning
*/
int AI::minimax(Board& game, int depth, int id, int a, int b) {
	if (id == 1) {
		int bestScore = depth - 10;

		int alpha = a;
		int beta = b;

		if (game.playerWins()) {
			return bestScore;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (game.getGameBoard()[i][j] == -1) {
					game.addCounter(1, i, j);
					int score = minimax(game, depth + 1, 0, alpha, beta);
					game.resetCounter(i, j);
					if (score > bestScore) { bestScore = score; }
					if (bestScore >= beta) { return bestScore; }
					if (bestScore > alpha) { alpha = bestScore; }
				}
			}
		}
		return bestScore;
	}
	else if (id == 0) {
		int bestScore = 10 - depth;

		int alpha = a;
		int beta = b;

		if (game.computerWins()) {
			return bestScore;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (game.getGameBoard()[i][j] == -1) {
					game.addCounter(0, i, j);
					int score = minimax(game, depth + 1, 1, alpha, beta);
					game.resetCounter(i, j);
					if (score < bestScore) { bestScore = score; }
					if (bestScore <= alpha) { return bestScore; }
					if (bestScore < beta) { beta = bestScore; }
				}
			}
		}
		return bestScore;
	}
}
