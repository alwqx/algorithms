/*
王道考研机试指南 p157

搜索 状态搜索、减枝、BFS
*/
#include <stdio.h>
#include <queue>

using namespace std;

bool mark[50][50][50];
int maze[50][50][50];

struct N {
    int x, y, z;
    int t;
};

queue<N> Q;
int go[][3] = {
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1,
};

int bfs(int a, int b, int c) {
    int i, nx, ny, nz;
    while(!Q.empty()) {
        N t = Q.front();
        Q.pop();
        for(i=0; i<6; i++) {
            nx = t.x+go[i][0];
            ny = t.y+go[i][1];
            nz = t.z+go[i][2];

            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c) continue;
            if(mark[nx][ny][nz]) continue;
            if(maze[nx][ny][nz] == 1) continue;

            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = t.t+1;
            Q.push(tmp);
            mark[nx][ny][nz] = true;
            if(nx==a-1 && ny==b-1 && nz==c-1) return tmp.t;
        }
    }

    return -1;
}

int main() {
    int i, j, k, n;
    scanf("%d", &n);

    int a, b, c, t;
    while(n--) {
        scanf("%d %d %d %d", &a, &b, &c, &t);
        for(i=0; i<a; i++)
            for(j=0; j<b; j++)
                for(k=0; k<c; k++) {
                    mark[i][j][k] = false;
                    scanf("%d", &maze[i][j][k]);
                }
    
        // clear Q
        while(!Q.empty()) Q.pop();
        N tmp;
        tmp.x = tmp.y = tmp.z = tmp.t = 0;
        mark[0][0][0] = true;
        Q.push(tmp);
        
        int ret = bfs(a, b, c);
        if(ret>0 && ret<=t) printf("%d\n", ret);
        else printf("-1\n");
    }
    
    return 0;
}