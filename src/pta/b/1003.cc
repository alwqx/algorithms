// https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192

#include <stdio.h>
#include <string.h>
#include <string>

#define MAXN 101

using namespace std;

int main() {
    int i, j, N;
    scanf("%d", &N);
    
    char s[MAXN];
    int a, b, c, p, t, len;
    for(i=0; i<N; i++) {
        bool ret = true;
        scanf("%s", s);
        a = b = c = p = t = 0;
        len = strlen(s);
        for(j=0; j<len; j++) {
            if(s[j]!='A' && s[j]!='P' && s[j]!='T') {
                ret = false;
                break;
            }
            if(s[j]=='P') {
                p++;
                if(p==2) {
                    ret = false;
                    break;
                }
            }
            if(s[j]=='T') {
                t++;
                if(t==2) {
                    ret = false;
                    break;
                }
            }
        }
        if(ret) {
            string ss = s;
            a = ss.find("P");
            b = ss.find("A");
            c = ss.find("T");
            if(b==-1) ret = false;
            else ret = ((a*(c-a-1)) == (len-c-1))?true:false;
        }

        if(ret) printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}