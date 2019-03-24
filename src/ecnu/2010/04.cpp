#include <stdio.h>

int main() {
    int n, sum, a, b, base;
    scanf("%d", &n);

    while(n--) {
        scanf("%d %d", &a, &b);
        sum = 0;
        base = a/b;         // 不算优惠，可以买多少个
        sum += base;
        sum += base/5*2;    // 算上买5送2的优惠
        base %= 5;          // 去掉买5的优惠
        sum += base/3;      // 算上买3送1的优惠

        printf("%d\n", sum);
    }

    return 0;
}