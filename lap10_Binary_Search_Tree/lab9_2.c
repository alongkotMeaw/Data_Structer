#include <stdio.h>
#include <stdlib.h>
struct Treenode {
 int data;
 struct Treenode *leftChild,*rightChild;
 struct Treenode *mother;
};
struct Treenode *Root=NULL;



int main()
{
   int i,count=20;
   int num[count];

   srand((unsigned) time(NULL));      //Initializes random number generator
   printf("Number before sorting\n");
   for(i=0;i<count;i++)
   {
      num[i]=rand();             //random number between 0-32767
      printf("%d ",num[i]);

   }
   printf("\nNumber after sorting\n");


   return 0;
}
