#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
  int data;
  struct Treenode *leftChild, *rightChild;
  struct Treenode *mother;
};

struct Treenode *Root = NULL;

struct Treenode *createNode(int data)
{
  struct Treenode *new_node = (struct Treenode *)malloc(sizeof(struct Treenode));
  new_node->data = data;
  new_node->leftChild = NULL;
  new_node->rightChild = NULL;
  new_node->mother = NULL;
  return new_node;
}

void Tree_insert(int data)
{
  struct Treenode *new_node = createNode(data);
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
    Inorder(ptr->leftChild);
    printf("%d ", ptr->data);
    Inorder(ptr->rightChild);
  }
}

struct Treenode *Tree_find(struct Treenode *ptr, int num_find)
{
  if (ptr == NULL || ptr->data == num_find)
    return ptr;

  if (num_find < ptr->data)
    return Tree_find(ptr->leftChild, num_find);
  else
    return Tree_find(ptr->rightChild, num_find);
}

struct Treenode *FindMin(struct Treenode *ptr)
{
  while (ptr && ptr->leftChild != NULL)
    ptr = ptr->leftChild;
  return ptr;
}

struct Treenode *FindMax(struct Treenode *ptr)
{
  while (ptr && ptr->rightChild != NULL)
    ptr = ptr->rightChild;
  return ptr;
}

struct Treenode *Tree_delete(struct Treenode *root, int num_delete)
{
  if (root == NULL)
    return root;

  if (num_delete < root->data)
    root->leftChild = Tree_delete(root->leftChild, num_delete);
  else if (num_delete > root->data)
    root->rightChild = Tree_delete(root->rightChild, num_delete);
  else
  {
    if (root->leftChild == NULL)
    {
      struct Treenode *temp = root->rightChild;
      free(root);
      return temp;
    }
    else if (root->rightChild == NULL)
    {
      struct Treenode *temp = root->leftChild;
      free(root);
      return temp;
    }

    struct Treenode *temp = FindMin(root->rightChild);
    root->data = temp->data;
    root->rightChild = Tree_delete(root->rightChild, temp->data);
  }
  return root;
}

int main()
{
  int a[] = {56, 26, 200, 18, 28, 190, 213, 12, 24, 27};
  int i, size;
  size = sizeof(a) / sizeof(a[0]);
  for (i = 0; i < size; i++)
    Tree_insert(a[i]);

  printf("Min=%d\n", FindMin(Root)->data);
  printf("Max=%d\n", FindMax(Root)->data);

  struct Treenode *p = Tree_find(Root, 190);
  if (p != NULL)
    printf("Found\n");
  else
    printf("Not found\n");

  Inorder(Root);
  printf("\n");

  Root = Tree_delete(Root, 190);
  Root = Tree_delete(Root, 26);

  Inorder(Root);
  printf("\n");

  return 0;
}
