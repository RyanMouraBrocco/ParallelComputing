/*

* Ryan Moura Brocco

* 32175566

* Crie um código-fonte que utilize fork() e shmget() entre 2 processos (pai e filho). Seu código deve garantir que:

    o processo pai e o processo filho compartilhem uma variável simples (por exemplo, inteiro - valor 1)

    o processo pai imprime o valor inicial dessa variável; em seguida, cria o processo filho e espera-o

    o processo filho acessa esta variável, realiza uma operação (por exemplo, adição - valor 2, totalizando 3), modificando o valor; em seguida, o processo filho termina

    o processo pai realiza uma outra operação (por exemplo, multiplicação - valor 4, totalizando 12), modificando novamente o valor, e imprime novamente a variável

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