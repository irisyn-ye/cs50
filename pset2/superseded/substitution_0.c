#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// prototype
void do_substitute();

int main(int argc, string argv[])
{
    // single line but invalid
    if (argc == 2)
    {
        // not containing 26 characters
        if (strlen(argv[1]) != 26)
        {
            printf("Command is not containing 26 characters.\n");
            return 1;
        }

        for (int j = 0, n = strlen(argv[1]); j < n; j++)
        {
            // containing non-alphabetic
            if (argv[1][j] < 'A' || argv[1][j] > 'z')
            {
                printf("Key contains non-alphabetic term.\n");
                return 1;
                // repeat characters
                for (int i = 0; i < n; i++)
                {
                    if (argv[1][j] == argv[1][i])
                    {
                        printf("Repeated charaters.\n");
                        return 1;
                    }
                }
            }
        }
        do_substitute(argv[1]);
        return 0;
    }

    // not single line
    else if (argc != 2)
    {
        printf("Key must be one-command line argument.\n");
        return 1;
    }

    // all else
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}


void(do_substitute(string argv[1]))
{
    string p = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, m = strlen(p); i < m; i++)
    {
        if (isupper(p[i]))
        {
            printf("%c", toupper(argv[1][p[i] - 'A']));
        }
        else if (islower(p[i]))
        {
            printf("%c", tolower(argv[1][p[i] - 'a']));
        }
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
