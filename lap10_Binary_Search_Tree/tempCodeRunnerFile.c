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

struct Treenode *Tree_find(struct Treenode *ptr, char num_find)
{
    if (ptr == NULL || ptr->data == num_find)
        return ptr;

    if (num_find < ptr->data)
        return Tree_find(ptr->leftChild, num_find);
    else
        return Tree_find(ptr->rightChild, num_find);
}
void Tree_insert(char data)
{
    if (Tree_find(Root, data) != NULL)
    {
        return;
    }

    Treenode *new_node = createNode(data);
    if (Root == NULL)
    {
        Root = new_node;
        return;
    }

    Treenode *ptr = Root;
    Treenode *prev = NULL;
    while (ptr != NULL)
    {
        prev = ptr;
        if (ptr->data < data)
        {
            ptr = ptr->rightChild;
        }
        else
        {
            ptr = ptr->leftChild;
        }
    }

    if (prev->data < data)
    {
        prev->rightChild = new_node;
    }
    else
    {
        prev->leftChild = new_node;
    }
    new_node->mother = prev;
}

void Inorder(struct Treenode *ptr, int choice)
{
    if (ptr != NULL) // preorder
    {
        if (choice == 2)
        {
            Inorder(ptr->leftChild, choice);
            Inorder(ptr->rightChild, choice);
            printf("%c ", ptr->data);
        }
        else if (choice == 3)
        {
            Inorder(ptr->leftChild, choice);
            printf("%c ", ptr->data);
            Inorder(ptr->rightChild, choice);
        }
        else if (choice == 4)
        {
            printf("%c ", ptr->data);
            Inorder(ptr->leftChild, choice);
            Inorder(ptr->rightChild, choice);
        }
    }
}

void main()
{
    char input[30] = "C2O2M2P2U2T2E2R2";
    // scanf("%s", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A')
        {
            Tree_insert(input[i]);
        }
        else if (input[i] == '2' || input[i] == '3' || input[i] == '4')
        {
            Inorder(Root, input[i] - '0'); // con to int
            printf("\n");
        }
    }
}
