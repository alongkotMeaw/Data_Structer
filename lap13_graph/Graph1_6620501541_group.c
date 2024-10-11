#include <stdio.h>
#include <stdlib.h>
int n; // number of vertices
typedef struct node
{
    int data;
    struct node *next;
} node;
node *Top = NULL;

void push(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    if (Top == NULL)
    {
        new_node->next = NULL;
        Top = new_node;
    }
    else
    {
        new_node->next = Top;
        Top = new_node;
    }
}

int pop()
{
    int data = -1;
    if (Top == NULL)
        printf("\nStack is Empty\n");
    else
    {
        node *ptr = Top;
        data = Top->data;
        Top = ptr->next;
        free(ptr);
    }
    return data;
}
// stack functions & variables
// queue functions & variables
// function list
void DFT(char V[], int G[n][n], int status[]);
void BFT(char V[], int G[n][n], int status[]);
// BFT();
int main()
{
    int i, j;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    int status[n]; // Array for tracking status of each node
    int G[n][n];   // Array for representing Graph
    char V[n + 1]; // Array for representing set of vertices
    printf("Enter node's name:");
    // Fill in your code
    scanf(" %s", V);
    printf("Enter the adjacency matrix:\n");
    // Fill in your code
    for (int i = 0; i < n; i++)
        status[i] = 1;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            scanf(" %d", &G[row][col]);
        }
    }

    printf("DFS Traversal: ");
    DFT(V, G, status);
    for (int i = 0; i < n; i++)
        status[i] = 1;
    printf("\nBFS Traversal: ");
    BFT(V, G, status);
}

void DFT(char V[], int G[n][n], int status[])
{

    push(0);
    status[0] = 2;
    while (Top != NULL)
    {
        int index_pop = pop();
        printf("%c ", V[index_pop]);
        status[index_pop] = 3;
        for (int check_node = 0; check_node < n; check_node++)
        {
            if (G[index_pop][check_node] != 0 && status[check_node] == 1)
            {
                push(check_node);
                status[check_node] = 2;
            }
        }
    }
}

int Q[50] = {0};
int Front = -1, Rear = -1;
int size = 0;
void enqueue(int data)
{
    if (size == 50)
        printf("\nQueue is Full\n");
    else
    {
        Q[Rear] = data;
        Rear = (Rear + 1) % 50;
        size++;
    }
}

int dequeue()
{
    int data;
    data = Q[Front];
    Front++;
    size--;
    return data;
}
void BFT(char V[], int G[n][n], int status[])
{
    enqueue(0);
    status[0] = 2;

    while (size != 0)
    {
        int index_pop = dequeue();
        printf("%c ", V[index_pop]);
        status[index_pop] = 3;
        for (int check_node = 0; check_node < n; check_node++)
        {
            if (G[index_pop][check_node] != 0 && status[check_node] == 1)
            {
                enqueue(check_node);
                status[check_node] = 2;
            }
        }
    }
}