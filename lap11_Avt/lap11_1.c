#include <stdio.h>
#include <stdlib.h>

typedef struct Treenode
{
    int data;
    struct Treenode *leftChild, *rightChild;
    struct Treenode *mother;
} Treenode;

Treenode *Root = NULL;

Treenode *createNode(int data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

void Tree_insert(int data)
{
    Treenode *new_node = createNode(data);
    if (Root == NULL)
    {
        Root = new_node;
        return;
    }

    Treenode *y = NULL, *ptr = Root;

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

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

int Height(Treenode *ptr)
{
    if (ptr == NULL)
        return 0;

    return (1 + max(Height(ptr->leftChild), Height(ptr->rightChild)));
}
int bf(Treenode *ptr)
{
    return (Height(ptr->leftChild) - Height(ptr->rightChild));
}

void inorder(Treenode *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        printf("(bf = %d)", bf(ptr));
        inorder(ptr->rightChild);
    }
}

int main()
{
    int a[] = {17, 3, 19, 1, 6, 18, 22, 4, 25};
    int i, size;
    size = sizeof(a) / sizeof(a[0]);
    for (i = 0; i < size; i++)
        Tree_insert(a[i]);
    inorder(Root);
    return 0;
}