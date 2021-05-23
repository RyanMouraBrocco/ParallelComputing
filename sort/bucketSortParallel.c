#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX 200

typedef struct
{
    int index;
    int items[MAX];
} bucket;

void bucketSort(int[], int, int);
void setBeginIndex(bucket[], int);
void setBucketsValues(int[], int, bucket[], int);
void sortBuckets(bucket[], int);
void setSortedArray(int[], bucket[], int);
void insertionSort(int[], int);
void printArray(int[], int);

void main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;
    bucketSort(arr, n, 5);
    printArray(arr, n);
}

void bucketSort(int array[], int arrayLength, int bucketQuantity)
{
    bucket buckets[bucketQuantity];
    setBeginIndex(buckets, bucketQuantity);
    setBucketsValues(array, arrayLength, buckets, bucketQuantity);
    sortBuckets(buckets, bucketQuantity);
    setSortedArray(array, buckets, bucketQuantity);
}

void setBeginIndex(bucket array[], int length)
{
#pragma omp parallel for
    for (int i = 0; i < length; i++)
    {
        array[i].index = 0;
    }
}

void setBucketsValues(int array[], int arrayLength, bucket buckets[], int bucketQuantity)
{
#pragma omp parallel for
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = bucketQuantity - 1; j >= 0; j--)
        {
            if (array[i] >= j * 10)
            {
#pragma omp critical
                {
                    buckets[j].items[buckets[j].index] = array[i];
                    buckets[j].index += 1;
                }
                break;
            }
        }
    }
}

void sortBuckets(bucket buckets[], int bucketQuantity)
{
#pragma omp parallel for
    for (int i = 0; i < bucketQuantity; i++)
        if (buckets[i].index > 0)
            insertionSort(buckets[i].items, buckets[i].index);
}

void setSortedArray(int finalArray[], bucket buckets[], int bucketQuantity)
{
    int finalArrayIndex = 0;
    for (int i = 0; i < bucketQuantity; i++)
    {
        for (int j = 0; j < buckets[i].index; j++)
        {
            finalArray[finalArrayIndex] = buckets[i].items[j];
            finalArrayIndex++;
        }
    }
}

void insertionSort(int array[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j -= 1;
        }

        array[j + 1] = key;
    }
}

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");
}