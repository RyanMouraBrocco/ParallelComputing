#include <stdio.h>

void showPirametNumbers(int, int);
int readNumber();

void main()
{
    int maxNumber = readNumber();
    showPirametNumbers(maxNumber, 0);
}

void showPirametNumbers(int maxValue, int current)
{
    for (int i = 0; i < maxValue - current; i++)
    {
        if (current > i)
        {
            printf(" ");
        }
        else
        {
            printf("%d", i + 1);
        }
    }

    printf("\n");

    if (current < (maxValue / 2) + 1)
    {
        showPirametNumbers(maxValue, current + 1);
    }
}

int readNumber()
{
    int number = 0;
    while (number % 2 == 0)
    {
        printf("Write a odd number: ");
        scanf("%d", &number);
    }

    return number;
}