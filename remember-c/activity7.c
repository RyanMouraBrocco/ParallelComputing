#include <stdio.h>
#define MAX 3

typedef struct Person
{
    char name[100];
    int age;
    double weight;
    double height;
} Person;

void showPeople(Person[MAX], int);
void showPerson(Person);
Person readPerson();
void flushIn();

void main()
{
    Person people[MAX];
    printf("person register (person 1): \n");
    people[0] = readPerson();
    printf("person register (person 2): \n");
    people[1] = readPerson();
    printf("person register (person 3): \n");
    people[2] = readPerson();

    showPeople(people, 3);
}

Person readPerson()
{
    Person newPerson;
    printf("write the person name: ");
    scanf("%s", &newPerson.name);
    flushIn();
    printf("write the age person: ");
    scanf(" %d", &newPerson.age);
    printf("write the weight person: ");
    scanf(" %lf", &newPerson.weight);
    printf("write the height person: ");
    scanf(" %lf", &newPerson.height);

    return newPerson;
}

void showPeople(Person people[MAX], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        printf("person %d:\n", i + 1);
        showPerson(people[i]);
    }
}

void showPerson(Person person)
{
    printf("\tname: %s\n", person.name);
    printf("\tage: %d\n", person.age);
    printf("\tweight: %lf\n", person.weight);
    printf("\theight: %lf\n", person.height);
}

void flushIn()
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n')
    {
    }
}