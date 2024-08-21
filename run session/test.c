
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS

typedef struct
{
    int *x;
    int start;
    int end;
    int max_diff;
} ThreadData;

void *maxdiff2_thread(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    int i, j, diff, max = 0;

    for (i = data->start; i < data->end - 1; i++)
    {
        for (j = i + 1; j < data->end; j++)
        {
            diff = abs(data->x[i] - data->x[j]);
            if (diff > max)
            {
                max = diff;
            }
        }
    }
    data->max_diff = max;
    pthread_exit(0);
}

int main()
{
    int n = 3200;
    int *x = (int *)malloc(n * sizeof(int));

    for (; n < 2500000; n = n * 2)
    {
        x = (int *)realloc(x, n * sizeof(int));
        clock_t start_t, end_t;
        double total_t;
        start_t = clock();

        pthread_t threads[NUM_THREADS];
        ThreadData thread_data[NUM_THREADS];
        int segment = n / NUM_THREADS;
        int max_diff = 0;

        for (int i = 0; i < NUM_THREADS; i++)
        {
            thread_data[i].x = x;
            thread_data[i].start = i * segment;
            thread_data[i].end = (i == NUM_THREADS - 1) ? n : (i + 1) * segment;
            pthread_create(&threads[i], NULL, maxdiff2_thread, &thread_data[i]);
        }

        for (int i = 0; i < NUM_THREADS; i++)
        {
            pthread_join(threads[i], NULL);
            if (thread_data[i].max_diff > max_diff)
            {
                max_diff = thread_data[i].max_diff;
            }
        }

        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        printf("n=%d\nMax Difference: %d\nApprox milliseconds: %f\n", n, max_diff, total_t * 1000);
    }

    free(x);
    return 0;
}
