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
    printf("6.First player to shootdown all the aircrafts wins\n");
    printf("Press enter to begin!!\n\n\n\n");
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

void craft_setup(char board[8][8])
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
            printf("Please reenter appropraite coordinates.\n");
        }
    }
}


void starting_point(int len_craft, int *row_coord, int *col_coord, int direction){
    switch(direction){
        case 0:
            *row_coord = rand () % 8;
            *col_coord = rand () % (8 - len_craft +1);
            break;
        case 1:
            *row_coord = ran () % (8 - len_craft +1);
            *col_coord = rand () % 10;
            break;

    }
}

void random_position(char board[8][8], char craft, int direction)
{
     int row_coord = 0; 
     int col_coord = 0;
     int size = 0;
     int count = 0;
     int row_test= 0;
     int col_test = 0;
  
     if (craft == 'O' || craft == 'C')
     {
         size = 5;
     }
     else if (craft == 'A')
     {
         size = 4;
     }
     else if (craft == 'F' )
     {
         size = 3;
     }
     else
     {
         size = 2;
     }
     starting_point(size, &row_coord, &col_coord, direction);
     while (count < size)
     {
         if(direction == 0){
             if(board[row_test][col_test] == '*'){
                 col_test++;
                 count++;
             }
             else{
                 starting_point(size, &row_coord, &col_coord, direction);
                 row_coord = row_test;
                 col_coord = col_test;
                 count = 0;
             }
            }
            else if (direction == 1){
                if(direction == 0){
             if(board[row_test][col_test] == '*'){
                 row_test++;
                 count++;
             }
             else{
                 starting_point(size, &row_coord, &col_coord, direction);
                 row_coord = row_test;
                 col_coord = col_test;
                 count = 0;
             }
            }
           else{
               printf("error: Try again\n");
           }
         }
         count = 0;
          while (count < size){
              board[row_coord][col_coord] = craft;
              if (direction == 0){
                  col_coord++;
              }
              else if ( direction == 1){
                  row_coord++;
              }
              count++;
          }
     }
}
         
        
bool check_status (short craftfall[][5], short player, char craftSymbol, FILE *stream) {
	bool fallen = false;


	switch (craftSymbol) {
		case Osprey:    
			if (--craftfall[player][0] == 0) {
				printf ("> Player %d's Osprey has fallen!\n", player + 1);


				
				fprintf (stream, "Player %d's Osprey has fallen!\n", player + 1);


				fallen = true;
			}
			break;


		case F_sixteen: 
			if (--craftfall[player][1] == 0) {
				printf ("> Player %d's F-16 has fallen!\n", player + 1);


				
				fprintf (stream, "Player %d's F-16 has fallen!\n", player + 1);


				fallen = false;
			}
			break;


		case A_ten:    
			if (--craftfall[player][2] == 0) {
				printf ("> Player %d's A-10 has fallen!\n", player + 1);

				fprintf (stream, "Player %d's A-10 has fallen!\n", player + 1);


				fallen = true;
			}
			break;


		case B_two:  
			if (--craftfall[player][3] == 0) {
				printf ("> Player %d's B-2 has fallen!\n", player + 1);

				fprintf (stream, "Player %d's B-2 has fallen!\n", player + 1);


				fallen = true;
			}
			break;


		case C_seventeen:  
			if (--craftfall[player][4] == 0) {
				printf ("> Player %d's C-17 has fallen!\n", player + 1);


				fprintf (stream, "Player %d's C-17 has fallen!\n", player + 1);


				fallen = true;
			}
			break;
	}


	return fallen;
}

coords target(void){
    int coords;

    fflush (stdin);
    printf("Enter coordinates of target: \n");
    printf("> \n");
    scanf("%d %d", &coords.row, &coords.column);
    return coords;

}
short check_target(char board[8][8], int coords){
    int hit = -2;
    switch(board[coords.row][coords.column].symbol){
        case AIR:
            hit = 0;
            break;

            case Osprey:
            case F_sixteen:
            case A_ten:
            case B_two:
            case C_seventeen:
                hit = 1;
                break;
            case HIT:
            case MISS:
            default:
                hit = -1;
                break;
    }
    return hit;
}

int display_winner(int HITS){
    if (HITS == 17)
    {
        return printf("YAY you won!");
    }
    else
    {
        return printf("Sorry Loser :/");
    }
}
