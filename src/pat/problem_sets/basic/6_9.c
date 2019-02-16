#include <stdio.h>

// https://pintia.cn/problem-sets/14/problems/741
int Count_Digit(const int N, const int D);

int main() {
    int N, D;
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N,D));

    return 0;
}

int Count_Digit(const int N, const int D) {
    if(N == 0) return 1;
    
    int n=N, cnt=0;
    if(n<0) n=-n;

    while(n>0) {
        if(n%10 == D)
            cnt++;
        n/=10;
    }

    return cnt;
}