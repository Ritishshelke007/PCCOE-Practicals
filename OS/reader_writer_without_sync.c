#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_READERS 5
#define NUM_WRITERS 5
#define MAX_EXECUTIONS 5

int shared_variable = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t readers_condition = PTHREAD_COND_INITIALIZER;
pthread_cond_t writers_condition = PTHREAD_COND_INITIALIZER;
int reader_executions = 0;
int writer_executions = 0;

void* reader(void* arg) {
    int id = *((int*)arg);
    while (reader_executions < MAX_EXECUTIONS) {
        // Reading the shared variable
        printf("Reader %d reads: %d\n", id, shared_variable);
        reader_executions++;
        sleep(1);  // Simulate some processing time
    }
    return NULL;
}

void* writer(void* arg) {
    int id = *((int*)arg);
    while (writer_executions < MAX_EXECUTIONS) {
        // Writing to the shared variable
        shared_variable++;
        printf("Writer %d writes: %d\n", id, shared_variable);
        writer_executions++;
        sleep(1);  // Simulate some processing time
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    // Create reader threads
    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    return 0;
}
