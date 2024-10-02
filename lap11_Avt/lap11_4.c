#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool check_avl = true;
bool find_status = false;

typedef struct Treenode
{
    char data;
    struct Treenode *leftChild, *rightChild;
    struct Treenode *mother;
} Treenode;

Treenode *Root = NULL;
Treenode *find_ptr = NULL;

Treenode *createNode(int data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

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

Treenode *leftRotate(Treenode *x)
{
    Treenode *y = x->rightChild;
    Treenode *T2 = y->leftChild;

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

    int balance = bf(node);

    if (balance > 1 && data < node->leftChild->data)
    {
        return rightRotate(node);
    }

    if (balance < -1 && data > node->rightChild->data)
    {
        return leftRotate(node);
    }

    if (balance > 1 && data > node->leftChild->data)
    {
        // printf("Left-Right Double Rotate\n");
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->rightChild->data)
    {
        // printf("Right-Left Double Rotate\n");
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

void inorder(Treenode *ptr, int choice)
{
    if (ptr != NULL)
    {
        if (choice == '2')
            printf("%c", ptr->data);
        inorder(ptr->leftChild, choice);
        if (choice == '3')
            printf("%c", ptr->data);
        inorder(ptr->rightChild, choice);
        if (choice == '4')
            printf("%c", ptr->data);
    }
}

void find(Treenode *ptr, char find_c)
{
    if (ptr != NULL)
    {
        if (ptr->data == find_c)
        {
            find_ptr = ptr;
            find_status = true;
        }
        find(ptr->leftChild, find_c);
        find(ptr->rightChild, find_c);
    }
}

int main()
{
    char input[101];
    scanf("%s", input);
    for (int round = 0; round < strlen(input); round++)
    {
        char choice = input[round];
        switch (choice)
        {
        case '2':
        case '3':
        case '4':
            inorder(Root, choice);
            break;
        case '1':
            round++;
            char c_find = input[round];
            find(Root, c_find);
            if (find_status)
            {
                printf("%d", (Height(find_ptr) - 1));

                find_status = false; // revalue for new round
            }
            else
                printf("-1");
            break;
        default:
            Root = insert(Root, choice);
            break;
        }
    }

    return 0;
}
