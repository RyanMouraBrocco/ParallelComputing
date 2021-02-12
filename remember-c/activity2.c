/*

* Ryan Moura Brocco

* 32175566

* 2. Escreva um programa que leia 3 notas de um aluno e a média das notas dos exercícios realizados por ele. Calcular a média de aproveitamento, usando a fórmula: MA = (N1 + N2*2 + N3*3 + ME)/7. A partir da média, informar o conceito de acordo com a tabela:
        maior ou igual a 9	A
        maior ou igual a 7.5 e menor que 9	B
        maior ou igual a 6 e menor que 7.5	C
        maior ou igual a 4 e menor que 6	D
        menor que 4	E
*/

#include <stdio.h>

double calculateAverage(double, double, double, double);
char NumberNoteToLetterNote(double);

/*
    inputs used:
    input 1: note1 = 10
             note2 = 9
             note3 = 7
             noteExerciesAverange = 1

    input 2: note1 = 6
             note2 = 2
             note3 = 4
             noteExerciesAverange = 10

    input 3: note1 = 4
             note2 = 4
             note3 = 1
             noteExerciesAverange = 1

*/

void main()
{
    double note1 = 4;
    double note2 = 4;
    double note3 = 1;
    double noteExerciesAverange = 1;

    double averageNote = calculateAverage(note1, note2, note3, noteExerciesAverange);
    char noteAsLetter = NumberNoteToLetterNote(averageNote);
    printf("Your note is: %c", noteAsLetter);
}

double calculateAverage(double note1, double note2, double note3, double noteExercises)
{
    return (note1 + (note2 * 2) + (note3 * 3) + noteExercises) / 7;
}

char NumberNoteToLetterNote(double note)
{
    char letterNote;
    if (note >= 9)
    {
        letterNote = 'A';
    }
    else if (note >= 7.5)
    {
        letterNote = 'B';
    }
    else if (note >= 6)
    {
        letterNote = 'C';
    }
    else if (note >= 4)
    {
        letterNote = 'D';
    }
    else
    {
        letterNote = 'E';
    }

    return letterNote;
}