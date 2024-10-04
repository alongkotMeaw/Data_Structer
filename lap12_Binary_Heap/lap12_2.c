#include <stdio.h>

int heap_input[100];

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int heap_input[], int heap_size, int i)
{
    int smallest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < heap_size && heap_input[left_child] < heap_input[smallest])
        smallest = left_child;

    if (right_child < heap_size && heap_input[right_child] < heap_input[smallest])
        smallest = right_child;

    // ถ้า smallest
    if (smallest != i)
    {
        swap(&heap_input[i], &heap_input[smallest]);
        heapify(heap_input, heap_size, smallest);
    }
}

void buildHeap(int heap_input[], int heap_size)
{

    for (int i = (heap_size / 2) - 1; i >= 0; i--)
    {
        heapify(heap_input, heap_size, i);
    }
}

void show(int *heap_input, int heap_size)
{
    int new_line = 1;
    for (int i = 0; i < heap_size; i++)
    {
        printf("%d ", heap_input[i]);
        if (i + 1 == new_line)
        {
            printf("\n");
            new_line = new_line * 2 + 1;
        }
    }
    printf("\n");
}

int is_heap(int heap_input[], int heap_size)
{
    for (int i = 0; i <= (heap_size - 2) / 2; i++)
    {
        int left_child_index = 2 * i + 1;
        int right_child_index = 2 * i + 2;

        if (left_child_index < heap_size && heap_input[i] > heap_input[left_child_index])
        {
            return 0;
        }
        if (right_child_index < heap_size && heap_input[i] > heap_input[right_child_index])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int heap_size;
    scanf("%d", &heap_size);

    for (int i = 0; i < heap_size; i++)
    {
        scanf("%d", &heap_input[i]);
    }

    if (is_heap(heap_input, heap_size))
    {
        printf("a Min-Heap\n");
    }
    else
    {
        printf("Not a Min-Heap\n");
        buildHeap(heap_input, heap_size);
        show(heap_input, heap_size);
    }

    return 0;
}
