/*
王道考研机试指南 p128

图 求图的连通分量-计算好朋友数量
*/
#include <stdio.h>

#define N 10001

int tree[N];

int findRoot(int x) {
    if(tree[x] == -1) return x;
    
    int t = findRoot(tree[x]);
    tree[x] = t;
    return findRoot(t);
}

// represent number of childs of on root
int sum[N];

int main() {
    int i, a, b, n, ans;
    while(scanf("%d", &n) != EOF) {
        // init
        for(i=1; i<N; i++) {
            sum[i] = 1;
            tree[i] = -1;
        }

        while(n--) {
            scanf("%d %d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b) {
                tree[a] = b;
                sum[b] += sum[a];
            }
        }

        ans = -1;
        for(i=1; i<N; i++)
            if(tree[i]==-1&&sum[i]>ans) ans=sum[i];
        printf("%d\n", ans);
    }

    return 0;
}