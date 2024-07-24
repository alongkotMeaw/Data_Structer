#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
   int data;
   struct node *next;
} node;
node *head = NULL;

node *newNode(int v)
{
   node *new_node;
   new_node = (node *)malloc(sizeof(node));
   new_node->data = v;
   new_node->next = NULL;

   return new_node;
}

void DisplayLL() // �ѧ�ѹ�����������
{
   struct node *ptr;
   ptr = head;
   while (ptr != NULL)
   {
      printf("Node val= %d \n", ptr->data);
      ptr = ptr->next;
   }
   printf("\n");
}

int main()
{
   head = newNode(1);
   head->next = newNode(2);
   head->next->next = newNode(3);
   head->next->next->next = newNode(4);

   DisplayLL();
   return 0;
}
