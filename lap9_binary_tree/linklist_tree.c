#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
} Treenode;
Treenode *Root;

Treenode *createNode(char);
void SetLeft(Treenode *, char);
void SetRight(Treenode *, char);
void preorder(Treenode *);
void postorder(Treenode *);

int main()
{
    Treenode *pn, *tnode;

    // create Exptree for Lab8
    // create root node
    tnode = createNode('*');
    if (Root == NULL)
        Root = tnode;

    // create node level 1
    SetLeft(Root, '+');
    SetRight(Root, '-');

    // create node level 2 '+'
    pn = Root->leftChild;
    SetLeft(pn, '*');
    SetRight(pn, '/');

    // create node level 2 '-'
    pn = Root->rightChild;
    SetLeft(pn, 'E');
    SetRight(pn, 'F');

    // create node level 3 '*'
    pn = Root->leftChild->leftChild;
    SetLeft(pn, 'A');
    SetRight(pn, 'B');

    // create node level 4 '/'
    pn = Root->leftChild->rightChild;
    SetLeft(pn, 'C');
    SetRight(pn, 'D');

    // call preorder and postorder
    printf("Prefix: ");
    preorder(Root);
    printf("\n");

    printf("Postfix: ");
    postorder(Root);
    printf("\n");

    free(tnode);
    free(pn);

    return 0;
}

/// ********************************************* define function ********************************************* ///

Treenode *createNode(char new_data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = new_data;
    new_node->leftChild = NULL; // set all child node is null
    new_node->rightChild = NULL;
    return new_node;
}

void SetLeft(Treenode *mother, char data)
{
    if (mother->leftChild == NULL) // check for node is not in use
    {
        Treenode *new_node = createNode(data);
        mother->leftChild = new_node;
    }
    else
        printf("node in use\n");
}

void SetRight(Treenode *mother, char data)
{
    if (mother->rightChild == NULL) // check for node is not in use
    {
        Treenode *new_node = createNode(data);
        mother->rightChild = new_node;
    }
    else
        printf("node in use\n");
}

// in progress
void preorder(Treenode *node_print)
{
    if (node_print != NULL)
    {
        printf("%c ", node_print->data);
        preorder(node_print->leftChild);
        preorder(node_print->rightChild);
    }
}
void postorder(Treenode *node_print)
{
    if (node_print != NULL)
    {
        postorder(node_print->leftChild);
        postorder(node_print->rightChild);
        printf("%c ", node_print->data);
    }
}
