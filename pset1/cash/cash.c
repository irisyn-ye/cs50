#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int coins = 0; // define the number of coins counter starting value is 0
    float change; // define the change variable

    do
    {
        change = get_float("Change owed: "); // get change from user
    }
    while (change < 0); // make sure change is positive
    int cents = round(change * 100); // round change to cents

    // count number of coins
    while (cents >= 25)
    {
        cents = cents - 25;
        coins++;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        coins++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }

    // print the greedy number of coins
    printf("%i\n", coins);
}