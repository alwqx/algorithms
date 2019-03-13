// https://eoj.i64d.com/problem/3532/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    long long int t,p;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &p);
        double x=(1+sqrt(1.0+8.0*(p-1)))/2.0;
        if(x-(long long int)x==0) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}

/*
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
}*/