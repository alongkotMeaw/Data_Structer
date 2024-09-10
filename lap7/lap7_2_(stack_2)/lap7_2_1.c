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
    while (top != NULL && top->op != '(') // stop if null or found (
    {
        list *ptr = top;
        printf("%c", ptr->op);
        top = top->next;
        free(ptr);
    }
    if (top != NULL && top->op == '(')
    { // move 1 for de (
        max_prio = 0;
        list *ptr = top;
        top = top->next;
        free(ptr);
    }
}

void push(char op, int prio)
{
    list *new_list = (list *)malloc(sizeof(list));
    new_list->op = op;

    if (top == NULL)
    {
        max_prio = prio;
        new_list->next = NULL;
        top = new_list;
    }
    else if (op == '(')
    {
        max_prio = 0;
        new_list->next = top;
        top = new_list;
    }
    else if (max_prio < prio)
    {
        max_prio = prio;
        new_list->next = top;
        top = new_list;
    }
    else
    {
        pop();
        new_list->next = top;
        top = new_list;
        max_prio = prio;
    }
}

int main()
{
    char n;
    // +- 1 : */ 2 / () 0
    while ((n = getchar()) != '\n')
    {
        switch (n)
        {
        case '+':
            push('+', 1);
            break;

        case '-':
            push('-', 1);
            break;

        case '*':
            push('*', 2);
            break;
        case '/':
            push('/', 2);
            break;
        case '^':
            push('^', 3);
            break;
        case '(':
            push('(', 0);
            break;
        case ')':
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
