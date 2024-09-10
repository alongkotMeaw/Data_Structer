#include <stdio.h>
#define HTsize 10
int hashArray[HTsize]= {0}; //hash table
int h(int k) //for generate hash function
{
    return k%HTsize;
}
void setHash(int n) //for insert number in hash table
{
    int index;
    index=h(n); //call genHashFn
    for(int i = 0; i < 10; i++)
    {
        if(i == 0) printf("%d mod 10 = %d\n",n,index);
        else printf("(%d + %d) mod 10 = %d\n",h(n),i*i,index);
        if(hashArray[index] == n){
                printf("duplicate number\n");
                break;
        }
        if(hashArray[index] == 0 )
        {
            hashArray[index] = n;
            printf("Put %d in H[%d]\n",n,index);
            break;
        }
        else
        {
            index = index + (i+1)*(i+1) - i*i;
            index = index%10;
        }
    }
}
int main()
{
    int n,h;

    for(int i =0; i<= 10; i++)
    {
        printf("Enter number:");
        scanf("%d",&n);
        if(n<=1) break;
        setHash(n);
    }
    if(n>=1) printf("Hash Table is full!\n");

//display hash table
for (h = 0; h < HTsize; h++)
    printf("%d [%d]\n", h,hashArray[h]);
return 0;
}
