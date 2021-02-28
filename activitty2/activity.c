/*

* Ryan Moura Brocco

* 32175566

* Escreva um programa que leia um arquivo texto com o nome, a idade e a altura de um conjunto de pessoa.
  Coloque os dados em um vetor de Structs e ordene o vetor por altura. No final, gere um novo arquivo com os dados ordenados

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct PERSON
{
    char name[100];
    int age;
    float height;
} PERSON;

void readFileName(char[50]);
int openFile(FILE **, char[50]);
void closeFile(FILE **);
int readPerson(PERSON *, FILE *);
void sortArray(PERSON[MAX], int);
int comparePerson(const void *, const void *);
void printArray(PERSON[MAX], int);

int main()
{
    char fileName[50];
    PERSON people[10], p;
    FILE *file;
    int i;
    readFileName(fileName);
    if (openFile(&file, fileName) == 1)
    {
        do
        {
            if (readPerson(&p, file) == 1)
            {
                people[i] = p;
                i++;
            }
            else
                break;
        } while (1);
        closeFile(&file);

        sortArray(people, i);
        printArray(people, i);
    }
    else
        printf("Error to open file");

    return 0;
}

void readFileName(char fileName[])
{
    printf("write the filename: ");
    scanf("%s", fileName);
}

int openFile(FILE **file, char fileName[])
{
    *file = fopen(fileName, "r");
    if (*file == NULL)
        return 0;

    return 1;
}

void closeFile(FILE **file)
{
    fclose(*file);
}

int readPerson(PERSON *person, FILE *file)
{
    int result = fscanf(file, "%s\n", &person->name);
    if (result == EOF)
        return 0;

    result = fscanf(file, "%d\n", &person->age);
    if (result == EOF)
        return 0;

    result = fscanf(file, "%f\n", &person->height);
    if (result == EOF)
        return 0;

    return 1;
}

void sortArray(PERSON people[MAX], int length)
{
    qsort(people, length, sizeof(PERSON), comparePerson);
}

int comparePerson(const void *a, const void *b)
{
    PERSON arg1 = *(const PERSON *)a;
    PERSON arg2 = *(const PERSON *)b;

    if (arg1.height < arg2.height)
        return -1;

    if (arg1.height > arg2.height)
        return 1;

    return 0;
}

void printArray(PERSON people[MAX], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("person - %d \n", i + 1);
        printf("\tname: %s\n", people[i].name);
        printf("\tage: %d\n", people[i].age);
        printf("\theigth: %f\n", people[i].height);
    }
}