#include <stdio.h>
/*
10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
*/
int width, height;
char maze[1010][85];
bool mark[1010][85];
int go[][2] = {
    1,0,
    -1,0,
    0,1,
    0,-1,
    1,1,
    1,-1,
    -1,1,
    -1,-1,
};

void dfs(int x, int y) {
    int i;
    for(i=0; i<8; i++) {
        int nx, ny;
        nx = x+go[i][0];
        ny = y+go[i][1];
        
        if(nx<1||nx>height||ny<1||ny>width) continue;
        if(maze[nx][ny] == '.') continue;
        if(mark[nx][ny]) continue;

        mark[nx][ny] = true;
        dfs(nx, ny);
    }

    return;
}

int main() {
    int i, j, ans;
    while(scanf("%d %d", &width, &height) != EOF) {
        if(width==0 && height==0) break;
        for(i=1; i<=height; i++) scanf("%s", maze[i]+1);
        // init mark
        for(i=1; i<=height; i++)
            for(j=1; j<=width; j++) mark[i][j] = false;

        ans = 0;
        for(i=1; i<=height; i++) {
            for(j=1; j<=width; j++) {
                if(mark[i][j]) continue;
                if(maze[i][j] == '.') continue;
                dfs(i, j);
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}

void v1() {
    
}