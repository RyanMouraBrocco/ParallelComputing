/*

* Ryan Moura Brocco

* 32175566

* 13. Faça um rotina que remova um caracter de uma string do tipo char Str[100], dada a posição do caracter.

*/

#include <stdio.h>
#include "inputs.h"

int getPosition(char[MAX_STR], char);
void removeCharacter(char[MAX_STR], char[MAX_STR], int);

void main()
{
    char string[MAX_STR];
    readString("write some text", string);
    char item = readCharacter("write character to remove");
    int position = getPosition(string, item);
    if (position > -1)
    {
        char stringResult[MAX_STR];
        removeCharacter(string, stringResult, position);
        printf("text result: %s", stringResult);
    }
    else
    {
        printf("character not found");
    }
}

void removeCharacter(char string[MAX_STR], char newString[MAX_STR], int removedPosition)
{
    int currentPositon = 0;
    while (string[currentPositon] != '\0')
    {
        if (currentPositon >= removedPosition)
        {
            if (currentPositon + 1 < MAX_STR)
            {
                newString[currentPositon] = string[currentPositon + 1];
            }
            else
            {
                newString = '\0';
            }
        }
        else
        {
            newString[currentPositon] = string[currentPositon];
        }

        currentPositon++;
    }
}

int getPosition(char string[MAX_STR], char item)
{
    int position = 0;
    while (string[position] != '\0')
    {
        if (string[position] == item)
        {
            return position;
        }

        position++;
    }

    return -1;
}