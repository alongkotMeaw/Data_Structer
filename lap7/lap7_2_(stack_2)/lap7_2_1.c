#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    char op;
    struct list *next;

} list;

list *top = NULL;
int max_prio;

void pop()
{
    list *ptr = top;
    while (ptr != NULL)
    {
        // op_return = ptr->op;
        if (ptr->op == '(')
            break;
        printf("%c", ptr->op);
        ptr = ptr->next;
    }
    top = ptr;
    free(ptr);
}

void push(char op, int prio)
{
    list *new_list = (list *)malloc(sizeof(list));
    new_list->op = op;
    // check if top NULL
    if (top == NULL)
    {
        max_prio = prio;
        top = new_list;
        new_list->next = NULL;
    }
    else if (op == '(')
    {
        max_prio = 0;
        new_list->next = NULL;
        top = new_list;
    }
    else if (max_prio < prio)
    {
        max_prio = prio;
        new_list->next = NULL;
        top = new_list;
    }
    else
    {
        pop();
        if (top == NULL)
        {
            top = new_list;
            new_list->next = NULL;
        }
        else
        {
            new_list->next = NULL;
            top = new_list;
        }
        max_prio = prio;
    }
}

void print()
{
    list *ptr = top;
    print("\n All in stack \n");
    while (ptr != NULL)
    {
        // op_return = ptr->op;
        printf("%c", ptr->op);
        ptr = ptr->next;
    }
    print("\n");
}
int main()
{
    char n;
    // +- 1 : */ 2 / () 0
    while ((n = getchar()) != '\n')
    {
        // printf("%c", n);

        switch (n)
        {
        case '+':
            // printf("\nCase  +\n");
            push('+', 1);
            print();
            break;

        case '-':
            // printf("\nCase  -\n");
            push('-', 1);
            print();
            break;

        case '*':
            // printf("\nCase  *\n");
            push('*', 2);
            break;
        case '/':
            // printf("\nCase  /\n");
            push('/', 2);
            print();
            break;
        case '^':
            // printf("\nCase  ^\n");
            push('^', 3);
            print();
            break;
        case '(':
            // printf("\nCase  (\n");
            push('(', 0);
            print();
            break;
        case ')':
            // printf("\nCase  )\n");
            pop();
            break;
        default:
            printf("%c", n);
            break;
        }
    }
    pop();

    return 0;
}
