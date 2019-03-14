// https://eoj.i64d.com/problem/2568/
#include <stdio.h>

int main() {
    long long a, b, sum=0;
    int i, n, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        cnt = 0;
        scanf("%lld %lld", &a, &b);
        sum = a+b;
        while(sum){
            cnt++;
            sum /= 10;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}