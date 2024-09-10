#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

char infix[50], var_n[50];
int index_infix = 0, index_var_n = 0, var_n_int[50];

void m_infix(char infix_op[])
{
    typedef struct list
    {
        char op;
        int prio;
        struct list *next;
    } list;

    list *top = NULL;
    int max_prio;

    void pop()
    {
        while (top != NULL && top->op != '(') // Stop if null or found (
        {
            list *ptr = top;
            infix[index_infix++] = ptr->op;
            top = top->next;
            free(ptr);
        }
        if (top != NULL && top->op == '(')
        { // Move 1 for de ('
            char op_list[] = "+-*/^";
            list *ptr = top;
            if (top->next == NULL)
            {
                max_prio = 0;
            }
            else
            {
                top = top->next;
                for (int i = 0; i < strlen(op_list); i++)
                {
                    if (top->op == op_list[i])
                    {
                        if (i < 2)
                            max_prio = 1;
                        else if (i < 4)
                            max_prio = 2;
                        else
                            max_prio = 3;
                    }
                }
                free(ptr);
            }
        }
    }

    void push(char op, int prio)
    {
        list *new_list = (list *)malloc(sizeof(list));
        new_list->prio = prio;
        new_list->op = op;

        if (top == NULL)
        {
            max_prio = prio;
            new_list->next = NULL;
            top = new_list;
        }
        else if (op == '(')
        {
            new_list->prio = prio;
            max_prio = prio;
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

    // Main
    for (int i = 0; i < strlen(infix_op); i++)
    {
        switch (infix_op[i])
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
            infix[index_infix++] = infix_op[i];
            var_n[index_var_n++] = infix_op[i];
            break;
        }
    }
    pop();
}

int prefix(char infix[], char var_n[])
{
    typedef struct list
    {
        int num;
        struct list *next;
    } list;

    list *top = NULL;

    void push(int n)
    {
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

    // Main
    int result = 0, num_1, num_2;
    for (int i = 0; i < strlen(infix); i++)
    {
        switch (infix[i])
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
            result = ceil(pow(num_1, num_2));
            push(result);
            break;

        default:
            for (int j = 0; j < strlen(var_n); j++)
            {
                if (infix[i] == var_n[j])
                {
                    push(var_n_int[j]);
                    break;
                }
            }
            break;
        }
    }

    return result;
}

int main()
{
    char input[50];

    printf("Enter infix: ");
    scanf("%s", input);

    m_infix(input);
    printf("Postfix: %s\n", infix);

    bool check;
    for (int i = 0; i < strlen(var_n); i++)
    {
        check = false; // for check if var
        // for check if var
        for (int j = 0; j < i - 1; j++)
        {
            if (var_n[i] == var_n[j])
            {
                var_n_int[i] = var_n_int[j];
                check = true;
                break;
            }
        }
        if (check)
            continue;

        printf("Enter value of %c: ", var_n[i]);
        scanf(" %d", &var_n_int[i]);
    }
    printf("Result: %d\n", prefix(infix, var_n));

    return 0;
}