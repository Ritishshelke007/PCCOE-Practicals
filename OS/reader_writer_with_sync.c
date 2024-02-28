#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for a readers-writers problem using mutex and semaphore.
It demonstrates multiple readers and writers accessing a shared balance variable.
*/

sem_t wrt;
pthread_mutex_t mutex;
int balance = 1000; // Initial balance

void *credit(void *cno) {
    sem_wait(&wrt);
    balance += 100; // Credit operation
    printf("Credit %d: New balance is %d\n", (*((int *)cno)), balance);
    sem_post(&wrt);
}

void *debit(void *dno) {
    sem_wait(&wrt);
    balance -= 100; // Debit operation
    printf("Debit %d: New balance is %d\n", (*((int *)dno)), balance);
    sem_post(&wrt);
}

void *reader(void *rno) {
    pthread_mutex_lock(&mutex);
    printf("Reader %d: Current balance is %d\n", (*((int *)rno)), balance);
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t readers[5], writers[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    int rids[5] = {1, 2, 3, 4, 5}; // Reader IDs
    int wids[5] = {1, 2, 3, 4, 5}; // Writer IDs

    for (int i = 0; i < 5; i++) {
        pthread_create(&readers[i], NULL, reader, &rids[i]);
        pthread_create(&writers[i], NULL, credit, &wids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
        pthread_join(writers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
