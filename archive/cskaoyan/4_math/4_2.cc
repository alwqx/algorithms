/*
王道考研机试指南 p79

数位拆解
*/
#include <stdio.h>

int main() {
    char a[11], b[11];
    scanf("%s %s", a, b);
    int i, j, sum=0;

    for(i=0; a[i]; i++) {
        for(j=0; b[j]; j++)
            sum += (a[i]-'0')*(b[j]-'0');
    }

    printf("%d\n", sum);
    return 0;
}