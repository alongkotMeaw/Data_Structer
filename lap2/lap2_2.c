#include <stdio.h>

int checkPrime(int num) { //chek that prime
    for (int i = 2; i*i <= num; i++) {
        if (num%i==0) {
            return 0;
        }
    }
    return 1;
}

int minPrimes(int num) {
    int cont = 2;
    for (int i = num; cont < num; i--) {
        if (checkPrime(i)==1) {
            //printf("%d\n",i);
            return i;
            //cont++;
        }
    }
}

int maxPrimes(int num) {
    int cont = 2;
    for (int i = num; cont < num; i++) {
        if (checkPrime(i)) {
            //printf("%d\n",i);
            return i;
            //cont++;
        }
    }
}

int main() {
    int quant;
    scanf("%d", &quant);
    int primeMin = minPrimes(quant);
    int primeMax = maxPrimes(quant);
    if(primeMax - quant >= quant - primeMin)
        printf("%d",primeMin);
    else
        printf("%d",primeMax);
    return 0;
}
