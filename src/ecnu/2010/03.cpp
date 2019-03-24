#include <stdio.h>

int main() {
    char c;
    int t, nl, nm, no;
    scanf("%d", &t);
    getchar();
    while(t--) {
        nl=nm=no = 0;
        while((c=getchar()) != '\n') {
            if((c>='a'&&c<='z') || (c>='A'&&c<='Z')) nl++;
            else if(c>='0' && c<='9') nm++;
            else no++;
        }

        printf("character:%d\n", nl);
        printf("number:%d\n", nm);
        printf("others:%d\n", no);
    }

    return 0;
}