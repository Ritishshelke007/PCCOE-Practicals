#include <pthread.h>

#include <stdio.h>

int balance = 1000; // Initial balance

void *credit(void *cno) {

    balance += 100; // Credit operation

    printf("Credit %d: New balance is %d\n", (*((int *)cno)), balance);

}

void *debit(void *dno) {

    balance -= 100; // Debit operation

    printf("Debit %d: New balance is %d\n", (*((int *)dno)), balance);

}

void *reader(void *rno) {

    printf("Reader %d: Current balance is %d\n", (*((int *)rno)), balance);

}

int main() {

    pthread_t readers[5], writers[5];



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

    return 0;

}

