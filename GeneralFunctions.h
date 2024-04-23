#ifndef HEX_2ND_PROJECT_GENERALFUNCTIONS_H
#define HEX_2ND_PROJECT_GENERALFUNCTIONS_H

#include "stack"
#include "Define.cpp"

struct Position{
    int row;
    int column;
};

int pawnNumbers(int redPawns, int bluePawns);

bool isBoardCorrect(int redPawns, int bluePawns);

void isBoardCorrectOutput(int redPawns, int bluePawns);

bool isGameOverRed(char **board, int boardSize);

bool isGameOverBlue(char **board, int boardSize);

bool isGameOver(char **board, int boardSize);

void isGameOverOutput(char **board, int boardSize, int redPawns, int bluePawns);

void handleCommands(char **board, int &cmd, int &boardSize, int &redPawns, int &bluePawns);

bool checkPath(char ** board, int boardSize, Position beginning);

#endif //HEX_2ND_PROJECT_GENERALFUNCTIONS_H
