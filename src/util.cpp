// #include "../inc/util.hpp"

// #define WIDTH 3
// #define PLAYER_MARK 'X'
// #define CPU_MARK '0'
// #define _UI unsigned

// char playerMark = PLAYER_MARK;
// char cpuMark = CPU_MARK;
// _UI PLAYER_CHOICE = 0;
// _UI CPU_CHOICE = 0;
// _UI currRow = 0; 
// _UI currCol = 0;
// _UI movesMade = 0;

// void drawBoard(char **board) {
//     for (int i=0; i<ROW; i++) {
//         for (int j=0; j<COL; j++) {
//             cout << right << setw(WIDTH) << board[i][j];
//             if (j!=2) {
//                 cout << right << setw(WIDTH) << '|';
//             }
//         }
//         cout << '\n';
//     }
// }

// char** playerTurn(char **board) {
//     drawBoard(board);
//     bool inputFlag = true;
//     while(inputFlag) { // validation loop with two different conditions
//         cout << "What position of the board do you want to play (1-9): ";
//         cin >> PLAYER_CHOICE;

//         if (PLAYER_CHOICE < 1 || PLAYER_CHOICE > 9) {
//             cout << "ERROR: enter number in valid range\n";
//         }
//         else if (!spotTaken(board, --PLAYER_CHOICE)) {
//             inputFlag = false;
//         }
//         else {
//             cout << "ERROR: spot was taken. Try Again.\n";
//         }
//     }
//     movesMade++;
//     return changeBoard(board, PLAYER_MARK, PLAYER_CHOICE);
// }

// char** initBoard(char** board) {
//     board = new char*[ROW];
//     for (int i = 0; i < ROW; i++) {
//         board[i] = new char[COL];
//     }
//     for (int i = 0; i < ROW; i++) {
//         for (int j = 0; j < COL; j++) {
//             board[i][j] = '-';
//         }
//     }
//     return board;
// }

// char** cpuTurn(char** board, bool FLAG) {
//     drawBoard(board);
//     movesMade++;
//     cout << "Computer is Thinking...\n";
//     // _UI delayTime = (rand()%2)+1;
//     // sleep_until(system_clock::now() + seconds(delayTime));
//     if (FLAG) {
//         return cpuTurnHard(board);
//     } else {
//         return cpuTurnEasy(board);
//     }
// }

// char** cpuTurnEasy(char** board) {
//     do {
//         CPU_CHOICE = rand() % 9;
//     } while (spotTaken(board, CPU_CHOICE));
//     return changeBoard(board, CPU_MARK, CPU_CHOICE);
// }

// char** cpuTurnHard(char** board) {
//     // basically we want to go through the board and find what spots are still available
//     // then we want to see if the player moves there, would they win
//     //      so we want to find all the possible outcomes of all the spots that the player could play at
//     // then if the player could win there, then the CPU should play there

//     // first, loop through all the spots and see if there are any where the computer could win

//     for (int i = 0; i < 9; i++) {
//         // 1) if the spot is already taken, then we have to move through the loop 
//         // otherwise, we can check the spot
//         if (!spotTaken(board, i)) {
//             // so the spot isn't taken. First we move the players mark to the spot to see if they would win
//             board = changeBoard(board, CPU_MARK, i);
//             if (isGameOver(board, CPU_MARK)) {
//                 return board;
//             }
//             // if we didn't leave the function, then we should change the board back
//             board = changeBoard(board, '-', i);
//         }
//     }

//     for (int i = 0; i < 9; i++) {
//         // 1) if the spot is already taken, then we have to move through the loop 
//         // otherwise, we can check the spot
//         if (!spotTaken(board, i)) {
//             // so the spot isn't taken. First we move the players mark to the spot to see if they would win
//             board = changeBoard(board, PLAYER_MARK, i);
//             if (isGameOver(board, PLAYER_MARK)) {
//                 return changeBoard(board, CPU_MARK, i);
//             }
//             // if we didn't leave the function, then we should change the board back
//             board = changeBoard(board, '-', i);
//         }
//     }
//     // if we get to this spot in the whole loop, then there were no possibilities of the player winning. 
//     // then we can just pick a random spot
//     return cpuTurnEasy(board);
// }

// char** changeBoard(char** board, char MARK, _UI CHOICE) {
//     currRow = CHOICE/ROW;
//     currCol = CHOICE%COL;
//     board[currRow][currCol] = MARK;
//     return board;
// }

// bool isGameOver(char** board, char MARK) {
//     bool flag = false; 
//     // we will use the current mark and choice to check the row, column, and diagonals to see if there was a win 
//     // first check the row, so move through the columns of the current row
//     for (_UI i = 0; i < COL; i++) {
//         if (board[currRow][i] != MARK) {
//             break;
//         } else if ((i+1) == COL) {
//             flag = true;
//         }
//     }

//     // now we have to check the current column, so we have to move through the row
//     for (_UI i = 0; i < ROW; i++) {
//         if (board[i][currCol] != MARK) {
//             break;
//         } else if ((i+1) == COL) {
//             flag = true;
//         }
//     }

//     // now check if there even can be a diagonal
//     if (currRow == currCol) {
//         // check the first diagonal
//         for (_UI i = 0; i < ROW; i++) {
//             if (board[i][i] != MARK) {
//                 break;
//             } else if ((i+1) == ROW) {
//                 flag = true;
//             }
//         }
//         // check the oppo diagonal
//         for (_UI i = 0; i < ROW; i++) {
//             if (board[i][2-i] != MARK) {
//                 break;
//             } else if ((i+1) == ROW) {
//                 flag = true;
//             }
//         }
//     }

//     // now check if there is a tie
//     flag = tieCheck(board);

//     return flag;
// }

// void gameLoop(char** BOARD) {
//     bool endFlag = false; //this will be the flag to keep track of for when the game is over
//     bool diffFlag; 
//     cout << "What difficulty do you want to play?\n";
//     cout << "\t0) Easy\n";
//     cout << "\t1) Hard\n";
//     cout << "Enter your choice: ";
//     cin >> diffFlag;
//     cout << "Player Mark: 'X'\n";
//     while (!endFlag) {
//         BOARD = playerTurn(BOARD);              //then the player needs to take their turn 
//         cout << "Index: (" << currRow << ", " << currCol << ")\n";
//         endFlag = isGameOver(BOARD, PLAYER_MARK);
//         if (endFlag) {                  //check if the player won
//             drawBoard(BOARD);
//             playerWin();
//             break;
//         }
//         BOARD = cpuTurn(BOARD, diffFlag);                 //then its the computer's turn
//         cout << "Index: (" << currRow << ", " << currCol << ")\n";
//         endFlag = isGameOver(BOARD, CPU_MARK);
//         if (endFlag) {                  //check if the computer wins
//             drawBoard(BOARD);
//             cpuWin();
//             break;
//         }
//         // now check if there has been a tie
//         if (tieCheck(BOARD)) {
//             drawBoard(BOARD);
//             tieGame();
//             endFlag = true;
//         }
//     }
// }

// bool spotTaken(char** board, unsigned spotIndex) {
//     return (board[spotIndex/3][spotIndex%3] != '-');
// }

// void playerWin() {
//     cout << "YOU WIN!\n";
// }

// void cpuWin() {
//     cout << "The CPU wins:(\n";
// }

// bool tieCheck(char** board) {
//     // loop through all of the indices. If any of the spot's ARE NOT TAKEN, then the game is not currently over
//     for (int i = 0; i < 9; i++) {
//         if (!spotTaken(board, i)) {
//             return false;
//         }
//     }

//     return true;
// }

// void tieGame() {
//     cout << "TIE GAME!\n";
// }