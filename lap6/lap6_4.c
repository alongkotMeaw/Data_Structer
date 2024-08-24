#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 10
char Q[maxsize] = {0};
int Front = -1;
int Rear = -1;
int size = 0;
int main()
{
    char n[20];
    scanf("%s",n);
    int n_size = strlen(n);
    printf("n_size = %d size = %d\n",n_size,size);
    for(int i = 0; i < n_size ; i++)
    {
        printf("loop  for %c\n",n[i]);
        if('A' <= n[i])
        {
            if(size == maxsize)
                 printf("!");
            else if(Front == -1 && Rear == -1)  // first Q
            {
                Front = 0;
                Rear = 0;
                Q[Rear] = n[i];
                //printf("\ncheck 1 :%c add %d",Q[Rear],size);
                size++;
            }
            else
            {
                Q[Rear] = n[i];
                Rear = (Rear+1)%maxsize;
                //printf("\ncheck 1 :%c add %d",Q[Rear],size);
                size++;
            }




        }
        else if(n[i] == '0')
        {
            printf("%d%d",Front,Rear);


        }
        else if(n[i] > '0')
        {
            for(int i = n[i] - '0'; i > 0; i--)
            {
                if(size > 0)
                {
                    Front = (Front + 1)% maxsize;
                    Rear = (Rear + 1)% maxsize;
                    size--;

                }else{
                    printf("!");
                    break;
                }



            }
        }

    }

    printf("\ncheck out");
    return 0;
}
