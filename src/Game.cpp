#include "../inc/Game.hpp"
#include <iostream>
namespace {
    const unsigned int ROW = 3;
    const unsigned int COL = 3;
}


// Default Constuctor 
Game::Game()
{
    m_player = new Player;
    m_bot = new Bot;
    m_board = new Board;
}
// Default Destructor
Game::~Game() {
    delete m_player;
    delete m_bot;
    delete m_board;
}
// Driver function
void Game::gameLoop() {
// First, we should draw the blank board to the screen
    m_board->draw();

// Then, print a message to the player to inform them of the playing mark that they are given
    std::cout << "The player's mark will be 'X'" << std::endl;
    std::cout << "The bot's mark will be 'O'" << std::endl;

// We will need a loop that is moving through both the player's turn and the bot's turn for the game
    while(true) {
        // First, let's take the player's turn
        m_player->turn(*m_board);
        if (m_board->isGameOver(m_player->getMark())) {
            m_board->draw();
            m_player->win();
            return;
        }

        // now we have the bots turn
        m_bot->turn(*m_board);// the board is edited automatically through the bot's turn
        if (m_board->isGameOver(m_bot->getMark())) {
            m_board->draw();
            m_bot->win();
            return;
        }

        if (m_board->isCat()) {
            m_board->draw();
            std::cout << "TIE" << std::endl;
            return;
        }
    }
}