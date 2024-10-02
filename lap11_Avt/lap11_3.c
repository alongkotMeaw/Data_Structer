#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_avl = true;

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

// Right rotation
Treenode *rightRotate(Treenode *y)
{
    Treenode *x = y->leftChild;
    Treenode *T2 = x->rightChild;

    // Perform rotation
    x->rightChild = y;
    y->leftChild = T2;

    // Update mother pointers
    if (T2 != NULL)
    {
        T2->mother = y;
    }
    x->mother = y->mother;
    y->mother = x;

    printf("Right Rotate at Node: %d\n", y->data);

    return x; // New root after rotation
}

// Left rotation
Treenode *leftRotate(Treenode *x)
{
    Treenode *y = x->rightChild;
    Treenode *T2 = y->leftChild;

    // Perform rotation
    y->leftChild = x;
    x->rightChild = T2;

    // Update mother pointers
    if (T2 != NULL)
    {
        T2->mother = x;
    }
    y->mother = x->mother;
    x->mother = y;

    printf("Left Rotate at Node: %d\n", x->data);

    return y; // New root after rotation
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int Height(Treenode *ptr)
{
    if (ptr == NULL)
        return 0;
    return 1 + max(Height(ptr->leftChild), Height(ptr->rightChild));
}

int bf(Treenode *ptr)
{
    if (ptr == NULL)
        return 0;
    return Height(ptr->leftChild) - Height(ptr->rightChild);
}

// Insert a node and ensure the tree remains balanced
Treenode *insert(Treenode *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
    {
        node->leftChild = insert(node->leftChild, data);
        node->leftChild->mother = node;
    }
    else if (data > node->data)
    {
        node->rightChild = insert(node->rightChild, data);
        node->rightChild->mother = node;
    }
    else
    {
        return node;
    }

    // Get the balance factor of this node
    int balance = bf(node);

    // Left Left Case (Right Rotation)
    if (balance > 1 && data < node->leftChild->data)
    {
        return rightRotate(node);
    }

    // Right Right Case (Left Rotation)
    if (balance < -1 && data > node->rightChild->data)
    {
        return leftRotate(node);
    }

    // Left Right Case (Left Rotate then Right Rotate)
    if (balance > 1 && data > node->leftChild->data)
    {
        printf("Left-Right Double Rotate\n");
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    // Right Left Case (Right Rotate then Left Rotate)
    if (balance < -1 && data < node->rightChild->data)
    {
        printf("Right-Left Double Rotate\n");
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

void inorder(Treenode *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->leftChild);
        printf("%d (Bf = %d)", ptr->data, bf(ptr));
        inorder(ptr->rightChild);
    }
}

int main()
{
    int input;
    do
    {
        printf("insert node: ");
        scanf("%d", &input);
        if (input < 0)
            break;
        Root = insert(Root, input);
    } while (1);

    inorder(Root);
    return 0;
}
