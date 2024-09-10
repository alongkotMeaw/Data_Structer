#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *next;

} Treenode;
Treenode *Top = NULL;
Treenode *Root = NULL;

// function list
// stack
void push(Treenode *);
Treenode *pop();
// tree
Treenode *createNode(char new_data);
Treenode *pushtree(Treenode *node_lef, Treenode *node_right, Treenode *mother);
void preinorder();
void main(int argc, char const *argv[])
{
    char op[51];
    Treenode *node_left, *node_right;
    scanf("%s", op);
    printf("input length = %d\n", strlen(op));
    for (int i = strlen(op) - 1; i >= 0; i--) // read at end to first // -1 for index start 0
    {
        if ('0' <= op[i] && op[i] <= '9')
        {
            // printf("2 case %c\n", op[i]);
            push(createNode(op[i]));
        }
        else
        {
            // printf("1 case %c\n", op[i]);
            node_left = pop();
            node_right = pop();
            // printf("left = %c\n", node_left->data);
            // printf("right = %c\n", node_right->data);
            //  if (Top == NULL)
            //  printf("top == null");
            push(pushtree(node_left, node_right, createNode(op[i]))); // pust back
        }
    }

    // call preorder and postorder
    printf("Prefix: ");
    preinorder(Top);
    printf("\n");
}

// stack
void push(Treenode *node_add) /// use left child is next
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
    mother->rightChild = node_right;
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
void preinorder(Treenode *node_print)
{
    if (node_print != NULL)
    {
        preinorder(node_print->leftChild);
        printf("%c ", node_print->data);
        preinorder(node_print->rightChild);
    }
}

///////////////////// od code at to use /////////////////////