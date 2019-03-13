// https://eoj.i64d.com/problem/3536/
#include <stdio.h>

int main() {
    long long int i, N;
    scanf("%lld", &N);

    long long int s1, a, b;
    s1 = N*(N+1)/2;
    printf("%lld\n", s1);

    a=N*4-5, b=N-1;
    for(i=2; i<=(N+1)/2; i++) {
        s1 = s1 + 1 + a*b;
        a -= 8;
        b -= 2;
        printf("%lld\n", s1);
    }

    if(N%2 == 1) {
        a=3, b=1;
        for(; i<=N; i++) {
            s1 = s1 - a*b;
            a += 8;
            b += 2;
            printf("%lld\n", s1);
        }
    } else {
        s1 += 4;
        printf("%lld\n", s1);
        a=2, b=7;
        i++;
        for(; i<=N; i++) {
            s1 = s1-a*b;
            a += 2;
            b += 8;
            printf("%lld\n", s1);
        }
    }

    return 0;
}