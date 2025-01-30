#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
pthread_mutex_t myMutex;

int mails = 0;

void *count(void *arg)
{
    for (int i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&myMutex);
        mails++;
        pthread_mutex_unlock(&myMutex);
    }
    return (NULL);
}

int main(void)
{
    pthread_mutex_init(&myMutex,NULL);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, count, NULL);
    pthread_create(&t2, NULL, count, NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    printf("%d\n",mails);
    pthread_mutex_destroy(&myMutex);
}