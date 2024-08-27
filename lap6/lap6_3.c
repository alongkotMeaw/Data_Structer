#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, k, k2 = 0, l;
    scanf("%d", &n);
    scanf(" %d", &k);
    // printf("%d %d\n",n,k);
    int list[n];

    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &list[k2]);
        // printf("add %d at index%d loop %d\n ", list[k2], k2, i);
        k2 = (k2 + 1) % n;
    }

    // printf("l == %d k2 == %d\n",l,k2);
    for (int i = k - 1; i >= 0; i--)
    {
        printf("%d ", list[i]);
    }

    for (int i = k; i < n; i++)
    {
        printf("%d ", list[i]);
    }

    return 0;
}
