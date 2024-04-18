#include "iostream"
#include "GeneralFunctions.h"

using namespace std;

int pawnNumbers(int redPawns, int bluePawns) {
    return redPawns + bluePawns;
}

bool isBoardCorrect(int redPawns, int bluePawns) {
    if (redPawns == bluePawns + 1 || redPawns == bluePawns)
        return true;
    else
        return false;
}

void isBoardCorrectOutput(int redPawns, int bluePawns) {
    if (isBoardCorrect(redPawns, bluePawns))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

bool isGameOver(char **board, int boardSize) {
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j] << ", ";
        }
    return false;
}

void isGameOverOutput(int redPawns, int bluePawns) {
    if (!isBoardCorrect(redPawns, bluePawns)) {
        cout << "NO" << endl;
    } else if (pawnNumbers(redPawns, bluePawns) == 0) {
        cout << "NO" << endl;
//    } else if (isGameOver(board, boardSize)) {

    } else
        cout << "NO - not this simple cases" << endl;
}

void handleCommands(int &cmd, int &boardSize, int &redPawns, int &bluePawns) {
    if (cmd != -1) {
        if (cmd == BOARD_SIZE)
            cout << boardSize << endl;
        else if (cmd == PAWNS_NUMBER)
            cout << pawnNumbers(redPawns, bluePawns) << endl;
        else if (cmd == IS_BOARD_CORRECT) {
            isBoardCorrectOutput(redPawns, bluePawns);
        } else if (cmd == IS_GAME_OVER) {
            isGameOverOutput( redPawns, bluePawns);
        }
        cmd = -1;
        redPawns = 0;
        bluePawns = 0;
    }
}