#include <stdio.h>
#include "inputs.h"

void showMatrix(int[MAX_R][MAX_C], int, int);
int readRowColumnNumber(int, int, int);
void multiplyRow(int[MAX_R][MAX_C], int, int, int);
void multiplyColumn(int[MAX_R][MAX_C], int, int, int);

void main()
{
    int matrixRowSize = readMatrixSize(1);
    int matrixColumnSize = readMatrixSize(2);
    int matrix[MAX_R][MAX_C];
    readMatrix(matrix, matrixRowSize, matrixColumnSize);
    int number = readNumber("write number to multiply");
    int isMultiplyRow = readBoolean("is multiply a row ? (y or n)");
    int rowColumnNumber = readRowColumnNumber(isMultiplyRow, matrixRowSize, matrixColumnSize);
    if (isMultiplyRow == 1)
    {
        multiplyRow(matrix, matrixColumnSize, rowColumnNumber, number);
    }
    else
    {
        multiplyColumn(matrix, matrixRowSize, rowColumnNumber, number);
    }

    showMatrix(matrix, matrixRowSize, matrixColumnSize);
}

int readRowColumnNumber(int isRow, int matrixLineSize, int matrixColumnSize)
{
    int value = -1;
    if (isRow == 1)
    {
        while (value < 0 || value > matrixLineSize - 1)
        {
            value = readNumber("write a row number");
        }
    }
    else
    {
        while (value < 0 || value > matrixColumnSize - 1)
        {
            value = readNumber("write a column number");
        }
    }

    return value;
}

void showMatrix(int matrix[MAX_R][MAX_C], int matrixLineSize, int matrixColumnSize)
{
    for (int i = 0; i < matrixLineSize; i++)
    {
        printf("[");
        for (int j = 0; j < matrixColumnSize; j++)
        {
            printf("   %d,   ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void multiplyRow(int matrix[MAX_R][MAX_C], int matrixColumSize, int rowNumber, int number)
{
    for (int i = 0; i < matrixColumSize; i++)
    {
        matrix[rowNumber][i] *= number;
    }
}

void multiplyColumn(int matrix[MAX_R][MAX_C], int matrixRowSize, int columnNumber, int number)
{
    for (int i = 0; i < matrixRowSize; i++)
    {
        matrix[i][columnNumber] *= number;
    }
}