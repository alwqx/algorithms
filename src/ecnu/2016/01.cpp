#include <stdio.h>
#include <vector>

using namespace std;

int map[6][6];

struct point {
    int x, y;
};

int main() {
    int i, j;
    for(i=1; i<=5; i++)
        for(j=1; j<=5; j++) scanf("%d", &map[i][j]);
    
    int x=1, y=1, nx, ny, n, step=0;
    vector<point> v;

    while(step < 25) {
        point p;
        if(step == 0) {
            x = 1;
            y = 1;
        }

        p.x = x;
        p.y = y;
        v.push_back(p);
        step++;
        
        if(10*x+y==map[x][y]) break;
        x = map[x][y]/10;
        y = map[x][y]%10;
    }

    if(step < 25)
        for(i=0; i<v.size(); i++) {
            if(i>0) printf("->");
            printf("(%d,%d)", v[i].x, v[i].y);
        }
    else printf("-1");
    putchar('\n');

    return 0;
}

/*
12 12 14 12 14
12 13 14 12 14
12 13 14 12 14
12 13 14 12 14
12 13 14 12 14

12 13 14 12 14
12 13 14 12 14
12 13 14 12 14
12 13 14 12 14
12 13 14 12 14
*/