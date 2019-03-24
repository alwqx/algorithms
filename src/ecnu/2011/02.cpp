#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    double s, t, e;
    while(n--) {
        scanf("%lf %lf %lf", &s, &t, &e);
        if(fabs(s-t)<=e) printf("Accept\n");
        else printf("Wrong Answer\n");
    }

    return 0;
}