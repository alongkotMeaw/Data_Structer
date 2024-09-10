#include <stdio.h>
#include <stdbool.h>
#define MAX 10
int numCompare=0,numSwap=0;
//swap
void swap(int *n1,int *n2){
     int ch = *n1;
     *n1 = *n2;
     *n2 = ch;
     numSwap++;

}

// Display all element in array
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void SelectionSort(int A[], int n)
{
 for(int i = 0; i <= n-2; i++){
     int min = i;
     for(int j = i + 1; j < n; j++){
         numCompare++;
         if(A[j] < A[min])
            min = j;
     }
     //swap_round++;
     swap(&A[i],&A[min]);
 }

}

void InsertionSort(int A[], int n)
{
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0){
            numCompare++;
            if(A[j] < A[j - 1]){
               swap(&A[j],&A[j - 1]);
               //j -= 1;
            }
            j -= 1;


        }

    }
}

void BubbleSort(int A[], int n)
{
    bool check = true;
    for(int i = 0; i < n  && check == true ;i++){
        check = false;
        for(int j = n - 1; j > i; j--){ //9
            numCompare++;
            if(A[j] < A[j-1]){
                //swap_round++;
               swap(&A[j],&A[j-1]);
               check = true;
            }
        }
    }

}



int main()
{
    int A[MAX],B[MAX],C[MAX];
    int i;
    //best case
    /*
     for (i=0; i< MAX; i++)
     A[i] = i+1;
     */

    //worstcase

    for (i=0; i< MAX; i++)
    A[i] = 10-i;


    //random 1 -30
    /*
    srand((unsigned) time(NULL));
    for (i=0; i< MAX; i++){
            A[i] = rand()%30 +1;
    }*/
    DisplayArray(A, MAX);
    printf("\n");
    //SelectionSort(A, MAX);              //Call Sorting Function
    //InsertionSort(A,MAX);
    BubbleSort(A,MAX);
    DisplayArray(A, MAX);
    printf("compare = %d swap = %d",numCompare,numSwap);











    return 0;
}
