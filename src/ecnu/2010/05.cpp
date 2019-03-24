#include <stdio.h>

int main() {
    int t, m, k;
    scanf("%d", &t);
    int i, sum, n;
    while(t--) {
        scanf("%d %d", &m, &k);
        sum = 0;
        for(i=0; i<m; i++) {
            scanf("%d", &n);
            if(i<k) sum+=n;
        }
        printf("%d\n", sum);
    }

    return 0;
}