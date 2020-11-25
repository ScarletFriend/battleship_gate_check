#include "battleship.h"

void intro_screen(void){
    printf("Welcome to DOGFIGHT\n");
    printf("RULES OF THE GAME");
    printf("1. This gofight is against you and the computer\n");
    printf("2. You will first pick coordinates within an 8X8 board\n");
    printf("3. You must also determine the direction of the aircraft: [h]orizontal or [v]ertical\n");
    printf("4.. You have 5 different aircraft to place:\n");
    printf("\tthe [C]-17 of 5 spaces \n");
    printf("\t the [A]-10 of 4 spaces \n");
    printf("\t the [F]-16 of three spaces\n");
    printf("\t the [B]-2 of 2 spaces \n");
    printf("\t the [O]sprey of 5 spaces \n");
    printf("A '*' represents the air A 'H' represents a hit and a 'M' represents a miss\n");
    printf("5.The game will begin and you must give coordinates within the 8X8 board\n");
    printf("6.First player to shootdown all the aircrafts wins\n\n\n\n");

}

game_board design_board(game_board player){
    int row_i = 0;
    int col_i = 0;
    printf(" 1 2 3 4 5 6 7 8\n");
    for(row_i = 0; row_i < player.row; row_i++){
        printf("%d ", row_i);
        for(col_i = 0; col_i < player.col; col_i++){
        player.board[row_i][col_i] = player.symbol;
        printf("%c ", player.board[row_i][col_i]);
    }
    printf("\n");
    }
}

void craft_setup(int board[8][8]){
    int craft_type = 1;
    int craft_length = 0; 
    int row = 0;
    int col = 0; 
    int direction = 0; 
    int count = 0;
    for(craft_type = 1; craft_type <= 5; craft_type++){
        if (craft_type == 1){
            printf("Please enter coordinates you would like to start your C-17(5).\n\n");
            craft_length = 5;
        }
        else if(craft_type == 2){
            printf("Please enter coordinates you would like to start your A-10(4).\n\n");
            craft_length = 4;
        }
        else if(craft_type == 3){
             printf("Please enter coordinates you would like to start your F-16(3).\n\n");
            craft_length = 3;
        }
        else if(craft_type == 4){
             printf("Please enter coordinates you would like to start your B-2(2).\n\n");
            craft_length = 2;
        }
        else if(craft_type == 5){
             printf("Please enter coordinates you would like to start your Osprey(5).\n\n");
            craft_length = 5;
        }
        printf("Please enter the direction of your craft\n");
        printf("\tv for vertical or h for horizontal")

    }
}



int main(){
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

    craft_setup(int board[row][col]);
}