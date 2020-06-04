// credit.c
// Michael Thorpe - 03/06/2020
// Program to verify if credit card details correct

#include <stdio.h>
#include <cs50.h>

// functions
void checksum(long long card);
void checkcompany( long long card);

int main(void)
{
    long long card;
    do
    {
        card = get_long_long("Please input card number: ");
    }
    while (card <0 || card > 9999999999999999 );//accepts up to 16 digit codes
    checksum(card);
    return 0;
}

//function to perform checksum calculation
void checksum(long long card)
{
    //declare variables
    int digit, sum = 0, newsum, altsum = 0, total;

    //first for loop to find every other value from second last
    for (long long i = 10; i < card; i = i*100)

    {   //store every other second last integer and multiply by 2
        digit = (card % (i*10)/i)*2;

        //updates sum to add all individual digits
        while (digit != 0)
        {
            newsum = digit % 10;
            sum = sum + newsum;
            digit = digit/10;
        }
    }

    //second for loop to find every other value from the end
    for (long long i = 1; i < card; i = i*100)
    {
        //store every other last integer
        digit = (card % (i*10)/i);
        altsum = altsum + digit;
    }

    //total adds all integers found
    total = (sum + altsum) % 10;

    //checks if legitimate and then performs company search, else INVALID
    if (total == 0)
    {
        checkcompany(card);
    }
    else
    {
        printf("INVALID\n");
    }
}

//function to check if credit card details match valid company details
void checkcompany( long long card)
{
    //return first two digit of card to check company match
    int counter = 0;
    long long cardtwo = card;

    //count digits in card
    while (card > 1)
    {
        card /= 10;
        counter++;
    }

    // find first two digits of card
    while (cardtwo >= 100)
    {
        cardtwo /= 10;
    }

    //Amex check
    if (counter == 15 & cardtwo == 34 || cardtwo == 37)
    {
        printf("AMEX\n");
    }

    //Mastercard check
    else if (cardtwo == 51 || cardtwo == 52 || cardtwo == 53 || cardtwo == 54 || cardtwo == 55 & counter == 16)
    {
        printf("MASTERCARD\n");
    }

    //Visa check
    else if (cardtwo/10 == 4 & counter == 13 || counter == 16)
    {
        printf("VISA\n");
    }

    //all other combinations must be invalid if they do not match these conditions
    else
    {
        printf("INVALID\n");
    }
}
