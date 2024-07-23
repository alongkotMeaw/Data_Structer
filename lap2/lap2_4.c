#include <stdio.h>
#include <string.h>
#include <math.h>
void main(){
    int n;
    scanf("%d",&n);
    int result = 0;
    for(int j = 0; j <= n ;j++){
       // char str[12]; //max int is 2147483647 have 11 index
        //result++;
        for(int i = 1; j/i != 0; i *=10){
            result++;
        }
        
        
    }
    
    printf("%d",result);
}