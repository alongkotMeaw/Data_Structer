#include <stdio.h>

int check_palindrom(char *s)//check_palindrom
{
        int i,j;
        for(i=0;s[i];i++);

        for(i=i-1,j=0;i>j;i--,j++)
                if(s[i]!=s[j])
                    return 0;
        if(s[i]==s[j])
                return 1;
}

int checkPrime(int num) { //chek that prime
    for (int i = 2; i*i <= num; i++) {
        if (num%i==0) {
            return 0;
        }
    }
    return 1;
}

int Primes(int num,int j) {
    int cont = 2;
    for (int i = num; cont < num; i = i + j) {
         if (checkPrime(i)) {
            //printf("%d\n",i);
            char str[11];  // max int is 2147483647 need 11 index to stall
            sprintf(str, "%d", i);
            if(check_palindrom(str)) 
              return i;
            //cont++;
        }
    }
}

int main() {
    int quant;
    scanf("%d", &quant);
    int primeMin = Primes(quant,-1);
    int primeMax = Primes(quant,1);
    if(primeMax - quant >= quant - primeMin)
        printf("%d",primeMin);
    else
        printf("%d",primeMax);
}
