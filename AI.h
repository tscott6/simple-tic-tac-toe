#pragma once
#include "Board.h"
#include <vector>

class AI
{
private:
	std::pair<int, int> computerMove;

public:
	void setComputerMove(std::pair<int, int> newMove);
	std::pair<int, int> getComputerMove();

	void bestMove(Board& game);
	int minimax(Board& game, int depth, int id, int a, int b);
};

