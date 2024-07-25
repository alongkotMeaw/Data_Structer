#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *head = NULL;

node *newNode(int v)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;

    return new_node;
}

void DisplayLL() // �ѧ�ѹ�����������
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("Node val=%d,add=%X\t ", ptr->data, ptr);
        printf("Next node add=%X\n", ptr->next);
        ptr = ptr->next;
    }
}

bool is_Cricular(node *h)
{
    node *ptr = h->next;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        if (ptr == head)
            return true;
    }
    return false;
}

int main()
{
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    bool n = is_Cricular(head);
    if (!is_Cricular(head))
        printf("false");
    // DisplayLL();
    if (!is_Cricular(head))
    {
        struct node *ptr;
        node *preptr;
        ptr = head;
        while (ptr != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        printf("\nadd=%X\t ", ptr);
        preptr->next = head;
        // ptr = head;
        printf("\nadd=%X\t\n\n ", ptr);
    }
    // DisplayLL();

    if (!is_Cricular(head))
        printf("\nfalse");
    return 0;
}
