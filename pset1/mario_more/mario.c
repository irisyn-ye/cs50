#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // define the height variable
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8); // limit the height any integer between 1 and 8

    // build up the rows
    for (int row = 0; row < n; row++)
    {
        // space
        for (int space = n - row - 1; space > 0; space--)
        {
            printf(" ");
        }

        // left
        for (int hash_l = 0; hash_l < row + 1; hash_l++)
        {
            printf("#");
        }

        // middle space
        printf("  ");

        // right
        for (int hash_r = 0; hash_r < row + 1; hash_r++)
        {
            printf("#");
        }

        printf("\n");
    }
}