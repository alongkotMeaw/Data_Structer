#ifndef END_H_ /* Include guard */
#define END_H_

#include <stdio.h>
#include <time.h>
clock_t start_t, end_t;
double total_t;
int START()
{
    start_t = clock();
}

void END()
{
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; // clock
    printf("Toatal time %d", total_t * 1000);
}

#endif // ALONO_H_
