#include "iostream"
#include "GeneralFunctions.h"

using namespace std;

int main() {
    char cell[CELL_SIZE];
    char tmp;
    int cellIndex = 0;

    int rowLength = 0, boardSize = 0; // Row length used to calculate boardSize
    int cmd = -1;
    bool boardBeg = false; // Beginning of board
    bool haveCmd = false; // We have command

    int bluePawns = 0;
    int redPawns = 0;
    bool inCell = false;

    char boardTmp[MAX_BOARD_LENGTH][MAX_BOARD_LENGTH];
    int rowCounter = 0; //numbers of board rows
    int xIndex = 0, yIndex = 0;
    bool endOfMiddleRow = false;
    bool boardTableFilled = false;

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
                if (next1 == MINUS && next2 == MINUS) { // Beginning or ending of boardTmp
                    if (boardBeg) { // Ending of board
                        getCommand(cmd);
                        boardBeg = false;
                        endOfMiddleRow = false;
                        haveCmd = true;
                        xIndex = 0;
                        yIndex = 0;
                        rowCounter = 0;
                    } else { // Beginning of board
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
                    } else if (next2 == SMALL_SIGN) // Skip this symbol >-<
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
                cell[cellIndex++] = tmp; // Set space as first element of cell
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

        if (!boardBeg && haveCmd) {
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
            haveCmd = false;

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