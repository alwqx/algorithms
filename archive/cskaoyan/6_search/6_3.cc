/*
王道考研机试指南 p162

搜索 状态搜索、减枝、BFS 可乐平分
*/
#include <stdio.h>
#include <queue>

#define MAXN 101

using namespace std;

struct N {
    int vs, vn, vm;
    int t;
};

queue<N> Q;
bool mark[MAXN][MAXN][MAXN];

/*
倾倒函数。从容积为va的杯子倒入vb的杯子，a、b为当前的体积
*/
void AtoB(int &a, int va, int &b, int vb) {
    if(vb-b>=a) {
        b += a;
        a = 0;
    } else {
        a = a-(vb-b);
        b = vb;
    }
}

int bfs(int s, int n, int m) {
    while(!Q.empty()) {
        N now = Q.front();
        Q.pop();
        
        int a, b, c; // 临时保存三个杯子中可乐体积
        a = now.vs;
        b = now.vn;
        c = now.vm;

        // a倒向b
        AtoB(a, s, b, n);
        if(!mark[a][b][c]) {
            mark[a][b][c] = true;
            N tmp;
            tmp.vs = a;
            tmp.vn = b;
            tmp.vm = c;
            tmp.t = now.t+1;
            if((a==s/2&&b==s/2) || (a==s/2&&c==s/2) || (c==s/2&&b==s/2))
                return tmp.t;

            Q.push(tmp);
        }

        a = now.vs;
        b = now.vn;
        c = now.vm;
        AtoB(b, n, a, s);
        if(!mark[a][b][c]) {
            mark[a][b][c] = true;
            N tmp;
            tmp.vs = a;
            tmp.vn = b;
            tmp.vm = c;
            tmp.t = now.t+1;
            if((a==s/2&&b==s/2) || (a==s/2&&c==s/2) || (c==s/2&&b==s/2))
                return tmp.t;

            Q.push(tmp);
        }

        a = now.vs;
        b = now.vn;
        c = now.vm;
        AtoB(a, s, c, m);
        if(!mark[a][b][c]) {
            mark[a][b][c] = true;
            N tmp;
            tmp.vs = a;
            tmp.vn = b;
            tmp.vm = c;
            tmp.t = now.t+1;
            if((a==s/2&&b==s/2) || (a==s/2&&c==s/2) || (c==s/2&&b==s/2))
                return tmp.t;

            Q.push(tmp);
        }
    }
}