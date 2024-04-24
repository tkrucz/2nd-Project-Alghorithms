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

bool isGameOverRed(char **board, bool **visited, int boardSize) {
//#ifdef DEBUG
//    for (int i = 0; i < boardSize; ++i) {
//        for (int j = 0; j < boardSize; ++j) {
//            if (board[i][j] == ' ')
//                cout << '_';
//            else
//                cout << board[i][j];
//        }
//        cout << endl;
//    }
//#endif
    for (int j = 0; j < boardSize; j++) {
        if (board[0][j] == 'r')
            if (checkPath(board, visited, boardSize, {0, j}))
                return true;
    }
    return false;
}

bool isGameOverBlue(char **board, bool **visited, int boardSize) {
    for (int j = 0; j < boardSize; j++) {
        if (board[j][0] == 'b')
            if (checkPath(board, visited, boardSize, {j, 0}))
                return true;
    }
    return false;
}

bool isGameOver(char **board, bool **visited, int boardSize) {
    if (isGameOverRed(board, visited, boardSize)) {
        cout << "YES RED" << endl;
        return true;
    } else if (isGameOverBlue(board, visited, boardSize)) {
        cout << "YES BLUE" << endl;
        return true;
    }
    return false;
}

void isGameOverOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns) {
    if (!isBoardCorrect(redPawns, bluePawns)) {
        cout << "NO" << endl;
    } else if (pawnNumbers(redPawns, bluePawns) == 0) {
        cout << "NO" << endl;
    } else if (isGameOver(board, visited, boardSize)) {}
    else if (!isGameOver(board, visited, boardSize)) {
        cout << "NO" << endl;
    } else
        cout << "NO - not this simple cases" << endl;
}

void handleCommands(char **board, bool **visited, int &cmd, int &boardSize, int &redPawns, int &bluePawns) {
    if (cmd != -1) {
        if (cmd == BOARD_SIZE)
            cout << boardSize << endl;
        else if (cmd == PAWNS_NUMBER)
            cout << pawnNumbers(redPawns, bluePawns) << endl;
        else if (cmd == IS_BOARD_CORRECT) {
            isBoardCorrectOutput(redPawns, bluePawns);
        } else if (cmd == IS_GAME_OVER) {
            isGameOverOutput(board, visited, boardSize, redPawns, bluePawns);
        }
        cmd = -1;
        redPawns = 0;
        bluePawns = 0;
        boardSize=0;
    }
}

bool checkPath(char **board, bool **visited, int boardSize, Position beginning) {


    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; ++j) {
            visited[i][j] = false;
        }
    }

    stack<Position> path;
    path.push(beginning);
    char tmp = board[beginning.row][beginning.column];

    while (!path.empty()) {
        Position currentPosition = path.top();
        path.pop();
        if (board[currentPosition.row][currentPosition.column] == 'r' && currentPosition.row == boardSize - 1) {
            return true;
        } else if (board[currentPosition.row][currentPosition.column] == 'b' &&
                   currentPosition.column == boardSize - 1) {
            return true;
        }

        Position neighbours[6] = {{1,  1},
                                  {0,  1},
                                  {-1, 0},
                                  {-1, -1},
                                  {0,  -1},
                                  {1,  0}};
        for (int i = 0; i < 6; i++) {
            int row = currentPosition.row + neighbours[i].row;
            int column = currentPosition.column + neighbours[i].column;
            if (0 <= row && 0 <= column && column < boardSize && row < boardSize && !visited[row][column] &&
                tmp == board[row][column]) {
                visited[row][column] = true;
                path.push({row, column});
            }
        }
    }
    return false;
}