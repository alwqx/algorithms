/*
王道考研机试指南 p153

图 拓扑排序 是否有环
*/
#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 101

using namespace std;

queue<int> q;
int indegree[MAXN];
vector<int> edge[MAXN];

int main() {
    int i, n, m, a, b, cnt;
    while(scanf("%d %d", &n, &m) != EOF) {
        if(m==0 && n==0) break;

        // init
        for(i=0; i<MAXN; i++) {
            edge[i].clear();
            indegree[i] = 0;
        }

        while(m--) {
            scanf("%d %d", &a, &b);
            indegree[b]++;
            edge[a].push_back(b);
        }

        // init queue
        while(!q.empty()) q.pop();
        for(i=0; i<n; i++)
            if(indegree[i]==0) q.push(i);
        cnt = 0;
        while(!q.empty()) {
            int p = q.front();
            cnt++;
            q.pop();
            for(i=0; i<edge[p].size(); i++) {
                indegree[edge[p][i]]--;
                if(indegree[edge[p][i]] == 0) q.push(edge[p][i]);
            }
        }

        printf("%s\n", cnt==n?"YES":"NO");
    }

    return 0;
}