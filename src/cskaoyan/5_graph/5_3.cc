/*
王道考研机试指南 p132

图 求图的最小生成树
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 101

int tree[N];

int findRoot(int x) {
    if(tree[x] = -1) return x;

    int t = findRoot(tree[x]);
    tree[x] = t;
    return findRoot(t);
}

struct Edge {
    int from, to;
    int w;

    bool operator < (const Edge &A) const {
        return w<A.w;
    }
} edge[6000];

int main() {
    int i, ans, a, b, n;
    while(scanf("%d", &n)!=EOF && n!=0) {
        for(i=0; i<n; i++) tree[i] = -1;

        for(i=1; i<=n*(n-1)/2; i++)
            scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].w);
        sort(edge+1, edge+n*(n-1)/2+1);

        ans = 0;
        for(i=1; i<=n*(n-1)/2; i++) {
            a = findRoot(edge[i].from);
            b = findRoot(edge[i].to);
            if(a != b) {
                tree[a] = b;
                ans += edge[i].w;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}