// https://eoj.i64d.com/problem/3533/
#include <stdio.h>

int main() {
    int M, N, S;
    scanf("%d %d %d", &M, &N, &S);

    int i, male=0, female=0;
    for(i=0; i<S; i++) {
        printf("%d %d\n", male+1, female+1);
        male = (male+1)%M;
        female = (female+1)%N;
    }

    return 0;
}