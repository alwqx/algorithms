/*
王道考研机试指南 p90

判断素数
*/
#include <stdio.h>
#include <math.h>

bool judge(int n) {
    if(n<2) return false;
    int i, bound = (int) sqrt(n) + 1;
    for(i=2; i<bound; i++)
        if(n%i == 0) return false;

    return true;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF)
        printf("%s\n", judge(n)?"yes":"no");

    return 0;
}