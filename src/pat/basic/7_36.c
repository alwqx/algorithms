// https://pintia.cn/problem-sets/14/problems/816

#include <stdio.h>

int main() {
    float a1, a2, a3, b1, b2;
    scanf("%f %f %f %f", &a1, &b1, &a2, &b2);

    float r[4], v[4];
    // +
    r[0] = a1+a2; v[0] = b1+b2;
    // -
    r[1] = a1-a2; v[1] = b1-b2;
    // *
    r[2] = a1*a2-b1*b2; v[2] = a1*b2+a2*b1;
    // /
    r[3] = (a1*a2+b1*b2)/(a2*a2+b2*b2);
    v[3] = (b1*a2-a1*b2)/(a2*a2+b2*b2);

    char op[] = {'+', '-', '*', '/'};
    int i;
    for(i=0; i<4; i++) {
        if(r[i]*10<1 && r[i]*10>-1) r[i] = 0;
        if(v[i]*10<1 && v[i]*10>-1) v[i] = 0;

        printf("(%.1f", a1);
        if(b1<0)
            printf("%.1fi) %c (%.1f", b1, op[i], a2);
        else
            printf("+%.1fi) %c (%.1f", b1, op[i], a2);
        if(b2<0)
            printf("%.1fi) = ", b2);
        else
            printf("+%.1fi) = ", b2);
        
        if(r[i]==0 && v[i]==0) {
            printf("0.0\n");
            continue;
        }

        if(r[i] != 0) {
            printf("%.1f", r[i]);
            if(v[i] > 0)
                printf("+%.1fi", v[i]);
            if(v[i] < 0)
                printf("%.1fi", v[i]);
        } else {
            if(v[i] != 0)
                printf("%.1fi", v[i]);
        }
        putchar('\n');
    }

    return 0;
}