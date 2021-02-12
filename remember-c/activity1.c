#include <stdio.h>


void createArray(int array[2][2]);
int getLineOfSmallerNumberInArray(int array[2][2]);

void main()
{
    int array[2][2];
    createArray(array);
    int smallerLineNumber = getLineOfSmallerNumberInArray(array);
    printf("The smaller number is in line: %d", smallerLineNumber);
}

void createArray(int array[2][2]){
	array[0][0] = 5;
	array[0][1] = 6;
	array[1][0] = 3;
	array[1][1] = 4;
}

int getLineOfSmallerNumberInArray(int array[2][2])
{
    int lineOfSmaller = 1;
    int smaller = array[0][0];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (smaller > array[i][j])
            {
                smaller = array[i][j];
                lineOfSmaller = i + 1;
            }
        }
    }
    
	return lineOfSmaller;
}