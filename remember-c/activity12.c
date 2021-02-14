/*

* Ryan Moura Brocco

* 32175566

* 12. Faça uma função que retorne a posição de um dado caracter dentro de uma string.

*/

#include <stdio.h>
#include "inputs.h"

int getPosition(char[MAX_STR], char);

void main()
{
    char string[MAX_STR];
    readString("write a text", string);
    char item = readCharacter("write a character to search");
    int positon = getPosition(string, item);
    if (positon == -1)
    {
        printf("not found this character in text");
    }
    else
    {
        printf("the character is in positon: %d", positon + 1);
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