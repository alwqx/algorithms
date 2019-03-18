/*
王道考研机试指南 p219

C++ STL map处理
*/
#include <stdio.h>
#include <map>

using namespace std;

int indegree[2002];
map<string, int> m;

int main() {
    int i, n, cnt, index, ia, ib;
    char s1[50], s2[50];
    while(scanf("%d", &n)!=EOF && n!=0) {
        // init
        m.clear();
        index = 0;
        for(i=0; i<2002; i++) indegree[i] = 0;

        for(i=0; i<n; i++) {
            scanf("%s %s", s1, s2);
            string a=s1, b=s2;
            
            if(m.find(a) == m.end()) {
                ia = index;
                m[a] = index++;
            } else ia = m[a];
            if(m.find(b) == m.end()) {
                ib = index;
                m[b] = index++;
            } else ib = m[b];

            indegree[ib]++;
        }

        cnt = 0;
        for(i=0; i<index; i++)
            if(indegree[i]==0) cnt++;
        printf("%s\n", cnt==1?"YES":"NO");
    }

    return 0;
}