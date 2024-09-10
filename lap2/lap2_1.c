#include <stdio.h>
#include <stdbool.h>
#include "end.h"
void main()
{
    START();
    bool prime = true;
    int n;
    scanf("%d", &n);
    if (n % 2 == 0 && n != 2)
        prime = false;
    else
        for (int i = 3; i * i <= n; i += 2)
        { // n
            if (n % i == 0)
            { // check int
                prime = false;
                break;
            } // 1
        }

    if (prime)
        printf("yes");
    else
        printf("no");

    END();
}
