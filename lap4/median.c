#include <stdio.h>
#include <stdbool.h>
int numCompare=0,numSwap=0;
//swap
void swap(int *n1,int *n2){
     int ch = *n1;
     *n1 = *n2;
     *n2 = ch;

}

// Display all element in array
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void BubbleSort(int A[], int n)
{
    bool check = true;
    for(int i = 0; i < n  && check == true ;i++){
        check = false;
        for(int j = n - 1; j > i; j--){ //9
            if(A[j] > A[j-1]){
               swap(&A[j],&A[j-1]);
               check = true;
            }
        }
    }

}



int main()
{
    int n,i;
    float median;
    printf("Enter n:");
    scanf("%d",&n);
    int A[n];
    //random
    srand((unsigned) time(NULL));
    for (i=0; i< n; i++)
      A[i] = rand()%100 +1;

    BubbleSort(A,n);
    DisplayArray(A,n);
    if(n%2 == 0)
       median =  ((float)A[n/2 - 1] + (float)A[n/2])/2;
    else
        median = A[n/2];

    printf("median = %.1f",median);







    return 0;
}
