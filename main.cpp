#include "iostream"
#include "GeneralFunctions.h"

using namespace std;

int main() {
    char cell[CELL_SIZE];
    char tmp, command[16];
    int cellIndex = 0, commandIndex = 0;

    int rowLength = 0, boardSize = 0;
    int cmd = -1;
    bool boardBeg = false;

    int bluePawns = 0;
    int redPawns = 0;
    bool inCell = false;

    char boardTmp[MAX_BOARD_LENGTH][MAX_BOARD_LENGTH];
    int rowCounter = 0; //numbers of board rows
    int xIndex = 0, yIndex = 0;
    bool endOfMiddleRow = false;
    bool boardTableFilled = false;

    static int COUNT = 0;

    // Read characters until end of input
    while ((tmp = getchar()) != EOF) {
        if (!inCell) {
            // Check if symbol is starting a new cell
            if (tmp == SMALL_SIGN) {
                inCell = true;
                cellIndex = 0;
                cell[cellIndex++] = tmp; // Start building new cell
            } else if (tmp == MINUS) {
                char next1 = getchar();
                char next2 = getchar();
                // Beginning or ending of boardTmp
                if (next1 == MINUS && next2 == MINUS) {
                    if (boardBeg) { // Ending of board
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
                            boardBeg = false;
                            endOfMiddleRow = false;
                            xIndex = 0;
                            yIndex = 0;
                            rowCounter = 0;
                        }
                    } else { // Beginning of board
                        COUNT++;
                        boardBeg = true;
                        boardTableFilled = false;
                    }
                } else if (next1 == MINUS && next2 == SMALL_SIGN) // Beginning of row
                    inCell = true;
            } else if (tmp == GREATER_SIGN) {
                char next1 = getchar();
                if (next1 == MINUS) {
                    char next2 = getchar();
                    if (next2 == MINUS) {
                        rowLength = 0; // End of row
                        rowCounter++;
                        yIndex = rowCounter;
                        if (endOfMiddleRow) {
                            yIndex = boardSize - 1;
                            xIndex = rowCounter - boardSize + 1;
                        } else
                            xIndex = 0;
                    } else if (next2 == SMALL_SIGN)
                        inCell = true;
                } else if (next1 == ENTER) { //End of middle row
                    rowLength = 0;
                    yIndex = rowCounter;
                    xIndex = 1;
                    endOfMiddleRow = true;
                    rowCounter++;
                }
            }
        } else {
            // Beginning of the cell
            if (cell[0] == SMALL_SIGN && cellIndex == 1 && tmp == SPACE) {
                cellIndex = 0;
                cell[cellIndex++] = tmp;
            } else { // Provide next elements into cell
                cell[cellIndex++] = tmp;
            }
            if (cellIndex == CELL_SIZE) { // If cell contains 3 elements

                if (cell[1] == BLUE_PAWN || cell[1] == RED_PAWN || cell[1] == SPACE) {
                    boardTmp[xIndex++][yIndex--] = cell[1];

                    inCell = false;
                    rowLength++;

                    if (cell[1] == BLUE_PAWN)
                        bluePawns++;
                    else if (cell[1] == RED_PAWN)
                        redPawns++;

                } else {
                    inCell = false;
                }
                if (rowLength > boardSize)
                    boardSize = rowLength;

                cellIndex = 0;
            }
        }

        if (!boardBeg) {
            char **board = new char *[boardSize]; // Array which represents board
            for (int i = 0; i < boardSize; i++)
                board[i] = new char[boardSize];

            bool **visited = new bool *[boardSize]; // Array which represent status of pawns
            for (int i = 0; i < boardSize; i++)
                visited[i] = new bool[boardSize];

            if (boardSize != 0 && !boardTableFilled) {
                for (int i = 0; i < boardSize; i++) {
                    for (int j = 0; j < boardSize; j++)
                        board[i][j] = boardTmp[i][j];
                }
                boardTableFilled = true;
            }

            handleCommands(board, visited, cmd, boardSize, redPawns, bluePawns);

            for (int i = 0; i < boardSize; i++) {
                delete board[i];
            }
            delete[] board;

            for (int i = 0; i < boardSize; i++) {
                delete visited[i];
            }
            delete[] visited;
        }
    }
    return 0;
}