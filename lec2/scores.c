#include <cs50.h>
#include <stdio.h>

const int TOTAL = 3;

int main(void)
{
    int TOTAL = get_int("Total number of scores: ");

    int scores[TOTAL];
    for (int i; i < TOTAL; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(TOTAL, scores));
}

// define the function named average
float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i]; // sum = sum + array[i]
    }
    return sum / (float) length; // make sure the type of length is float
}