#include "battleship.h"

int main(void){
    intro_screen;
    FILE *outfile = NULL;
    outfile = fopen("dogfight.log", "w");
    
    game_board person, comp;

    person.symbol = '*';
    person.row = 8;
    person.col = 8;
    comp.symbol = '*';
    comp.row = 8;
    comp.col = 8;

    design_board(person);
    design_board(comp);

    int board[8][8];
    craft_setup(board[8][8]);

    int direction;
    random_position(board[8][8], 'O', direction);
    random_position(board[8][8], 'F', direction);
    random_position(board[8][8], 'A', direction);
    random_position(board[8][8], 'B', direction);
    random_position(board[8][8], 'C', direction);
 int HITS = 0;
 short player = 0;
 
 while(true){
     fprintf(OutStream.WRITE, "Player %d goes \n", player + 1);
     
     switch(player){
        case player_one:
            design_board(person, false);
            do{
                int targ = coords target;
            int check = check_target(board.comp, targ);
            if{check == -1){
                printf("Try again\n");
            }
            }
             while (check == -1);
            char craftsymbol = board[targ.row][targ.column].symbol;
            break;

            case player_two:
              design_board(person, true);
 
    if(HITS == 19){
   
    display_winner(HITS);
    }
    else {return true;
    }
}