#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int cnt;

void *thread(void *num);

int main(int argc, char** argv)
{    
    int layer = atoi(argv[1]);
    cnt = (2 << layer - 1) / 2 - 2;
    if (layer > 1)
    {
        pthread_t children[2];
        int left = 1;
        int right = 2;
	pthread_create(&children[0], NULL, thread, (void *) &left);
        pthread_create(&children[1], NULL, thread, (void *) &right);
        pthread_join(children[0], NULL);
        pthread_join(children[1], NULL);
    }
    printf("Thread %d done\n", 0);
    exit(0);
}

void *thread(void *num)
{
    int *numpt = (int *) num;
    int id = *numpt;
    if (cnt >= id)
    {
        pthread_t children[2];
        int left = id * 2 + 1;
        int right = id * 2 + 2;
        pthread_create(&children[0], NULL, thread, (void *) &left);
        pthread_create(&children[1], NULL, thread, (void *) &right);
        pthread_join(children[0], NULL);
        pthread_join(children[1], NULL);
    }
    printf("Thread %d done\n", id);
    return NULL;
}
