/*
王道考研机试指南 p141

图 最短路径：Floyd和Dijkstra算法
*/
#include <stdio.h>
#include <vector>

#define N 101

using namespace std;

int dis[N][N];

void floyd();
void dijkstra();

int main() {
    // floyd();
    dijkstra();
    return 0;
}

void floyd() {
    int i, j, k, a, b, c, n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n==0 && m==0) break;

        // init matrix
        for(i=1; i<=n; i++) {
            for(j=1; j<=n; j++)
                dis[i][j] = dis[j][i] = -1;
            dis[i][i] = 0;
        }

        while(m--) {
            scanf("%d %d %d", &a, &b, &c);
            dis[a][b] = dis[b][a] = c;
        }
        
        // floyd
        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++) {
                    if(dis[i][k]==-1 || dis[k][j]==-1) continue;
                    if(dis[i][j]==-1 || dis[i][k]+dis[k][j]<dis[i][j])
                        dis[i][j] = dis[i][k]+dis[k][j];
                }
        
        printf("%d\n", dis[1][n]);
    }
}

struct E {
    int next;
    int w;
};

vector<E> edge[N];
bool mark[N];
int ddis[N];
void dijkstra() {
    int i, j, n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        if(n==0 && m==0) break;
        // init adj list
        for(i=1; i<=n; i++) {
            edge[i].clear();
            ddis[i] = -1;
            mark[i] = false;
        }

        int a, b, c;
        while(m--) {
            scanf("%d %d %d", &a, &b, &c);
            E t;
            t.w = c;
            t.next = b;
            edge[a].push_back(t);
            t.next = a;
            edge[b].push_back(t);
        }

        // from 1
        ddis[1] = 0;
        mark[1] = true;
        int newp = 1;
        for(i=1; i<=n; i++) {
            for(j=0; j<edge[newp].size(); j++) {
                int t = edge[newp][j].next;
                int w = edge[newp][j].w;
                if(mark[t]) continue;
                if(ddis[t]==-1||ddis[t]>ddis[newp]+w)
                    ddis[t] = ddis[newp]+w;
            }
            int min = 123123123;
            for(j=1; j<=n; j++) {
                if(mark[j]) continue;
                if(ddis[j]==-1) continue;
                if(ddis[j]<min) {
                    min = ddis[j];
                    newp = j;
                }
            }
            mark[newp] = true;
        }

        printf("%d\n", ddis[n]);
    }
}