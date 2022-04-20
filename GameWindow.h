#pragma once
#include <SFML/Graphics.hpp>
#include "GameElements.h"
#include "Board.h"
#include "AI.h"

class GameWindow
{
private:
    GameElements elements;
    Board board;
    AI computer;
    char playerCounter;
    char computerCounter;

    sf::RenderWindow window;

public:
    GameWindow();
    void setCounterID(char counter);
    int currentCounter(int x, int y);
    void placeCounter(int id, int x, int y);
    void updateCounterText(char counter, int x, int y);

    void run();
};

