#include <stdio.h>

int main() {
    int i, j, n, cnt, digit;
    long long a, b, ret;

    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%lld %lld", &a, &b);
        ret = a+b;
        cnt = 0;
        while(ret) {
                cnt++;
            ret /= 10;
        }
        printf("%d\n", cnt);
    }

   return 0;
}
