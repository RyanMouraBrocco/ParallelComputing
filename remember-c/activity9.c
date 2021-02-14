#include <stdio.h>
#include "inputs.h"

void setAbsoluteMatrix(int[MAX_R][MAX_C], int, int);
void showMatrix(int[MAX_R][MAX_C], int, int);

void main()
{
    int matrixRowSize = readMatrixSize(1);
    int matrixColumnSize = readMatrixSize(0);
    int matrix[MAX_R][MAX_C];
    readMatrix(matrix, matrixRowSize, matrixColumnSize);
    setAbsoluteMatrix(matrix, matrixRowSize, matrixColumnSize);
    showMatrix(matrix, matrixRowSize, matrixColumnSize);
}

void setAbsoluteMatrix(int matrix[MAX_R][MAX_C], int matrixRowSize, int matrixColumnSize)
{
    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColumnSize; j++)
        {
            if (matrix[i][j] < 0)
            {
                matrix[i][j] *= -1;
            }
        }
    }
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