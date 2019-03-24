#include <stdio.h>

int gcd(int a, int b) {
    int c;
    while(a%b != 0) {
        c = a%b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int a, b, n, ret;
    scanf("%d", &n);
    while(n--) {
        scanf("%d %d", &a, &b);
        ret = gcd(a, b);
        printf("%d %d\n", ret, a*b/ret);
    }

    return 0;
}
