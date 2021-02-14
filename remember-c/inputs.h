#ifndef INPUTS_H_
#define INPUTS_H_

#define MAX_C 100
#define MAX_R 100

int readNumber(char[100]);
int readBoolean(char[100]);
int readMatrixSize(int);
void readMatrix(int[MAX_R][MAX_C], int, int);

#endif