#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>


// how to define k in the command line?

int main(int argc, string argv[])
{
    // check the command line numbers
    if (argc != 2)
    {
        // error report
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int arg_length = strlen(argv[1]);
    for (int i = 0; i < arg_length; i++)
    {
        // not digit
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key");  //if not print this //
            return 1;
        }
    }
    // availability check

    // argv[i] is a string, convert string to integer
    int k = atoi(argv[1]);
    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    //iterate through plaintext
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", (((p[i] - 'A') + k) % 26) + 'A');
        }
        else if (islower(p[i]))
        {
            printf("%c", (((p[i] - 'a') + k) % 26) + 'a');
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}

