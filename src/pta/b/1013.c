// https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112
#include <stdio.h>

#define MAXN 10000

int prime(int n) {
    int flag = 1;
    int i;
    if(n==1 || n==2 || n==3)    return flag;
    if (n%6!=1 && n%6!=5)       return 0;

    for(i=5; i*i<=n; i+=6)
        if(n%i==0 || n%(i+2)==0) {
            flag = 0;
            break;
        }

    return flag;
}

int main() {
    int M, N;
    int i=0, len=0;
    scanf("%d %d", &M, &N);

    long int a[MAXN] = {0};
    for(i=1; len<=N; i++)
        if(prime(i)) a[len++] = i;

    int c = 0;
    for(i=M; i<len; i++) {
        if(c == 9) {
            printf("%d\n", a[i]);
            c = 0;
            continue;
        }
        if(i == len-1)  printf("%d\n", a[i]);
        else            printf("%d ", a[i]);
        c++;
    }
    
    return 0;
}