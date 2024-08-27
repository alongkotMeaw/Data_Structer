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

    char n;
    while ((n = getchar()) != '\n')
    {

        if ('A' <= n)
        {
            if (size >= maxsize)
                printf("!");
            else if (Front == -1 && Rear == -1) // first Q
            {
                Front = 0;
                Rear = 0;
                Q[Rear] = n;
                // printf("\ncheck 1 :%c add %d", Q[Rear], size);
                size++;
            }
            else
            {
                Rear = (Rear + 1) % maxsize;
                Q[Rear] = n;
                // printf("\ncheck 1 :%c add %d", Q[Rear], size);
                size++;
            }
        }
        else if (n == '0')
        {
            printf("%d%d", Front, Rear);
        }
        else if (n > '0')
        {
            for (int i = n - '0'; i > 0; i--)
            {
                if (size > 0)
                {
                    printf("%c", Q[Front]);
                    Front = (Front + 1) % maxsize;
                    size--;
                }
                else
                {
                    // Front = -1;
                    // Rear = -1;
                    printf("!");
                    break;
                }
            }
        }
    }
    return 0;
}
