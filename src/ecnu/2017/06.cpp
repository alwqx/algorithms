/*
五子棋，判断白棋再下一步是否能赢
*/
#include <stdio.h>

#define MAXN 19

char map[MAXN+9][MAXN+9];

int dx[] = {1,0,1,1};
int dy[] = {0,1,1,-1};

bool isBlack(int x, int y) {
    return x>=0 && x<MAXN && y>=0 && y<MAXN && map[x][y] == 'B';
}

// 检查在line行上是否符合
bool checkLine(int x, int y, int line) {
    int i, nx, ny, black;

    nx = x; ny = y;
    black = 1;
    for(i=0; i<4; i++) {
        nx += dx[line];
        ny += dy[line];
        if(isBlack(nx, ny)) black++;
        else break;
        if(black>=5) return true;
    }

    nx = x; ny = y;
    black = 1;
    for(i=0; i<4; i++) {
        nx -= dx[line];
        ny -= dy[line];
        if(isBlack(nx, ny)) black++;
        else break;
        if(black>=5) return true;
    }

    return false;
}

bool canWin(int x, int y) {
    int i;
    for(i=0; i<4; i++)
        if(checkLine(x, y, i)) return true;

    return false;
}

int main() {
    int i, j;
    for(i=0; i<MAXN; i++)
        scanf("%s", map[i]);
    
    for(i=0; i<MAXN; i++)
        for(j=0; j<MAXN; j++)
            if(map[i][j] == '.' && canWin(i, j))
                printf("(%d,%d)\n", i, j);

    return 0;
}

/*
BBBB...............
.B.................
..B................
...B...............
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
...................
*/