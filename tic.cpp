#include "pch.h"

#define WIDTH 3
#define PLAYER_MARK 'X'
#define CPU_MARK '0'

void drawBoard(char **board) {
    cout << "Current Game Board:\n";
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

void playerTurn(char **board) {
    drawBoard(board);
    unsigned playerChoice; 
    char playerMark = PLAYER_MARK;
    cout << "Player Mark: 'X'\n";
    do {
        cout << "What position of the board do you want to play (1-9): ";
        cin >> playerChoice;
    } while (playerChoice < 1 || playerChoice > 9);
    playerChoice--;
    board = changeBoard(board, playerChoice, PLAYER_MARK);
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
    unsigned num;
    do {
        num = rand() % 9;
    } while (board[num/3][num%3] != '-');
    return changeBoard(board, num, CPU_MARK);
}

char** changeBoard(char** board, unsigned NUM, char playerMark) {
    board[NUM/3][NUM%3] = playerMark;
    return board;
}

bool isGameOver(char** board, char check, unsigned ) {
    bool flag = false;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == check) {
                
            }
        }
    }

    return flag;
}