#include "pch.h"

int main() {
    srand(time(0));

    char **gameBoard = initBoard(gameBoard);

    gameLoop(gameBoard);
    
    // deallocate the dynamic 2d array
    // first deallocate the columns
    for (int i = 0; i < ROW; i++) {
        delete[] gameBoard[i];
    }
    delete[] gameBoard; //deallocate the first layer
    return 0;
}
