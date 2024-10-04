#include <stdio.h>
#include <math.h>
int heap_array[100];
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void insertHeap(int new_heap, int round)
{

    heap_array[round] = new_heap;

    int index = round;
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (heap_array[index] < heap_array[parent])
        {
            swap(&heap_array[index], &heap_array[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void show(int *heap_array, int heap_size)
{
    int new_line = 3;
    for (int i = 1; i <= heap_size; i++)
    {
        printf("%d ", heap_array[i - 1]);
        if (i == 1 || i % 3 == 0)
        {
            new_line = new_line * 2 + 1;
            printf("\n");
        }
    }
}

int main()
{
    int heap_size, input;
    scanf("%d", &heap_size);
    for (int round = 0; round < heap_size; round++)
    {
        scanf("%d", &input);
        insertHeap(input, round;
    }

    show(heap_array, heap_size);

    return 0;
}
