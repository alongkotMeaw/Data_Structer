#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,k2,l,check = 1;
    scanf(" %d",&n);
    scanf(" %d",&k);
    //printf("%d %d\n",n,k);
    int list[n];
    k2 = k;
    k = k%n;
    for(int i = 0 ; i < n ; i++)
    {
        scanf(" %d",&list[k]);
        //printf("add %d at index%d loop %d\n ",list[k],k,i);
        if( (i+1) == k2 && check)
        {
            l = k;
            check = 0;
        }
        k = ( k + 1 )%n;

    }
    //printf("l == %d k2 == %d\n",l,k2);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",list[l]);
        l--;
        if(l < 0) l = n;
    }

    return 0;
}
