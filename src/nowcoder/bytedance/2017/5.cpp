#include <stdio.h>

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    int y=1, n=0;

    while(n<k) {
        if(x+y == x|y) n++;
        y++;
    }
    printf("%d\n", y);

    return 0;
}