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

Treenode *createNode(char data)
{
    Treenode *new_node = (Treenode *)malloc(sizeof(Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}

Treenode *Tree_find(struct Treenode *ptr, char num_find)
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
    if (ptr == NULL)
        return;

    if (choice == 2)
    {
        printf("%c", ptr->data);
        Inorder(ptr->leftChild, choice);
        Inorder(ptr->rightChild, choice);
    }
    else if (choice == 3)
    {
        Inorder(ptr->leftChild, choice);
        printf("%c", ptr->data);
        Inorder(ptr->rightChild, choice);
    }
    else if (choice == 4)
    {
        Inorder(ptr->leftChild, choice);
        Inorder(ptr->rightChild, choice);
        printf("%c", ptr->data);
    }
}

void findMaxMin(Treenode *ptr)
{
    Treenode *find_max = ptr;
    /// min
    while (ptr && ptr->leftChild != NULL)
        ptr = ptr->leftChild;
    printf("%c", ptr->data);
    /// max
    while (find_max && find_max->rightChild != NULL)
        find_max = find_max->rightChild;
    printf("%c", find_max->data);
}

Treenode *FindMin(Treenode *ptr)
{
    while (ptr && ptr->leftChild != NULL)
        ptr = ptr->leftChild;
    return ptr;
}

Treenode *Tree_delete(Treenode *root, char num_delete)
{
    if (root == NULL)
    {
        printf("-1");
        return root;
    }
    if (num_delete < root->data)
        root->leftChild = Tree_delete(root->leftChild, num_delete);
    else if (num_delete > root->data)
        root->rightChild = Tree_delete(root->rightChild, num_delete);
    else
    {
        if (root->leftChild == NULL)
        {
            Treenode *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            Treenode *temp = root->leftChild;
            free(root);
            return temp;
        }

        Treenode *temp = FindMin(root->rightChild);
        root->data = temp->data;
        root->rightChild = Tree_delete(root->rightChild, temp->data);
    }
    return root;
}

struct Treenode *find(struct Treenode *ptr, char num_find, int *h)
{

    if (ptr == NULL || ptr->data == num_find)
        return ptr;
    (*h)++;
    if (num_find < ptr->data)
        return find(ptr->leftChild, num_find, h);
    else
        return find(ptr->rightChild, num_find, h);
}

void main()
{
    char input[70];
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A')
        {
            Tree_insert(input[i]);
        }
        else if (input[i] == '2' || input[i] == '3' || input[i] == '4')
        {
            Inorder(Root, input[i] - '0'); // con to int
        }
        else if (input[i] == '5')
        {
            findMaxMin(Root);
        }
        else if (input[i] == '0')
        {
            Tree_delete(Root, input[++i]);
        }
        else if (input[i] == '1')
        {
            int h = 0;
            if (find(Root, input[++i], &h) == NULL)
            {
                printf("-1");
            }
            else
                printf("%d", h);
        }
    }
}
