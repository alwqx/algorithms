#include <stdio.h>

#define MAXN 40

char pattern[MAXN], str[MAXN];

// 判断pattern的p位置和str的s位置是否匹配
bool dfs(int p, int s) {
    int i;

    if(pattern[p]=='\0' && str[s]=='\0') return true;

    if(pattern[p]!='*' && pattern[s]!='?') {
        if(pattern[p] == str[s]) return dfs(p+1, s+1);
        return false;
    } else if (pattern[p]=='?') {
        if(str[s] != '\0') return dfs(p+1, s+1);
        return false;
    } else {
        for(i=0; i+s<MAXN; i++)
            if(dfs(p+1, s+i)) return true;
            return false;
    }
}

int main() {
    while(scanf("%s %s", str, pattern) != EOF) 
        if(dfs(0, 0)) printf("YES\n");
        else printf("NO\n");
    
    return 0;
}