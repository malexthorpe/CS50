// Mario c
// Michael Thorpe - 03/06/2020
// Creates two pyramids which mirror each other

#include <cs50.h>
#include <stdio.h>

int main(void)

{   //declare variables
    int height;
    int space;
    int hash;
    int row;

    // prompts user for integer between 1 and 20
    do
    {
        height = get_int("Welcome to Mario! How big are the pyramids?: ");
    }
    while (0 > height && height < 21);
    for (row = 0; row < height; row++)
    {
        for (space = 0;space < height - row;space++)
            printf(" ");

        for (hash = 0; hash <= row; hash++)
    {        printf("#");

    }
        printf(" ");

        for (hash = 0; hash<=row; hash++)
    {       printf("#");
    }
        printf("\n");
    }
    return 0;
}
