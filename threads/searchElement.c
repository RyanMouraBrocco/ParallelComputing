#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int numberToFind;
int position;
int length = 65536;
int *array;
int found = 0;

void find(void);
void populateArray();

int main(int argc, char *argv[])
{
    array = malloc(length * sizeof(int));
    numberToFind = strtol(argv[1], NULL, 10);
    int threadsQuantity = strtol(argv[2], NULL, 10);
    populateArray();

#pragma omp parallel num_threads(threadsQuantity)
    find();

    if (found == 1)
    {
        printf("Found the number %d in %d positon\n", numberToFind, position);
    }
    else
    {
        printf("Number not found the number %d\n", numberToFind);
    }

    free(array);
    return 0;
}

void find(void)
{
    int currentThread = omp_get_thread_num();
    int totalThreads = omp_get_num_threads();
    int interval = length / totalThreads;
    int beginIndex = currentThread * interval;
    int endIndex;

    if (currentThread == (totalThreads - 1))
    {
        endIndex = length;
    }
    else
    {
        endIndex = beginIndex + interval;
    }

    for (int i = beginIndex; i < endIndex; i++)
    {
        if(found == 1)
            break;

        if (array[i] == numberToFind)
        {
            position = i;
            found = 1;
            break;
        }
    }
}

void populateArray()
{
    FILE *file = fopen("/home/ryanbrocco/Documents/GitHub/ParallelComputing/threads/vetor1.csv", "r");

    int index = 0;
    fscanf(file, "%d", &array[index]);
    while (!feof(file))
    {
        index++;
        fscanf(file, "%d", &array[index]);
    }

    fclose(file);
}