// https://pintia.cn/problem-sets/14/problems/806

#include <stdio.h>

int main() {
    char c = 0; // init lastc
    int count = 0;

    while(c=getchar()) {
        if(c!=' ' && c!='.') count++;
        else if(c==' ') {
            if(count) printf("%d ", count);
            count=0;
        }else if(c == '.') {
            if(count) printf("%d", count);
            break;
        }
    }

    return 0;
}