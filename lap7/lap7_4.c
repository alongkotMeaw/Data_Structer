#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//                                      in progress   A72Bb27A
int checck = 1;
typedef struct node
{
    char data;
    struct node *next;
} node;

node *Top = NULL;

void push(char data)
{
    data = tolower(data);
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = Top;
    Top = new_node;
}

void pop(char data)
{
    data = tolower(data);
    if (Top == NULL || data != Top->data)
    {
        checck = 0;
    }
    else
    {
        node *ptr = Top;
        Top = ptr->next;
        free(ptr);
    }
}

int main()
{
    int ch_d = 1, size;
    char n[100];
    scanf("%s", n);
    size = strlen(n);
    //printf("size = %d\n", size);
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
        {
            push(n[i]);
        }
        else if (!(i == size / 2 && size % 2 == 1))
        {
            pop(n[i]);
        }
    }

    if (checck == 1)
    {
        //check double
        ch_d = 2;


            for (int i = 0; i < size / 2; i++)// check only size/2 for double
            {


                ch_d = 2;
                if (i < (size /4))
                {
                    //printf("%d = push -- %c\n", i, n[i]);
                    push(n[i]);
                }else if(size/4 == i)
                    continue;
                else if (i > size /4)
                {
                    pop(n[i]);
                    //printf("%d = pop -- %c\n", i, n[i]);
                }
            }

    }

   if (checck == 1 && ch_d == 2)
      printf(" double Palindrome ");
   else if (ch_d == 2)
      printf(" Palindrome ");
   else
      printf("no");
}
