#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *next;
    struct Treenode *mother;

} Treenode;
Treenode *Top = NULL;
Treenode *Root = NULL;

// funcsion list
int numNode(Treenode *node_num);
void push(Treenode *node_add);
Treenode *pop();
Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother);
Treenode *createNode(char new_data);
void preinorder(Treenode *node_print); // Postfix
bool isleft(Treenode *node_check);
int sumnode(Treenode *node_sum);
int calculate(int x, int y, char opt);

//////////////////////////////////////////////////////////////////////////////////////////////////
int numNode(Treenode *node_num)
{

    if (node_num == NULL)
        return 0;
    return 1 + numNode(node_num->leftChild) + numNode(node_num->leftChild);
}

// stack
void push(Treenode *node_add)
{
    if (Top == NULL)
        Top = node_add;
    else
    {
        node_add->next = Top;
        Top = node_add;
    }
}

Treenode *pop()
{
    if (Top == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    Treenode *re_node = Top;
    Top = Top->next;
    return re_node;
}

Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother)
{
    mother->leftChild = node_lef;
    node_lef->mother = mother; // set mother
    node_right->mother = mother;
    mother->rightChild = node_right;
    // printf("mother = %c ,left = %c , right = %c");
    return mother;
}

// tree
Treenode *createNode(char new_data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = new_data;
    new_node->leftChild = NULL; // set all child node is null
    new_node->rightChild = NULL;
    return new_node;
}

void postfix(Treenode *node_print)
{
    if (node_print != NULL)
    {
        postfix(node_print->leftChild);
        postfix(node_print->rightChild);

        bool check_operrand = false;
        char operand[] = "+-*/^";
        for (int i = 0; i < strlen(operand); i++)
            if (node_print->data == operand[i])
            {
                check_operrand = true;
                break;
            }

        if (check_operrand)
        {
            printf("(");
            printf("%c", node_print->data);
            printf(")");
        }
        else
            printf("%c", node_print->data);
    }
}

bool isleft(Treenode *node_check)
{
    return (node_check->leftChild == NULL && node_check->rightChild == NULL);
}

int sumnode(Treenode *node_sum)
{
    if (node_sum == NULL)
        return 0;

    if (isleft(node_sum))
        return node_sum->data - '0'; // Assume leaf node stores char '0'-'9'

    int x = sumnode(node_sum->leftChild);
    int y = sumnode(node_sum->rightChild);
    char opt = node_sum->data;
    if (node_sum->data == '+')
        return x + y;
    if (node_sum->data == '-')
        return x - y;
    if (node_sum->data == '*')
        return x * y;
    if (node_sum->data == '/')
        return x / y;
    return 0; // if not mach all
}
