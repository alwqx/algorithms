#include <stdio.h>

int fib[101];
void initFib() {
    int i;
    fib[0] = fib[1] = 1;
    for(i=2; i<=100; i++) fib[i] = fib[i-1]+fib[i-2];
}

int isPrime(long int n) {
    int flag = 1;
    long int i;
    if(n==1 || n==2 || n==3)    return flag;
    if (n%6!=1 && n%6!=5)       return 0;

    for(i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0) {
            flag = 0;
            break;
        }

    return flag;
}
bool mark[10001];
void initPrime() {
    int i, j;
    mark[0] = mark[1] = false;
    mark[2] = true;
    
    for(i=3; i<=10000; i+=2) {
        mark[i] = true;
        mark[i+1] = false;        
    }

    for(i=3; i<=10000; i+=2) {
        if(mark[i])
            for(j=i+i; j<=10000; j+=i) mark[j] = false;
    }
}

int main() {
    initFib();
    initPrime();

    int i, a, b, sum;
    while(scanf("%d %d", &a, &b) != EOF) {
        sum = 0;
        for(i=fib[a]; i<=fib[b]; i++)
            if(mark[i]) sum++;
        printf("%d\n", sum);
    }

    return 0;
}