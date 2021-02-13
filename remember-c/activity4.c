#include <stdio.h>

void printAlphabetically(char[60], char[60]);

void main()
{
    char name1[60];
    char name2[60];
    printf("Write a name: ");
    scanf("%s", &name1);
    printf("Write a other name: ");
    scanf("%s", &name2);
    printAlphabetically(name1, name2);
}

void printAlphabetically(char name1[60], char name2[60])
{
    for (int i = 0; i < 60; i++)
    {
        if (name1[i] > name2[i])
        {
            printf("%s\n", name1);
            printf("%s\n", name2);
            break;
        }
        else if (name1[i] < name2[i])
        {
            printf("%s\n", name2);
            printf("%s\n", name1);
            break;
        }
    }
}