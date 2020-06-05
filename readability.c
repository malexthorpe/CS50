//readability.c
//program to calculate grade level from a line of text
//Michael Thorpe - 05/06/2020

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//reference function
void counts(string s);

//main program
int main(void)
{
    //ask user for text input
    string s = get_string("Text: ");
    counts(s);
}

// function to count letters, words and sentences
void counts(string s)
{
    //declare variables
    int count = 0; //letter count
    int words = 1; //word count
    int sentences = 0; //sentence count

    //loop over all characters in string and count letters, words and sentences
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if alphabet character, add to count
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            count += 1;
        }

        //if space, add to word count
        else if (s[i] == 32)
        {
            words += 1;
        }

        //if sentence end, add to sentence count
        else if (s[i] == 33 ||s[i] == 46 ||s[i] == 63)
        {
            sentences +=1;
        }
    }

    //number of letters per 100 words
    float L = 100*((float)count/words);

    //number of sentences per 100 words
    float S = 100*((float)sentences/words);

    //Coleman-Liau Index calculation
    int grade = round((0.0588 * L) - (0.296 * S) - 15.8);

    //low and high grade statements and print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
    printf("Grade %i\n", grade);
    }
}
