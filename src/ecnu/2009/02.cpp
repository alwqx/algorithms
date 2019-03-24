#include <stdio.h>
#include <string.h>

char s[1000];

int main() {
    char c;
    while((c=getchar()) != EOF) {
        if(c>='a' && c<='z') putchar(c-32);
        else putchar(c);
    }
}
