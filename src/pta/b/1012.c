// https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840
#include <stdio.h>

int main() {
    int i, N, n;
    scanf("%d", &N);

    int x, c=0, c3=0;
    long int a[5] = {0};
    for(i=0; i<N; i++) {
        scanf("%d", &n);
        switch(n%5) {
        case 0:
            if(n%2==0) a[0] += n;
            break;
        case 1:
            if(c%2==0)  a[1] += n;
            else        a[1] -= n;
            c++;
            break;
        case 2:
            a[2]++;
            break;
        case 3:
            a[3] += n;
            c3++;
            break;
        case 4:
            if(a[4]<n) a[4] = n;
            break;
        }
    }

    if(a[0] == 0)   printf("N ");
    else            printf("%ld ", a[0]);
    if(c == 0)      printf("N ");
    else            printf("%ld ", a[1]);
    if(a[2] == 0)   printf("N ");
    else            printf("%ld ", a[2]);

    if(c3 == 0)     printf("N ");
    else            printf("%.1f ", a[3]/((float) c3));

    if(a[4] == 0)   printf("N");
    else            printf("%ld", a[4]);
    
    return 0;
}