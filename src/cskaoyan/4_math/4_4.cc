/*
王道考研机试指南 p83

进制转换
*/
#include <stdio.h>
#include <string.h>

int main() {
    char a, s[40], b;
    int i, x, tmp, len, c, size;
    while(scanf("%d %s %d", &a, s, &b) != EOF) {
        len = strlen(s); c = 1; tmp = 0;
        for(i=len-1; i>=0; i--) {
            if(s[i]>='0' && s[i]<='9')
                x = s[i]-'0';
            else if(s[i]>='a' && s[i]<='f')
                x = s[i]-'a'+10;
            else if(s[i]>='A' && s[i]<='F')
                x = s[i]-'A'+10;
            tmp += c*x;
            c *= a;
        }

        char ans[40];
        size = 0;
        while(tmp) {
            x = tmp%b;
            ans[size++] = x<10?x+'0':x+'A'-10;
            tmp /= b;
        }

        for(i=size-1; i>=0; i--)
            putchar(ans[i]);
        putchar('\n');
    }

    return 0;
}