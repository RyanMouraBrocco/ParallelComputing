#include <stdio.h>

double calculateAverage(double, double, double, double);
char NumberNoteToLetterNote(double);

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