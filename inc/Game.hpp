#pragma once
#include "Player.hpp"
#include "Board.hpp"
#include "Bot.hpp"

class Game {
private:
    Player* m_player;
    Bot* m_bot;
    Board* m_board;
public:
// 
//  Default Constructor
// 
    Game();
// 
//  Default Destructor
// 
    ~Game();
// 
//  driver function that will run the game
// 
    void gameLoop();
};