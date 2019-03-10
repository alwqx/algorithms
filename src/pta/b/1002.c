// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
#include <stdio.h>

#define MAXN 100

char *s[] = {"ling", "yi", "er", "san", "si",
            "wu", "liu", "qi", "ba", "jiu"};

int main() {
    int a[MAXN], i=0;
    char c;
    while(1) {
        c = getchar();
        if(c<'0' || c>'9') break;
        a[i++] = c-'0';
    }
    int N=i, sum=0;
    for(i=0; i<N; i++)
        sum += a[i];

    int b[MAXN];
    i = 0;
    while(sum!=0) {
        b[i++] = sum%10;
        sum /= 10;
    }
    N= i;
    for(i=N-1; i>=0; i--)
        if(i==0)    printf("%s\n", s[b[i]]);
        else        printf("%s ", s[b[i]]);
    return 0;
}