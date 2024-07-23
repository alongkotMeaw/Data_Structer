#include <stdio.h>
int gcd();
void main()
{
    int size;
    scanf("%d", &size);
    int num_1, num_2, result;
    scanf(" %d", &num_1);
    scanf(" %d", &num_2);
    result = gcd(num_1, num_2);
    for (int i = 2; i < size; i++)
    {
        scanf("%d", &num_1);
        result = gcd(result, num_1);
        // printf("i = %d result =%d\n",i,result);
    }
    printf("gdc = %d", result);
    return 0;
}

int gcd(int a, int b)
{
    while (a != 0 && b != 0)
    {
        if (a < b)
            b = b % a;
        else
            a = a % b;
    }
    return a + b;
}
