#include "Board.h"

Board::Board() {

	//-1 indicates no counter placed by player or computer
	gameBoard.resize(3);
	for (int i = 0; i < gameBoard.size(); i++) {
		for (int j = 0; j < 3; j++) {
			gameBoard[i].push_back(-1);
		}
	}

	markTotal = 0;
}

void Board::addCounter(int id, int row, int col) {
	
	//Player = 0, computer = 1
	if (id == 0) {
		gameBoard[row][col] = 0;
	}
	else if (id == 1) {
		gameBoard[row][col] = 1;
	}

	increaseMarkTotal();
}

//Reset counter at specified position on board to -1 (used for AI minimax algorithm)
void Board::resetCounter(int row, int col) {
	gameBoard[row][col] = -1;

	decreaseMarkTotal();
}

void Board::increaseMarkTotal() {
	markTotal++;
}

void Board::decreaseMarkTotal() {
	markTotal--;
}

int Board::getMarkTotal() {
	return markTotal;
}

std::vector<std::vector<int>> Board::getGameBoard() {
	return gameBoard;
}

int Board::getCounter(int row, int col) {
	return gameBoard[row][col];
}

void Board::resetGameBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			gameBoard[i][j] = -1;
		}
	}

	markTotal = 0;
}

bool Board::isGameBoardFull() {
	if (markTotal == 9) {
		return true;
	}
	else {
		return false;
	}
}

int Board::checkWinner(int id) {

	int result = 0;

	//Check for three counters in series in a row
	for (int i = 0; result == 0 && i < 3; i++) {
		int row_result = 1;
		for (int j = 0; row_result == 1 && j < 3; j++) {
			if (gameBoard[i][j] != id) {
				row_result = 0;
			}
		}

		if (row_result != 0) {
			result = 1;
		}
	}

	//Check for three counters in series in a column
	for (int i = 0; result == 0 && i < 3; i++) {
		int col_result = 1;
		for (int j = 0; col_result == 1 && j < 3; j++) {
			if (gameBoard[j][i] != id) {
				col_result = 0;
			}
		}

		if (col_result != 0) {
			result = 1;
		}
	}

	//Check for three counters in a descending diagonal
	if (result == 0) {
		int descDiag = 1;
		for (int i = 0; descDiag == 1 && i < 3; i++) {
			if (gameBoard[i][i] != id) {
				descDiag = 0;
			}
		}

		if (descDiag != 0) {
			result = 1;
		}
	}

	//Check for three counters in an ascending diagonal
	if (result == 0) {
		int ascDiag = 1;
		for (int i = 0; ascDiag == 1 && i < 3; i++) {
			if (gameBoard[i][2 - i] != id) {
				ascDiag = 0;
			}
		}

		if (ascDiag != 0) {
			result = 1;
		}
	}

	return result;
}

bool Board::playerWins() {
	if (checkWinner(0) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::computerWins() {
	if (checkWinner(1) == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::checkTiedGame() {
	if (isGameBoardFull()) {
		return true;
	}
	else {
		return false;
	}
}


