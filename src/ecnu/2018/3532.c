// https://eoj.i64d.com/problem/3532/
#include <stdio.h>
#include <string.h>
#include <math.h>

void process(long int n);

int main() {
    long int i, N, n;
    scanf("%ld", &N);
    char s[] = "1101001000100001000001000000100000001000000001000000000";
    int l = strlen(s);
    for(i=0; i<N; i++) {
        scanf("%ld", &n);
        if(n<l) printf("%c\n", s[n-1]);
        else process(n);
    }

    return 0;
}

long int alg(long int n) {
    return n*(n+1)/2;
}

void process(long int N) {
    long int i;

    for(i=(int) sqrt(N); i<=N; i++)
        if(alg(i)<N && alg(i+1)>=N) break;
    
    if(alg(i)+1 == N)   printf("1\n");
    else                printf("0\n");
}