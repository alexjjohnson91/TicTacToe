#include "../inc/Bot.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Default Constructor
Bot::Bot() 
: m_mark('O'), m_markPlace(0) {}
// Default Destructor
Bot::~Bot() {}
// Hard turn from the previous implementation of this game
void Bot::turn(Board& board) {
    // first check the spots that aren't taken and see if that means you can win.
    for (unsigned int i = 0; i < 3; i++) {
        if (!board.spotTaken(i)) {
            // if the spot is not taken, check to see if you could win.
            board.edit(getMark(), i);
            // if the game is over now, leave the function
            if (board.isGameOver(getMark())) {
                m_markPlace = i;
                board.draw();
                return;
            }
            else { // otherwise, change the board back to what it was
                board.edit('-', i);
            }
        }
    }

    // now we need to check and see if the player can win anywhere on the board
    for (unsigned int i = 0; i < 3; i++) {
        if (!board.spotTaken(i)) {
            // change the board to the player's mark to check
            board.edit('X', i);
            // if the game is over now, switch the board to the bot's mark
            if (board.isGameOver('X')) {
                board.edit(getMark(), i);
                m_markPlace = i;
                return;
            }
            else {
                board.edit('-', i);
            }
        }
    }

    // if nothing happens till now, then we can just pick a random open spot on the board
    easyTurn(board);
}
// easy turn
void Bot::easyTurn(Board& board) {
    do {
        m_markPlace = rand() % 9;
    } while (board.spotTaken(m_markPlace));
    board.edit(getMark(), m_markPlace);
    board.draw();
}
// Printing the winning message if the bot wins.
void Bot::win() const {
    std::cout << "The computer wins!" << std::endl;
}