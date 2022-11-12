#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters = 0;
int words = 1;
int sentences = 0;

int main(void)
{
    string text = get_string("Text: ");

    // count letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isspace(text[i]))
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }

    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    float index = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int grade = round(index);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

    // double check counts of the input text
    // printf("%i letter(s)\n", letters);
    // printf("%i word(s)\n", words);
    // printf("%i sentence(s)\n", sentences);
}


