/*
王道考研机试指南 p180

递归 dfs遍历地图，寻找条件
*/
#include <stdio.h>

#define MAXN 8

char maze[MAXN][MAXN];
int row, col, t;
bool success;

int go[][2] = {
    1, 0,
    -1, 0,
    0, 1,
    0, -1,
};

void dfs(int x, int y, int time) {
    int i, nx, ny;
    for(i=0; i<4; i++) {
        nx = x+go[i][0];
        ny = y+go[i][1];
        if(nx<1||nx>row||ny<1||ny>col) continue;
        if(maze[nx][ny] == 'X') continue;
        if(maze[nx][ny] == 'D') {
            if(time+1 == t) {
                success = true;
                return;
            }else continue;
        }

        // 不是门，继续走
        maze[nx][ny] = 'X';
        dfs(nx, ny, time+1);
        maze[nx][ny] = '.';

        if(success) return;
    }
}

int main() {
    int i, j;
    int xs, ys; // 起点坐标
    int xd, yd; // 门坐标
    bool founds, foundd; // 是否找到门和起点坐标
    while(scanf("%d %d %d", &row, &col, &t) != EOF) {
        if(row==0 && col==0 && t==0) break;
        for(i=1; i<=row; i++)
            scanf("%s", maze[i]+1);
        
        success = false;
        founds = foundd = false;
        for(i=1; i<=row; i++) {
            if(foundd && founds) break;
            for(j=1; j<=col; j++) {
                if(maze[i][j] == 'S') {
                    xs = i;
                    ys = j;
                    founds = true;
                }
                if(maze[i][j] == 'D') {
                    xd = i;
                    yd = j;
                    foundd = true;
                }
            }
        }

        printf("s:(%d, %d). d:(%d, %d)\n", xs, ys, xd, yd);
        
        // 根据坐标判断是否减枝，奇偶性相同则dfs
        if((xs+ys)%2 == ((xd+yd)%2+t%2)%2) {
            maze[xs][ys] = 'X';
            dfs(xs, ys, 0);
        }

        printf("%s\n", success==true?"YES":"NO");
    }

    return 0;
}