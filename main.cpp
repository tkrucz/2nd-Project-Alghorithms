#include "iostream"
#include "GeneralFunctions.h"
#include "Define.cpp"

using namespace std;

int main() {
    char cell[CELL_SIZE], command[4];
    char tmp;
    int cellIndex = 0, index = 0;
    int rowLength = 0;
    int boardSize = 0;
    int cmd = -1;
    bool boardBeg = false;

    int bluePawns = 0;
    int redPawns = 0;
    bool inCell = false;

    // Read characters until end of input
    while ((tmp = getchar()) != EOF) {
        if (!inCell) {
            // Check if starting a new cell
            if (tmp == SMALL_SIGN) {
                inCell = true;
                cellIndex = 0;
                cell[cellIndex++] = tmp; // Start building new cell
            } else if (tmp == MINUS) {
                char next1 = getchar();
                char next2 = getchar();
                if (next1 == MINUS && next2 == MINUS) {
                    if (boardBeg) {
                        tmp = getchar();
                        if (tmp == ENTER) {
                            while ((tmp = getchar()) != ENTER && index != 4)
                                command[index++] = tmp;
                            if (command[0] == 'B')
                                cmd = BOARD_SIZE;
                            else if (command[0] == 'P')
                                cmd = PAWNS_NUMBER;
                            else if (command[0] == 'I' && command[3] == 'B')
                                cmd = IS_BOARD_CORRECT;
                            else if (command[0] == 'I' && command[3] == 'G')
                                cmd = IS_GAME_OVER;
                            boardBeg = false;
                        }
                    } else
                        boardBeg = true;
                } else if (next1 == MINUS && next2 == SMALL_SIGN)
                    inCell = true;
            } else if (tmp == GREATER_SIGN) {
                char next1 = getchar();
                if (next1 == MINUS) {
                    char next2 = getchar();
                    if (next2 == MINUS)
                        rowLength = 0;
                    else if (next2 == SMALL_SIGN)
                        inCell = true;
                } else if (next1 == ENTER)
                    rowLength = 0;
            }
        } else {
            if (cell[0] == SMALL_SIGN && cellIndex == 1 && tmp == SPACE) {
                cellIndex = 0;
                cell[cellIndex++] = tmp;
            } else {
                cell[cellIndex++] = tmp;
            }
            if (cellIndex == CELL_SIZE) {
                if (cell[1] == BLUE_PAWN || cell[1] == RED_PAWN || cell[1] == SPACE) {
                    inCell = false;
                    rowLength++;

                    if (cell[1] == BLUE_PAWN)
                        bluePawns++;
                    else if (cell[1] == RED_PAWN)
                        redPawns++;

                } else
                    inCell = false;

                cellIndex = 0;
                if (rowLength > boardSize)
                    boardSize = rowLength;
            }
        }
        handleCommands(cmd,boardSize,redPawns,bluePawns);
    }
    return 0;
}