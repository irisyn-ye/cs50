#include <cs50.h>
#include <stdio.h>

// prototype the function
void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

// define the function named meow()
void meow(void)
{
    printf("meow\n");
}