#ifndef TIC_HPP
#define TIC_HPP

#define ROW 3
#define COL 3

void drawBoard(char**);
char** playerTurn(char**);
char** initBoard(char**);
char** changeBoard(char**, char, unsigned);
char** cpuTurn(char**);
char** cpuTurnEasy(char**);
char** cpuTurnHard(char**);
bool isGameOver(char**, char);
void gameLoop(char**);
void playerWin();
void cpuWin();
bool spotTaken(char**, unsigned);
bool tieCheck(char**);
void tieGame();

#endif