#ifndef HEX_2ND_PROJECT_GENERALFUNCTIONS_H
#define HEX_2ND_PROJECT_GENERALFUNCTIONS_H

#include "stack"
#include "Define.cpp"

struct Position {
    int row;
    int column;
};

int pawnNumbers(int redPawns, int bluePawns); // Return pawns number

bool isBoardCorrect(int redPawns, int bluePawns); // Check if number of pawns is "legal"

void isBoardCorrectOutput(int redPawns, int bluePawns); // Display output

bool isGameOverRed(char **board, bool **visited, int boardSize); // Check if red pawns won

bool isGameOverBlue(char **board, bool **visited, int boardSize); // Check if blue pawns won

bool isGameOver(char **board, bool **visited, int boardSize); // Return bool value ad cout

void isGameOverOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Check wins conditions

bool isBoardPossibleRed(char **board, bool **visited, int boardSize); // Check if board is possible if red won

bool isBoardPossibleBlue(char **board, bool **visited, int boardSize); // Check if board is possible if blue won

bool isBoardPossible(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Return bool value

void isBoardPossibleOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Check board possibility conditions

void handleCommands(char **board, bool **visited, int &cmd, int &boardSize, int &redPawns, int &bluePawns);

bool checkPath(char **board, bool **visited, int boardSize, Position beginning);

#endif //HEX_2ND_PROJECT_GENERALFUNCTIONS_H
