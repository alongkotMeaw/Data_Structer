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

  struct Treenode *y = NULL, *ptr = Root;

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
  while (ptr != NULL && ptr->data != num_find)
  {
    if (ptr->data > num_find)
    {
      ptr = ptr->leftChild;
    }
    else
    {
      ptr = ptr->rightChild;
    }
  }
  return ptr;
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

struct Treenode *Tree_delete(struct Treenode *t, int num_delete)
{
  struct Treenode *x, *y;
  x = Tree_find(t, num_delete);
  if (x == NULL)
    printf("value is not found in the tree\n");
  else
  {
    if (x->leftChild != NULL && x->rightChild != NULL)
    {
      // printf("case 1\n");
      y = FindMax(x->leftChild);
      x->data = y->data;
      Tree_delete(x->leftChild, y->data);
    }
    else if (x->leftChild != NULL)
    {
      // printf("case 2\n");
      x->data = x->rightChild->data;
      // x->rightChild = NULL;
    }
    else if (x->rightChild != NULL)
    {
      // printf("case 3\n");
      x->data = x->rightChild->data;
      // x->rightChild = NULL;
    }
    else
    {
      if (x->mother->data > x->data)
      {
        x->mother->leftChild = NULL;
      }
      else
      {
        x->mother->rightChild = NULL;
      }
      // printf("case 4\n");
    }
  }
}

/*                                  56
                          26               200
                      18        28     190     213
                  12      24
*/

int main()
{
  int a[] = {56, 26, 200, 18, 28, 190, 213, 12, 24, 27};
  int i, size;
  size = sizeof(a) / sizeof(a[0]);
  for (i = 0; i < size; i++)
    Tree_insert(a[i]);

  printf("Min=%d\n", FindMin(Root)->data);
  printf("Max=%d\n", FindMax(Root)->data);

  //
  struct Treenode *p = Tree_find(Root, 190);
  // printf("found == %d",p->data);
  if (p != NULL)
    printf("Found\n");
  else
    printf("Not found\n");

  Tree_delete(Root, 190);
  Tree_delete(Root, 26);

  Inorder(Root);
  printf("\n");

  return 0;
}
