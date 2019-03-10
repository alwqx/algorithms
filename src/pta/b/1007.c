// https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744
#include <stdio.h>
#include <stdlib.h>

void build(long int *, long int *, long int);

int main() {
    long int i, j, N;
    scanf("%ld", &N);
    long int *a = (long int *) malloc(sizeof(long int)*(N+1));

    i = 1;
    build(a, &i, N);
    
    // printf("len of prime array is %ld\n", i);
    // for(j=1; j<i; j++)
    //     printf("%ld ", a[j]);
    // putchar('\n');
    // for(j=i-1; j>=1; j--)
    //     printf("%ld ", a[j]);
    // putchar('\n');

    long int count = 0;
    for(j=1; j<=i-2; j++)
        if(a[j+1]-a[j] == 2) count++;
    printf("%ld\n", count);
    return 0;
}

int prime(long int n) {
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

void build(long int *a, long int *len, long int N) {
    long int k;
    for(k=1; k<=N; k++) {
        if(prime(k)) {
            a[*len] = k;
            (*len)++;
        }
    }
}