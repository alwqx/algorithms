/*
王道考研机试指南 p136

图 求图的最小生成树权值
*/
#include <stdio.h>
#include <math.h>
#include <algorithm>

#define N 101

using namespace std;

int tree[N];

int findRoot(int x) {
    if(tree[x] == -1) return x;

    int t = findRoot(tree[x]);
    tree[x] = t;
    return findRoot(t);
}

struct Edge {
    int a, b;
    double w;

    bool operator < (const Edge &A) const {
        return w<A.w;
    }
} edge[6000];

struct Point {
    double x, y;
    double getDis(Point A) {
        double t = (x-A.x)*(x-A.x) + (y-A.y)*(y-A.y);
        return sqrt(t);
    }
} pps[N];

int main() {
    int i, j, a, b, size, n;
    double ans;

    while(scanf("%d", &n) != EOF) {
        for(i=1; i<=n; i++)
            scanf("%lf %lf", &pps[i].x, &pps[i].y);
        size = 0;
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++) {
                edge[size].a = i;
                edge[size].b = j;
                edge[size].w = pps[i].getDis(pps[j]);
                size++;
            }
        sort(edge, edge+size);

        ans = 0;
        for(i=1; i<=n; i++) tree[i] = -1;
        for(i=0; i<size; i++) {
            a = findRoot(edge[i].a);
            b = findRoot(edge[i].b);
            if(a != b) {
                tree[a] = b;
                ans += edge[i].w;
            }
        }

        printf("%.2lf\n", ans);
    }

    return 0;
}