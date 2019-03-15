/*
王道考研机试指南 p59

哈夫曼树
*/
#include <queue>
#include <stdio.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main() {
    int i, n, x, ans;
    int a, b;
    while(scanf("%d", &n) != EOF) {
        // empty q
        while(q.empty() == false) q.pop();

        for(i=0; i<n; i++) {
            scanf("%d", &x);
            q.push(x);
        }

        ans = 0;
        while(q.size() > 1) {
            a = q.top();
            q.pop();
            b = q.top();
            q.pop();
            ans = ans + a + b;
            q.push(a+b);
        }

        printf("%d\n", ans);
    }
    
    return 0;
}