#include <stdio.h>
#define MAX 100

int readNumber(char[100]);
int readBoolean(char[100]);
int readMatrixSize();
void readMatrix(int[MAX][MAX], int);
void showMatrix(int[MAX][MAX], int);
int readRowColumnNumber(int, int);
void multiplyRow(int[MAX][MAX], int, int, int);
void multiplyColumn(int[MAX][MAX], int, int, int);

void main()
{
    int matrixSize = readMatrixSize();
    int matrix[MAX][MAX];
    readMatrix(matrix, matrixSize);
    int number = readNumber("write number to multiply");
    int isMultiplyRow = readBoolean("is multiply a row ? (y or n)");
    if (isMultiplyRow == 1)
    {
        int rowNumber = readRowColumnNumber(isMultiplyRow, matrixSize);
        multiplyRow(matrix, matrixSize, rowNumber, number);
    }
    else
    {
        int columnNumber = readRowColumnNumber(isMultiplyRow, matrixSize);
        multiplyColumn(matrix, matrixSize, columnNumber, number);
    }

    showMatrix(matrix, matrixSize);
}

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

int readRowColumnNumber(int isRow, int matrixSize)
{
    int value = -1;
    while (value < 0 || value > matrixSize - 1)
    {
        if (isRow == 1)
        {
            value = readNumber("write a row number");
        }
        else
        {
            value = readNumber("write a column number");
        }
    }

    return value;
}

int readMatrixSize()
{
    int matrixSize = 0;
    while (matrixSize <= 0 || matrixSize > 100)
    {
        matrixSize = readNumber("write the size of matrix ( value between 1 and 100 )");
    }

    return matrixSize;
}

void readMatrix(int matrix[MAX][MAX], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < matrixSize; j++)
        {
            printf("write value to matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void showMatrix(int matrix[MAX][MAX], int matrixSize)
{
    for (int i = 0; i < matrixSize; i++)
    {
        printf("[");
        for (int j = 0; j < matrixSize; j++)
        {
            printf("   %d,   ", matrix[i][j]);
        }
        printf("]\n");
    }
}

void multiplyRow(int matrix[MAX][MAX], int matrixSize, int rowNumber, int number)
{
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[rowNumber][i] *= number;
    }
}

void multiplyColumn(int matrix[MAX][MAX], int matrixSize, int columnNumber, int number)
{
    for (int i = 0; i < matrixSize; i++)
    {
        matrix[i][columnNumber] *= number;
    }
}