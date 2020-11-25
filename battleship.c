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

void craft_setup(int board[8][8])
{

    int craft_type = 1;
    int craft_length = 0; 
    int row = 0;
    int col = 0; 
    int direction = 0; 
    int count = 0;
    char* typestr[] = { "Craft type 0", "C-17", "A-10", "F-16", "B-2", "Osprey" };
    char* tag = "0CAFBO"; 

    for (craft_type = 0; craft_type <= 5; craft_type++)
    {
        craft_length = 7 - craft_type;
        prinf("Please enter where you would like to start you %s (%s) spots).\n\n",typestr[craft_type], craft_length);

        printf("Choose the direction of your craft. v is vertical & h is horizontal\n\n");
        scanf("%c ",&direction);

        printf("Please choose a row number.\n");
        scanf("%d",&row);
        printf("Please choose a column number.\n");
        scanf("%d",&col);

        if ((direction == 'v') && (row + craft_length <= 8))
        {
            board[row+count][col] = tag[craft_type];
        }
        else if((direction == 'h') && (col + craft_length <= 8))
        {
            board[row][col+count] = tag[craft_type];
        }
        else{
            printf("PLease reenter appropraite coordinates.\n");
        }
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

    int board[8][8];
    craft_setup(board[8][8]);
}