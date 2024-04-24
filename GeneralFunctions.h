#ifndef HEX_2ND_PROJECT_GENERALFUNCTIONS_H
#define HEX_2ND_PROJECT_GENERALFUNCTIONS_H

#include "stack"
#include "Define.cpp"

struct Position {
    int row;
    int column;
};

int pawnNumbers(int redPawns, int bluePawns);

bool isBoardCorrect(int redPawns, int bluePawns);

void isBoardCorrectOutput(int redPawns, int bluePawns);

bool isGameOverRed(char **board, bool **visited, int boardSize);

bool isGameOverBlue(char **board, bool **visited, int boardSize);

bool isGameOver(char **board, bool **visited, int boardSize);

void isGameOverOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns);

void handleCommands(char **board, bool **visited, int &cmd, int &boardSize, int &redPawns, int &bluePawns);

bool checkPath(char **board, bool **visited, int boardSize, Position beginning);

#endif //HEX_2ND_PROJECT_GENERALFUNCTIONS_H
