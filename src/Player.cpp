#include "../inc/Player.hpp"

#include <iostream>

//  Default Constructor.
Player::Player() 
: m_mark('X'), m_markPlace(0)
{

}
//  Default Destructor.
Player::~Player() {

}
//  Taking input from the user.  
void Player::turn(Board& board) {
    unsigned int spot = 0;
    do {    
        std::cout << "Which spot do you want to play on the board? (1-9)\n"
            << "Select the position: ";
        std::cin >> spot;

        if (spot < 1 || spot > 9)
            std::cout << "ERROR: Invalid Choice. Please Try Again." << std::endl;
    } while (spot < 1 || spot > 9);
    m_markPlace = --spot;
    board.edit(getMark(), getSpot());
    board.draw();
}
// Print message if the player wins
void Player::win() const {
    std::cout << "Player wins!" << std::endl;
}