/////////////////////////////////////////////main session////////////////////////////////////////////////////
// to use rename main to test_main(char str[])
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <string.h>
#define NUM_THREADS 1024           // num of theard
char test_input[] = "4+6*(5+6)-8"; // your test in put
const int round_test = 2147483647;
int n = 200; // Starting with a smaller value
int test_main(char str[]);
void *fill_array(void *arg);
typedef struct
{
    int thread_id;
    char *x;
} thread_data;

int main(int argc, char const *argv[])
{
    char *x = (char *)malloc(n * sizeof(char));
    if (x == NULL)
    {
        perror("Failed to allocate memory");
    }

    for (; n <= round_test; n = n * 2)
    {
        x = (char *)realloc(x, n * sizeof(char));
        if (x == NULL)
        {
            perror("Failed to reallocate memory");
        }
        // asian array x
        // create threads
        thread_data t_data[NUM_THREADS];
        pthread_t threads[NUM_THREADS];
        for (int i = 0; i < NUM_THREADS; i++)
        {
            t_data[i].thread_id = i;
            t_data[i].x = x;
            pthread_create(&threads[i], NULL, fill_array, (void *)&t_data[i]);
        }

        // check all thred end
        for (int i = 0; i < NUM_THREADS; i++)
        {
            pthread_join(threads[i], NULL);
        }
        //////////////////////////////////////////////////////
        clock_t start_t, end_t;
        double total_t;
        unsigned long int total_c;
        start_t = clock();
        for (int l = 0; l < 3; l++) // test 3 round
            test_main(x);           // Call your function here

        end_t = clock();
        total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
        total_c = (unsigned long int)total_t;

        printf("n =%d\nApprox milliseconds:%lu  %f\n", n, total_c / 3, total_t / 3.0);
    }

    free(x);
    return 0;
}

/// ptheard
void *fill_array(void *arg)
{
    thread_data *data = (thread_data *)arg;
    int start = (n / NUM_THREADS) * data->thread_id;
    int end = (data->thread_id == NUM_THREADS - 1) ? n : start + (n / NUM_THREADS);

    for (int i = start; i < end; i += strlen(test_input))
    {
        if (i + strlen(test_input) <= n)
        {
            strncpy(&data->x[i], test_input, strlen(test_input));
        }
    }

    return NULL;
}

//////////////////////////////////////////progam to test ////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        // printf("%c", ptr->op);
        top = top->next;
        free(ptr);
    }
    if (top != NULL && top->op == '(')
    { // move 1 for de (
        char op_list[] = "+-*/^";
        list *ptr = top;
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

int test_main(char str[])
{
    char n;
    // +- 1 : */ 2 / () 0
    for (int i = 0; i < strlen(str); i++)
    {
        n = str[i];
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
            // printf("%c", n);
            break;
        }
    }
    pop();
}
