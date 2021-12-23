#ifndef TIC_HPP
#define TIC_HPP

#define ROW 3
#define COL 3

void drawBoard(char**);
void playerTurn(char**);
char** initBoard(char**);
char** changeBoard(char**, unsigned, char);
char** cpuTurn(char**);
bool isGameOver(char**, char);

#endif