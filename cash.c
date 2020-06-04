// Cash.c
// Michael Thorpe - 04/06/2020
// Program to calculate change given from a float

#include <stdio.h>
#include <cs50.h>
#include <math.h>

// declare variables
    float dollars;
    int cents, quarters = 0, dimes = 0, nickels = 0;

int main(void)
{
    // ask user for change required, must be positive
    do
    {
    dollars = get_float("How much change is that?");
    }
    while (dollars <= 0);
    // convert this to an amount in cents and calculate change given
    cents = round(100 * dollars);
    printf("So that is %d cents\n", cents);

    while (quarters*25 <= cents)
    {
        quarters++;
    }
    printf("That is %d quarters\n", quarters-1);

    int change = cents - ((quarters-1)*25);

    while (dimes*10 <= change)
    {
        dimes++;
    }

    printf("That is %d dimes\n", dimes-1);

    int change1 = change - ((dimes-1)*10);

    while (nickels*5 <= change1)
    {
        nickels++;
    }

    printf("That is %d nickels\n", nickels-1);

    int pennies = change1 - ((nickels-1)*5);

    printf("That is %d pennies\n", pennies);

}
