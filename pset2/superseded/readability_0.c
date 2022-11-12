#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// prototype
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    // count letters of the input text
    int letters = count_letters(text);
    printf("%i letter(s)\n", letters);
    // count words of the input text
    int words = count_words(text);
    printf("%i word(s)\n", words);
    // count sentences of the input text
    int sentences = count_sentences(text);
    printf("%i sentence(s)\n", sentences);

    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    float L = letters / words * 100;
    float S = sentences / words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}



// count letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// count words by counting whitespaces
int count_words(string text)
{
    int spaces = 0, words;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            spaces++;
        }
    }
    return words = spaces + 1;
}

// count sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }
    return sentences;
}