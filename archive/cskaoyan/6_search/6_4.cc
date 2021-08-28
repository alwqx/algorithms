/*
王道考研机试指南 p170

递归 汉诺塔
*/
#include <stdio.h>

int han(int x) {
    if(x == 1) return 2;
    return 3*han(x-1)+2;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%d\n", han(n));
    
    return 0;
}