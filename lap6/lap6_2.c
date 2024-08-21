#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
typedef struct Node
{
    int data;
    struct Node *next;
} node;
node *Front = NULL;
node *Rear = NULL;

node *createnode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data)
{
    node *newNode = createnode(data);
    if (Rear == NULL)
    {
        Front = newNode;
        Rear = newNode;
    }
    else
    {
        Rear->next = newNode;
        Rear = newNode;
    }
}

int dequeue()
{
    if (Front == NULL)
    {
        printf("\nQueue is Empty\n");
        return -1;
    }
    else
    {
        node *ptr = Front;
        int data = Front->data;
        Front = Front->next;

        if (Front == NULL)
        {
            Rear = NULL;
        }
        free(ptr);
        return data;
    }
}

// Function to display the queue
void displayQ()
{
    if (Front == NULL)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        node *ptr = Front;
        printf("front [ ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("] rear\n");
    }
}

int main()
{
    int i, n;

    for (i = 1; i < 1000; i *= 2)
        enqueue(i);
    displayQ();

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        dequeue();
    displayQ();

    for (i = 10; i >= 1; i /= 2)
        enqueue(i);
    displayQ();

    return 0;
}
