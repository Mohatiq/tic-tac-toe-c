#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>
struct player
{
    char *name;
    int score;
    char item;
};

void win(char item,char table[3][3],char userItem){
    int i=0;
    bool win=false;
    for(i=0;i<3;i++){
        if (table[0][i]==item && table[1][i]==item && table[2][i]==item){
            win=true;
        }else if(table[i][0]==item && table[i][1]==item && table[i][2]==item){
            win=true;
        } 
    }
    if (table[0][0]==item && table[1][1]==item && table[2][2]==item){
        win=true;
    }
    if (table[0][2]==item && table[1][1]==item && table[2][0]==item){
        win=true;
    }
        
    
    if(win){
        if(item==userItem){
            printf("Congrats!!! You are the winner ;)\n");
        }else{
            printf("Ohhh!! The computer won :(\n");
        }
        exit(0);
    }

}
void PlayerChoice(char item, char tab[3][3])
{
    int line, column;
    int valid = 0; // checks if the position is valid
    printf("your turn!!\n");
    while (valid == 0)
    {
        printf("Please type the coordinates of your desired position.\n1.line:");
        scanf("%d", &line);
        printf("2.column: ");
        scanf("%d", &column);
        if (line >= 1 && line <= 3 && column >= 1 && column <= 3)
        {
            if (tab[line - 1][column - 1] == '.')
            {
                tab[line - 1][column - 1] = item;
                valid = 1;
            }
            else
            {
                printf("This position is already taken please choose another one!!\n");
            }
        }
        else
        {
            printf("Invalid position!! Please insert a number between 1 and 3.\n\n");
        }
    }
}
void ComputerChoice(char item, char table[3][3])
{
    int AI_line, AI_column;
    int valid_move=0;
    printf("Now it is the computer's turn!!\n");
    while(valid_move==0){
        AI_line=rand()%3;
        AI_column=rand()%3;
        if(table[AI_line][AI_column]=='.'){
            table[AI_line][AI_column]=item;
            valid_move=1;//breaking the while loop because a valid move was made
        }
    }
}
void fill_table(char tab[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            printf("| %c ", tab[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void game(char userItem, char table[3][3]) {
    char computerItem = (userItem == 'X') ? 'O' : 'X';
    int moves = 0;

    while (moves < 9) {
        // Player's Turn 
        if (userItem == 'X') {
            PlayerChoice(userItem, table);
        } else {
            ComputerChoice(computerItem, table);
        }
        fill_table(table);
        win('X', table,userItem); // Always check if X won
        win('O', table,userItem); // Always check if O won
        moves++;
        if (moves == 9) break;

        //Computer's Turn
        if (userItem == 'X') {
            ComputerChoice(computerItem, table);
        } else {
            PlayerChoice(userItem, table);
        }
        fill_table(table);
        win('X', table,userItem);
        win('O', table,userItem);
        moves++;
    }

    printf("It's a tie!!\n");
    exit(0);
}

int main(void)
{
    char table[3][3] = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}};
    char userItem;
    int line, column;
    int round=1;
    srand(time(NULL)); // seeding the generator using the current time system which changes every second
   
    printf("the game table:\n");
    printf("Please choose your character 'X' or 'O' :\n");
    scanf("%c", &userItem);
    getchar();
    while (userItem != 'X' && userItem != 'O')
    {
        printf("Please enter a valid character:\n");
        scanf("%c", &userItem);
        getchar(); // eat the newline character'\n' left in the input buffer after the user hits enter to confirm their choice
    }

    struct player User = {.name = "Player", .score = 0, .item = userItem};
    struct player Computer = {.name = "Robot", .score = 0, .item = userItem == 'X' ? 'O' : 'X'};
    printf("You are '%c', the computer is '%c'.\nLet's start the game!!\nNotice: the position of your item should be enterd in the following order:\n1.Line.\n2.column.\n", User.item, Computer.item);
    game(userItem,table);
}
