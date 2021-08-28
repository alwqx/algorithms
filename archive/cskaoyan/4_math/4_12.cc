/*
王道考研机试指南 p104

求A的B次方后3位
*/
#include <stdio.h>

int main() {
    int a, b, ret;
    while(scanf("%d %d", &a, &b) != EOF) {
        if(a==0 && b==0) break;

        ret = 1;
        while(b) {
            if(b%2 == 1) {
                ret *= a;
                ret %= 1000;
            }

            b /= 2;
            a *= a;
            a %= 1000;
        }

        printf("%d\n", ret);
    }
    
    return 0;
}