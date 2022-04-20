#pragma once
#include <vector>

class Board
{
private:
	std::vector<std::vector<int>> gameBoard;
	int markTotal;

public:
	Board();
	void addCounter(int id, int row, int col);
	void resetCounter(int row, int col);
	int getCounter(int row, int col);

	void increaseMarkTotal();
	void decreaseMarkTotal();
	int getMarkTotal();

	std::vector<std::vector<int>> getGameBoard();
	void resetGameBoard();
	bool isGameBoardFull();

	int checkWinner(int id);
	bool playerWins();
	bool computerWins();
	bool checkTiedGame();
};

