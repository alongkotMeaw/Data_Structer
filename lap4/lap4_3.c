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
/*
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}
*/
void BubbleSort(int A[], int n)
{
    bool check = true;
    for(int i = 0; i < n  && check == true ;i++){
        check = false;
        for(int j = n - 1; j > i; j--){ //9
            if(A[j] < A[j-1]){
               swap(&A[j],&A[j-1]);
               check = true;
            }
        }
    }

}



int main()
{
    int n,w;
    printf("Enter n:");
    scanf("%d %d",&n,&w);
    int A[n];
    //input
    for(int i = 0; i < n; i++)
        scanf(" %d",&A[i]);

    BubbleSort(A,n);
    int sum = 0,person = 0;
    for(int j = 0;sum <= w ; j++){
        sum += A[j];
        person++;
    }
    printf("%d",person -1);







    return 0;
}
