#include <stdio.h>

int main() {
    long long a, b;
    while(scanf("%llX %llX", &a, &b) != EOF)
        printf("%llX\n", a+b);

    return 0;
}