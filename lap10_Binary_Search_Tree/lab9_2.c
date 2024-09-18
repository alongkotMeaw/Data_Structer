#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
int main()
{
   int i, count = 20;
   int num[count];

   srand((unsigned)time(NULL)); // Initializes random number generator
   printf("Number before sorting\n");
   for (i = 0; i < count; i++)
   {
      num[i] = rand(); // random number between 0-32767
      Tree_insert(num[i]);
      printf("%d ", num[i]);
   }
   printf("\nNumber after sorting\n");
   Inorder(Root);
   return 0;
}
