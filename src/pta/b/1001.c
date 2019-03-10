// https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
#include <stdio.h>

int main() {
    int n, sum=0;
    scanf("%d", &n);
    while(n!=1) {
        if(n%2==0)  n /= 2;
        else        n = (3*n+1)/2;
        sum++;
    }

    printf("%d\n", sum);
    return 0;
}