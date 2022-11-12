#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string s = get_string("Input: ");
    printf("Output: ");
    // define the n variable to avoid repeat strlen(s) in loop
    int n = strlen(s);
    for (int i = 0; i < n; i ++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}