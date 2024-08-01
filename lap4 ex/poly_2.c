#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Declare structure of Linked List
struct polynode
{
    int coef;
    int exp;
    struct polynode *next;
};
struct polynode *head1 = NULL;
struct polynode *head2 = NULL;
struct polynode *head3 = NULL;
// Display all element in linked list
void displayPoly(struct polynode *head)
{
    struct polynode *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->exp == 0 && ptr->coef == 0)
            ;
        else if (ptr->exp == 0)
            printf("%d", ptr->coef);
        else if (ptr->coef == 0)
            ;
        else if (ptr->exp == 1)
            printf("%dx", ptr->coef);
        else
            printf("%dX^%d", ptr->coef, ptr->exp);
        if (ptr->next != NULL)
            printf("+");
        ptr = ptr->next;
    }
    printf("\n");
}
// Compare degree of exponential, return

// values are 0, 1,‐1
int compareExp(int e1, int e2)
{
    if (e1 == e2)
        return 0;
    else if (e1 < e2)
        return 1;
    else if (e1 > e2)
        return -1;
}

// Create new node
struct polynode *createNode(int e, int c)
{
    struct polynode *new_node;
    new_node = (struct polynode *)malloc(sizeof(struct polynode));
    new_node->exp = e;
    new_node->coef = c;
    new_node->next = NULL;

    return new_node;
}

void bubbleSort(int arr[], int n)
{
    int temp;
    int swapped;

    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

int main()
{
    srand(time(NULL));
    int i = 0;
    int size_a1 = 0, size_a2 = 0, input;
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;
    // 1st polynomial
    int *a1 = (int *)malloc(size_a1 * sizeof(int));
    printf("==== Create 1st Polynomial ====\n");
    for (;;)
    {
        printf("Enter exponential 1:");
        scanf("%d", &input);
        if (input < 0)
            break;
        size_a1++;
        a1 = (int *)realloc(a1, size_a1 * sizeof(int));
        a1[size_a1 - 1] = input;
    }

    // sort exponential

    bubbleSort(a1, size_a1);
    printf("size a1 = %d", size_a1);
    // asian in linklist
    struct polynode *head1 = createNode(a1[size_a1 - 1], (rand() % 30 + 1));
    struct polynode *current = head1;

    for (int i = 1; i < size_a1; i++)
    {
        struct polynode *new_node = createNode(a1[size_a1 - i - 1], (rand() % 30 + 1));
        current->next = new_node;
        current = new_node;
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    // 2st polynomial
    int *a2 = (int *)malloc(size_a2 * sizeof(int));
    printf("==== Create 2nd Polynomial ====\n");
    for (;;)
    {
        printf("Enter exponential 2:");
        scanf("%d", &input);
        if (input < 0)
            break;
        size_a2++;
        a2 = (int *)realloc(a2, size_a1 * sizeof(int));
        a2[size_a2 - 1] = input;
    }

    // sort exponential
    bubbleSort(a2, size_a2);
    // asian in linklist
    struct polynode *head2 = createNode(a2[size_a2 - 1], (rand() % 30 + 1));
    struct polynode *current2 = head2;

    for (int i = 1; i < size_a2; i++)
    {
        struct polynode *new_node = createNode(a2[size_a2 - i - 1], (rand() % 30 + 1));
        current2->next = new_node;
        current2 = new_node;
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    // add two polynomial numbers
    p1 = head1;
    p2 = head2;

    int x, e;
    // createNode head
    head3 = createNode(0, 0);
    p3 = head3;
    while (p1 != NULL && p2 != NULL)
    {

        switch (compareExp(p1->exp, p2->exp))
        {
        case 0:
            // printf("check case 1 \n");
            x = p1->coef + p2->coef;
            e = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
            break;
        case 1:
            x = p2->coef;
            e = p2->exp;
            p2 = p2->next;
            break;
        case -1:
            x = p1->coef;
            e = p1->exp;
            p1 = p1->next;
            break;
        }
        struct polynode *new_node = createNode(e, x);
        p3->next = new_node;
        p3 = new_node;
    }

    printf("\nAdded Polynomial:\n");
    displayPoly(head3->next);

    return 0;
}