/*
王道考研机试指导 P52

利用栈处理括号匹配问题
*/
#include <stdio.h>
#include <stack>

using namespace std;

void v1();
void v2();

int main() {
    v1();
    // v2();

    return 0;
}

char s[110];
char ans[110];

void v1() {
    stack<int> v;
    int i, n;
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%s", s);
        for(i=0; s[i]; i++) {
            if(s[i] == '(') {
                v.push(s[i]);
                ans[i] = ' ';
            } else if(s[i] == ')') {
                if(v.empty() == false) {
                    v.pop();
                    ans[i] = ' ';
                } else ans[i] = '?';
            } else ans[i] = ' ';
        }

        while(!v.empty()) {
            printf("v top is: %d\n", v.top());
            ans[v.top()] = '$';
            v.pop();
        }

        ans[i] = '\0';
        printf("src is: %s\n", s);
        printf("ans is: %s\n", ans);
    }
}

void v2() {
    stack<int> s;
    int i, n, m;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &m);
        s.push(m);
    }

    printf("%d\n", s.top());
    printf("%d\n", s.size());
}