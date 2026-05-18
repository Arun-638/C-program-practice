#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, db;
int readcount = 0;

void *reader(void *arg) {
    int id = *((int *)arg);

    sem_wait(&mutex);
    readcount++;

    if (readcount == 1) {
        sem_wait(&db);
    }

    sem_post(&mutex);

    printf("Reader %d is reading\n", id);
    sleep(1);

    sem_wait(&mutex);
    readcount--;

    if (readcount == 0) {
        sem_post(&db);
    }

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);

    sem_wait(&db);

    printf("Writer %d is writing\n", id);
    sleep(1);

    sem_post(&db);

    return NULL;
}

int main() {
    pthread_t r[5], w[5];
    int r_id[5], w_id[5];

    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);

    for (int i = 0; i < 5; i++) {
        r_id[i] = i + 1;
        w_id[i] = i + 1;

        pthread_create(&r[i], NULL, reader, &r_id[i]);
        pthread_create(&w[i], NULL, writer, &w_id[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(r[i], NULL);
        pthread_join(w[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&db);

    return 0;
}