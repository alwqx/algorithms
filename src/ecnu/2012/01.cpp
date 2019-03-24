#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    char s[110];
    while(scanf("%s", s) != EOF) {
        sort(s, s+strlen(s));
        printf("%s\n", s);
    }

    return 0;
}