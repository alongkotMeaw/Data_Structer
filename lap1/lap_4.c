#include <stdio.h>

typedef struct
{
    char code[6];
    int point;
} student;

int main()
{
    int round,mixPoint = 0;
    scanf("%d", &round);
    student st[round];
    for (int i = 0; i < round; i++)
    {
        scanf("%s", st[i].code);
        scanf("%d", &st[i].point);
        mixPoint = mixPoint + st[i].point;
    }

    int avg = mixPoint/round,pass = 0;

    for (int i = 0; i < round; i++)
    {
        if(avg < st[i].point)
                    pass++;
    }
    printf("%d\n",pass);

    for (int i = 0; i < round; i++)
    {
        if(avg < st[i].point)
        printf("%s\n",st[i].code);
    }

    return 0;
}
