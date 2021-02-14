#include "inputs.h"
#include <stdio.h>

int readNumber(char text[100])
{
    int value;
    printf("%s: ", text);
    scanf("%d", &value);
    return value;
}

int readBoolean(char text[100])
{
    char response;
    printf("%s: ", text);
    scanf(" %c", &response);
    if (response == 'y' || response == 'Y')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int readMatrixSize(int isRow)
{
    int matrixSize = 0;
    while (matrixSize <= 0 || matrixSize > 100)
    {
        if (isRow == 1)
        {
            matrixSize = readNumber("write the matrix line size ( value between 1 and 100 )");
        }
        else
        {
            matrixSize = readNumber("write the matrix column size ( value between 1 and 100 )");
        }
    }

    return matrixSize;
}

void readMatrix(int matrix[MAX_R][MAX_C], int matrixRowSize, int matrixColumnSize)
{
    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColumnSize; j++)
        {
            printf("write value to matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}