#pragma once
#include <SFML/Graphics.hpp>

class GameElements {
public:
    sf::Font font;

    sf::RectangleShape line1;
    sf::RectangleShape line2;
    sf::RectangleShape line3;
    sf::RectangleShape line4;

    sf::Text gameStartMessage;
    sf::RectangleShape newGameButton;
    sf::Text newGameMessage;
    sf::RectangleShape quitGameButton;
    sf::Text quitGameMessage;

    sf::Text selectCounterMessage;

    sf::RectangleShape xCounterButton;
    sf::Text xCounterSelect;
    sf::RectangleShape oCounterButton;
    sf::Text oCounterSelect;

    sf::Text gameStatusMessage;

    sf::Text activeCounter[3][3];

    GameElements();

    void setFont();
    void setText();
    void placeCounter(char counter, int row, int col);

    void resetCounterText();
};
