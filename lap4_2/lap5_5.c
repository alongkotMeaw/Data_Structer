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
    if (pos == 0)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                printf("Position out of range\n");
                free(newNode);
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void insertAtEnd(int data)
{
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL; // Initialize prev to NULL

    if (head == NULL)
    {
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
    Node *ptr = head;
    head = ptr->next;
    head->prev = NULL;
    free(ptr);
}

void deleteAtEnd()
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    struct Node *temp = head;
    

    for (int i = 0; temp != NULL && i < pos - 1; i++) {//-1 for fix index
        temp = temp->next;
    }
    //printf("temp delete = %d",temp->data);
    
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    temp->prev = NULL;
    temp->next = NULL;
    free(temp);
}


int main()
{
    char input[30] = "N1N2N3PDA2P";
    int i = 0;
    // scanf("%s", input);
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
                //printf("check  Position = %d\n",pos);
                int num = 0;
                while (i < strlen(input) && input[i] >= '0' && input[i] <= '9')
                {
                    num = num * 10 + (input[i] - '0');
                    i++;
                }
                // printf("check  num = %d\n",num);
                insertAtPosition(pos, num);
            }
        }
        else if (input[i] == 'D')
        {
            // printf("check 1");
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
            
            else if(input[i] == 'A'){
             i++;
               int pos = 0;
               pos = input[i] - '0';
               i++;
               //printf("pos = %d",pos);
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
            // printf("i == %d ====== %d",i,strlen(input));
            // break;
        }
    }

    return 0;
}