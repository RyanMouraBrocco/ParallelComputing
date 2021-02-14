#include <stdio.h>
#include "inputs.h"

void createMatrixTransposed(int[MAX_R][MAX_C], int[MAX_R][MAX_C], int, int);
void showMatrix(int[MAX_R][MAX_C], int, int);

void main()
{
    int matrixRowSize = readMatrixSize(1);
    int matrixColumnSize = readMatrixSize(0);
    int matrix[MAX_R][MAX_C];
    readMatrix(matrix, matrixRowSize, matrixColumnSize);
    int matrixTransposed[MAX_R][MAX_C];
    createMatrixTransposed(matrix, matrixTransposed, matrixRowSize, matrixColumnSize);
    showMatrix(matrixTransposed, matrixColumnSize, matrixRowSize);
}

void createMatrixTransposed(int matrix[MAX_R][MAX_C], int matrixTransposed[MAX_R][MAX_C], int matrixRowSize, int matrixColumnSize)
{
    for (int i = 0; i < matrixRowSize; i++)
    {
        for (int j = 0; j < matrixColumnSize; j++)
        {
            matrixTransposed[j][i] = matrix[i][j];
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