#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define the variable
    int n;
    // get ingeter from user
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); // why does while(i > 0 & i < 9) not work?



    // loop for left-align
    for (int row = 0; row < n; row++) // print rows
    {
        // loop for right-align (print dots or blanks)
        for (int dot = 0; dot < n - row - 1; dot++)
        {
            printf(" ");
        }

        // print hashes for each line with hashes of the number of that line
        for (int hash = 0; hash < row + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}