#include <stdio.h>
#include <stdlib.h>

int main() 
{
    // firstExample();
    // secondExample();
    // thirdExample();

    return 0;
}

void firstExample()
{
    char name[256];
    char secondName[256];

    int bornDate = 0;
    int date = 2021;

    printf("What's your name?\n");
    scanf("%s", name);
    printf("\nCool, %s... What's your born date?", name); // %s goes to string
    scanf("%d", &bornDate); // Reference the input value to the bornDate variable

    int result = bornDate >= date && bornDate <= date - 120 ? 167891 : date - bornDate;

    if (result == 167891)
        printf("Invalid Response");
    else
        printf("Ok %s, Your age is %d", name, result); // %d goes to int
}

void secondExample() 
{
    char name[256];

    printf("Name: ");
    scanf("%s", &name);

    printf("The first letter of your name is %c", name[0]); // %c goes to array.
}

void thirdExample() 
{
    char player1[256];
    char player2[256];

    printf("Player 1; ");
    scanf("%s", &player1);
    printf("Player 2; ");
    scanf("%s", &player2);

    if(strcmp(player1, player2) == 0) {
        printf("Draw");
    } else {
        if(strcmp(player1, "paper") == 0 && strcmp(player2, "rock") == 0) {
            printf("Player 1 Wins");
        } else if(strcmp(player1, "rock") == 0 && strcmp(player2, "scissor") == 0) {
            printf("Player 1 Wins");
        } else if(strcmp(player1, "scissor") == 0 && strcmp(player2, "paper") == 0) {
            printf("Player 1 Wins");
        } else {
            printf("player 2 wins");
        }
    }
}