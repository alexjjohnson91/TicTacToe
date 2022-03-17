#include "../inc/Board.hpp"
#include <iostream>
#include <cmath>
#include <iomanip>

// these are the constant values for the rows and the columns
namespace {
    const int ROW = 3;
    const int COL = 3;
    const int WIDTH = 3;
};

// Normal constructor.
Board::Board() 
: m_currRow(0), m_currCol(0), m_moves(0)
{
    m_board = new char*[ROW];
    for (int i = 0; i < ROW; i++) {
        m_board[i] = new char[COL];
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            m_board[i][j] = '-';
        }
    }
}
// Normal Destructor.
Board::~Board() {
    for (int i = 0; i < ROW; i++) {
        delete[] m_board[i];
    }

    delete[] m_board;
}
// Draw board to the screen.
void Board::draw() const {
    for (int i=0; i<ROW; i++) {
    for (int j=0; j<COL; j++) {
        std::cout << std::right << std::setw(WIDTH) << m_board[i][j];
        if (j!=2) {
            std::cout << std::right << std::setw(WIDTH) << '|';
        }
    }
        std::cout << '\n';
    }
}
// Edit the position of the board.
void Board::edit(const char& mark, const int& position) {
    m_currRow = position/ROW;
    m_currCol = position%COL;
    m_board[m_currRow][m_currCol] = mark;    
    
    if (mark == '-')
        m_moves--;
    else
        m_moves++;

}
// Find out if the current spot is taken
bool Board::spotTaken(const unsigned int& spot) const {
    return (m_board[spot/3][spot%3] != '-');
}
char Board::at(const unsigned int& row, const unsigned int& col) const {
    return m_board[row][col];
}
// Is game over
// end game
bool Board::isGameOver(const char& mark) {
// flag to track when the game is over
    bool flag = false;
// first we want to check to see if any of the rows are winning
    for (unsigned int i = 0; i < ROW; i++) {
        if (at(getRow(), i) != mark)
            break;
        else if ((i + 1) == ROW)
            flag = true;
    }

// next, we want to check and see if there is a column that has a winning value
    for (unsigned int i = 0; i < COL; i++) {
        if (at(i, getCol()) != mark)
            break;
        else if ((i + 1) == COL)
            flag = true;
    }

// now check for the first diagonal
    for (unsigned int i = 0; i < ROW; i++) {
        if (at(i, i) != mark)
            break;
        else if ((i + 1) == ROW)
            flag = true;
    }

// check the anti-diagonal
    for (unsigned int i = 0; i < ROW; i++) {
        if (at(i, ROW-i) != mark)
            break;
        else if ((i + 1) == ROW)
            flag = true;
    }

// check if the game is a cat's eye
    if (isCat()) {
        std::cout << "TIE GAME" << std::endl;
        flag = true;
    }

// if the function returns false, then the game is still a tie
    return flag;
}
// Is the game a Cat's Eye?
// 
// If this function returns true, the game is a cat's eye
// If this function returns falst, the game is not a cat's eye
// 
bool Board::isCat() const {
    return m_moves == 9;
}