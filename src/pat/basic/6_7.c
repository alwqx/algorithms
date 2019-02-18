#include <stdio.h>
#include <math.h>

// https://pintia.cn/problem-sets/14/problems/739
int IsTheNumber(const int N);

int main() {
    int n1, n2, i, cnt;
    scanf("%d %d", &n1, &n2);
    cnt=0;

    for(i=n1; i<=n2; i++) {
        if(IsTheNumber(i))
            cnt++;
    }

    printf("cnt=%d\n", cnt);
    return 0;
}

int IsTheNumber(const int N) {
    int s, n, i, a[10];
    for(i=0; i<10; i++)
        a[i] = 0;
    
    s = sqrt(N);
    if(s*s == N) {
        int tmp = N;
        for(; tmp>0; tmp/=10) {
            n = tmp%10;
            a[n]++;
        }
        for(i=0; i<10; i++)
            if(a[i]>=2)
                return 1;
    }

    return 0;
}