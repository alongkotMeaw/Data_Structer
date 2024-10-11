#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Treenode
{
    char data;
    struct Treenode *leftChild, *rightChild;
    struct Treenode *mother;
} Treenode;

Treenode *Root = NULL;

struct Treenode *createNode(char data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

void Tree_insert(char data)
{
    Treenode *new_node = createNode(data);
    if (Root == NULL)
    {
        Root = new_node;
        return;
    }

    struct Treenode *y = NULL;
    struct Treenode *ptr = Root;

    while (ptr != NULL)
    {
        y = ptr;
        if (data < ptr->data)
            ptr = ptr->leftChild;
        else
            ptr = ptr->rightChild;
    }

    if (data < y->data)
    {
        y->leftChild = new_node;
    }
    else
    {
        y->rightChild = new_node;
    }
    new_node->mother = y;
}

void Inorder(struct Treenode *ptr)
{
    if (ptr != NULL)
    {
        printf("%c ", ptr->data);
        Inorder(ptr->leftChild);
        Inorder(ptr->rightChild);
    }
}
void main()
{
    char input[20] = "COMPUTER2";
    // scanf("%s", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A')
        {
            Tree_insert(input[i]);
        }
        else if (input[i] == '2')
        {
            Root = Root;
            Inorder(Root);
        }
    }
}
