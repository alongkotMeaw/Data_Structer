#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
    char n[10], num[20] = "", n_read;
    int TOP = -1;
    do
    {
        scanf("%s", &n);
        if (!strcmp(n, "WRITE"))
        {
            // printf("WRITE");
            scanf("%c", &n_read);
            TOP++;
            num[TOP] = n_read;
        }
        else if (!strcmp(n, "UNDO"))
        {
            TOP--;
            // printf("UNDO");
        }
        else if (!strcmp(n, "REDO"))
        {
            TOP++;
            // printf("REDO");
        }
        else if (!strcmp(n, "READ"))
        {
            // printf("READ");
            if (TOP == -1)
                printf(" Blank document ");
            else
                for (int i = 0; i <= TOP; i++)
                    printf("%c ", num[i]);
            printf("\n");
        }

    } while (strcmp(n, "END"));
    return 0;
}
