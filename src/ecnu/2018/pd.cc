/*
计算机专硕 上机题目
Problem D:统计领导和团队数
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 200001

struct Node {
    long leader; // leader id
    long count; // count of team member
} tree[MAXN];

int main() {
    long i, n;
    scanf("%ld", &n);
    for(i=1; i<=n; i++) {
        scanf("%ld", &tree[i].leader);
        tree[i].count = 1;
    }

    long curIndex;
    for(i=1; i<=n; i++) {
        curIndex = i;
        while(tree[curIndex].leader) {
            tree[tree[curIndex].leader].count++;
            curIndex = tree[curIndex].leader;
        }
    }

    for(i=1; i<=n; i++)
        if(i==1) printf("%ld", tree[i].count);
        else printf(" %ld", tree[i].count);
    putchar('\n');

    return 0;
}

struct NNode {
    long index;
    long leader;
    long level;

    bool operator < (const NNode &b) {
        return level < b.level;
    }
} *ttree;

void v2() {
    long *count;
    long i, n;
    scanf("%ld", &n);
    count = new long[n+1];
    ttree = new NNode[n+1];

    for(i=1; i<=n; i++) {
        scanf("%ld", &ttree[i].leader);
        ttree[i].index = i;
        ttree[i].level = ttree[ttree[i].leader].leader+1;
        count[i] = 0;
    }
    sort(ttree+1, ttree+n+1);

    for(i=n; i>=1; i--) {
        count[ttree[i].index] + 1;
        count[ttree[i].leader] += count[ttree[i].index];
    }

    for(i=1; i<=n; i++) {
        if(i>1) printf(" ");
        printf("%ld", count[i]);
    }
    putchar('\n');
}