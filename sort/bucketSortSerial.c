#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX_BUCKET 5000

typedef struct
{
    int index;
    int items[MAX_BUCKET];
} bucket;

void bucketSort(int[], int, int);
void setBeginIndex(bucket[], int);
void setBucketsValues(int[], int, bucket[], int);
void sortBuckets(bucket[], int);
void setSortedArray(int[], bucket[], int);
void insertionSort(int[], int);
void printArray(int[], int);
void createRadomArray(int[], int);
double getTime();

void main(int argc, char *argv[])
{
    double startValue, endValue, total;
    srand(time(NULL));
    int length = strtol(argv[1], NULL, 10);
    int *arr = malloc(length * sizeof(int));
    createRadomArray(arr, length);

    startValue = getTime();
    bucketSort(arr, length, 5);

    endValue = getTime();
    total = endValue - startValue;

    printf("sort array of length: %d, time %f usecs\n ", length, total);
}

void createRadomArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % 6000;
    }
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
    for (int i = 0; i < length; i++)
    {
        array[i].index = 0;
    }
}

void setBucketsValues(int array[], int arrayLength, bucket buckets[], int bucketQuantity)
{
    for (int i = 0; i < arrayLength; i++)
    {
        for (int j = bucketQuantity - 1; j >= 0; j--)
        {
            if (array[i] >= j * 10)
            {
                buckets[j].items[buckets[j].index] = array[i];
                buckets[j].index += 1;
                break;
            }
        }
    }
}

void sortBuckets(bucket buckets[], int bucketQuantity)
{
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

double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}