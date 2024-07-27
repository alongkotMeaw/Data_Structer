#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;

void insertAtBeginning(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertAtPosition(int pos, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    /*
    if (pos == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
    }
    else
    {*/
    Node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        if (temp == NULL)
        {
            printf("Position out of range\n");
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    //}
}

void insertAtEnd(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void printList()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void printList_revert()
{
    Node *temp = head;
    if (temp == NULL)
        return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->prev;
    }
}

int searchList(int data)
{
    Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return pos;
        }
        temp = temp->next;
        pos++;
    }
    return -1;
}

void deleteAtStart()
{
    if (head == NULL)
        return;

    Node *ptr = head;
    head = ptr->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(ptr);
}

void deleteAtEnd()
{
    if (head == NULL)
        return;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    free(temp);
}

void deleteAtPosition(int pos)
{
    // pos =- 1;
    if (head == NULL)
        return;

    Node *temp = head;
    if (pos - 1 == 0)
    {
        head = temp->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    free(temp);
}

int main()
{
    char input[30]; //= "N3IF5IL2IF6PDA2DA2R";
    int i = 0;
    scanf("%s", input);
    while (i < strlen(input))
    {
        if (input[i] == 'N')
        {
            i++;
            int num = 0;
            while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            insertAtBeginning(num);
        }
        else if (input[i] == 'I')
        {
            i++;
            if (input[i] == 'F')
            {
                i++;
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
                {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                insertAtBeginning(num);
            }
            else if (input[i] == 'L')
            {
                i++;
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
                {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                insertAtEnd(num);
            }
            else if (input[i] == 'A')
            {
                i++;
                int pos = 0;
                pos = input[i] - '0';
                i++;
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
                {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                insertAtPosition(pos, num);
            }
        }
        else if (input[i] == 'D')
        {
            i++;
            if (input[i] == 'F')
            {
                i++;
                deleteAtStart();
            }
            else if (input[i] == 'L')
            {
                i++;
                deleteAtEnd();
            }
            else if (input[i] == 'A')
            {
                i++;
                int pos = 0;
                pos = input[i] - '0';
                i++;
                deleteAtPosition(pos);
            }
        }
        else if (input[i] == 'P')
        {
            i++;
            printList();
        }
        else if (input[i] == 'R')
        {
            i++;
            printList_revert();
        }
        else if (input[i] == 'S')
        {
            i++;
            int num = 0;
            while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
            {
                num = num * 10 + (input[i] - '0');
                i++;
            }
            int result = searchList(num);
            printf("%d", result);
        }
    }

    return 0;
}
