#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void DisplayLL() // �ѧ�ѹ�����������
{
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("Node val= %d \n", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void DisplayAddressLL()
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

int main()
{
    // 1.1 Code for creating Linked List with random number 1-100
    srand((unsigned)time(NULL));
    int n;
    scanf("%d", &n);
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = rand() % 100 + 1;
    new_node->prev = NULL;
    new_node->next = head;
    head = new_node;

    // Code for creating Linked List
    for (int i = 1; i < n; i++)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rand() % 100 + 1;
        new_node->next = head;
        new_node->prev = NULL;
        head->prev = new_node;
        head = new_node;
    }

    DisplayLL();
    DisplayAddressLL();
}
