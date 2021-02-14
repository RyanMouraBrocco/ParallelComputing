/*

* Ryan Moura Brocco

* 32175566

* 3. Faça o programa que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). Este número deve ser sempre ímpar.

            1 2 3 4 5 6 7 8 9
              2 3 4 5 6 7 8
                3 4 5 6 7
                  4 5 6
                    5  

*/

#include <stdio.h>
#include "inputs.h"

void showPyramidNumbers(int, int);
int readOddNumber();

void main()
{
    int maxNumber = readOddNumber();
    showPyramidNumbers(maxNumber, 0);
}

void showPyramidNumbers(int maxValue, int current)
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
        showPyramidNumbers(maxValue, current + 1);
    }
}

int readOddNumber()
{
    int number = 0;
    while (number % 2 == 0)
    {
        number = readNumber("Write a odd number");
    }

    return number;
}