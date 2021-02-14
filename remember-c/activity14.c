/*

* Ryan Moura Brocco

* 32175566

* 14. Faça uma rotina que insira um caracter em uma string do tipo char Str[100], dada a posição do caracter.

*/

#include <stdio.h>
#include "inputs.h"

int getPosition(char string[MAX_STR], char item);
void addCharacter(char string[MAX_STR], char newString[MAX_STR], int addedPosition, char newCharacter);
int readPosition();

void main()
{
    char string[MAX_STR];
    readString("write some text", string);
    int positon = readPosition();
    char newCharacter = readCharacter("write new character");
    char stringResult[MAX_STR];
    addCharacter(string, stringResult, positon - 1, newCharacter);
    printf("result: %s", stringResult);
}

void addCharacter(char string[MAX_STR], char newString[MAX_STR], int addedPosition, char newCharacter)
{
    int currentPositon = 0;
    while (string[currentPositon] != '\0')
    {
        if (currentPositon == addedPosition)
        {
            newString[currentPositon] = newCharacter;
        }
        else if (currentPositon > addedPosition)
        {
            newString[currentPositon] = string[currentPositon - 1];
        }
        else
        {
            newString[currentPositon] = string[currentPositon];
        }

        currentPositon++;
    }
}

int readPosition()
{
    int positon = 0;
    while (positon <= 0 || positon >= MAX_STR)
    {
        positon = readNumber("write a position of text to add new character (number between 1 and 100)");
    }
    return positon;
}