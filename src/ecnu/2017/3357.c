// https://eoj.i64d.com/problem/3357/
#include <stdio.h>

void v1();
void v2();

int main() {
    v1();
}

void v1() {
    int d;
    long long i, k;
    scanf("%d %lld", &d, &k);
    
    double s = 0.0;
    long long a = 1 + (k-1)*d;
    for(i=k; i>=1; i--) {
        if(i==k)    s = 1.0/((double) a);
        else        s = 1.0/((double) a+1/s);
        a -= d;
    }

    printf("%.16f\n", s);
}