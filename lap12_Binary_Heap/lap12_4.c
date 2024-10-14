#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x, int *y);
void heapSort(int arr[], int n);
void show(int arr[], int n, int choice);
void heap(int arr[], int n, int i);

int main()
{
    int i, n = 20;
    srand((unsigned)time(NULL)); // Initializes random number generator
    int num[n];
    printf("Number before sorting\n");
    for (i = 0; i < n; i++)
    {
        num[i] = rand() % 100 + 1; // random number between 0-100
        printf("%d ", num[i]);
    }

    heapSort(num, n);
    printf("Sorting (A)scending order\n");
    printf("Sorting (D)escending order\n");
    printf("Select choice:");
    char choice;
    scanf("%c", &choice);
    if (choice == 'A')
    {
        printf("Number after sorting: Descending order");
        show(num, n, 1);
    }
    else
    {
        printf("Number after sorting: Ascending order");
        show(num, n, 2);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heap(arr, i, 0);
    }
}

void heap(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}

void show(int arr[], int n, int choice)
{
    if (choice == 1)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for (int i = n; i > 0; i--)
            printf("%d ", arr[i]);
        printf("\n");
    }
}