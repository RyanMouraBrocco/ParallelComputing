#ifndef INPUTS_H_
#define INPUTS_H_

#define MAX_C 100
#define MAX_R 100
#define MAX_STR 100

int readNumber(char[100]);
int readBoolean(char[100]);
int readMatrixSize(int);
void readMatrix(int[MAX_R][MAX_C], int, int);
void readString(char[MAX_STR], char[100]);
void flushIn();
double readDouble(char[100]);
char readCharacter(char[100]);

#endif