#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int checck = 1;
typedef struct node
{
    char data;
    struct node *next;
} node;
node *Top = NULL;

void push(char data)
{
    printf("push -- %c\n", data);
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

int pop(char data)
{
    printf("pop -- %c\n", Top->data);
    if (Top == NULL || data != Top->data)
        checck = 0;
    else
    {
        node *ptr = Top;
        Top = ptr->next;
        free(ptr);
    }
}

int main()
{
    char n[100];
    scanf("%s", n);
    for (int i = 0; i < strlen(n); i++)
    {
        if (strlen(n) / 2 > i)
        {
            push(n[i]);
        }
        else if (strlen(n) / 2 == i && strlen(n) % 2 == 1) // if %2 == 1
            continue;
        else
            pop(n[i]);
    }
    if (checck == 1)
        printf(" Palindrome ");
    else
        printf("no");
}