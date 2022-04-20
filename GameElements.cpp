#include "GameElements.h"
#include <iostream>

GameElements::GameElements() {

    line1 = sf::RectangleShape(sf::Vector2f(5.f, 175.f));
    line2 = sf::RectangleShape(sf::Vector2f(5.f, 175.f));
    line3 = sf::RectangleShape(sf::Vector2f(175.f, 5.f));
    line4 = sf::RectangleShape(sf::Vector2f(175.f, 5.f));

    line1.setFillColor(sf::Color::Black);
    line2.setFillColor(sf::Color::Black);
    line3.setFillColor(sf::Color::Black);
    line4.setFillColor(sf::Color::Black);

    line1.setPosition(60.f, 55.f);
    line2.setPosition(120.f, 55.f);
    line3.setPosition(5.f, 110.f);
    line4.setPosition(5.f, 170.f);

    xCounterButton = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    xCounterButton.setFillColor(sf::Color::White);
    xCounterButton.setOutlineThickness(5.f);
    xCounterButton.setOutlineColor(sf::Color::Black);
    xCounterButton.setPosition(390.f, 85.f);

    oCounterButton = sf::RectangleShape(sf::Vector2f(30.f, 30.f));
    oCounterButton.setFillColor(sf::Color::White);
    oCounterButton.setOutlineThickness(5.f);
    oCounterButton.setOutlineColor(sf::Color::Black);
    oCounterButton.setPosition(440.f, 85.f);

    newGameButton = sf::RectangleShape(sf::Vector2f(77.f, 20.f));
    newGameButton.setFillColor(sf::Color::White);
    newGameButton.setOutlineThickness(5.f);
    newGameButton.setOutlineColor(sf::Color::Black);
    newGameButton.setPosition(7.f, 260.f);

    quitGameButton = sf::RectangleShape(sf::Vector2f(77.f, 20.f));
    quitGameButton.setFillColor(sf::Color::White);
    quitGameButton.setOutlineThickness(5.f);
    quitGameButton.setOutlineColor(sf::Color::Black);
    quitGameButton.setPosition(102.f, 260.f);
}

void GameElements::setFont() {
    font.loadFromFile("Roboto-Regular.ttf");
}

void GameElements::setText() {
    gameStartMessage.setFont(font);
    gameStartMessage.setString("Welcome to Tic-Tac-Toe");
    gameStartMessage.setFillColor(sf::Color::Black);
    gameStartMessage.setCharacterSize(20);
    gameStartMessage.setPosition(200.f, 55.f);

    selectCounterMessage.setFont(font);
    selectCounterMessage.setString("Select your counter");
    selectCounterMessage.setFillColor(sf::Color::Black);
    selectCounterMessage.setCharacterSize(20);
    selectCounterMessage.setPosition(200.f, 85.f);

    xCounterSelect.setFont(font);
    xCounterSelect.setString("X");
    xCounterSelect.setFillColor(sf::Color::Black);
    xCounterSelect.setCharacterSize(30);
    xCounterSelect.setPosition(395.f, 80.f);

    oCounterSelect.setFont(font);
    oCounterSelect.setString("O");
    oCounterSelect.setFillColor(sf::Color::Black);
    oCounterSelect.setCharacterSize(30);
    oCounterSelect.setPosition(445.f, 80.f);

    gameStatusMessage.setFont(font);
    gameStatusMessage.setString("");
    gameStatusMessage.setFillColor(sf::Color::Black);
    gameStatusMessage.setCharacterSize(15);
    gameStatusMessage.setPosition(5.f, 235.f);

    newGameMessage.setFont(font);
    newGameMessage.setString("New Game");
    newGameMessage.setFillColor(sf::Color::Black);
    newGameMessage.setCharacterSize(15);
    newGameMessage.setPosition(10.f, 260.f);

    quitGameMessage.setFont(font);
    quitGameMessage.setString("Quit Game");
    quitGameMessage.setFillColor(sf::Color::Black);
    quitGameMessage.setCharacterSize(15);
    quitGameMessage.setPosition(105.f, 260.f);

    float xPos = 24;
    float yPos = 64;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            activeCounter[i][j].setFont(font);
            activeCounter[i][j].setString("");
            activeCounter[i][j].setFillColor(sf::Color::Black);
            activeCounter[i][j].setCharacterSize(30);
            activeCounter[i][j].setPosition(xPos, yPos);

            xPos += 60;
        }
        xPos = 24;
        yPos += 60;
    }
}

void GameElements::placeCounter(char counter, int row, int col) {
    activeCounter[row][col].setString(counter);
}

//Resets all counter text to blank. Used when player begins new game.
void GameElements::resetCounterText() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            activeCounter[i][j].setString("");
        }
    }
}