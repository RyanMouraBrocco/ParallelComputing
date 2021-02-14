/*

* Ryan Moura Brocco

* 32175566

* 4. Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. Faça isto com string de C e de C++

*/
#include <stdio.h>
#include "inputs.h"

void printAlphabetically(char[60], char[60]);

void main()
{
    char name1[MAX_STR];
    char name2[MAX_STR];
    readString("Write a name", name1);
    readString("Write a other name", name2);
    printAlphabetically(name1, name2);
}

void printAlphabetically(char name1[MAX_STR], char name2[MAX_STR])
{
    for (int i = 0; i < MAX_STR; i++)
    {
        if (name1[i] > name2[i])
        {
            printf("%s\n", name2);
            printf("%s\n", name1);
            break;
        }
        else if (name1[i] < name2[i])
        {
            printf("%s\n", name1);
            printf("%s\n", name2);
            break;
        }
    }
}