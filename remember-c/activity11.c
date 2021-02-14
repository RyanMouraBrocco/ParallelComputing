#include <stdio.h>
#include "inputs.h"

void showMatrix(int[MAX_R][MAX_C], int, int);
void sumElements(int[MAX_R][MAX_C], int);
void mulElements(int[MAX_R][MAX_C], int);

void main()
{
    int matrixRowSize = readMatrixSize(1);
    int matrixColumnSize = readMatrixSize(0);
    int matrix[MAX_R][MAX_C];
    readMatrix(matrix, matrixRowSize, matrixColumnSize);

    int isSum = readBoolean("Is sum instead multiply ? (y or n)");
    if (isSum == 1)
    {
        sumElements(matrix, matrixColumnSize);
    }
    else
    {
        mulElements(matrix, matrixColumnSize);
    }

    showMatrix(matrix, matrixRowSize, matrixColumnSize);
}

void showMatrix(int matrix[MAX_R][MAX_C], int matrixRowSize, int matrixColumnSize)
{
    for (int i = 0; i < matrixRowSize; i++)
    {
        printf("[");
        for (int j = 0; j < matrixColumnSize; j++)
        {
            printf("   %d,   ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void sumElements(int matrix[MAX_R][MAX_C], int matrixColumnSize)
{
    for (int j = 0; j < matrixColumnSize; j++)
    {
        matrix[1][j] += matrix[0][j];
    }
}

void mulElements(int matrix[MAX_R][MAX_C], int matrixColumnSize)
{
    for (int j = 0; j < matrixColumnSize; j++)
    {
        matrix[1][j] *= matrix[0][j];
    }
}
