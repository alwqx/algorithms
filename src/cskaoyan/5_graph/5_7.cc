/*
王道考研机试指南 p147

图 最短路径：多权值Dijkstra算法
*/
#include <stdio.h>
#include <vector>

#define MAXN 1001

using namespace std;

struct E {
    int adj, d, p;
};

vector<E> edge[MAXN];
int dis[MAXN];
int cost[MAXN];
bool mark[MAXN];

int main() {
    int i, j, n, m, s, t;
    int pa, pb, d, p, newp;
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n==0 && m==0) break;

        // init
        for(i=1; i<=n; i++) {
            edge[i].clear();
            mark[i] = false;
            dis[i] = -1;
        }

        // build adj list for Graph
        while(m--) {
            scanf("%d %d %d %d", &pa, &pb, &d, &p);
            E tmp;
            tmp.adj = pa;
            tmp.d = d;
            tmp.p = p;
            edge[pb].push_back(tmp);
            tmp.adj = pb;
            edge[pa].push_back(tmp);
        }

        scanf("%d %d", &s, &t);
        dis[s] = 0;
        mark[s] = true;
        newp = s;

        // calculate shortest path
        for(i=1; i<n; i++) {
            for(j=0; j<edge[newp].size(); j++) {
                int t = edge[newp][j].adj;
                if(mark[t]) continue;
                d = edge[newp][j].d;
                p = edge[newp][j].p;

                if(dis[t]==-1 || dis[t]>dis[newp]+d || (dis[t]==dis[newp]+d && cost[t]>cost[newp]+p)) {
                    dis[t] = dis[newp]+d;
                    cost[t] = cost[newp]+p;
                }
            }

            int min = 123123123;
            for(j=1; j<=n; j++) {
                if(mark[j]) continue;
                if(dis[j] == -1) continue;
                if(dis[t]<min) {
                    min = dis[t];
                    newp = j;
                }
            }
            mark[newp] = true;
        }

        printf("%d %d\n", dis[t], cost[t]);
    }
}
