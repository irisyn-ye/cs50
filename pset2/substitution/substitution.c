#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // if command line argument is not equal to 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    int argv_length = strlen(argv[1]);

    // 26 characters
    if (argv_length != 26)
    {
        printf("Key must be up to 26\n");
        return 1;
    }
    // iterate over the args
    for (int i = 0; i < argv_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("All Key must be an Alphabeth\n");
            return 1;
        }
        for (int j = i + 1; j < argv_length; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated alphabeth");
                return 1;
            }
        }
    }

    // get the input as plaintext
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", toupper(argv[1][p[i] - 65]));
        }
        else if (islower(p[i]))
        {
            printf("%c", tolower(argv[1][p[i] - 97]));
        }
        else
        {
            printf("%c", p[i]);
        }

    }
    printf("\n");
}
