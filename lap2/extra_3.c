#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Define the maxdiff2 function to avoid compilation errors
void maxdiff2(int x[], int n)
{
    int i, j, diff, max = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            diff = abs(x[i] - x[j]);
            for (int l = 0; l < pow(n, 2); l++)
                if (diff > max)
                {
                    max = diff;
                }
        }
    }
}

int main()
{
    int n = 3000;
    int *x = (int *)malloc(n * sizeof(int));

    for (; n < 250000000; n = n * 2)
    {
        // ��Ѻ��Ҵ
        x = (int *)realloc(x, n * sizeof(int));
        clock_t start_t, end_t;
        double total_t;
        start_t = clock();
        // cal maxdiff2
        maxdiff2(x, n);
        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // clock
        printf("n=%d\n Approx milliseconds: %f\n", n, total_t * 1000);
    }
    free(x);
    return (0);
}
