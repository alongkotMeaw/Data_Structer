
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char n[10], num[20] = "",n_read,op[10];
    int TOP = -1,index_op = -1;
    do
    {
        scanf("%s", n);
        if (!strcmp(n, "WRITE"))
        {
            //printf("WRITE :");
            scanf(" %c",&n_read);
            TOP++;
            num[TOP] = n_read;
            //printf("write %c add index %d\n",num[TOP],TOP);
        }
        else if (!strcmp(n, "UNDO"))
        {
            if(TOP != -1){
            op[++index_op] = num[TOP];
            //printf("undo  :%c",op);
            TOP--;
            // printf("UNDO");
            }
        }
        else if (!strcmp(n, "REDO"))
        {
            TOP++;
            num[TOP] = op[index_op];
            index_op--;
            // printf("REDO");
        }
        else if (!strcmp(n, "READ"))
        {
            //printf("READ :");
            if (TOP == -1)
                printf(" Blank document ");
            else
                for (int i = 0; i <= TOP; i++)
                    printf("%c", num[i]);
            printf("\n");
        }

    } while (strcmp(n, "END"));
    return 0;
}
