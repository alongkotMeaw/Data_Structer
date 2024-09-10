#include <stdio.h>
#include <stdlib.h>
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
        if (ptr->next != NULL && ptr != head)
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

int main()
{

    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;
    int i, n = 5;
    int a1[] = {6, 2, 3, 8, 0};    // 1st polynomial
    int a2[] = {-3, 18, 0, 0, 23}; // 2nd polynomial

    // Create linked list for representing polynomial
    // Loop for create 1st polynomial (add node at beginning)
    // int n = sizeof(a1) / sizeof(a1[0]); // Number of coefficients
    i = 0;
    struct polynode *head1 = createNode(n - 1, a1[n - 1]);
    struct polynode *current = head1;

    for (int i = 1; i < n; i++)
    {
        struct polynode *new_node = createNode(n - 1 - i, a1[n - i - 1]);
        current->next = new_node;
        current = new_node;
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    // Loop for create 2nd polynomial (add node at beginning)
    i = 0;
    struct polynode *head2 = createNode(n - 1, a2[n - 1]);
    struct polynode *current2 = head2;

    for (int i = 1; i < n; i++)
    {
        struct polynode *new_node = createNode(n - 1 - i, a2[n - i - 1]);
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
        // fill‐in some statements for each case
        // printf("p1 is %dx^%d p2 is %dx^%d case %d\n",p1->coef,p1->exp,p2->coef,p2->exp,compareExp(p1-> exp, p2-> exp));
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
        // printf("new node  %dx^%d next add = %x\n\n",p3->coef,p3->exp,p3->next);
        // create new node and add it in the resulted polynomial
    }

    // check whether p1 is not null, Loop for creating new nodeand add it in the resulted polynomial
    // check whether p2 is not null, Loop for creating new nodeand add it in the resulted polynomial

    printf("\nAdded Polynomial:\n");
    displayPoly(head3);

    return 0;
}