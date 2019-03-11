// https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952
#include <stdio.h>

int main() {
    int i, T;
    scanf("%d", &T);
    long int A, B, C;
    for(i=0; i<T; i++) {
        scanf("%ld %ld %ld", &A, &B, &C);
        if(A+B-C>0) printf("Case #%d: true\n", i+1);
        else        printf("Case #%d: false\n", i+1);
    }
    
    return 0;
}