#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct player{
    char *name;
    int score;
    char item;
};
void PlayerChoice(char item,char tab[3][3]){
    int line,column;
    int valid=0;//checks if the position is valid
    printf("your turn!!\n");
    while(valid==0){
        printf("Please type the coordinates of your desired position.\n1.line:");
        scanf("%d",&line);
        printf("2.column: ");
        scanf("%d",&column);
        if (line>=1 && line<=3 && column>=1 && column<=3){
            if (tab[line-1][column-1]=='.'){
                tab[line-1][column-1]=item;
                valid=1;
            }else{
                printf("This position is already taken please choose another one!!\n");
            }
        }else{
            printf("Invalid position!! Please insert a number between 1 and 3.\n\n");
        }
        
    }
    
}
void ComputerChoice(int line,int column,char item,char tab[3][3]){
    
    tab[line][line]='O';
    printf("Now it is the computer's turn!!\n");
   
}
void fill_table(char tab[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        
            printf("| %c ",tab[i][j]);
        }
        printf("|");
        printf("\n");
    }
}
int main(void){
    char table[3][3]={
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'}
    };
    char userItem;
    int line,column;
    int AI_line=rand()%3;
    int AI_column=rand()%3;
    srand(time(NULL));//seeding the generator using the current time system which changes every second
    printf("the game table:\n");
    printf("Please choose your character 'X' or 'O' :\n");
    scanf("%c",&userItem);
    getchar();
    while(userItem != 'X' && userItem != 'O'){
        printf("Please enter a valid character:\n");
        scanf("%c",&userItem);
        getchar();//eat the newline character'\n' left in the input buffer after the user hits enter to confirm their choice
    }
    
    struct player User={.name="Player",.score=0,.item=userItem};
    struct player Computer={.name="Robot",.score=0,.item=userItem=='X'?'O':'X'};
    printf("You are '%c', the computer is '%c'.\nLet's start the game!!\nNotice: the position of your item should be enterd in the following order:\n1.Line.\n2.column.\n",User.item,Computer.item);
    if(userItem=='X'){
        printf("You start.\n");
        PlayerChoice(userItem,table);
        fill_table(table);
        
        ComputerChoice(AI_line,AI_column,Computer.item,table);
        fill_table(table);

        
        PlayerChoice(userItem,table);
        fill_table(table);

       
        ComputerChoice(AI_line,AI_column,Computer.item,table);
        fill_table(table);


    }
}
