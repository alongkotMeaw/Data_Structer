#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int checck = 1;
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

int pop(int data)
{
    if (Top == NULL || data != Top->data)
        checck = 0;
    else
    {
        node *ptr = Top;
        Top = ptr->next;
        free(ptr);
    }
}
int display()
{
    int count = 0;

    node *ptr = Top;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int main()
{
    char n;
    while ((n = getchar()) != '\n')
    {
        // printf("%s ", &n);
        char str_math[7] = "[{(]})";
        for (int i = 0; i < 3; i++)
        {
            if (n == str_math[i])
                push(i);
        }
        for (int j = 3; j < 7; j++)
        {
            if (n == str_math[j])
                pop((j - 3));
        }
    }
    if (checck == 0)
        printf("-1");
    else if (Top == NULL)
        printf("0");
    else
        printf("%d", display());
    return 0;
}