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
    for (int i = 0; i < boardSize; i++) {
        if (board[0][i] == 'r')
            if (checkPath(board, visited, boardSize, {0, i}))
                return true;
    }
    return false;
}

bool isGameOverBlue(char **board, bool **visited, int boardSize) {
    for (int i = 0; i < boardSize; i++) {
        if (board[i][0] == 'b')
            if (checkPath(board, visited, boardSize, {i, 0}))
                return true;
    }
    return false;
}

bool isGameOver(char **board, bool **visited, int boardSize) {
    if (isGameOverRed(board, visited, boardSize)) {
        return true;
    } else if (isGameOverBlue(board, visited, boardSize)) {
        return true;
    }
    return false;
}

void isGameOverOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns) {
    if (!isBoardCorrect(redPawns, bluePawns)) {
        cout << "NO" << endl;
    } else if (pawnNumbers(redPawns, bluePawns) == 0) {
        cout << "NO" << endl;
    } else if (isGameOverRed(board, visited, boardSize)) {
        cout << "YES RED" << endl;
    } else if (isGameOverBlue(board, visited, boardSize)) {
        cout << "YES BLUE" << endl;
    } else if (!isGameOver(board, visited, boardSize)) {
        cout << "NO" << endl;
    }
}

bool isBoardPossibleRed(char **board, bool **visited, int boardSize) {
    if (isGameOverRed(board, visited, boardSize)) {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == 'r') {
                    board[i][j] = ' ';
                    if (!isGameOverRed(board, visited, boardSize)) {
                        board[i][j] = 'r';
                        return true;
                    }
                    board[i][j] = 'r';
                }
            }
        }
        return false;
    }
    return true;
}

bool isBoardPossibleBlue(char **board, bool **visited, int boardSize) {
    if (isGameOverBlue(board, visited, boardSize)) {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] == 'b') {
                    board[i][j] = ' ';
                    if (!isGameOverBlue(board, visited, boardSize)) {
                        board[i][j] = 'b';
                        return true;
                    }
                    board[i][j] = 'b';
                }
            }
        }
        return false;
    }
    return true;
}

bool isBoardPossible(char **board, bool **visited, int boardSize, int redPawns, int bluePawns) {
    if (isGameOverRed(board, visited, boardSize)) {
        if (redPawns == bluePawns)
            return false;
        if (isBoardPossibleRed(board, visited, boardSize)) {
            cout << "YES" << endl;
            return true;
        }
    } else if (isGameOverBlue(board, visited, boardSize)) {
        if (bluePawns < redPawns)
            return false;
        if (isBoardPossibleBlue(board, visited, boardSize)) {
            cout << "YES" << endl;
            return true;
        }
    }
    return false;
}

void isBoardPossibleOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns) {
    if (!isBoardCorrect(redPawns, bluePawns)) {
        cout << "NO" << endl;
    } else if (pawnNumbers(redPawns, bluePawns) == 0) {
        cout << "YES" << endl;
    } else if (!isGameOver(board, visited, boardSize))
        cout << "YES" << endl;
    else if (isBoardPossible(board, visited, boardSize, redPawns, bluePawns)) {}
    else if (!isBoardPossible(board, visited, boardSize, redPawns, bluePawns)) {
        cout << "NO" << endl;
    }
}

bool recursiveNaiveCheck(char **board, bool **visited, char tmp, int boardSize, int nMoves) {
    bool redWon=false;
    bool blueWon=false;

    if ((tmp == 'r' && isGameOverRed(board, visited, boardSize)) ||
        (tmp == 'b' && isGameOverBlue(board, visited, boardSize))) {
        if (tmp == 'r')
            redWon = true;
        else
            blueWon = true;
    }

    if (((tmp == 'r' && redWon) || (tmp == 'b' && blueWon)) && nMoves == 0) {
        return true;
    } else if ((tmp == 'r' && redWon) || (tmp == 'b' && blueWon))
        return false;

    if(nMoves <= 0)
        return false;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ') {
                board[i][j] = tmp;
                if (recursiveNaiveCheck(board, visited, tmp, boardSize, nMoves - 1)) {
                    board[i][j] = ' ';
                    return true;
                }
                board[i][j] = ' ';
            }
        }
    }
    return false;
}

bool canWinNaive(char **board, bool **visited, int boardSize, int redPawns, int bluePawns, int cmd) {
    char tmp;
    int nMoves = 0, emptyCell = 0;

    if (cmd == CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE || cmd == CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE)
        tmp = 'r';
    else
        tmp = 'b';

    if (cmd == CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE || cmd == CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE)
        nMoves = 1;
    else
        nMoves = 2;

    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j] == ' ')
                emptyCell++;
        }
    }

    if (emptyCell == 0) // No empty cell so no one can win in 1/2 move
        return false;

    if(redPawns == bluePawns){ // Red start
        if(tmp == 'r' && emptyCell < (( 2 * nMoves) - 1 )) // Need 1 or 3 free cells
            return false;
        if(tmp == 'b' && emptyCell < ( 2 * nMoves )) // Need 2 or 4 free cells
            return false;
    }

    if(redPawns == bluePawns + 1){ // Blue start
        if(tmp == 'r' && emptyCell < ( 2 * nMoves)) // Need 2 or 4 free cells
            return false;
        if(tmp == 'b' && emptyCell < (( 2 * nMoves) - 1 )) // Need 1 or 3 cells
            return false;
    }

    return recursiveNaiveCheck(board, visited, tmp, boardSize, nMoves);
}

void canWinNaiveOutput(char **board, bool **visited, int boardSize, int redPawns, int bluePawns, int cmd) {
    if (!isBoardCorrect(redPawns, bluePawns))
        cout << "NO" << endl;
    else if (isGameOver(board, visited, boardSize))
        cout << "NO" << endl;
    else if (canWinNaive(board, visited, boardSize, redPawns, bluePawns,cmd))
        cout << "YES" << endl;
    else if (!canWinNaive(board, visited, boardSize, redPawns, bluePawns,cmd))
        cout << "NO" << endl;
}

void handleCommands(char **board, bool **visited, int &cmd, int &boardSize, int &redPawns, int &bluePawns) {
    if (cmd != -1) {
        if (cmd == BOARD_SIZE)
            cout << boardSize << endl;
        else if (cmd == PAWNS_NUMBER)
            cout << pawnNumbers(redPawns, bluePawns) << endl;
        else if (cmd == IS_BOARD_CORRECT)
            isBoardCorrectOutput(redPawns, bluePawns);
        else if (cmd == IS_GAME_OVER)
            isGameOverOutput(board, visited, boardSize, redPawns, bluePawns);
        else if (cmd == IS_BOARD_POSSIBLE)
            isBoardPossibleOutput(board, visited, boardSize, redPawns, bluePawns);
        else if (cmd == 5 ) {
            canWinNaiveOutput(board, visited, boardSize, redPawns, bluePawns, cmd);
            cmd++;
            while (cmd < 9) {
                canWinNaiveOutput(board, visited, boardSize, redPawns, bluePawns, cmd);
                cmd++;
            }
            cout << endl;
        }
        cmd = -1;
        redPawns = 0;
        bluePawns = 0;
        boardSize = 0;
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

void getCommand(int &cmd) {
    char tmp, command[16];
    int commandIndex = 0;
    tmp = getchar();
    if (tmp == ENTER || tmp == '\r') {
        if (tmp == '\r') getchar();
        while ((tmp = getchar()) != ENTER && commandIndex != 16)
            command[commandIndex++] = tmp;
        if (command[0] == 'B')
            cmd = BOARD_SIZE;
        else if (command[0] == 'P')
            cmd = PAWNS_NUMBER;
        else if (command[0] == 'I' && command[3] == 'B' && command[9] == 'C')
            cmd = IS_BOARD_CORRECT;
        else if (command[0] == 'I' && command[3] == 'G')
            cmd = IS_GAME_OVER;
        else if (command[0] == 'I' && command[3] == 'B' && command[9] == 'P')
            cmd = IS_BOARD_POSSIBLE;
        else if (command[0] == 'C' && command[4] == 'R' && command[15] == '1')
            cmd = CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE;
        else if (command[0] == 'C' && command[4] == 'B' && command[15] == '1')
            cmd = CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE;
        else if (command[0] == 'C' && command[4] == 'R' && command[15] == '2')
            cmd = CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE;
        else if (command[0] == 'C' && command[4] == 'B' && command[15] == '2')
            cmd = CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE;
    }
}