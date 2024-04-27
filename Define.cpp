#define CELL_SIZE 3
#define ENTER '\n'
#define SPACE ' '
#define MINUS 45
#define SMALL_SIGN 60
#define GREATER_SIGN 62
#define BLUE_PAWN 98
#define RED_PAWN 114
#define MAX_BOARD_LENGTH 11

#define DEBUG

enum COMMANDS {
    BOARD_SIZE,
    PAWNS_NUMBER,
    IS_BOARD_CORRECT,
    IS_GAME_OVER,
    IS_BOARD_POSSIBLE,
    CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE,
    CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE,
    CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE,
    CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE,
    CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT,
    CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT,
    CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT,
    CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT
};