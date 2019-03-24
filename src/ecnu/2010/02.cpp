#include <stdio.h>

int main() {
    int e, f, c, tot, sum;
    while(scanf("%d %d %d", &e, &f, &c) != EOF) {
        tot = e+f;
        if(tot<c) {
            printf("0\n");
            continue;
        }

        sum = 0;
        while(tot >= c) {
            sum += tot/c;
            tot = tot/c + tot%c;
        }

        printf("%d\n", sum);
    }
    
    return 0;
}