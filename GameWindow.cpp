#include "GameWindow.h"
#include <iostream>
#include <vector>

GameWindow::GameWindow() {
	window.create(sf::VideoMode(500, 350), "Tic-Tac-Toe");

    elements = GameElements();
    board = Board();
    computer = AI();
}

void GameWindow::setCounterID(char counter) {
    playerCounter = counter;
    
    if (playerCounter == 'X') {
        computerCounter = 'O';
    }
    else {
        computerCounter = 'X';
    }
}

/**
* Determines the counter present on the game board at the position of mouse click.
* If the location is outside the game board, currentCounter returns -5
* Else returns the counter value at the selected position (-1, 0, or 1).
*/
int GameWindow::currentCounter(int x, int y) {
    
    //Return -5 if anywhere outside of board selected
    int counter = -5;

    if (y >= 55 && y <= 110) {
        if (x >= 5 && x <= 60) {
            counter = board.getCounter(0, 0);
        }
        else if (x > 60 && x <= 120) {
            counter = board.getCounter(0, 1);
        }
        else if (x > 120 && x < 175) {
            counter = board.getCounter(0, 2);
        }
    }
    else if (y > 110 && y <= 170) {
        if (x >= 5 && x <= 60) {
            counter = board.getCounter(1, 0);
        }
        else if (x > 60 && x <= 120) {
            counter = board.getCounter(1, 1);
        }
        else if (x > 120 && x < 175) {
            counter = board.getCounter(1, 2);
        }
    }
    else if (y > 170 && y <= 230) {
        if (x >= 5 && x <= 60) {
            counter = board.getCounter(2, 0);
        }
        else if (x > 60 && x <= 120) {
            counter = board.getCounter(2, 1);
        }
        else if (x > 120 && x < 175) {
            counter = board.getCounter(2, 2);
        }
    }

    return counter;
}

/**
* Updates the text of the game board at the selected board location to use the player id's counter
* The game board is likewise updated with that player id.
* If the selected location falls outside the game board, no update is made.
*/
void GameWindow::placeCounter(int id, int x, int y) {
    char counter;

    if (id == 0) { counter = playerCounter; }
    else { counter = computerCounter; }

    if (y >= 55 && y <= 110) {
        if (x >= 5 && x <= 60) {
            board.addCounter(id, 0, 0);
            updateCounterText(counter, 0, 0);
        }
        else if (x > 60 && x <= 120) {
            board.addCounter(id, 0, 1);
            updateCounterText(counter, 0, 1);
        }
        else if (x > 120 && x < 175) {
            board.addCounter(id, 0, 2);
            updateCounterText(counter, 0, 2);
        }
    }
    else if (y > 110 && y <= 170) {
        if (x >= 5 && x <= 60) {
            board.addCounter(id, 1, 0);
            updateCounterText(counter, 1, 0);
        }
        else if (x > 60 && x <= 120) {
            board.addCounter(id, 1, 1);
            updateCounterText(counter, 1, 1);
        }
        else if (x > 120 && x < 175) {
            board.addCounter(id, 1, 2);
            updateCounterText(counter, 1, 2);
        }
    }
    else if (y > 170 && y <= 230) {
        if (x >= 5 && x <= 60) {
            board.addCounter(id, 2, 0);
            updateCounterText(counter, 2, 0);
        }
        else if (x > 60 && x <= 120) {
            board.addCounter(id, 2, 1);
            updateCounterText(counter, 2, 1);
        }
        else if (x > 120 && x < 175) {
            board.addCounter(id, 2, 2);
            updateCounterText(counter, 2, 2);
        }
    }
}

void GameWindow::updateCounterText(char counter, int x, int y) {
    elements.activeCounter[x][y].setString(counter);
}

void GameWindow::run() {

    //Need to set font outside of GameElements constructor to avoid font object being deleted during destructor call
    elements.setFont();
    elements.setText();

    window.setMouseCursorVisible(true);

    //Specifies where mouse in relation to screen coordinates. Initialized to avoid errors
    sf::Vector2i mouseScreenPosition(0, 0);

    //Booleans used to control active game state
    bool counterSelect = true;
    bool gameInProgress = false;

    while (window.isOpen()) {
        
        sf::Event event;

        while (window.pollEvent(event))
        {
            //Window exited, close program
            if (event.type == sf::Event::Closed)
                window.close();

            //Escape used as program exit hotkey
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }

            //All game choices and game loop handled through mouse clicking and change of game state booleans
            if (event.type == sf::Event::MouseButtonReleased) {
                mouseScreenPosition = sf::Mouse::getPosition(window);

                //Counter select state, allow player to choose which counter to represent them on the game board
                if (counterSelect == true) {
                    if (mouseScreenPosition.x >= 390 && mouseScreenPosition.x <= 420 && mouseScreenPosition.y >= 85 && mouseScreenPosition.y <= 115) {
                        setCounterID('X');
                        counterSelect = false;
                        gameInProgress = true;
                        elements.gameStatusMessage.setString("Game start!\nClick on board space to place your counter");
                        //std::cout << "Player counter: " << playerCounter << std::endl;
                        //std::cout << "Computer counter: " << computerCounter << std::endl;
                    }
                    else if (mouseScreenPosition.x >= 440 && mouseScreenPosition.x <= 470 && mouseScreenPosition.y >= 85 && mouseScreenPosition.y <= 115) {
                        setCounterID('O');
                        counterSelect = false;
                        gameInProgress = true;
                        elements.gameStatusMessage.setString("Game start!\nClick on board space to place your counter");
                        //std::cout << "Player counter: " << playerCounter << std::endl;
                        //std::cout << "Computer counter: " << computerCounter << std::endl;
                    }

                    mouseScreenPosition = sf::Vector2i(0, 0);
                }

                //Main game loop, AI conducts its turn after player has clicked on desired board space for placing their counter
                else if (gameInProgress == true) {
                    
                    int counter = currentCounter(mouseScreenPosition.x, mouseScreenPosition.y);

                    //Only execute new turn if player selected an empty space on the game board
                    if (counter == -1) {
                        placeCounter(0, mouseScreenPosition.x, mouseScreenPosition.y);

                        if (board.playerWins()) { 
                            elements.gameStatusMessage.setString("Game over! You win!");
                            gameInProgress = false;
                            break;
                        }
                        if (board.checkTiedGame()) { 
                            elements.gameStatusMessage.setString("Game over! It's a tie!"); 
                            gameInProgress = false;
                            break;
                        }

                        computer.bestMove(board);

                        std::pair<int, int> computerMove = computer.getComputerMove();

                        std::cout << "Computer move: " << computerMove.first << ", " << computerMove.second << std::endl;

                        board.addCounter(1, computerMove.first, computerMove.second);
                        updateCounterText(computerCounter, computerMove.first, computerMove.second);

                        if (board.computerWins()) { 
                            elements.gameStatusMessage.setString("Game over! Computer wins!"); 
                            gameInProgress = false;
                            break;
                        }
                    }
                }

                //Game has ended, allow player to play again or exit the game
                else if (counterSelect == false && gameInProgress == false) {
                    if (mouseScreenPosition.x >= 7 && mouseScreenPosition.x <= 84 && mouseScreenPosition.y >= 260 && mouseScreenPosition.y <= 280) {
                        counterSelect = true;
                        board.resetGameBoard();
                        elements.resetCounterText();
                    }
                    else if (mouseScreenPosition.x >= 102 && mouseScreenPosition.x <= 179 && mouseScreenPosition.y >= 260 && mouseScreenPosition.y <= 280) {
                        window.close();
                    }
                }
            }
        }

        window.clear(sf::Color(255, 255, 255, 255));
        window.draw(elements.line1);
        window.draw(elements.line2);
        window.draw(elements.line3);
        window.draw(elements.line4);

        if (counterSelect == true) {
            window.draw(elements.gameStartMessage);
            window.draw(elements.selectCounterMessage);
            window.draw(elements.xCounterButton);
            window.draw(elements.xCounterSelect);
            window.draw(elements.oCounterButton);
            window.draw(elements.oCounterSelect);
        }

        if (gameInProgress == true) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    window.draw(elements.activeCounter[i][j]);
                }
            }
            window.draw(elements.gameStatusMessage);
        }

        if (counterSelect == false && gameInProgress == false) {
            window.draw(elements.newGameButton);
            window.draw(elements.newGameMessage);
            window.draw(elements.quitGameButton);
            window.draw(elements.quitGameMessage);
            window.draw(elements.gameStatusMessage);
        }

        window.display();
    }
}
