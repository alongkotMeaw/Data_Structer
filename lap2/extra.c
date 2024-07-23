#include <time.h>
#include <stdio.h>
void maxdiff2(int x[],int n) {
   int i,max,min,maxdiff;
   max=x[0];
   min=x[0];
   for(i=1;i<n;i++) {
         if(x[i]> max) max=x[i];
         if(x[i]< min) min=x[i];
   }
    maxdiff=max-min;
}

int main () {
   int n = 3200;
   int* x = (int*)malloc(n * sizeof(int));

   for(;n < 250000; n= n*2 ){
        //ปรับขนาด
        x = (int*)realloc(x, n * sizeof(int));
        clock_t start_t, end_t;
        double total_t;
        start_t = clock();
        //cal maxdiff2
        maxdiff2(x,n);
        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC; //clock
        printf("n=%d\n Approx milliseconds: %f\n",n, total_t  );

   }
   free(x);
   return(0);
}
