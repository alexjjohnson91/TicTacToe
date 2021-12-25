#include "pch.h"

#define WIDTH 3
#define PLAYER_MARK 'X'
#define CPU_MARK '0'
#define _UI unsigned

char playerMark = PLAYER_MARK;
char cpuMark = CPU_MARK;
_UI PLAYER_CHOICE = 0;
_UI CPU_CHOICE = 0;
_UI currRow = 0; 
_UI currCol = 0;
_UI movesMade = 0;

void drawBoard(char **board) {
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            cout << right << setw(WIDTH) << board[i][j];
            if (j!=2) {
                cout << right << setw(WIDTH) << '|';
            }
        }
        cout << '\n';
    }
}

char** playerTurn(char **board) {
    drawBoard(board);
    bool inputFlag = true;
    while(inputFlag) { // validation loop with two different conditions
        cout << "What position of the board do you want to play (1-9): ";
        cin >> PLAYER_CHOICE;

        if (PLAYER_CHOICE < 1 || PLAYER_CHOICE > 9) {
            cout << "ERROR: enter number in valid range\n";
        }
        else if (!spotTaken(board, --PLAYER_CHOICE)) {
            inputFlag = false;
        }
        else {
            cout << "ERROR: spot was taken. Try Again.\n";
        }
    }
    movesMade++;
    return changeBoard(board, PLAYER_MARK, PLAYER_CHOICE);
}

char** initBoard(char** board) {
    board = new char*[ROW];
    for (int i = 0; i < ROW; i++) {
        board[i] = new char[COL];
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = '-';
        }
    }
    return board;
}

char** cpuTurn(char** board) {
    drawBoard(board);
    cout << "Computer's Turn\n";
    do {
        CPU_CHOICE = rand() % 9;
    } while (spotTaken(board, CPU_CHOICE));
    movesMade++;
    return changeBoard(board, CPU_MARK, CPU_CHOICE);
}

char** changeBoard(char** board, char MARK, _UI CHOICE) {
    currRow = CHOICE/ROW;
    currCol = CHOICE%COL;
    board[currRow][currCol] = MARK;
    return board;
}

bool isGameOver(char** board, char MARK) {
    bool flag = false; 
    // we will use the current mark and choice to check the row, column, and diagonals to see if there was a win 
    // first check the row, so move through the columns of the current row
    for (_UI i = 0; i < COL; i++) {
        if (board[currRow][i] != MARK) {
            break;
        } else if ((i+1) == COL) {
            flag = true;
        }
    }

    // now we have to check the current column, so we have to move through the row
    for (_UI i = 0; i < ROW; i++) {
        if (board[i][currCol] != MARK) {
            break;
        } else if ((i+1) == COL) {
            flag = true;
        }
    }

    // now check if there even can be a diagonal
    if (currRow == currCol) {
        // check the first diagonal
        for (_UI i = 0; i < ROW; i++) {
            if (board[i][i] != MARK) {
                break;
            } else if ((i+1) == ROW) {
                flag = true;
            }
        }
        // check the oppo diagonal
        for (_UI i = 0; i < ROW; i++) {
            if (board[i][2-i] != MARK) {
                break;
            } else if ((i+1) == ROW) {
                flag = true;
            }
        }
    }
    return flag;
}

void gameLoop(char** BOARD) {
    bool endFlag = false; //this will be the flag to keep track of for when the game is over
    cout << "Player Mark: 'X'\n";
    while (!endFlag) {
        BOARD = playerTurn(BOARD);              //then the player needs to take their turn 
        endFlag = isGameOver(BOARD, PLAYER_MARK);
        if (endFlag) {                  //check if the player won
            drawBoard(BOARD);
            playerWin();
            break;
        }
        BOARD = cpuTurn(BOARD);                 //then its the computer's turn
        endFlag = isGameOver(BOARD, CPU_MARK);
        if (endFlag) {                  //check if the computer wins
            drawBoard(BOARD);
            cpuWin();
            break;
        }
        // now check if there has been a tie
        if (tieCheck()) {
            drawBoard(BOARD);
            tieGame();
        }
    }
}

bool spotTaken(char** board, unsigned spotIndex) {
    return (board[spotIndex/3][spotIndex%3] != '-');
}

void playerWin() {
    cout << "YOU WIN!\n";
}

void cpuWin() {
    cout << "The CPU wins:(\n";
}

bool tieCheck() {
    return (movesMade == 9);
}

void tieGame() {
    cout << "TIE GAME!\n";
}