#include <stdio.h>

// https://pintia.cn/problem-sets/14/problems/740
int Factorial(const int N);

int main() {
    int N, NF;
    scanf("%d", &N);

    NF = Factorial(N);
    if(NF) printf("%d!=%d\n", N, NF);
    else printf("Invalid input!\n");

    return 0;
}

int Factorial(const int N) {
    if(N==0) return 1;
    if(N<0) return 0;
    int sum = 1, n = N;
    while(n>0) {
        sum *= n;
        n--;
    }

    return sum;
}