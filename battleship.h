#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#include <stdio.h>
#include <stdlib.h>

void intro_screen(void);

typedef struct game_board{
    int board[8][8];
    int row;
    int col;
    char symbol;
}game_board;

game_board design_board(game_board player);


void craft_setup(int board[row][col]);

#endif //BATTLESHIP_H

