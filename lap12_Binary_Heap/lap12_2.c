#include <stdio.h>
#include <math.h>
int heap_array[100];

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

int is_heap(int heap_array[], int round)
{

    for (int i = 0; i <= (round - 2) / 2; i++)
    {
        int left_child_index = 2 * i + 1;
        // Right child index
        int right_child_index = 2 * i + 2;

        if (left_child_index < round && arr[i] > arr[left_child_index])
        {
            return 0;
        }
        if (right_child_index < round && arr[i] > arr[right_child_index])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int heap_size, input;
    scanf("%d", &heap_size);
    if (is_heap(heap_array))
        for (int round = 0; round < heap_size; round++)
        {
            scanf("%d", &input);
            insertHeap(input, round, heap_array);
        }
    printf("saddddddddddd\n");
    show(heap_array, heap_size);

    return 0;
}
