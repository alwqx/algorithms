// https://pintia.cn/problem-sets/14/problems/801

#include <stdio.h>

int main() {
    int x, y, N, found=1;
    scanf("%d", &N);

    if(N<=4) {
        for(x=1; x<N; x++)
            for(y=x; y<=N-x*x; y++){
                if(x*x+y*y == N) {
                    printf("%d %d\n", x, y);
                    found = 0;
                }
            }
    } else {
        for(x=1; x*x<N; x++)
            for(y=x; y<=N-x*x; y++){
                if(x*x + y*y == N) {
                    printf("%d %d\n", x, y);
                    found = 0;
                }
            }
    }

    if(found == 1)
        printf("No Solution\n");
    return 0;
}