#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef BATTLESHIP_H
#define BATTLESHIP_H
#define Osprey 5
#define F_sixteen 3
#define A_ten 4
#define B_two 2
#define C_seventeen 5
#define HIT 'X'
#define MISS 'M'
#define AIR '*'
#define player_one person
#define player_two comp

void intro_screen(void);

typedef struct game_board{
    int board[8][8];
    int row;
    int col;
    char symbol;
}game_board;

game_board design_board(game_board player);


void craft_setup(char board[8][8]);


void random_position(char board[8][8], char craft, int direction);

void starting_point(int len_craft, int *row_coord, int *col_coord, int direction);

typedef struct coords{
    int board[8][8];
    int row;
    int column;
    char symbol;
} coords;

coords target(coords player);

short check_target(char board[8][8], int coords);

bool check_status (short craftfall[][5], short player, char craftSymbol, FILE *stream);

int display_winner(int HITS);

#endif //BATTLESHIP_H

