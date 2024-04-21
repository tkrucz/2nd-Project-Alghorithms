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

bool isGameOverRed(char **board, int boardSize) { //TO DO!
    for(int j=0; j<boardSize; j++){
        if(board[j][0] == 'r')
            checkPath(board,boardSize,{j,0});

    }
}

bool isGameOverBlue(char **board, int boardSize) { //TO DO!
    for(int j=0; j<boardSize; j++){
        if(board[0][j] == 'b')
            checkPath(board,boardSize,{0,j});

    }
}

bool isGameOver(char **board, int boardSize){
    if(isGameOverRed(board,boardSize))
        return true;
    else if(isGameOverBlue(board,boardSize))
        return true;
    return false;
}

void isGameOverOutput(char **board, int boardSize, int redPawns, int bluePawns) {
    if (!isBoardCorrect(redPawns, bluePawns)) {
        cout << "NO" << endl;
    } else if (pawnNumbers(redPawns, bluePawns) == 0) {
        cout << "NO" << endl;
    } else if (isGameOver(board, boardSize)) {
        cout << "YES" << endl;
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
            //isGameOverOutput(board,boardSize,redPawns, bluePawns);
        }
        cmd = -1;
        redPawns = 0;
        bluePawns = 0;
    }
}

bool checkPath(char **board, int boardSize, Position beginning) {
    bool visited[boardSize][boardSize];

    for(int i=0; i<boardSize; i++){
        for (int j = 0; j < boardSize; ++j) {
            visited[i][j]=false;
        }
    }

    stack<Position> path;
    path.push(beginning);
    char tmp = board[beginning.row][beginning.column];

    while (!path.empty()) {
        Position currentPosition = path.top();
        path.pop();
        if(board[currentPosition.row][currentPosition.column] == 'r' && currentPosition.column == boardSize - 1){
            return true;
        }
        else if(board[currentPosition.row][currentPosition.column] == 'b' && currentPosition.row == boardSize - 1){
            return true;
        }

        Position neighbours[6] = {{1,  1}, {0,  1},{-1, 0},
                                  {-1, -1}, {0,  -1},{1,  0}};
        for (int i = 0; i < 6; i++) {
            int row=currentPosition.row + neighbours[i].row;
            int column=currentPosition.column + neighbours[i].column;
            if(!visited[row][column] && tmp == board[row][column] && 0 <= row && row < boardSize && 0 <= column && column < boardSize) {
                visited[row][column] = true;
                path.push({row,column});
            }
        }
    }
    return false;
}