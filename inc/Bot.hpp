#pragma once

#include "Board.hpp"

class Bot {
private:
// 
//  Mark made for the Bot ('O')
// 
    char m_mark;
// 
//  Position of the board chosen by the Bot
// 
    int m_markPlace;
public:
// 
//  Default Constructor
// 
    Bot();
// 
//  Default Destructor
//     
    ~Bot();
// 
//  Turn hard from the previous implementation of this game.
//     
    void turn(Board&);
// 
//  Easy Turn for the bot. This just consists of picking a random open spot on the board for the bot.
// 
    void easyTurn(Board&);
// 
//  Printing the winning message if the Bot wins.
//     
    void win() const;
// 
//  Getters and setters
// 
    inline char getMark() const {       return m_mark;      }
    inline int getSpot() const {        return m_markPlace; }
};