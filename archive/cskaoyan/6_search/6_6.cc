/*
王道考研机试指南 p176

递归 最大相邻块
*/
#include <stdio.h>
#define MAXN 101

char map[MAXN][MAXN];
bool mark[MAXN][MAXN];

int go[][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
    1, 1,
    1, -1,
    -1, 1,
    -1, -1,
};

int row, col;

void dfs(int x, int y) {
    mark[x][y] = true;
    int i, nx, ny;
    for(i=0; i<8; i++) {
        // 遍历8个相邻的点
        nx = x+go[i][0];
        ny = y+go[i][1];
        
        if(nx<1||nx>row||ny<1||ny>col) continue;
        if(mark[nx][ny]) continue;
        if(map[nx][ny] == '*') {
            mark[nx][ny] = true;
            continue;
        }
        
        mark[nx][ny] = true;
        dfs(nx, ny);
    }
}

int main() {
    int i, j, ans;
    while(scanf("%d %d", &row, &col) != EOF) {
        if(row==0 && col==0) break;
        // input map and init mark
        for(i=1; i<=row; i++)
            scanf("%s", map[i]+1);
        for(i=1; i<=row; i++)
            for(j=1; j<=col; j++)
                mark[i][j] = false;
        
        // print map
        printf("map of %d rows and %d cols are:\n", row, col);
        for(i=1; i<=row; i++)
            printf("%s\n", map[i]+1);
        
        ans = 0;
        // init
        for(i=1; i<=row; i++) {
            for(j=1; j<=col; j++) {
                if(map[i][j] == '*') {
                    mark[i][j] = true;
                    continue;
                }
                if(mark[i][j]) continue;
                dfs(i, j);
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}