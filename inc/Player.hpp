#pragma once

#include "Board.hpp"

class Player {
private:
    char m_mark;
    unsigned int m_markPlace;
public:
// 
//  Default Constructor.
// 
    Player();
// 
//  Default Destructor.
//     
    ~Player();
// 
//  Taking input from the user.
//     
    void turn(Board& board);
// 
//  Print message if player wins.
// 
    void win() const;
// 
//  Getters and Setters 
// 
    inline unsigned int getSpot() const {   return m_markPlace;     }
    inline char getMark() const {           return m_mark;          }
};