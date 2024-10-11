#include <stdio.h>

#define MAX 4

void getDegree(int G[MAX][MAX], int k, int *in_order, int *out_order)
{
    for (int i = 0; i < MAX; i++)
    {
        if (G[k][i] != 0)
        {
            (*out_order)++;
        }
    }
    for (int i = 0; i < MAX; i++)
    {
        if (G[i][k] !0 = 1)
        {
            (*in_order)++;
        }
    }
}

int main()
{
    int G[MAX][MAX] = {{0, 1, 1, 1},
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0}};
    int in_order = 0, out_order = 0, k = 0;

    getDegree(G, k, &in_order, &out_order);

    printf("In-degree of node %d: %d\n", k, in_order);
    printf("Out-degree of node %d: %d\n", k, out_order);

    return 0;
}
