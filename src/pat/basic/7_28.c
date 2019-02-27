// https://pintia.cn/problem-sets/14/problems/808

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int loop, i, j, k, arr[N+1];
    arr[0] = 0;
    for(i=1; i<=N; i++)
        arr[i] = i;

    // i用于报数，j记录剩下的猴子数，k下一个参与报数的猴子下标
    i = 0; j = N; k = 1; loop=1;
    while(j!=1) {
        i = (++i)%3;
        printf("loop %d\n", loop++);
        printf("    i is %d\n", i);
        if(i == 0) { // get 3
            j--;
            arr[k] = 0;
        }
        
        k++;
        if(k>N) k-=N;
        while(arr[k] == 0) {
            k++;
            if(k>N)
                k -= N;
        }
        printf("    k is %d\n", k);
    }

    for(i=1; i<=N; i++)
        if(arr[i] != 0) printf("%d", i);
    return 0;
}