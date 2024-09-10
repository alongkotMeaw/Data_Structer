#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct list
{
    int num;
    struct list *next;
} list;

list *top = NULL;

void push(int n)
{
    // printf("n input == %d\n", n);
    list *new_list = (list *)malloc(sizeof(list));
    new_list->num = n;
    new_list->next = top;
    top = new_list;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    int re_n = top->num;
    list *temp = top;
    top = top->next;
    free(temp);
    return re_n;
}

int main()
{
    char n;
    int result = 0, num_1, num_2;

    // +- 1 : */ 2 / () 0
    while ((n = getchar()) != '\n')
    {
        switch (n)
        {
        case '+':
            num_2 = pop();
            num_1 = pop();
            result = num_1 + num_2;
            push(result);
            break;

        case '-':
            num_2 = pop();
            num_1 = pop();
            result = num_1 - num_2;
            push(result);
            break;

        case '*':
            num_2 = pop();
            num_1 = pop();
            result = num_1 * num_2;
            push(result);
            break;

        case '/':
            num_2 = pop();
            num_1 = pop();
            result = num_1 / num_2;
            push(result);
            break;

        case '^':
            num_2 = pop();
            num_1 = pop();
            result = pow(num_1, num_2);
            push(result);
            break;

        default:
            if (n >= '0' && n <= '9')
            {
                push(n - '0');
            }
            break;
        }
    }

    printf("\n%d\n", result);

    return 0;
}
