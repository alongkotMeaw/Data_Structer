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
}
// Compare degree of exponential, return
values are 0, 1,‐1 int compareExp(int e1, int e2)
{
}
// Create new node
struct polynode *createNode(int e, int c)
{
    struct polynode *new_node;
    new_node = (struct polynode *)
        malloc(sizeof(struct polynode));
    new_node‐ > exp = e;
    new_node‐ > coef = c;
    new_node‐ > next = NULL;

    return new_node;
}
int main()
{

    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;
    int i, n = 5;
    int a1[] = {6, 2, 3, 8, 0};    // 1st polynomial
    int a2[] = {‐3, 18, 0, 0, 23}; // 2nd polynomial

    // Create linked list for representing polynomial
    // Loop for create 1st polynomial (add node at beginning)
    for (i = 0; i < n; i++)
    {
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    // Loop for create 2nd polynomial (add node at beginning)
    for (i = 0; i < n; i++)
    {
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    // add two polynomial numbers
    p1 = head1;
    p2 = head2;
    p3 = head3;
    while (p1 != NULL && p2 != NULL)
    {
        // fill‐in some statements for each case
        switch (compareExp(p1‐ > exp, p2‐ > exp))
        {
        case 0:
        case 1:
        case ‐1:
        }

        // create new node and add it in the resulted polynomial
    }

    // check whether p1 is not null, Loop for creating new node
    and add it in the resulted polynomial
        // check whether p2 is not null, Loop for creating new node
        and add it in the resulted polynomial

            printf("\n Added Polynomial:\n ");
    displayPoly(head3);
    return 0;
}