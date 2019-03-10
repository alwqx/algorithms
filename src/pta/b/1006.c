// https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592
#include <stdio.h>

int main() {
    int n, j, k, i=0;
    scanf("%d", &n);
    
    int a[3];
    while(n) {
        a[i++] = n%10;
        n /= 10;
    }
    for(j=i-1; j>=0; j--) {
        if(j==2) // B
            for(k=0; k<a[j]; k++) printf("B");
        else if(j==1)
            for(k=0; k<a[j]; k++) printf("S");
        else
            for(k=0; k<a[j]; k++) printf("%d", k+1);
    }
    return 0;
}