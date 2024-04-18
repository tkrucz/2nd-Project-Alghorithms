#ifndef HEX_2ND_PROJECT_GENERALFUNCTIONS_H
#define HEX_2ND_PROJECT_GENERALFUNCTIONS_H

#include "Define.cpp"

int pawnNumbers(int redPawns, int bluePawns);

bool isBoardCorrect(int redPawns, int bluePawns);

void isBoardCorrectOutput(int redPawns, int bluePawns);

bool isGameOver(char **board, int boardSize);

void isGameOverOutput(char **board, int boardSize, int redPawns, int bluePawns);

void handleCommands(int &cmd, int &boardSize, int &redPawns, int &bluePawns);

#endif //HEX_2ND_PROJECT_GENERALFUNCTIONS_H
