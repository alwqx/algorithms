#include <stdio.h>

bool valid(long long x) {
    if(x%7 == 0) return true;

    int m;
    long long ret=0;
    while(x) {
        m = x%10;
        ret += m;
        if(m == 7) return true;
        x /= 10;
    }

    if(ret%7 == 0) return true;

    return false;
}

int main() {
    long long m, n;
    scanf("%lld %lld", &m, &n);

    long long i, ret=0;
    for(i=m; i<n; i++)
        if(!valid(i)) ret += i*i;

    printf("%lld\n", ret);
}
