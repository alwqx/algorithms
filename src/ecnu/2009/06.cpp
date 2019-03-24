#include <algorithm>
#include <stdio.h>

using namespace std;

struct Edge {
    int a, b;
    int weight;

    bool operator < (const Edge &A) {
        return weight<A.weight;
    }
}edge[15001];

int tree[1001];

int findRoot(int x) {
    if(tree[x] == -1) return x; // x is root
    int tmp = findRoot(tree[x]);
    tree[x] = tmp;
    return tmp;
}

int cmp(Edge m, Edge n) {
    return m.weight<n.weight;
}

int main() {
    int i, n, m;
    scanf("%d %d", &n, &m);

    // init tree
    for(i=1; i<=n; i++) tree[i] = -1;
    for(i=1; i<=m; i++)
        scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].weight);
    sort(edge+1, edge+m+1);

    int x, y, ret=0;
    for(i=1; i<=m; i++) {
        x = findRoot(edge[i].a);
        y = findRoot(edge[i].b);
        if(x != y) {
            tree[y] = x;
            ret += edge[i].weight;
        }
    }

    printf("%d\n", ret);
}
