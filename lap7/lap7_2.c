#include <stdio.h>
#include <stdbool.h>
#define maxsize 5
typedef struct node
{
    int data;
    struct node *next;
} node;
node *Top = NULL;

bool isEmpty()
{
    if (Top == NULL)
        return true;
    else
        return false;
}

void push(data)
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

int peek()
{
    if (Top == NULL)
        return -1;
    return Top->data;
}
void display()
{
    int i;
    if (Top == NULL)
        printf("\nStack is Empty\n");
    else
    {
        node *ptr = Top;
        while (ptr != NULL)
        {
            printf(" %d", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int item, option;

    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            if (Top == NULL)
                printf("\nStack is Empty\n");
            else
            {
                item = pop();
                printf("\n The value deleted from stack is: %d", item);
            }
            break;

        case 3:
            item = peek();
            if (item != -1)
                printf("\n The value stored at top of stack is: %d", item);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye ...\n");
            break;

        default:
            printf("Unknown option\n");
            break;

        } // end switch
    } while (option != 5);
    return 0;
} // alo