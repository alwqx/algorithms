/*
王道考研机试指南 p126

图 求图的连通分量
*/
#include <stdio.h>

#define N 1000

int tree[N];

int findRoot(int x) {
    if(tree[x] == -1) return x;
    int tmp = findRoot(tree[x]);
    tree[x] = tmp;
    return findRoot(tmp);
}

int main() {
    int m, n, a, b, i, ans;
    while(scanf("%d", &n)!=EOF && n!=0) {
        for(i=0; i<n; i++) tree[i] = -1;
        
        scanf("%d", &m);
        while(m--) {
            scanf("%d %d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b) tree[a] = b;
        }

        ans = 0;
        for(i=0; i<n; i++)
            if(tree[i]==-1) ans++;
        
        printf("%d\n", ans-1);
    }

    return 0;
}