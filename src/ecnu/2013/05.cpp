#include <stdio.h>

int main() {
    int n, money, people;
    scanf("%d", &n);

    int x, y; // maile, female
    while(n--) {
        scanf("%d %d", &people, &money);
        for(x=0; x<=people; x++)
            for(y=0; y<= people-x; y++)
                if(3*x+2*y+(people-x-y) == money)
                    printf("%d %d %d\n", x, y, people-x-y);
    }

    return 0;
}