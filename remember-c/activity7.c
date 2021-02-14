#include <stdio.h>
#include "inputs.h"
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
    readString("write the person name", newPerson.name);
    newPerson.age = readNumber("write the age person");
    newPerson.weight = readDouble("write the weight person");
    newPerson.height = readDouble("write the height person");

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