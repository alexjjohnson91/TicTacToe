#pragma once

class Board {
private:
// 
//  Char 2d array to store the board values.
// 
    char** m_board;
// 
//  Members to store the current row location and the current column location as chosen by the player or the bot.
// 
    unsigned int m_currRow;
    unsigned int m_currCol;
// 
//  count the moves made by incrementing this in the edit function
// 
    unsigned int m_moves;
public:
// 
//  Default Constructor
// 
    Board();
// 
//  Default Destructor. This will deallocate the memory used in the Constructor.
//     
    ~Board();
// 
//  Draw Method. This method will draw the board to the console.
//     
    void draw() const;
// 
//  Edit method. This will take in the new mark ('X' or 'O') and edit that position (the integer parameter) on the board.
//     
    void edit(const char& mark, const int& position);
// 
//  method to find if the current spot is taken or not.
// 
    bool spotTaken(const unsigned int& position) const;
// 
//  Method that returns the char at the specified location of the board
// 
    char at(const unsigned int&, const unsigned int&) const;
// 
//  self documenting
// 
    bool isGameOver(const char&);
// 
//  check for a tie
// 
    bool isCat() const;

// Inline Getters
    inline unsigned int getRow() const {    return m_currRow;   }
    inline unsigned int getCol() const {    return m_currCol;   }
};