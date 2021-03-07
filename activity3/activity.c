/*

* Ryan Moura Brocco

* 32175566

* 

*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

void main()
{
    int shmid;
    key_t key;
    int *shm, *value;
    pid_t pid;

    key = 5678;

    if ((shmid = shmget(key, sizeof(int), IPC_CREAT | 0666)) < 0)
    {
        printf("error when create segment");
        return;
    }

    if ((shm = shmat(shmid, NULL, 0)) == (int *)-1)
    {
        printf("error to allocate a variable");
        return;
    }
    value = shm;
    *value = 1;
    printf("Initial value: %d\n", *value);

    pid = fork();
    if (pid == -1)
    {
        printf("Error to create fork");
        return;
    }

    if (pid == 0)
    {
        *value += 2;
    }
    else
    {
        while (*value == 1)
            ;

        *value *= 4;
        printf("Final value: %d\n", *value);
    }
}