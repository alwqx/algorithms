// https://pintia.cn/problem-sets/14/problems/805

#include <stdio.h>
#define MAXN 20

int main() {
    int n;
    scanf("%d", &n);
    if(n == 0) {
        printf("ling");
        return 0;
    }

    char *s[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    if(n<0){
        printf("%s ", "fu");
        n = -n;
    }

    int v[MAXN], j, i=0;
    while(n>0) {
        v[i++] = n%10;
        n /= 10;
    }

    for(j=i-1; j>=1; j--)
        printf("%s ", s[v[j]]);
    printf("%s", s[v[0]]);

    return 0;
}