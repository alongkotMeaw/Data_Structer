#include <stdio.h>
#include <stdbool.h>
void main(){
    bool prime = true;

    int n;
    scanf("%d",&n);
    for(int i = 3; i < n; ){
        if(n%1 == 0){
            prime = false;
            break;
        }
        i = i+2;
    }

    if(prime)
        printf("yes");
    else
        printf("no");

}
