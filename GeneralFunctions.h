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

bool isGameOver(char **board, bool **visited, int boardSize); // Return bool value

void isGameOverOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Check wins possibility conditions

bool isBoardPossibleRed(char **board, bool **visited, int boardSize); // Check if board is possible if red won

bool isBoardPossibleBlue(char **board, bool **visited, int boardSize); // Check if board is possible if blue won

bool isBoardPossible(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Return bool value and cout

void isBoardPossibleOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns); // Check board possibility conditions

bool recursiveNaiveCheck(char **board, bool **visited, char tmp, int boardSize, int nMoves); // Recursive check if player can win with naive opponent

bool canWinNaive(char **board, bool **visited, int boardSize, int redPawns, int bluePawns, int cmd); // Begin check for win with naive opponent

void canWinNaiveOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns, int cmd); // Display output for winning with naive opponent

void handleCommands(char **board, bool **visited, int &cmd, int &boardSize, int &redPawns, int &bluePawns); // Evaluate command

bool checkPath(char **board, bool **visited, int boardSize, Position beginning); // DFS Check if there is winning path

void getCommand(int &cmd); // Read the command

#endif //HEX_2ND_PROJECT_GENERALFUNCTIONS_H
