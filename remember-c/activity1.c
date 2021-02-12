/*

* Ryan Moura Brocco

* 32175566

* 1. Crie um programa capaz de ler os dados de uma matriz quadrada de inteiros. Ao final da leitura o programa deverá imprimir o número da linha que contém o menor dentre todos os números lidos.

*/

#include <stdio.h>

void createArray(int array[2][2]);
int getLineOfSmallerNumberInArray(int array[2][2]);

void main()
{
    int array[2][2];
    createArray(array);
    int smallerLineNumber = getLineOfSmallerNumberInArray(array);
    printf("The smaller number is in line: %d", smallerLineNumber);
}

/*
inputs used:
input 1 = | 1  2 |
          | 3  4 |

input 2 = | 5  5 |
          | 5  5 |

input 3 = | 5  6 |
          | 3  4 |
*/

void createArray(int array[2][2])
{
    array[0][0] = 5;
    array[0][1] = 5;
    array[1][0] = 5;
    array[1][1] = 5;
}

int getLineOfSmallerNumberInArray(int array[2][2])
{
    int lineOfSmaller = 1;
    int smaller = array[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (smaller > array[i][j])
            {
                smaller = array[i][j];
                lineOfSmaller = i + 1;
            }
        }
    }

    return lineOfSmaller;
}